#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
private:
    //inima, trefla, frunza si romb
    int suit;
    //valorile cartilor, cele peste 10 vor avea valoarea 10 iar A va fi atat
    //cat si 11
    int value;

    std::string suitToString() const;
    std::string valueToString() const;

public:
    Card(int s, int val);

    ~Card();

    int getSuit() const;
    int getValue() const;
    int getBlackjackValue() const; //adaptam valoarea cartii la valoarea pt blackjack

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};



#endif //CARD_H
