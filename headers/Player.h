#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Deck.h"

class Player {
private:
    std::vector<Card> hand;
    int balance;
    int profit;
    int currentBet;

public:
    Player(int initialBalance = 1000);

    void addCard(const Card& card);
    void clearHand();
    const std::vector<Card>& getHand() const;
    void displayHand() const;
    int getHandScore() const;
    bool isBusted() const;
    bool hasBlackjack() const;
    int getBalance() const;
    int getProfit() const;
    int getCurrentBet() const;
    bool placeBet(int amount);
    void receiveMoney(int amount);
    void loseBet();
    void pushBet();

    virtual void performTurn(Deck& deck);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};



#endif //PLAYER_H
