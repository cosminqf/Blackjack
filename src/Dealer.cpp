#include "Dealer.h"
#include <iostream>
#include <vector>

Dealer::Dealer() : Player(0) {

}

void Dealer::displayInitialHand() const {
    std::cout << getHand()[0];
}

bool Dealer::wantsToHit() const {
    if (getHandScore() < 17)
        return true;
    return false;
}

void Dealer::performTurn(Deck &deck) {
    std::cout << "Dealeru are: ";
    displayHand();
    std::cout << "\n";

    while (wantsToHit()) {
        addCard(deck.dealCard());
        std::cout << "Dealeru are: ";
        displayHand();
        std::cout << "\n";
        if (isBusted())
            break;
    }
    if (!isBusted())
        std::cout << "Dealerul s-a oprit la " << getHandScore() << "\n";
}


std::ostream& operator<<(std::ostream& os, const Dealer& dealer) {
    for (const auto& card : dealer.getHand()) {
        os << card << " ";
    }
    return os;
}

