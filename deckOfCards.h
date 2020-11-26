#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "playingCard.h"
struct DeckOfCards{
    PlayingCard cards[52];
    int cardsRemaining;
};
DeckOfCards newDeck();
void shuffleTheDeck(DeckOfCards& deck);
PlayingCard cardFromDeck(DeckOfCards& deck);
int cardsRemaining(const DeckOfCards& deck);
void resetDeck(DeckOfCards& deck);
void changeValues(PlayingCard &a, PlayingCard &b);
#endif // DECKOFCARDS_H
