#include <iostream>
#include <string>
#include <vector>
#include "Oeuvre.h"
#include "Auteur.h"
#include "Exemplaire.h"
using namespace std;

class Bibliotheque{
    private:
        string nom;
        vector<Exemplaire*> exemplaires;
    public:
        Bibliotheque(string n);
        string getNom();
        void stocker(Oeuvre oeuvre , int n=1);
        void lister_exemplaires();
        int compter_exemplaires();
        void afficher_auteurs();
        ~Bibliotheque();
};

Bibliotheque::Bibliotheque(string n):nom(n){
    cout<<"La bibloitheque "<<n<<" est ouverte"<<endl;
}

string  Bibliotheque::getNom(){
    return nom;
}

void Bibliotheque::stocker(Oeuvre oeuvre, int n) {
    for (int i = 0; i < n; ++i) {
        Exemplaire* exemplaire = new Exemplaire(oeuvre); 
        exemplaires.push_back(exemplaire);       
    }
}

void  Bibliotheque::lister_exemplaires(){
    for (const auto& exemplaire : exemplaires) {
        if (langue.empty() || exemplaire->getLangue() == langue) {
            exemplaire->afficher();
            cout <<endl;
        }
    }

}

int  Bibliotheque::compter_exemplaires(){
    return exemplaires.size();
}

void  Bibliotheque::afficher_auteurs(){
    for (const auto& exemplaire : exemplaires) {
        if (!uniquement_auteurs_primés || exemplaire->getAuteur().aUnPrix()) {
            std::cout << exemplaire->getAuteur().getNom() << std::endl;
        }
    }
}

Bibliotheque::~Bibliotheque(){
    cout<<"La bibliotheque " <<n<<"ferme ses portes,et détruit ses exemplaires"<<endl;
    ~Bibliotheque()=delete;
}
