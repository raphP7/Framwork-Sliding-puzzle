/*
 * FramPlateauLand.tpp
 *
 *  Created on: 1 déc. 2016
 *      Author: raphael
 */

template<class T> void FramPlateauLand<T>::startGame() {
	this->affiche();
	do {
		this->performAction();
		this->affiche();
	} while (!this->gameEnd());
	cout << "JEUX FINI" << endl;
}

template<class T> void FramPlateauLand<T>::doSwap(int i2,int j2){

    T* tmp=plateau[PositionXPersonnage][PositionYPersonnage];
    plateau[PositionXPersonnage][PositionYPersonnage]=plateau[i2][j2];
    plateau[i2][j2]=tmp;

}

template<class T> void FramPlateauLand<T>::getPositionFromDirectionPersonnage(
		int * xArriv, int * yArriv, char direction) {

	if (direction == 'i') {

		*xArriv = (this->PositionXPersonnage) - 1;
		*yArriv = this->PositionYPersonnage;

	} else if (direction == 'j') {
		*xArriv = this->PositionXPersonnage;
		*yArriv = (this->PositionYPersonnage) - 1;

	} else if (direction == 'k') {
		*xArriv = (this->PositionXPersonnage) + 1;
		*yArriv = this->PositionYPersonnage;

	} else if (direction == 'l') {
		*xArriv = this->PositionXPersonnage;
		*yArriv = (this->PositionYPersonnage) + 1;

	} else {
		cout << "Bad input" << endl;
	}

}

template<class T> bool FramPlateauLand<T>::doDirectionalSWIPE(char direction,bool recursive,bool justTest){

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
						if(isCaseEmpty(plateau[i][tmpJ])){//case vide , ne ce deplace pas
							canMove=false;
						}
						else if(isFusionnable(plateau[i][tmpJ],plateau[i][tmpJ+1])){
							if(!justTest){
								if(!isCaseEmpty(plateau[i][tmpJ+1])){//&&recursive
									/*
									 * Dans le cadre de la fusion Si la deuxieme case n'est pas vide
									 * alors c'est la nouvelle borne dans le cas NON recursif
									 */
									LimiteJ--;
								}
								applyFusion(plateau[i][tmpJ],plateau[i][tmpJ+1]);

							}else{
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
						if(isCaseEmpty(plateau[i][tmpJ])){//case vide , ne ce deplace pas
							canMove=false;
						}
						else if(isFusionnable(plateau[i][tmpJ],plateau[i][tmpJ-1])){
							if(!justTest){
								if (!isCaseEmpty(plateau[i][tmpJ-1])) {//&&recursive
									LimiteJ++;
								}
								applyFusion(plateau[i][tmpJ],plateau[i][tmpJ-1]);
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
						if(isCaseEmpty(plateau[tmpI][j])){//case vide , ne ce deplace pas
							canMove=false;
						}
						else if(isFusionnable(plateau[tmpI][j],plateau[tmpI-1][j])){
							if (!justTest) {
								if (!isCaseEmpty(plateau[tmpI-1][j])) {//&&recursive
									LimiteI++;
								}
								applyFusion(plateau[tmpI][j],plateau[tmpI-1][j]);
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
						if(isCaseEmpty(plateau[tmpI][j])){//case vide , ne ce deplace pas
							canMove=false;
						}
						else if(isFusionnable(plateau[tmpI][j],plateau[tmpI+1][j])){

							if (!justTest) {
								if (!isCaseEmpty(plateau[tmpI+1][j])) {//&&recursive
									LimiteI--;
								}

								applyFusion(plateau[tmpI][j],plateau[tmpI+1][j]);
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
        if(modeJoeur){
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
        return nullptr;
    }


template<class T> FramPlateauLand<T>::FramPlateauLand(int sizeI, int sizeJ):PositionXPersonnage(-1),PositionYPersonnage(-1)
    {

        static_assert(std::is_base_of< CaseGeneric, T>::value, "wrong type");

        for (int i = 0; i < sizeI; i++)
        {
            vector<T*> tab;
            this->plateau.push_back(tab);

            for (int j = 0; j < sizeJ; j++)
            {
                plateau[i].push_back(new T( i, j));
            }
        }
        speedGame=1;
        modeJoeur=true;
        PlateauSizeI=sizeI;
        PlateauSizeJ=sizeJ;

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
