#include "deckOfCards.h"
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
void changeValues(PlayingCard &a, PlayingCard &b){

    PlayingCard oldA=a;
    a=b;
    b=oldA;
}

DeckOfCards newDeck(){
    DeckOfCards deck;
    deck.cardsRemaining=52;
    int n=0;
    for(int suit=0; suit<4;suit++){
        CardSuit cs =(CardSuit) suit;
        for(int value=1; value<14;value++){
            deck.cards[n]=playingCard(cs,value);
            n++;
        }
    }
    return deck;
}
void shuffleTheDeck(DeckOfCards& deck){
    srand(time(0));
    for(int i=0; i<deck.cardsRemaining; i++){
        int j=i+(rand() %(52-i));
        swap(deck.cards[i], deck.cards[j]);

    }

}
PlayingCard cardFromDeck(DeckOfCards& deck){
    assert(deck.cardsRemaining>0);
    deck.cardsRemaining-=1;
    PlayingCard card = deck.cards[deck.cardsRemaining];
    return card;
}
int cardsRemaining(const DeckOfCards& deck){
    int remaining=deck.cardsRemaining;
    return remaining;

}
void resetDeck(DeckOfCards& deck){
    int n=0;
    for(int value=1;value<14;value++)
        for(int suit=0;suit<4;suit++){
            deck.cards[n]=playingCard((CardSuit) suit, value);
            n++;
        }
    deck.cardsRemaining=52;
}
