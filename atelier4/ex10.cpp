#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> element;

    cout<<"Entrez la date avec le tamps par hour et min : "<<endl;

    int i , v;

    while (i<12){
        cin>>v;
        element.push(v);
        i++;
    }

    cout<<"Le jour est "<<element.front();
    element.pop();
    cout<<element.front()<<endl;
    element.pop();
    cout<<"Et le mois est  "<<element.front();
    element.pop();
    cout<<element.front();
    element.pop();
    cout<<"Et  l'annee est "<<element.front();
    element.pop();
    cout<<element.front();
    element.pop();
    cout<<element.front();
    element.pop();
    cout<<element.front();
    element.pop();
    cout<<"Et  la date est "<<element.front();
    element.pop();
    cout<<endl;
    cout<<element.front();
    element.pop();
    cout<<"H:";
    cout<<element.front();
    element.pop();
    cout<<element.front();
    element.pop();
    cout<<"min ";
}