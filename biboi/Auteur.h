#include <iostream>
#include <string>
using namespace std;

class Auteur{
    private:
        string nom;
        bool prime;
public:
    Auteur(string n , bool p);
    string getnom();
    bool  getprime();

};

Auteur::Auteur(string n , bool p ):nom(n),prime(p){}

string Auteur::getnom(){
    return nom;
}

bool Auteur::getprime(){
    return prime;
}
