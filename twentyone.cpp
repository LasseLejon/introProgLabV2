#include <iostream>
#include "vanligt.h"
#include "deckOfCards.h"
#include "playingCard.h"
using namespace std;
void checkWhoWon(int player, int computer){
    cout << "The value of your cards are: " << player << '\n' <<
            "The value of the computers cards are: " << computer << " " << endl;
    if(player>21)
        cout << "You lost!" << endl;
    if(computer>21)
        cout << "You won!" << endl;
    if(player<computer && computer < 22)
        cout << "You lost!" << endl;
    if(player>computer && player<22)
        cout << "You won!" << endl;
}
void testShuffle(){
    DeckOfCards deck=newDeck();
    shuffleTheDeck(deck);
    for(int n=0;n<deck.cardsRemaining;n++)
        cout << stringFromPlayingCard(deck.cards[n]) << "   ";
}

void playTwentyOne(){

    bool wantToPlay=boolFranUppmaning2("Do you want to play twenty one? (y/n)");
    if(wantToPlay){
        DeckOfCards deck=newDeck();
        shuffleTheDeck(deck);
        PlayingCard playersCard=cardFromDeck(deck);
        cout << "You got " << stringFromPlayingCard(playersCard) << endl;
        PlayingCard computersCard=cardFromDeck(deck);
        cout << "The computer got " << stringFromPlayingCard(computersCard) << endl;
        int sumOfPlayer=playersCard.value;
        int sumOfComputer=computersCard.value;
        bool takeCard=true;
        while(sumOfPlayer < 22 && sumOfComputer < 22 && takeCard){
            cout << "The value of your cards are: " << sumOfPlayer << '\n' <<
                    "The value of the computers cards are: " << sumOfComputer << endl;
            takeCard=boolFranUppmaning2("Do you want another card? (y/n)");
            if(takeCard){
                playersCard=cardFromDeck(deck);
                sumOfPlayer+=playersCard.value;
                cout << "You got the card " << stringFromPlayingCard(playersCard) << endl;

            }
            // datorn tar ett kort om datorns värde är mindre än spelarens
            if(sumOfComputer<sumOfPlayer && sumOfPlayer<22){
                computersCard=cardFromDeck(deck);
                sumOfComputer+=computersCard.value;
                cout << "The computer got " << stringFromPlayingCard(computersCard) << endl;
            }
        }
        checkWhoWon(sumOfPlayer,sumOfComputer);


    }

}

