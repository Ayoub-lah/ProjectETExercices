#include <iostream>
#include <string>
#include "Auteur.h"
using namespace std;

class Oeuvre{
    private:
        string titre;
        string langue;
        Auteur auteur;
    public:
        Oeuvre(string tit , string lan , Auteur a);
        string  getTitre();
        Auteur getAuteur();
        string   getLangue();
        void Affiche();
        ~Oeuvre();
};

Oeuvre::Oeuvre(string tit , string lan , Auteur a ): titre(tit), langue(lan) ,  auteur(a){}


string Oeuvre::getTitre(){
    return titre;
}

Auteur Oeuvre::getAuteur(){
    return auteur;
}

string Oeuvre::getLangue(){
    return langue;
}

void Oeuvre::Affiche(){
    cout<< titre <<" , ";
    auteur.getnom();
    cout<< langue <<endl;
}

Oeuvre::~Oeuvre(){
    cout<<"L'oeuvre \" "<<titre<<","<< auteur.getnom() <<","<<langue<<"\"  n'est plusdisponible."<<endl;
}
