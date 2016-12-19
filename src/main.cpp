#include"FramPlateauLand.hpp"
#include"2048/Case2048.hpp"
#include"2048/Plateau2048.hpp"
#include"2048/Case2048Destroy/Case2048Destroy.hpp"
#include"Takin/PlateauTakin.hpp"
#include"Sokoban/PlateauSokoban.hpp"
#include <memory>

void playSokoban(){

	PlateauSokoban pSokoban(5,5);
    vector<char> v { '#','#','#','#','#',
    				'#',' ',' ',' ','#',
					'#','.','$',' ','#',
					'#',' ',' ','@','#',
					'#','#','#','#','#',
    				};
    pSokoban.initPlateau(v);
    pSokoban.setModeJeux(true);
    pSokoban.startGame();
}

void playTakinInt(){

	PlateauTakin<int> pTakinInt(2,2);
    vector<int> v { 2,7,0,10 };
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(1,0);
    pTakinInt.setBlankCaseAtTheEnd();
    pTakinInt.setModeJeux(true);
    pTakinInt.startGame();
}

void playTakinChar(){

	PlateauTakin<char> pTakinInt(2,2);
    vector<char> v { 'a','b',' ','d' };
    pTakinInt.initPlateau(v);
    pTakinInt.setBlank(1,0);
    pTakinInt.setBlankCaseAtTheEnd();
    pTakinInt.setModeJeux(true);
    pTakinInt.startGame();
}

void play2048(){

	Plateau2048 pl2048(5,5);
	pl2048.initPlateau();
	pl2048.setModeJeux(false);
	/*
	Case2048Destroy *a = new Case2048Destroy(0,0);
		a->valeur=9;

	CaseGeneric * tmp=pl2048.plateau[0][0];
	pl2048.plateau[0][0]=a;
	delete tmp;

	//pl2048.plateau[1][0]->valeur=12;
	pl2048.plateau[0][1]->empty=false;
	pl2048.plateau[0][1]->valeur=2;

	*/
	pl2048.startGame();
}

const Case2048 Case2048::operator+(const Case2048 &other) const {
	Case2048 result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
    result.valeur+=other.valeur;
    return result;              // All done!
  }

int main() {
    std::cout<<"bonjour2"<<std::endl;

    class mama:public CaseGeneric{
    public:
    mama(int t,int v):CaseGeneric(t,v,true){

        }
    };

    class Casemystere:public Case2048Destroy{
    	public:
    	Casemystere(int t , int v):Case2048Destroy(t,v){

    	}
		virtual bool isFusionnableWith(CaseGeneric & case2) {


		}

    };
    //playTakinChar();
    playSokoban();
    //play2048();

/*

    Case2048 * a =new Case2048(3,4);
    a->valeur=10;
    Case2048 * aa =new Case2048(3,4);
    aa->valeur=20;
    CaseGeneric * b =new Case2048Destroy(3,6);
    CaseGeneric * bb =new Case2048Destroy(3,6);

    std::cout<<"passage au V"<<endl;

    Case2048  c = (*a)+(*aa);

    std::vector<std::shared_ptr<CaseGeneric> > v;


    v.push_back(std::shared_ptr<CaseGeneric>(new Case2048(3,4,true)));

    v.push_back(std::shared_ptr<CaseGeneric>(new Case2048Destroy(3,4)));

    for (auto it : v) {


    }




    //(*a)>(*b);

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
