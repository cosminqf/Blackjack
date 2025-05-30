#ifndef DEALER_H
#define DEALER_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Player.h"

class Dealer : public Player {
public:
    Dealer();
    void displayInitialHand() const;
    bool wantsToHit() const;

    void performTurn(Deck& deck) override;
    friend std::ostream& operator<<(std::ostream& os, const Dealer& dealer);
};



#endif //DEALER_H
