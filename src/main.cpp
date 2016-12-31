#include"FramPlateauLand.hpp"
#include"2048/Case2048.hpp"
#include"2048/Plateau2048.hpp"
#include"2048/Case2048Destroy/Case2048Destroy.hpp"
#include"Takin/PlateauTakin.hpp"
#include"Sokoban/PlateauSokoban.hpp"
#include"Sokoban/CaseSokoban.hpp"
#include "Display/display.hpp"
#include <memory>

void playSokoban(const char * nameFile){

	PlateauSokoban * pSokoban;
	if(nameFile!=nullptr){
		pSokoban=PlateauSokoban::readFile(nameFile);
	}
	if(pSokoban!=nullptr){
		pSokoban->setGameMode(true);
		display<CaseSokoban> affichage(*pSokoban,45);
		affichage.gridBGColour=new sf::Color (250, 248, 239, 255);
		affichage.StartModeWindow();
	}

}

void playSokoban(){

	PlateauSokoban pSokoban(5,6);
    vector<char> v { '#','#','#','#','#','#',
    				'#',' ',' ',' ','#','#',
					'#','.','$',' ','#','#',
					'#',' ',' ','@','#','#',
					'#','#','#','#','#','#',
    				};
    pSokoban.initPlateau(v);
    pSokoban.setGameMode(true);
    display<CaseSokoban> affichage(pSokoban,60);
    //pSokoban.StartModeTerminal();
    cout<<"avant mode windows"<<endl;
    affichage.StartModeWindow();
}

void playTakinInt(){

	PlateauTakin<int> pTakinInt(5,2);
    vector<int> v { 2,7,0,10,5,1,4,8,4,9 };
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(1,0);
    pTakinInt.setModeBlankCaseAtTheEnd();
    pTakinInt.setGameMode(true);
    //pTakinInt.StartModeTerminal();
    display<CaseTakin<int>> affichage(pTakinInt,80);
    affichage.StartModeWindow();

}

void playTakinChar(){
	PlateauTakin<char> pTakinInt(3,6);
    vector<char> v { 'a','b',' ','d','k','t','p','m','l',
    	'x','s','a','b','p' ,'w','y','q','h'};
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(0,2);
    pTakinInt.setModeBlankCaseAtTheEnd();
    pTakinInt.setGameMode(true);
    pTakinInt.StartModeTerminal();
}

void play2048(){

	Plateau2048 pl2048(5,5);
	pl2048.initPlateau();
	pl2048.setGameMode(true);
	pl2048.setModeRecursive(false);



	cout<<"Pointeur in vector : AVANT APPEL "<<pl2048.plateau[0][0]<<endl;

	Case2048 *a = new Case2048Destroy(0,0);
	CaseGeneric * tmp=pl2048.plateau[4][0];

	pl2048.setRandomEmptyCase(a);

	cout<<"Pointeur in vector : APRES APPEL "<<pl2048.plateau[0][0]<<endl;

	//pl2048.plateau[4][0]=a;
	//delete tmp;

	/*

	//pl2048.plateau[1][0]->valeur=12;
	pl2048.plateau[0][1]->empty=false;
	pl2048.plateau[0][1]->valeur=2;

	//pl2048.StartModeTerminal();
	 */
	display<Case2048> * affichage=new display<Case2048>(pl2048,70);
	affichage->StartModeWindow();
	delete affichage;
}

/*
const Case2048 Case2048::operator+(const Case2048 &other) const {
	Case2048 result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
    result.valeur+=other.valeur;
    return result;              // All done!
  }
*/
int main(int argc, char* argv[]) {
   if(argc>1){
	   //playSokoban(argv[1]);
   }


/*
    std::cout<<"bonjour2"<<std::endl;

    class mama:public CaseGeneric{
    public:
    mama(int t,int v):CaseGeneric(t,v){

        }
    };

    class Casemystere:public Case2048Destroy{
    	public:
    	Casemystere(int t , int v):Case2048Destroy(t,v){

    	}
		virtual bool isFusionnableWith(CaseGeneric & case2) {
			return false;
		}

    };
*/

    //playTakinChar();
    //playSokoban();
    //playTakinInt();
    play2048();

/*
    Case2048 * a =new Case2048(3,4);
    a->valeur=10;
    Case2048 * aa =new Case2048(3,4);
    aa->valeur=20;
    CaseGeneric * b =new Case2048Destroy(3,6);
    CaseGeneric * bb =new Case2048Destroy(3,6);


    std::cout<<"passage au V"<<endl;

    //Case2048  c = (*a)+(*aa);

    std::vector<std::shared_ptr<CaseGeneric> > v;


    v.push_back(std::shared_ptr<CaseGeneric>(new Case2048(3,4,true)));

    v.push_back(std::shared_ptr<CaseGeneric>(new Case2048Destroy(3,4)));

    for (auto it : v) {


    }

*/


    //(*a)>(*b);
/*
    a->FusionWith(*b,true);
    bb->FusionWith(*a,true);
    bb->FusionWith(*b,true);
*/


    //play2048();
    //a->fusion(a);


    //Case2048 * a =new CaseGe(3,4,true);



    //FramPlateauLand<int>* fr; //INTERDIT

    //FramPlateauLand<mama>* fr;
    //fr = new FramPlateauLand<mama>(8, 8);

    /*
	FramPlateauLand<Case2048>* fram;

    fram = new FramPlateauLand<Case2048>(8, 8);//interdit
	fram->affiche();

	Case2048Destroy *a = new Case2048Destroy(0,0);
	a->valeur=9;

	fram->plateau[0][0]=a;

	fram->plateau[1][0]->valeur=12;

	fram->affiche();

	fram->doDirectionalSWIPE('i',false);
	delete fram;
	*/

}
