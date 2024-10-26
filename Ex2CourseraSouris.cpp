#include <iostream>
using namespace  std;

/*******************************************
* Complétez le programme à partir d’ici.
*******************************************/
class Souris{

    private:
        double  poids;
        string color;
        int  age;
        int esperance_vie;
        bool clonee=true ;

    public:
        Souris();
        Souris( Souris &s);
        Souris(string c , bool  cl , int a ,  double p);
        ~Souris();
        void Affiche();
        void vieillir();
        void evolue();

};

Souris::Souris(){
    cout<<"un nouvelle  souris !"<<endl;
}

Souris::Souris(Souris &autre ):poids(autre.poids), color(autre.color), age(autre.age), clonee(true) {
        std::cout << "Clonage d'une souris !" <<endl;
}

Souris::Souris( string c , bool cl , int a ,double p):color(c), clonee(cl),age(a), poids(p){}

Souris::~Souris(){
    cout<<"Fin d'une souris..."<<endl;
}

void  Souris::Affiche(){
    if(clonee==false)
        cout<<"Une souris "<<color<<" de "<<age<<" mois et pesant "<<poids<<" grammes "<<endl;
    else
        cout<<"Une souris "<<color<<", clonee ,  de "<<age<<" mois et pesant "<<poids<<" grammes "<<endl;
}

void  Souris::vieillir(){
    ++age;
    if (clonee && age > esperance_vie / 2) {
        color = "verte";
    }
}

void Souris::evolue(){
    while (age < esperance_vie) {
        vieillir();
    }
}


int main(){

    Souris s1;
    Souris  s2;
    Souris s4("Blanch",false,2,50);
    s4.Affiche();
    Souris s5("grise",false,0,45);
    s5.Affiche();
    Souris s6=s5;
    s6.Affiche();
    Souris s7("Blanch",false,36,50);
    s7.Affiche();
    Souris s8("grise",false,36,45);
    s8.Affiche();
    
}

/*******************************************
* Ne rien modifier après cette ligne.
*******************************************/