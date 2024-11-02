#include <iostream>
using namespace std;

void CalculeNbAffichage (){
    static int cnt=0;
    cnt++;
    cout<<"apple numero "<<cnt<<endl;
}

int main(){
    CalculeNbAffichage();
    CalculeNbAffichage();
    CalculeNbAffichage();
    CalculeNbAffichage();
}