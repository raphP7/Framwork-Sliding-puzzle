/*
 * FramPlateauLand.tpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

/*
 * Ask the game to perform a new step with a given direction
 */
template<class T> bool FramPlateauLand<T>::doAction(char direction) {

	int xArriv = -1;
	int yArriv = -1;

	if (isJeuxPersonnage) {
		this->getArrival_from_Direction_of_Personnage(&xArriv, &yArriv,direction);
		if (!this->testArrivalPositionForPersonnage(xArriv, yArriv)) {
			return false;
		}
	}

	if (this->performAction(xArriv, yArriv, direction)) {

		afterAction();
		return true;
	} else {
		if (modeGame && this->modeTerminal) {
			cout << "MOUVEMENT INEFICASSE" << endl;
		}
		return false;
	}
}

template<class T> void FramPlateauLand<T>::StartModeTerminal() {
	this->modeTerminal=true;
	this->affiche();
	do {
		bool moveNotDone = true;
		char direction;

		while (moveNotDone) {
			if (this->modeGame) {
				direction=getInputDirectionFromConsole();
			} else {
				direction = this->getRandomDirection();
				cout<< "direction choisi : " << direction << endl;
			}
			moveNotDone = !doAction(direction);
		}
		this->affiche();
	} while (!this->isGameEnd());
	cout << "JEUX FINI" << endl;
}


template<class T> void FramPlateauLand<T>::doSwap(int i2,int j2){

    T* tmp=plateau[PositionXPersonnage][PositionYPersonnage];
    plateau[PositionXPersonnage][PositionYPersonnage]=plateau[i2][j2];
    plateau[i2][j2]=tmp;

}

template<class T> char FramPlateauLand<T>::getInputDirectionFromConsole() {
	bool notGoodValue = true;
	char input =' ';
	while (notGoodValue) {

		cout << "Entre une direction i|j|k|l :";
		cin >> &input;
		if (input == 'i' || input == 'j' || input == 'k'
				|| input == 'l') {
			notGoodValue=false;
		}
		else{
			cout<< "BAD INPUT , i -> UP | j -> LEFT | k -> DOWN | l -> RIGHT"<< endl;
		}
	}

	return input;

}

template<class T> void FramPlateauLand<T>::getArrival_from_Position_and_Direction(int xStart, int yStart,char direction,
		int * xArriv, int * yArriv) {

	if (direction == 'i') {

		*xArriv = xStart - 1;
		*yArriv = yStart;

	} else if (direction == 'j') {
		*xArriv = xStart;
		*yArriv = yStart - 1;

	} else if (direction == 'k') {
		*xArriv = xStart + 1;
		*yArriv = yStart;

	} else if (direction == 'l') {
		*xArriv = xStart;
		*yArriv = yStart + 1;

	} else {
		cout << "Bad input" << endl;
	}

}

template<class T> void FramPlateauLand<T>::getArrival_from_Direction_of_Personnage(
		int * xArriv, int * yArriv, char direction) {

	getArrival_from_Position_and_Direction(this->PositionXPersonnage,this->PositionYPersonnage,direction,xArriv,yArriv);

}

template<class T> bool FramPlateauLand<T>::testArrivalPositionForPersonnage(
		int xArriv, int yArriv) {

	int sizeMaxI = this->plateau.size() - 1;
	int sizeMaxJ = this->plateau[0].size() - 1;

	//hors du terrain
	if (xArriv < 0 || yArriv < 0 || xArriv > sizeMaxI || yArriv > sizeMaxJ) {
		if (this->modeGame && this->modeTerminal) {
			cout << "valeur INCORRECT ou Mouvement Interdit\n" << endl;

		}
		return false;
	}else {
		return true;
	}
}

