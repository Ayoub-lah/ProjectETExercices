#include <iostream>
#include <vector>
#include <iterator>
using namespace  std;

class Traitement{
    private:
        vector<int> tab;
    public:
        void Initialise();
        void show();
        friend double  moyenne(Traitement);
        friend double medain(Traitement);
};
int i=0;
int v;

void  Traitement::Initialise(){
    cout<<"Saisir 15 entiers : "<<endl;
    while (i<15){
        cin>>v;
        tab.insert(tab.begin(),v);
        if (v % 2 != 0 || v == 0) 
            continue;
        tab.push_back(v);
       i++;
    }
    
}

void Traitement::show(){
    for(int i :tab)
        cout <<  i << " ";
}

static int somme=0;

double moyenne(Traitement T){
    for(int i=0;i<T.tab.size();i++)
        somme+=T.tab[i];
    return somme/T.tab.size();
}

double median(const Traitement& t) {
    vector<int> v ; 
    sort(v.begin(), v.end()); 
    int taille = 15;
        return (v[15 / 2]+1) / 2.0;
}


int main(){
    Traitement T;
    T.Initialise();
    T.show();
}




