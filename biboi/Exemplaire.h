#include <iostream>
#include <string>
#include "Oeuvre.h"
#include "Auteur.h"
using namespace std;

class Exemplaire{
    private:
        Oeuvre oeuvre;
    public:
        Exemplaire(Oeuvre o);
        Exemplaire( Exemplaire &e);
        ~Exemplaire();
        Oeuvre getOeuvre();
        void Affich();
};

Exemplaire::Exemplaire(Oeuvre o):oeuvre(o){
    cout<<"Novelle examplaire de " <<", ";
    o.getTitre();
    cout<<" , ";
    o.getAuteur();
    cout<<" , en ";
    o.getLangue();
    cout<<endl;
}

Exemplaire::Exemplaire(Exemplaire &autre):oeuvre(autre.oeuvre){
    cout<<"Copie d'un exemplaire :"
    << oeuvre.getTitre() << ", "
    << oeuvre.getAuteur() << ", en "
    << oeuvre.getLangue() << endl;
}

Exemplaire::~Exemplaire(){
    cout<<"Un exemplaire \" "
    << oeuvre.getTitre() << ", "
    << oeuvre.getAuteur() << ", en "
    << oeuvre.getLangue() << "a ete jete !" <<endl;
}

Oeuvre Exemplaire::getOeuvre(){
    return oeuvre;
}

void  Exemplaire::Affich(){
    cout<<"Exemaplaire de : "
    << oeuvre.getTitre() << ", "
    << oeuvre.getAuteur() << ", en "
    << oeuvre.getLangue() <<endl;
}
