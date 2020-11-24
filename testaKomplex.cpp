#include "vanligt.h"
#include "komplex.h"
using namespace std;
void testaKomplex(){
    Komplex i=komplexFromReIm(0,1);
    Komplex a=komplexFromAbsArg(1,45);
    cout << "a= " << stringFromKomplex(a) << endl;
    cout << " argGrader(a) = " << argGrader(a) << endl;
    cout << "abs(a) = " << abs(a) << endl;

    Komplex ai = produkt(a,i);
    cout << "a * i = " << stringFromKomplex(ai) << endl;
    cout << "argGrader(a * i) = " << argGrader(ai) << endl;
    Komplex x=kvot(komplexFromReIm(2,3),komplexFromReIm(1,2));
    cout << stringFromKomplex(x);
}
void shortcutToTestaKomplex(){
    testaKomplex();
}
