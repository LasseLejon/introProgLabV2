#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <string>
struct Komplex{
    double re;
    double im;
};
Komplex komplexFromReIm(double re, double im);
Komplex komplexFromAbsArg(double absolutbelopp, double vinkelIGrader);

double real(Komplex c);
double img(Komplex c);
double abs(Komplex c);
double argGrader(Komplex c);

Komplex konjugat(Komplex c);
Komplex summa(Komplex a, Komplex b);
Komplex differens(Komplex a, Komplex b);
Komplex produkt(Komplex a, Komplex b);
Komplex kvot(Komplex a, Komplex b);

std::string stringFromKomplex(Komplex c);
#endif // KOMPLEX_H
