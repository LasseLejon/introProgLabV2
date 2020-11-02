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
bool matcharNyckeln(string ord, string nyckel){
    for(unsigned int i=0;i<ord.size();i++){
        if(nyckel[i]=='?')
            nyckel[i]=ord[i];
        for(unsigned int k=0;k<nyckel.size();k++){
            if(ord[i]==nyckel[k])
                continue;
        }
    }
    return (ord==nyckel);

}
void automattestaMatcharFrgenyckel(){
    assert( matcharNyckeln("xaby", "?ab?") );
    assert( !matcharNyckeln("xaby", "?abz") );
    assert( !matcharNyckeln("xaby", "?abyx") );
    assert( !matcharNyckeln("xabyx", "?aby") );
}

void skrivMatchningar(const vector<string>& allaOrd, string nyckel){
    for (unsigned int i=0; i<allaOrd.size(); i+=1) {
        if (matcharNyckeln(allaOrd[i], nyckel))
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

void shortcutToKap7Och8(){
    automattestaMatcharFrgenyckel();
    ordMatch();


}