template<class T> bool FramPlateauLand<T>::doDirectionalSWIPE(char direction,bool justTest){

	bool onMoveDone=false;
	int LimiteJ;
	int LimiteI;

	//DROITE
	if(direction=='l'){

		for(int i=0; i < PlateauSizeI;i++){

			LimiteJ=PlateauSizeJ-1;

			for(int j=LimiteJ-1;j>-1;j--){
				bool canMove=true;
				int tmpJ=j;
				//cout<<"AVANT BOUCLE\nvaleur i:"<<i<<" |j: "<<tmpJ<<endl;

				do{
					//cout<<"DANS BOUCLE"<<endl;
					//cout<<"valeur i:"<<i<<" |j: "<<tmpJ<<endl<<"--------"<<endl;

					if(tmpJ>=LimiteJ){//limite a droite
						canMove=false;
					}else{

						//direction va nous dire dans quel sens on peut demande une fusion au type des cases
						char direction=' ';
						if(isCaseEmpty(plateau[i][tmpJ])){//case vide , ne ce deplace pas
							canMove=false;
						}

						else if((direction=isFusionnable(plateau[i][tmpJ],plateau[i][tmpJ+1]))!=' '){
							if(!justTest){
								if(!isCaseEmpty(plateau[i][tmpJ+1])){//&&recursive
									/*
									 * Dans le cadre de la fusion Si la deuxieme case n'est pas vide
									 * alors c'est la nouvelle borne dans le cas NON recursif
									 */
									//LimiteJ--;
									LimiteJ=tmpJ;
								}
								//applique la fusion dans la direction des types des cases
								DoublePointer<T>*result = applyFusion(plateau[i][tmpJ],plateau[i][tmpJ+1],direction);

								if(result!=nullptr){

									if(result->a!=nullptr){
										T * tmp=plateau[i][tmpJ];
										//cout<<"Pointeur vector A AVANT : "<<plateau[i][tmpJ]<<endl;
										plateau[i][tmpJ]=result->a;
										//cout<<"Pointeur vector A APRES : "<<plateau[i][tmpJ]<<endl;
										delete tmp;
									}

									if(result->b!=nullptr){
										T* tmp2 = plateau[i][tmpJ+1];
										//cout<<"Pointeur vector B AVANT : "<<plateau[i][tmpJ+1]<<endl;
										plateau[i][tmpJ+1] = result->b;
										//cout<<"Pointeur vector B APRES : "<<plateau[i][tmpJ+1]<<endl;
										delete tmp2;
									}
									delete result;
								}

							}else{
								//un mouvement est possible | mode juste test
								return true;
							}
							tmpJ++;
							onMoveDone=true;
						}
						else{
							canMove=false;
						}
					}
				}while(canMove);
			}
		}
	}
	//GAUCHE
	else if(direction=='j'){
		for(int i=0; i < PlateauSizeI;i++){

			LimiteJ=0;
			for(int j=LimiteJ+1;j<PlateauSizeJ;j++){
				bool canMove=true;
				int tmpJ=j;

				do{

					if(tmpJ<=LimiteJ){//limite a GAUCHE
						canMove=false;
					}else{
						char direction=' ';
						if(isCaseEmpty(plateau[i][tmpJ])){//case vide , ne ce deplace pas
							canMove=false;
						}
						else if((direction=isFusionnable(plateau[i][tmpJ],plateau[i][tmpJ-1]))!=' '){
							if(!justTest){
								if (!isCaseEmpty(plateau[i][tmpJ-1])) {//&&recursive
									//LimiteJ++;
									LimiteJ=tmpJ;
								}
								DoublePointer<T>*result=applyFusion(plateau[i][tmpJ],plateau[i][tmpJ-1],direction);
								if(result!=nullptr){
									T* tmp=plateau[i][tmpJ];
									plateau[i][tmpJ]=result->a;
									delete tmp;
									T* tmp2 = plateau[i][tmpJ-1];
									plateau[i][tmpJ-1] = result->b;
									delete tmp2;
									delete result;
								}
							}
							else {
								return true;
							}
							tmpJ--;
							onMoveDone=true;

						}
						else{
							canMove=false;
						}
					}
				}while(canMove);
			}
		}
	//HAUT
	}else if(direction=='i'){
		for(int j=0; j < PlateauSizeJ;j++){
			LimiteI=0;
			for(int i=LimiteI+1;i<PlateauSizeI;i++){
				bool canMove=true;
				int tmpI=i;
				do{

					if(tmpI<=LimiteI){//limite en haut
						canMove=false;
					}else{
						char direction=' ';
						if(isCaseEmpty(plateau[tmpI][j])){//case vide , ne ce deplace pas
							canMove=false;
						}
						else if((direction=isFusionnable(plateau[tmpI][j],plateau[tmpI-1][j]))!=' '){
							if (!justTest) {
								if (!isCaseEmpty(plateau[tmpI-1][j])) {//&&recursive
									//LimiteI++;
									LimiteI=tmpI;
								}
								DoublePointer<T>*result=applyFusion(plateau[tmpI][j],plateau[tmpI-1][j],direction);
								if(result!=nullptr){
									T* tmp=plateau[tmpI][j];
									plateau[tmpI][j]=result->a;
									delete tmp;
									T* tmp2 = plateau[tmpI-1][j];
									plateau[tmpI-1][j] = result->b;
									delete tmp2;
									delete result;

								}
							} else {
								return true;
							}
							tmpI--;
							onMoveDone=true;
						}
						else{
							canMove=false;
						}
					}
				}while(canMove);
			}
		}

	//BAS
	}else if(direction=='k'){
		for(int j=0; j < PlateauSizeJ;j++){
			LimiteI=PlateauSizeI-1;
			for(int i=LimiteI-1;i>-1;i--){
				bool canMove=true;
				int tmpI=i;

				do{

					if(tmpI>=LimiteI){//limite en bas
						canMove=false;
					}else{
						char direction=' ';
						if(isCaseEmpty(plateau[tmpI][j])){//case vide , ne ce deplace pas
							canMove=false;
						}
						else if((direction=isFusionnable(plateau[tmpI][j],plateau[tmpI+1][j]))!=' '){

							if (!justTest) {
								if (!isCaseEmpty(plateau[tmpI+1][j])) {//&&recursive
									//LimiteI--;
									LimiteI=tmpI;

								}

								DoublePointer<T>*result=applyFusion(plateau[tmpI][j],plateau[tmpI+1][j],direction);
								if(result!=nullptr){

									T* tmp=plateau[tmpI][j];
									plateau[tmpI][j]=result->a;
									delete tmp;
									T* tmp2 = plateau[tmpI+1][j];
									plateau[tmpI+1][j] = result->b;
									delete tmp2;
									delete result;

								}
							} else {
								return true;
							}
							tmpI++;
							onMoveDone=true;
						}
						else{
							canMove=false;
						}
					}
				}while(canMove);
			}
		}
	}else{
		//TODO exception
	}

	//cout<<"Un mouvomeent a ete realiser ?:"<<onMoveDone<<endl;
	return onMoveDone;
}

