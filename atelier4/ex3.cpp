#include <iostream>
#include <string>
using namespace std ; 

class Personne{
    protected:
        string nom;
        string prenom;
        string date_naissance;
    public:
        Personne Initialiser_Donnee(string n , string p , string d);
        virtual void Affiche();
};

Personne Personne::Initialiser_Donnee(string n , string p , string d){
    nom = n ;
    prenom = p ;
    date_naissance = d ;
}

void Personne::Affiche(){
    cout << "Nom : " << nom << endl ;
    cout << "Prenom : " << prenom << endl ;
    cout << "Date de naissance : " << date_naissance << endl ;
}

class Employe:public Personne{
    protected:
        float salaire;
    public:
        Employe Initialiser_Donnee(string n , string p , string d , float s );
        void Affiche() override ;
};

Employe Employe::Initialiser_Donnee(string n , string p , string d , float s){
    nom=n;
    prenom=p;
    date_naissance=d;
    salaire=s;
}

void Employe::Affiche(){
    Personne::Affiche() ;
    cout << "Salaire : " << salaire << endl ;
}

class Chef:public Employe{
    protected:
        string serveur;
    public:
        Chef Initialiser_Donnee(string n , string p , string d , float s , string ser);
        virtual  void Affiche() override ;
};

void  Chef::Affiche(){
    Employe::Affiche() ;
    cout<<"Serveur : "<<serveur<<endl;
}

class Directeur:public Chef{
    protected:
        string Societe ;
    public:
        Directeur Initialiser_Donnee(string n , string p , string d , float s , string ser, string so);
        virtual void Affiche() override;
};

Directeur Directeur::Initialiser_Donnee(string n , string p , string d , float s , string ser, string so){
    nom=n;
    prenom=p;
    date_naissance=d;
    salaire=s;
    serveur=ser;
}

void  Directeur::Affiche(){
    Chef::Affiche();
    cout<<"Societe : "<<Societe<<endl;
}
