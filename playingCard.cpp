#include "playingCard.h"
#include <cassert>
#include "vanligt.h"
using namespace std;
PlayingCard playingCard(CardSuit suit, int value){
    PlayingCard card;
    card.suit=suit;
    card.value=value;
    return card;
}

string stringFromCardSuit(CardSuit suit){
    if(suit==CardSuit::hearts)
        return "hearts";
    if(suit==CardSuit::spades)
        return "spades";
    if(suit==CardSuit::diamonds)
        return "diamonds";
    if(suit==CardSuit::clubs)
        return "clubs";
}
string stringFromCardSuit2(CardSuit suit){
    static const char* strings[]={"hearts", "spades", "diamonds", "clubs"};
    int i=(int)suit;
    return strings[i];
}

string stringFromCardvalue(int cardValue){
    static const char* strings[]{"doesn't exist","ace","two","three","four",
        "five","six","seven","eight","nine","ten","jack",
        "queen","king"};
    int i=(int)cardValue;
    return strings[i];
}


string stringFromPlayingCard(PlayingCard card){
    string numName[14]{"doesn't exist","ace","two","three","four",
                       "five","six","seven","eight","nine","ten","jack",
                       "queen","king"};
    return numName[card.value] + " of " + stringFromCardSuit(card.suit);
}
bool boolFranUppmaning2(const char uppmaning[]){
    cout << uppmaning;
    while(true){
        char svar;
        cout << ":";
        cin >> svar;
        if(svar=='y')
            return true;
        if(svar=='n')
            return false;
        if(svar!='j'&&svar!='n'){
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
            cout << endl;
        }


    }
}
