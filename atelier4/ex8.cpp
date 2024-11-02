#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Fichier{
    private:
        string adriss;
        double longueur;
    public:
        Fichier();
        void Creation();
        void Remplit();
        void  Afficher();
        ~Fichier();
};

void Fichier::Creation(){
    ofstream my_file("C:/fiche/file_app");
}

void  Fichier::Remplit(){
    ofstream my_file("C:/fiche/file_app");
    if(my_file.is_open())
        my_file<<"Hello World."<<endl;
    else
        cerr<<"Erreur "<<endl;
    my_file.close();
}

void Fichier::Afficher(){
    ifstream my_file("C:/fiche/file_app");
    string line;
    if(my_file.is_open())
        while (getline(my_file,line)){
            cout<<"line"<<endl;
        }
    my_file.close();
}

int main(){
    Fichier f1;
    Fichier*f = new  Fichier();
    f1.Creation();
    f1.Remplit();
    f1.Afficher();
    delete [] f ;
}