template<class T> char FramPlateauLand<T>::getRandomDirection() {

	int sizeMax = 4;

	random_device seeder;
	mt19937 engine(seeder());
	uniform_int_distribution<int> dist(0, sizeMax - 1);
	int randomPosition = dist(engine);
	if(randomPosition==0){
		return 'i';
	}else if(randomPosition==1){
		return 'j';
	}else if(randomPosition==2){
		return 'l';
	}else{
		return 'k';
	}
}

/**
 * Ajouter dans un emplacement vide , une nouvelle case de type hérité de celui d'instance du Framework
 */
template<class T> void FramPlateauLand<T>::setRandomEmptyCase(T* newCase) {
	iterDoubleVector<T> monIter(this->plateau);
	vector<TwoValue> vecFreeCase;
	for(int i =0;i<PlateauSizeI;i++){
		for(int j =0;j<PlateauSizeJ;j++){
			if(this->plateau[i][j]->empty){
				vecFreeCase.push_back(TwoValue(i,j));
			}
		}
	}
	int sizeMax = vecFreeCase.size();
	if (sizeMax == 0) {
		return;
	}
	//select by random the case with a new value
	random_device seeder;
	mt19937 engine(seeder());
	uniform_int_distribution<int> dist(0, sizeMax - 1);
	int randomPosition = dist(engine);
	int x=vecFreeCase[randomPosition].x;
	int y=vecFreeCase[randomPosition].y;
	T * oldCase=this->plateau[x][y];
	this->plateau[x][y]=newCase;
	delete oldCase;
}


