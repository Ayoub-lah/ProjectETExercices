#include <iostream>
using namespace std;

class Animal{
    protected:
        string nom;
        int age;
    public:
        void set_value(string n , int a);
        void display_value();
};

void Animal::set_value(string n , int a ){
    nom=n;
    age=a;
}

void  Animal::display_value(){
    cout<<"Nom : "<<nom<<endl;
    cout<<"age : "<<age<<endl;
}


class Zebra: public Animal{
    protected:
        string lieu;
    public:
        void  set_value(string n , int a , string l);
        void display_value();
};

void  Zebra::set_value(string n , int a , string l ){
    Animal::set_value(n,a);
    lieu=l;
}

void  Zebra::display_value(){
    Animal::display_value();
    cout<<"lieu de cette zebra est : "<<lieu<<endl;
}

class Dolphin:Animal{
    protected:
        string lieu;
    public:
        void set_value(string n , int  a , string l);
        void  display_value();
};

void Dolphin::set_value(string n , int a , string l ){
    Animal::set_value(n,a);
    lieu=l;
}

void   Dolphin::display_value(){
    Animal::display_value();
    cout<<"lieu de ce dauphin est : "<<lieu<<endl;
}

int main(){
    Zebra zebra;
    zebra.set_value("Marty", 5, "Africa");
    zebra.display_value();

    cout << "......................................"<<endl;

    Dolphin dolphin;
    dolphin.set_value("Flipper", 8,"Amirica");
    dolphin.display_value();

    return 0;
}
