#include "Player.h"
#include "Card.h"
#include <iostream>

Player::Player(int initialBalance): balance(initialBalance), profit(0), currentBet(0) {

}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}

void Player::displayHand() const {
    for (const auto& card : hand) {
        std::cout << card << " ";
    }
    std::cout << getHandScore();
}

int Player::getHandScore() const {
    int score = 0;
    int cntAce = 0;

    for (const auto& card : hand) {
        int val = card.getBlackjackValue();
        if (val == 11) {
            cntAce++;
        }
        score += val;
    }

    while (score > 21 && cntAce > 0) {
        score -= 10;
        cntAce--;
    }

    return score;
}

bool Player::isBusted() const {
    if (getHandScore() > 21)
        return true;
    return false;
}

bool Player::hasBlackjack() const {
    if (hand.size() == 2 && getHandScore() == 21)
        return true;
    return false;
}

int Player::getBalance() const {
    return balance;
}

int Player::getProfit() const {
    return profit;
}

int Player::getCurrentBet() const {
    return currentBet;
}

bool Player::placeBet(int amount) {
    if (amount <= 0 || amount > balance)
        return false;
    balance -= amount;
    currentBet = amount;
    return true;
}

void Player::receiveMoney(int amount) {
    balance += amount;
    profit += amount - currentBet;
    currentBet = 0;
}

void Player::loseBet() {
    profit -= currentBet;
    currentBet = 0;
}

void Player::pushBet() {
    balance += currentBet;
    currentBet = 0;
}

void Player::performTurn(Deck &deck) {
    char input;
    bool turnEnded = false;

    while (!turnEnded) {
        std::cout << "Ai in mana: ";
        displayHand();
        std::cout << "\n";

        if (isBusted() || getHandScore() == 21) {
            turnEnded = true;
            break;
        }

        std::cout << "h pentru Hit si s pentru Stand. Ce alegi?\n";
        std::cin >> input;
        if (tolower(input) == 'h')
            addCard(deck.dealCard());
        else if (tolower(input) == 's')
            turnEnded = true;
        else
            std::cout << "Input invalid\n";
    }
}


std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.balance << "\n";
    os << player.profit << "\n";
    os << player.currentBet << "\n";
    os << "\n";
    return os;
}









