#include <iostream>
using namespace std ;

class Pile{
    private:
        int * element  ;
        int  taille ;
        int sommet ;
    public:
        Pile Initializer(int t=20);
        void Push(int v);
        int Pop();
};

Pile Pile::Initializer(int t){
    taille=t;
    element = new int[t];
    sommet=-1;
}

void  Pile::Push(int v){
    cout<<"Enterez les elements de  la pile"<<endl;
    if(sommet>=taille-1)
        element[sommet+1]=v;
}

int  Pile::Pop(){
    if(sommet<0){
        cout<<"Pile est vide"<<endl;
    }
    return element[sommet--];
}
