#include <iostream>
using namespace std;

class Fleur {

    private:
        string voiture;
        string color;

    public :
        Fleur (string vtr , string clr );
        void Affiche();
        void eclore();
        ~Fleur();

};

Fleur::Fleur(string vtr , string clr):voiture(vtr), color(clr){}

void Fleur::Affiche(){
    cout<<voiture<<" fraichement cueillie "<<endl
    <<"Fragile corolle taillee"<<endl;
}

void Fleur::eclore(){
    cout<<"veine de "<<color<<endl;
}

Fleur::~Fleur(){
    cout<<"qu'un simple souffle..."<<endl
    <<"qu'un simple souffle...";
}



int main (){

Fleur f1("Violette", "bleu");
Fleur f2(f1);
f1.Affiche();
cout << "dans un cristal ";
f2.eclore();
cout << "Donne un poeme un peu fleur bleue" << endl
<< "ne laissant plus ";

return 0;
}


