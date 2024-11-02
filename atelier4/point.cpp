#include "point.h"
#include <iostream>
using namespace std;

point::point(float x, float y) : x(x), y(y) {}

void  point::deplace(float dx, float dy){
    x += dx; 
    y += dy;
}

void  point::Affiche(){
    cout << "(" << x << "," << y << ")" << endl;
}
