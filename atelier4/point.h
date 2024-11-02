#ifndef POINT_H
#define POINT_H

class point{
    private:
        float x;
        float y;
    public:
        point(float x, float y) ;
        void deplace(float dx, float dy) ;
        void Affiche();
};

#endif