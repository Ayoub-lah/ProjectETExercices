#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace  std;

class Traitement{
    private:
        vector<int> tab;
    public:
        void Initialise();
        void show(int index);
        friend double  moyenne(Traitement tab);
        friend double medain(const Traitement& tab);
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

void  Traitement::show(int index) {
     index=0;
        if (index < tab.size()) {
            cout << tab[index] << " ";
            show(index + 1);
        } else if (index == 0) {
            cout << "vide."<<endl;
        }
    }

static int somme=0;

double moyenne(Traitement T){
    for(int i=0;i<T.tab.size();i++)
        somme+=T.tab[i];
    return somme/T.tab.size();
}

double median(const Traitement& t) {
    vector<int> v = t.tab; 
    sort(v.begin(), v.end()); 

    int taille = v.size();
    if (taille % 2 == 0) 
        return (v[taille / 2 - 1] + v[taille / 2]) / 2.0;
    else 
        return v[taille / 2];
}




