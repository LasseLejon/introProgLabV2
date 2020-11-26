#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H
#include <string>
enum class CardSuit{
    hearts,
    spades,
    diamonds,
    clubs
};
struct PlayingCard{
    int value;//1....13
    CardSuit suit;
};
PlayingCard playingCard(CardSuit suit, int value);

std::string stringFromCardSuit(CardSuit suit);
std::string stringFromCardvalue(int cardValue);
std::string stringFromPlayingCard(PlayingCard card);
void changeValues(PlayingCard &a, PlayingCard &b);
bool boolFranUppmaning2(const char uppmaning[]);

#endif // PLAYINGCARD_H
