#include <iostream>
#include <cassert>
#include <myMathFunctions.h>
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
void mindReading(){
    int spooky;
    cout << "I think the secret is " << spooky << endl;
}
void testMindReading(){
    thinkOfANumber();
    mindReading();
}

void shortcutToKap9och10(){
    testMindReading();
    testBiggest();
    provaNastlatAnrop();


}

//Hej heltal 2
//Hej på dig flyttal 2.1
//Hej på er flyttal
