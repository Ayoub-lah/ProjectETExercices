#include <iostream>
#include <cmath>
using namespace std;


//le résultat est renvoyé par valeur


/*class vecteur3d{
    protected:
        float x, y, z;
    public:
        vecteur3d(float a ,  float b, float c):x(5),y(6),z(1){}
        void Affiche();
        void somme(vecteur3d v1 , vecteur3d v2);
        void produit(vecteur3d  v1 , vecteur3d v2);
        void coincide(vecteur3d v1 );
        double norm(vecteur3d v1 ,  vecteur3d v2);
        static vecteur3d normax( vecteur3d v1,  vecteur3d v2) {
        return (v1.norm(v1,v2) > v2.norm(v1,v2)) ? v1 : v2;
    }
};

void  vecteur3d::Affiche(){
    cout<<"Vecteur est : ("<<x<<","<<y<<","<<z<<")"<<endl;
}

void vecteur3d::somme(vecteur3d v1 , vecteur3d v2){
    x = v1.x + v2.x;
    y=v1.y +v2.y;
    z=v1.z  + v2.z;
    Affiche();
}

void  vecteur3d::produit(vecteur3d  v1 , vecteur3d v2){
    x = v1.x * v2.x;
    y=v1.y * v2.y;
    z=v1.z  * v2.z;
    Affiche();
}

void   vecteur3d::coincide(vecteur3d v1 ){
    if (x == v1.x && y == v1.y && z == v1.z)
        cout<<"Les deux  vecteurs sont coincides"<<endl;
}

double  vecteur3d::norm(vecteur3d v1 ,  vecteur3d v2){
    return sqrt(pow(x - v1.x, 2) + pow(y - v1.y , 2)+pow(z -  v1.z , 2));

}*/

//le résultat est renvoyé par référence, l’argument étant également transmis par référence.

/*class vecteur3d{
    protected:
        float x, y, z;
    public:
        vecteur3d(float &a ,  float &b, float &c):x(5),y(6),z(1){}
        void Affiche();
        void somme(vecteur3d &v1 , vecteur3d &v2);
        void produit(vecteur3d  &v1 , vecteur3d &v2);
        void coincide(vecteur3d &v1 );
        double norm(vecteur3d &v1 ,  vecteur3d &v2);
        static vecteur3d normax( vecteur3d &v1,  vecteur3d &v2) {
        return (v1.norm(v1,v2) > v2.norm(v1,v2)) ? v1 : v2;
    }
};

void  vecteur3d::Affiche(){
    cout<<"Vecteur est : ("<<x<<","<<y<<","<<z<<")"<<endl;
}

void vecteur3d::somme(vecteur3d &v1 , vecteur3d &v2){
    x = v1.x + v2.x;
    y=v1.y +v2.y;
    z=v1.z  + v2.z;
    Affiche();
}

void  vecteur3d::produit(vecteur3d  &v1 , vecteur3d &v2){
    x = v1.x * v2.x;
    y=v1.y * v2.y;
    z=v1.z  * v2.z;
    Affiche();
}

void   vecteur3d::coincide(vecteur3d &v1 ){
    if (x == v1.x && y == v1.y && z == v1.z)
        cout<<"Les deux  vecteurs sont coincides"<<endl;
}

double  vecteur3d::norm(vecteur3d &v1 ,  vecteur3d &v2){
    return sqrt(pow(x - v1.x, 2) + pow(y - v1.y , 2)+pow(z -  v1.z , 2));
}*/

//le résultat est renvoyé par adresse, l’argument étant également transmis par adresse

class vecteur3d{
    protected:
        float x, y, z;
    public:
        vecteur3d(float *a ,  float *b, float *c);
        void Affiche();
        void somme(vecteur3d *v1 , vecteur3d *v2);
        float produit( vecteur3d* v1)  {
        return (x * v1->x) + (y * v1->y) + (z * v1->z);
        }
        void coincide(vecteur3d *v1 );
        double norm(vecteur3d *v1 ,  vecteur3d *v2);
        static void normax( vecteur3d *v1,  vecteur3d *v2) {
            ( v1->norm(v1,v2) > v2->norm(v1,v2)) ? v1 : v2;
            
    }
};

void  vecteur3d::Affiche(){
    cout<<"Vecteur est : ("<<&x<<","<<&y<<","<<&z<<")"<<endl;
}

void vecteur3d::somme(vecteur3d *v1 , vecteur3d *v2){
    x = v1->x + v2->x;
    y=v1->y +v2->y;
    z=v1->z  + v2->z;
    Affiche();
}

void   vecteur3d::coincide(vecteur3d *v1 ){
    if (x == v1->x && y == v1->y && z == v1->z)
        cout<<"Les deux  vecteurs sont coincides"<<endl;
}

double  vecteur3d::norm(vecteur3d *v1 ,  vecteur3d *v2){
    return sqrt(pow(x - v1->x, 2) + pow(y - v1->y , 2)+pow(z -  v1->z , 2));
}
