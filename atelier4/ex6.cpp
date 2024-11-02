#include "point.h"

int main(){
    point p1(1, 2);
    point p2(3, 4);

    p1.Affiche();
    p1.deplace(0.5,1.2);

    p2.Affiche();
    p2.deplace(0.9,1.7);
}



