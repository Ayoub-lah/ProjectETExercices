#include <iostream>
#include <stdexcept>
using namespace std ; 

class complexes{
    private:
        double x ;
        double y ;

    public:
        complexes (double reelle=0  , double imaginaire=0):x(reelle), y(imaginaire){}
        complexes operator/(  complexes& autre);
        complexes operator+( complexes& autre);
        bool operator==(  complexes& autre);
        complexes operator*(  complexes& autre);
        complexes operator-(  complexes& autre);
        double getx()  ;
        double gety()  ;
        void Affiche();
};

double complexes::getx() {
    return x ;
}

double complexes::gety()  {
    return y ;
}

bool complexes::operator==( complexes &autre){
    return (x == autre.x &&  y == autre.y);
} 

complexes complexes::operator+(  complexes& autre){
   return complexes  (x + autre.x ,  y + autre.y);
} 

complexes  complexes::operator-( complexes &autre){
    return complexes (x - autre.x , y - autre.y); 
} 

complexes complexes::operator*(  complexes& autre) {
    double real = x * autre.x - y * autre.y;
    double img = x * autre.y + y * autre.x;
    return complexes(real, img);
}

complexes complexes::operator/(  complexes& autre) {
    double denominator = autre.x * autre.x + autre.y * autre.y;
    if(autre.x==0 ||  autre.y==0)
        throw runtime_error("ooooo divise par 0 !!!!!");
    double reel = (x * autre.x + y * autre.y) / denominator;
    double img = (y * autre.x - x * autre.y) / denominator;
    return complexes(reel, img);
}

void complexes::Affiche(){
    cout << "(" << x << " , " << y << ") donc la partie reelle est :  " << x << " et la partie imaginaire est : " << y << endl ;
}

int main(){

    double reelle1, imaginaire1, reelle2, imaginaire2;
    int choix;

    cout << "Entrez la partie reelle du 1er nombre complexe : ";
    cin >> reelle1;
    cout << "Entrez la partie imaginaire du 1er nombre complexe : ";
    cin >> imaginaire1;
    cout << "Entrez la partie reelle du 2eme nombre complexe : ";
    cin >> reelle2;
    cout << "Entrez la partie imaginaire du 2eme nombre complexe : ";
    cin >> imaginaire2;

    complexes z1(reelle1, imaginaire1);
    complexes z2(reelle2, imaginaire2);

    cout<<"1:egalite"<<endl;
    cout<<"2:addition"<<endl;
    cout<<"3:soustraction"<<endl;
    cout<<"4:multiplication"<<endl;
    cout<<"5:division"<<endl;
    cout<<"Entrez votre choix : ";
    cin>>choix;

    switch (choix){
        case 1 :{
            if (z1 == z2)
                cout << "Les deux nombres complexes sont egaux." << endl;
            else
                cout << "Les deux nombres complexes ne sont pas egaux." << endl;
            break;
        }
        case 2:{
            complexes z3 = z1 + z2; 
            z3.Affiche();
            break;
        }
        case 3:{
            complexes z3 = z1 - z2; 
            z3.Affiche();    
            break;
        }
        case 4:{
            complexes z3 = z1 * z2; 
            z3.Affiche();
            break;
        }
        case 5:{
            try{
                complexes z3 = z1 / z2; 
                z3.Affiche();  
            }
            catch(exception& e){
                cout << e.what() <<endl;
            }     
                break;
        }
        default:
            cout << "Veuillez choisir une option valide" <<endl;
    }

return 0 ;

}