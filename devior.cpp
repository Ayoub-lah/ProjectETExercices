#include <iostream>
using namespace std;

template<class T1 , class T2> class NombreComplexe{
    T1 reel;
    T2 imaginair;

    public:
        NombreComplexe();
        NombreComplexe(T1 r, T2 i);
        NombreComplexe(const NombreComplexe& autre);
        void Afficher(){
            if(imaginair>0)
                cout<<"Le nombre complexe est : "<<reel<<"+"<<imaginair<<"i"<<endl;
        }
        NombreComplexe operator+(const NombreComplexe& autre){
            NombreComplexe res;
            res.reel = reel + autre.reel;
            res.imaginair = imaginair + autre.imaginair;
        }
        NombreComplexe operator-(const NombreComplexe& autre){
            NombreComplexe res;
            res.reel = reel - autre.reel;
            res.imaginair = imaginair - autre.imaginair;
        }
        NombreComplexe operator*(const NombreComplexe& autre){
            NombreComplexe res;
            res.reel = reel * autre.reel;
            res.imaginair = imaginair * autre.imaginair;
        };
        NombreComplexe operator/(const NombreComplexe& autre){
            NombreComplexe res;
            res.reel = reel / autre.reel;
            if(autre.imaginair==0){
                throw"oooooooooo divise par 0!!!!!!!!!"
            }
            try{
                
            }
            catch(const exception& e){
                std::cerr << e.what() <<endl;
            }
        }
        NombreComplexe operator==(const NombreComplexe& autre){
            if(reel==autre.reel && imaginair==autre.imaginair)
                cout<<"Les deux nombre complexe est egaux"<<endl;
        }
        NombreComplexe operator!=(const NombreComplexe& autre){
            if(reel!=autre.reel && imaginair!=autre.imaginair)
                cout<<"Les deux nombre complexe est diffirent "<<endl;
        }
        NombreComplexe operator<(const NombreComplexe& autre){
            if(reel<autre.reel && imaginair<autre.imaginair)
                cout<<"le plus grand complexe est la 2eme "<<endl;
        }
        NombreComplexe operator>(const NombreComplexe& autre){
            if(reel>autre.reel && imaginair>autre.imaginair)
                cout<<"le plus grand complexe est la 1er"<<endl;
        }
        NombreComplexe operator<=(const NombreComplexe& autre){
            if(reel<=autre.reel && imaginair<=autre.imaginair)
                cout<<"la 2eme nombre complexe est sepuriere au egale a la 1er"<<endl;
        }
        NombreComplexe operator>=(const NombreComplexe& autre){
            if(reel>=autre.reel && imaginair>=autre.imaginair)
                cout<<"la 1er nombre complexe est sepuriere au egale a la 2eme"<<endl;
        }
        
};

int main(){
    NombreComplexe<int , int > d(5,8);
    
}