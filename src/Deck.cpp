#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>

Deck::Deck() {
    initializeDeck();
    shuffle();
}

Deck::~Deck() {

}

void Deck::initializeDeck() {
    for (int i = 0; i < 7; i++)
        for (int s = 0; s <= 3; s++) {
            for (int v = 1; v <= 13; v++) {
                cards.push_back(Card(s, v));
            }
        }
}

void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

Card Deck::dealCard() {
    if (isEmpty()) {
        throw std::runtime_error("DE UNDE VREI BA SA DAI DACA E GOL PACHETU");
    }

    Card dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
}

bool Deck::isEmpty() const {
    return cards.empty();
}

int Deck::getSize() const {
    return cards.size();
}

std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    int cnt = 0;
    for (const auto& card : deck.cards) {
        os << card << "  ";
        cnt++;
        if (cnt % 5 == 0) {
            os << "\n";
        }
    }
    if (cnt % 5 != 0) {
        os << "\n";
    }
    return os;
}