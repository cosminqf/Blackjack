#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Menu.h"
#include "Game.h"
#include "Dealer.h"
#include <iostream>

#include "Dealer.h"

int main() {
    /*
    std::cout << "Test card-----------------------\n";
    Card c1(3, 1);
    Card c2(0, 13);
    Card c3(1, 10);

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << "Stop test card--------------------\n";

    std::cout << "Start test deck----------------------\n";
    Deck deck;
    std::cout << deck << std::endl;
    deck.shuffle();
    std::cout << deck << std::endl;
    for (int i = 0; i < 5; i++) {
        Card dealtCard = deck.dealCard();
        std::cout << dealtCard << std::endl;
    }
    std::cout << deck.getSize() << std::endl;
    std::cout << deck << std::endl;
    std::cout << "Stop test deck-----------------------\n";

    std::cout << "Start test player----------------------\n";
    Player player;

    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    player.displayHand();
    std::cout << std::endl;

    player.placeBet(100);

    player.addCard(deck.dealCard());
    player.displayHand();
    std::cout << std::endl;

    std::cout << player.getBalance() << std::endl;
    std::cout << player.getProfit() << std::endl;
    std::cout << player.getCurrentBet() << std::endl;

    player.receiveMoney(player.getCurrentBet() * 2);
    std::cout << player.getBalance() << std::endl;

    player.placeBet(50);
    player.loseBet();

    player.placeBet(20);
    player.pushBet();

    std::cout << player.getBalance() << std::endl;
    std::cout << player.getProfit() << std::endl;
    std::cout << player.getCurrentBet() << std::endl;

    std::cout << "Stop test player-----------------------\n";

    std::cout << "Start test dealer-----------------------\n";

    Dealer dealer;
    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    dealer.displayInitialHand();

    std::cout << std::endl;

    while (dealer.wantsToHit()) {
        dealer.addCard(deck.dealCard());
        std::cout << dealer.getHandScore() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Stop test dealer--------------------\n";

    */

    Game joc;
    joc.startGame();

}
