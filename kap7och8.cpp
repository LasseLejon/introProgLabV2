#include <iostream>
#include <string>
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

void shortcutToKap7Och8(){
    huvudLoop();

}