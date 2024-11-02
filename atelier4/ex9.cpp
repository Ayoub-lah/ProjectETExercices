#include <iostream>
#include <list>
using namespace std ;

class liste{
    private:
        list<int>l;
    public:
        void ajouter();
        void supprimer();
        void afficher();
};

void liste::ajouter(){
    int n;
    cout<<"entrer un nombre : "<<endl;
    cin>>n;
    l.push_back(n);
}

void  liste::supprimer(){
    if(l.empty())
        cout<<"la liste est deja vide"<<endl;
    else
        l.erase(l.begin());
}

void  liste::afficher(){
    if(l.empty())
        cout<<"Liste est vide !!!"<<endl;
    for(list<int>::iterator it = l.begin();  it != l.end(); it++){
        cout<<*it<<endl;
    }
}




