#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

    void initializeDeck(); //default pachetul are 52 carti

public:
    Deck();

    ~Deck();

    void shuffle();
    Card dealCard();
    bool isEmpty() const;
    int getSize() const;

    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
};



#endif //DECK_H
