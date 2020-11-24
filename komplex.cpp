#include "komplex.h"
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;
double radFromDegrees(double angleInDegrees){
    double radians=angleInDegrees/180*M_PI;
    return radians;
}
Komplex komplexFromReIm(double re, double im){
    Komplex talet;
    talet.re=re;
    talet.im=im;
    return talet;
}
Komplex komplexFromAbsArg(double absolutbelopp, double angleInDegrees){
    Komplex talet;
    talet.re=absolutbelopp*cos(radFromDegrees(angleInDegrees));
    talet.im=absolutbelopp*sin(radFromDegrees(angleInDegrees));
    return talet;
}

double real(Komplex c){
    double realDel=c.re;
    return realDel;
}
double img(Komplex c){
    double imgDel=c.im;
    return imgDel;
}
double abs(Komplex c){
    double absolutbelopp=sqrt((c.re*c.re)+(c.im*c.im));
    return absolutbelopp;
}
double argGrader(Komplex c){
    double vinkel=atan((c.im/c.re)*180.0/M_PI);
    return vinkel;
}

Komplex konjugat(Komplex c){
    Komplex konjugatet;
    konjugatet.re=c.re;
    konjugatet.im=-c.im;
    return konjugatet;

}
Komplex summa(Komplex a, Komplex b){
    Komplex summa;
    summa.re=a.re+b.re;
    summa.im=a.im+b.im;
    return summa;
}
Komplex differens(Komplex a, Komplex b){
    Komplex differens;
    differens.re=a.re-b.re;
    differens.im=a.im-b.im;
    return differens;
}
//=(ac−bd)+(ad+bc)i
Komplex produkt(Komplex a, Komplex b){
    Komplex produkt;
    produkt.re=a.re*b.re-a.im*b.im;
    produkt.im=a.re*b.im+a.im*b.re;
    return produkt;
}
//(a.re*b.re+a.im*b.im)
//=(ac+bd)/(c2+d2)+(bc−ad)/(c2+d2)i
Komplex kvot(Komplex a, Komplex b){
    Komplex k=konjugat(b);
    Komplex nyTaljare=produkt(a,k);
    Komplex nyNamnare=produkt(b,k);
    Komplex kvot;
    kvot.re=nyTaljare.re/nyNamnare.re;
    kvot.im=nyTaljare.im/nyNamnare.re;
    return kvot;
}

Komplex operator+(Komplex a, Komplex b){
    return(summa(a,b));
}
Komplex operator+(Komplex a, double b){
    a.re+=b;
    return a;
}
Komplex operator+(double a, Komplex b){
    b.re+=a;
    return b;
}
Komplex operator-(Komplex a, Komplex b){
    return(differens(a,b));
}
Komplex operator-(Komplex a, double b){
    a.re-=b;
    return a;
}
Komplex operator-(double a, Komplex b){
    b.re-=a;
    return b;
}

Komplex operator*(Komplex a, Komplex b){
    return(produkt(a,b));
}
Komplex operator*(Komplex a, double b){
    a.re*=b;
    return a;
}
Komplex operator*(double a, Komplex b){
    b.re*=a;
    return b;
}

Komplex operator/(Komplex a, Komplex b){
    return(kvot(a,b));
}
Komplex operator/(Komplex a, double b){
    a.re/=b;
    return a;
}
Komplex operator/(double a, Komplex b){
    b.re/=a;
    return b;
}

std::string stringFromKomplex(Komplex c){
    std::stringstream os;
    os << "(" << c.re;
    if(c.im>=0)
        os << "+";
    os << c.im << "i" << ")";
    return os.str();
}

ostream& operator<<(ostream&o, Komplex c){
    o << stringFromKomplex(c);
    return o;
}
