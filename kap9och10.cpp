#include <iostream>
#include <cassert>
#include "myMathFunctions.h"
#include "vanligt.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

void hejTal(int x){
    cout << "Hej heltal " << x << endl;
}
void hejTal(double x){
    cout << "Hej pa dig flyttal " << x << endl;
}
void hejTal(double x, double y){
    cout << "Hej pa er flyttal " << x << ", " << y << endl;
}
void hejTal(int x, int y, int z){
    cout << "Hej alla tre heltal " << x << ", " << y << ", " << z << endl;
}
void testaHejTal(){
    hejTal(2);
    hejTal(2.1);
    hejTal(2, 3);
    //hejTal(2.2, 3.1, 4.3);
    hejTal(2.0, 3.0, 4.0);
    double two=2;
    hejTal(two, 3.0, 4.0);

}
void skrivResultat(int x){
    cout << "resultatet blev " << x << endl;
}
int seven(){
    cout << "returnerar 7 ";
    return 7;
}
int two(){
    cout << "returnerar 2 ";
    return 2;
}
int summan(int x, int y){
    int summa= x+y;
    cout << "returnerar summan " << summa;
    return summa;
}
void provaNastlatAnrop(){
    skrivResultat(summan(two(),seven()));
}

void testBiggest(){
    cout << biggest(3,7) << endl;
    cout << biggest(biggest(3,8), biggest(7,5)) << endl;
    cout << biggest(biggest(-5.2,-14.3), -10.5) << endl;
    assert(biggest(biggest(2.0,2.5),1.0)>2.4);
    assert(biggest(biggest(2, 3),biggest(1,8))==8);
}
void thinkOfANumber(){
    int secret =12345;
    cout << "Now I'm, the computer, thinking of a secret number." << endl;
    if(secret % 2==1)
        cout <<"I'm only telling you that the number is uneven" << endl;
    else cout <<"I'm only telling you that the number is even" << endl;
    cout << endl;
}

void writeRandomNumber(int antal){
    srand(42);
    for(int i=0;i<antal;i+=1)
        cout << rand() << endl;
    cout << endl;
}
void testWriteRandomNumber(){
    writeRandomNumber(5);
    writeRandomNumber(5);
}
void tryCycle(){
    const int x=42;
    long int antalAnropTllRand=0;
    int antalSeddaX=0;
    long int senasteAnropsnummret=0;
    while(antalSeddaX<3){
        int slumptal=rand();
        antalAnropTllRand+=1;
        if(slumptal==x){
            cout << "Såg " << x << " efter " << antalAnropTllRand << " anrop\n";
            if(antalSeddaX>0)
                cout << antalAnropTllRand - senasteAnropsnummret
                     << " anrop sedan förra gången." << endl;
            antalSeddaX+=1;
            senasteAnropsnummret=antalAnropTllRand;
            cout << "Efter " << x << " kommer nu "
                 << rand() << ", " << rand() << " och " << rand() << endl << endl;
            antalAnropTllRand+=3;
        }

    }
}
int seededSlumptal(){
    srand(unsigned(time(nullptr)));
    return rand();
}
void trySeededSlumptal(){
    for(int i=0;i<5;i++)
        cout << seededSlumptal() << " ";
    cout << endl;
}


int tarningsvarde(){
    int n=1+rand()%6;
    return n;
}
int bruttovinst(int t1, int t2, int t3){
    if(t1==6 && t2==6&&t3==6)
        return 100;
    if(t1==t2&&t2==t3)
        return 50;
    if(t1==t2||t2==t3||t1==t3)
        return 20;
    return 0;
}
void testaBruttoVinst(){
    assert(bruttovinst(6,6,6)==100);
    assert(bruttovinst(3,3,3)==50);
    assert(bruttovinst(1,2,3)==0);
    assert(bruttovinst(1,1,5)==20);
}
bool boolFranUppmaning(const char uppmaning[]){
    cout << uppmaning;
    while(true){
        char svar;
        cin >> svar;
        if(svar=='j')
            return true;
        if(svar=='n')
            return false;
        else continue;

    }
}
int bruttovinstFranUtfordSpelomgang(){
    int t1=tarningsvarde();
    int t2=tarningsvarde();
    int t3=tarningsvarde();
    int vinst = bruttovinst(t1,t2,t3);
    cout << "Tarningarna blev " << t1 << " " << t2 << " " << t3 << "."
         << " Du vann " << vinst << " kronor" << endl;
    return vinst;
}
void spelaTarningsspelet(){
    int kapital = 100;
    while(kapital>=10){
        cout << "Du har " << kapital << " kronor" << endl;
        bool spelaMera = boolFranUppmaning("Vill du spela mera? (j/n):");
        if(spelaMera){
            kapital = kapital - 10 + bruttovinstFranUtfordSpelomgang();
        }
        else{
            cout << "Fegis!!" << endl;
            break;
        }
    }
}
int nettoVinstAnalys(){
    int t1=tarningsvarde();
    int t2=tarningsvarde();
    int t3=tarningsvarde();
    int nettoVinstPerOmgang=bruttovinst(t1,t2,t3)-10;
    return nettoVinstPerOmgang;
}
void skrivAnalysAvSpel(){
    double nettovinst=0;
    for(int i=0; i<999999; i++){
        nettovinst+=nettoVinstAnalys();
    }
    cout << "Den totala vinsten blev: " << nettovinst << endl
         << "Den genomsnittliga vinsten blev: " << nettovinst/1000000 << endl;


}

void shortcutToKap9och10(){
    skrivAnalysAvSpel();
    spelaTarningsspelet();



}


//Hej heltal 2
//Hej på dig flyttal 2.1
//Hej på er flyttal