template<class T> T* FramPlateauLand<T>:: getRandomEmptyCase() {
	iterDoubleVector<T> monIter(this->plateau);

	//list all the empty cases
	vector<T*> vecFreeCase;
	T * tmp;
	while (monIter.hasnext()) {
		tmp = monIter.next();
		if (tmp->empty) {
			vecFreeCase.push_back(tmp);
		}
	}
	int sizeMax = vecFreeCase.size();

	if (sizeMax == 0) {
		return nullptr;
	}
	//select by random the case with a new value
	random_device seeder;
	mt19937 engine(seeder());
	uniform_int_distribution<int> dist(0, sizeMax - 1);
	int randomPosition = dist(engine);

	return vecFreeCase[randomPosition];
}

template<class T> void FramPlateauLand<T>::getInputFromConsole(int * input,
		int size, int groupe, string const& message1, string const& message2) {
	for (int i = 0; i < size; i++) {
		if (i % groupe == 0) {

			if (!message1.empty()) {
				cout << message1;
			} else {
				cout << "Entre une valeur :";
			}

		} else {
			if (!message1.empty()) {
				cout << message2;
			} else {
				cout << "Entree une valeur associe : ";
			}

		}
		cin >> input[i];
	}
}

template<class T> char* FramPlateauLand<T>:: getCommandeFromConsole(int nbCommandes){

		char * commandes=new char[nbCommandes+1];
		for(int i=0; i<nbCommandes;i++){
			cin>>commandes[i];
		}
		commandes[nbCommandes]='\0';
		cout<<"COMMANDE : ";
		for(int i=0; i<nbCommandes;i++){
			cout<<commandes[i];
		}
		cout<<endl;
		return commandes;
    }


template<class T> FramPlateauLand<T>::FramPlateauLand(int sizeI, int sizeJ,bool _isJeuxPersonnage) :
		PositionXPersonnage(-1), PositionYPersonnage(-1) {

	static_assert(std::is_base_of< CaseGeneric, T>::value,
			"wrong type , you need to use a GenericCase or extends it");

	for (int i = 0; i < sizeI; i++) {
		vector<T*> tab;
		this->plateau.push_back(tab);

		for (int j = 0; j < sizeJ; j++) {
			plateau[i].push_back(new T(i, j));
		}
	}
	modeTerminal = false;
	recursive=false;
	modeGame = true;
	isJeuxPersonnage = _isJeuxPersonnage;
	PlateauSizeI = sizeI;
	PlateauSizeJ = sizeJ;
}

template<class T> void FramPlateauLand<T>::affiche()
    {
        cout<<this->style;

        typename vector< vector<T*> >::iterator row;
        typename vector<T*>::iterator col;

        for (row = this->plateau.begin(); row != this->plateau.end(); row++)
        {

            for (col = row->begin(); col != row->end(); col++)
            {
                cout<<*(*col);
            }
            cout<<endl;
        }
        cout<<this->style<<endl<<endl;
    }

template<class T>  FramPlateauLand<T>:: ~FramPlateauLand()
    {
        //static_assert(std::is_base_of<CaseGeneric, T>::value, "wrong type");

        typename vector< vector<T*> >::iterator row;
        typename vector<T*>::iterator col;

        for (row = this->plateau.begin(); row != this->plateau.end(); row++)
        {

            for (col = row->begin(); col != row->end(); col++)
            {
                delete *col;
            }

        }
    }
