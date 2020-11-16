#include <iostream>
#include <cassert>
using namespace std;

void swap(int *pA, int *pB){
    int oldA=*pA;
    *pA=*pB;
    *pB=oldA;
}
void swap(double *pA, double *pB){
    double oldA=*pA;
    *pA=*pB;
    *pB=oldA;
}
void automattestaSwap(){
    int a=1;
    int b=2;
    swap(&a,&b);
    assert(a==2&&b==1);
    double x=1.5;
    double y=2.5;
    swap(&x,&y);
    assert(x==2.5&&y==1.5);
}
int lenght(const char *str){
    const char *p = str;
    while(*p!=0)
        p+=1;
    return p-str;
}
void automattestaLenght(){
    assert(lenght("hej")==3);
}
bool isSame(const char *str1, const char *str2){
    if(lenght(str1)!=lenght(str2))
        return false;
    int i=0;
    while(*(str1+i)!=0){
        if(*(str1+i)!=*(str2+i))
            return false;
        i+=1;
    }
    return true;
}
void automattestaAreSame(){
    assert(isSame("abcd","abcd"));
    assert(!isSame("abcd e","abcd"));
    assert(!isSame("abcd","abcd e"));
    assert(!isSame("abcd","abcX"));
    assert(!isSame("abcd","Xbcd"));
}
void konverteraTillVersaler2(char *str){
    int i=0;
    while(*(str+i)!=0){
        *(str+i)=toupper(*(str+i));
        i+=1;
    }
}
void automattestaKonverteraTillVersaler2(){
    char str1[]="abc ABC 123 .,- xyz";
    char str2[]="ABC ABC 123 .,- XYZ";
    konverteraTillVersaler2(str1);
    assert(isSame(str1,str2));
}
void konverteraTillRubrik2(char *str){
    int i=0;
    while(*(str+i)!=0){
        if(*(str+i-1)==32)
            *(str+i)=toupper(*(str+i));
        else *(str+i)=tolower(*(str+i));
        i+=1;
    }
    *str=toupper(*str);
}
void automattestaKonverteraTillRubrik2(){
    char str1[]="this is a test";
    char str2[]="THIS IS A TEST";
    char rubrik[]="This Is A Test";
    konverteraTillRubrik2(str1);
    konverteraTillRubrik2(str2);
    assert(isSame(str1,rubrik));
    assert(isSame(str2,rubrik));

}
void writeStrings(const char** str,int antal){
    int i=0;
    while(*(str+i)!=0){
        *(str+i)=*(str+i);
        i+=1;
    }
    for(int n=0; n<antal; n+=1)
        cout << *(str+n) << endl;
}
void testWriteStrings(){
    const int antal=7;
    const char *dagnamn[antal] ={"mandag","tisdag","onsdag","torsdag","fredag","lordag","sondag"};
    writeStrings(dagnamn, antal);
}
void skrivUtArr2(const int *pBegin, const int *pEnd){
    for(int const *p=pBegin; p<pEnd; p+=1)
        cout << *p;
    cout << endl;
}
void fyllMedKonstant2(int *pBegin, int *pEnd, int konstant){
    for(int *p=pBegin;p<pEnd;p++)
        *p=konstant;
}
void fyllMedSlumptal2(int *pBegin, int *pEnd, int minst, int storst){
    for(int *p=pBegin; p<pEnd;p++)
        *p=(rand()%storst+1-minst)+minst;
}
int minst2(const int *pBegin, const int *pEnd){
    assert(pEnd-pBegin > 0);
    int minst=*pBegin;
    for(int const *p=pBegin;p<pEnd;p++){
        if(minst>*p)
            minst=*p;
    }
    return minst;
}
int storst2(const int *pBegin, const int *pEnd){
    assert(pEnd-pBegin > 0);
    int storst=*pBegin;
    for(int const *p=pBegin;p<pEnd;p++){
        if(storst<*p)
            storst=*p;
    }
    return storst;
}
bool isSorted2(const int *pBegin, const int *pEnd){
    for(int const *p=pBegin; p<pEnd; p+=1){
        if(*p>*(p+1))
            return false;
    }
    return true;
}
bool contains2(const int *pBegin, const int *pEnd, int x){
    for(int const *p=pBegin;p<pEnd;p+=1){
        if(*p==x)
            return true;
    }
    return false;
}
void testaArrayFunktionerna(){
    const int storlek = 10;
    int arr[storlek];
    fyllMedKonstant2(&arr[0], &arr[storlek], 5);
    skrivUtArr2(&arr[0], &arr[storlek]);
    arr[0] -= 1;
    arr[storlek-1] += 1;
    assert( isSorted2(&arr[0], &arr[storlek]) );
    arr[0] = 6;
    assert( !isSorted2(&arr[0], &arr[storlek]) );
    fyllMedSlumptal2(&arr[0], &arr[storlek], -2, 2);
    skrivUtArr2(&arr[0], &arr[storlek]);
    arr[1] = -3; // Detta blir det minsta värdet
    arr[storlek-1] = 3; // Detta blir det största värdet
    int m = minst2(&arr[0], &arr[storlek]);
    int s = storst2(&arr[0], &arr[storlek]);
    assert( m == -3 && s == 3 );
    assert( contains2(&arr[0], &arr[storlek], 3));
}
void shortcutToKap11(){
    testaArrayFunktionerna();
    testWriteStrings();
    automattestaKonverteraTillRubrik2();
    automattestaKonverteraTillVersaler2();
    automattestaAreSame();
    automattestaLenght();
    automattestaSwap();

}
