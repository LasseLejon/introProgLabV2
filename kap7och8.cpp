#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

void testaCin1(){
    while(true){
        int x=0;
        cout << "Skriv ett heltal:";
        cin >> x;
        cout << "läste " << x << endl;
    }
}
void testaCin2(){
    while(true){
        int x=0;
        cout << "skriv ett heltal:";
        cin >> x;
        if(!cin.fail())
            cout << "lyckades läsa " << x << endl;
        else{
            cout << "misslyckad läsning" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    }
}
double flyttalFranUppmaning(const char uppmaning[]){
    while(true){
        int x=0;
        cout << uppmaning;
        cin >> x;
        if(!cin.fail())
            return x;
        else{
            cout << "ogiltigt tal, försök igen!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    }
}
void provaFlyttalFranUppmaning(){
    const double bokPris=flyttalFranUppmaning("Hur många kronor kostar boken?");
    const double antalSidor=flyttalFranUppmaning("Hur många sidor har boken?");
    const double procentAttLasa=flyttalFranUppmaning("Hur många procent av sidorna kommer du läsa?");
    cout << "Du har angett att boken kostar " << bokPris <<" kronor"
         << ", och att den har " << antalSidor <<" sidor"
         << ", och att du tänker läsa " << procentAttLasa << "%" << endl;


}
void testarCinString(){
    cout << "testarCinString" << endl;
    while(true){
        string str;
        cout << "skriv en sträng:";
        cin >> str;
        if(!cin.fail())
            cout << "lyckades läsa" << str << endl;
        else{
            cout << "misslyckad inläsning" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}
bool doingCalculations(string uttryck){
    cout << "beräknar " << uttryck << endl;
    return true;
}
void huvudLoop(){
    while(true){
        string textRad;
        cout << ":";
        getline(cin, textRad);
        if(textRad =="")
            continue;
        if(textRad=="exit")
            break;
        bool ok=doingCalculations(textRad);
        if(!ok)
            cout << "förstår ej" << endl;
    }
}
bool doingCalculations2(string kommandorad){
    int a, b;
    char op;
    istringstream stream(kommandorad);
    stream >> a >> op >> b;
    bool ok=!stream.fail();
    if(ok){
        char dum;
        stream >> dum;
        ok=stream.fail();
    }
    if(ok){
        if(op=='+') cout << a+b << endl;
        else if(op=='-') cout << a-b << endl;
        else if(op=='*') cout << a*b << endl;
        else if(op=='/') cout << a/b << endl;
        else if(op=='%') cout << a%b << endl;
        else cout << "okänd operand" << endl;
    }
    return ok;
}
vector <string> ordlistan(){
    string path = "C:/Users/Lasse/OneDrive/Skrivbord/ord.txt";
    ifstream filen(path);
    vector<string> listan;
    string ettOrd;
    while(filen>>ettOrd){
        listan.push_back(ettOrd);
    }
    return listan;

}
void provaOrdlistan(){
    vector<string> utskrift=ordlistan();
    for(unsigned int i=0;i<utskrift.size();i++)
        cout << utskrift[i] << endl;

}

//n:  a?avb
//o:  abacb
bool matcharNyckeln(string ord, string nyckel){
    if(nyckel.size()!=ord.size())
        return false;
    for(unsigned int i=0;i<ord.size();i++){
        if(nyckel[i]=='?')
            continue;
        if(nyckel[i]==ord[i])
            continue;
        else return false;
    }
    return true;
}


//ord       hejsan
//nyckel    he?*n
//temp      hej
bool matcharVildnyckel(string ord, string nyckel){
    string temp;
    for(unsigned int i=0;i<ord.size();i+=1){
        if(nyckel[i]=='?'){
            temp+=ord[i];
            continue;
        }
        if(ord[i]==nyckel[i]){
            temp+=ord[i];
            continue;
        }
        if(nyckel[i]=='*'){
            for(unsigned int n=i;n<ord.size()-1;n+=1)
                temp+=ord[n];

        }
        for(unsigned int k=i+1;k<nyckel.size();k+=1)
            temp+=nyckel[k];
    }
    return (temp==ord);
}
bool matcharVildnyckel2(string ord, string nyckel){
    for(unsigned int i=0;i<ord.size() && nyckel[i]!='*';i+=1){
        if(nyckel[i]=='?'){
            nyckel[i]=ord[i];
        }
        if(ord[i]==nyckel[i])
            continue;
        else return false;

    }
    unsigned int n=nyckel.size()-1;
    unsigned int o=ord.size()-1;
    while(nyckel[n]!='*'){
        if(ord[o]==nyckel[n]){
            o-=1;
            n-=1;
        }
        else return false;
    }
    return true;

}
void automattestaMatcharVildnyckel(){
    assert( matcharVildnyckel2("abcdefgh", "a?c*h") );
    assert( !matcharVildnyckel2("abcdefgh", "a?c*x") );
    assert( !matcharVildnyckel2("abcdefgh", "abc?") );
}

void automattestaMatcharFrgenyckel(){
    assert( matcharNyckeln("xaby", "?ab?") );
    assert( !matcharNyckeln("xaby", "?abz") );
    assert( !matcharNyckeln("xaby", "?abyx") );
    assert( !matcharNyckeln("xabyx", "?aby") );
}

void skrivMatchningar(const vector<string>& allaOrd, string nyckel){
    for (unsigned int i=0; i<allaOrd.size(); i+=1) {
        if (matcharVildnyckel2(allaOrd[i], nyckel))
            cout << allaOrd[i] << endl;
    }


}
void ordMatch(){
    vector<string> allaOrd = ordlistan();
    cout << "Valkommen till ordmatch!" << endl;
    while (true){
        cout << "NYCKEL:";
        string nyckel;
        getline( cin , nyckel );
        if (nyckel == "")
            continue;
        if (nyckel == "avbryt")
            break;
        skrivMatchningar( allaOrd, nyckel);
    }
    cout << "(ordmatchningen avbrats)" << endl;
}
string testet(string ord, string nyckel){
    string temp;
    const unsigned int x = ord.size();
    for(unsigned int i=0;i<ord.size();i+=1){
        if(nyckel[i]=='?'){
            temp+=ord[i];
            continue;
        }
        if(ord[i]==nyckel[i]){
            temp+=ord[i];
            continue;
        }
        if(nyckel[i]=='*'){
            for(unsigned int n=i;n<(x-1);n+=1)
                temp+=ord[n];

        }
        if(nyckel[i+1]==ord[x-1])
            temp+=ord[x-1];
    }
    return temp;
}
void testarTestet(){
    string s1=testet("hejsan","h?j*n");
    string s2="reer";
    cout << s2 << s2.size();

}
void skrivHejfilsystem(){
    string filnamn = "C:/Users/Lasse/OneDrive/Skrivbord/hej.txt";
    ofstream ut;
    ut.open(filnamn);
    for(int i=0; i<10;i+=1)
        ut << "Hej filsystem!" << endl;
    ut.close();
}
unsigned int konstigMatch(string str1, string str2){
    for(unsigned int i=0;i<str1.size()&&i<str2.size();i+=1){
     if(str2[i]=='X')
         continue;
     if(tolower(str1[i])!=tolower(str2[i]))
         return i;
    }
    return 99;
}
void provaKonstigMatch(){
    cout << "prova" << endl;
    unsigned int x0 = konstigMatch("abc","Xfc");
    unsigned int x1 = konstigMatch("ABC","abc");
    unsigned int x2=konstigMatch("abcdef","Xbcde");
    unsigned int x3=konstigMatch("abc","defabc");
    unsigned int x4=konstigMatch("abc","anjovis");
    cout << x0 << endl;
    cout << x1 << endl;
    cout << x2 << endl;
    cout << x3 << endl;
    cout << x4 << endl;
}
int x(const char str[]){
    for(int i=0; true;i++){
        if(str[i]==0)
            return i;
    }
}
void provaX(){
    cout << x("HEJ") << endl;
    cout << x("////") << endl;
    cout << x("\t\t") << endl;
}
vector <string> enVek(){
    istringstream texts("Denna dag ett liv!");
    vector <string> resultat;
    string ord;
    while(texts >> ord)
        resultat.push_back(ord);
    return resultat;
}
void testaEnVek(){
    vector<string> v = enVek();
    string s=v[3];
    cout << "Size = " << v.size() << endl;
    cout << "strang =" << s << endl;
}
void shortcutToKap7Och8(){
    testaEnVek();
    provaX();
    provaKonstigMatch();
    automattestaMatcharFrgenyckel();
    skrivHejfilsystem();
    automattestaMatcharVildnyckel();
    ordMatch();


}
