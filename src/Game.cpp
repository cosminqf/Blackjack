#include "Game.h"
#include <string>
#include <iostream>
#include <cctype>
#include <limits>

Game::Game() : deck(), player(), dealer(), menu() {

}

void Game::startGame() {
    std::cout << "AM INCEPUT JOCUL\n";
    while (player.getBalance() > 0) {
        std::cout << "Balanta ta este de " << player.getBalance() << "\n";
        playRound();

        if (player.getBalance() <= 0) {
            std::cout << "Nu mai ai bani baiete";
            break;
        }

        std::cout << "Mai joci o runda? Zi y sau n\n";
        char input;
        std::cin >> input;

        if (tolower(input) == 'n')
            break;
    }
}

void Game::playRound() {
    player.clearHand();
    dealer.clearHand();
    if (deck.getSize() < 100)
        deck = Deck();

    int betAmount;
    bool betPlaced = false;
    while (!betPlaced) {
        std::cout << "Cat pariezi? Momentan ai " << player.getBalance() << "\n";
        std::cin >> betAmount;

        if (std::cin.fail()) {
            std::cout << "Input invalid\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //curata buffer-ul de intrare daca din greseala introduc litere
            continue;
        }

        if (player.placeBet(betAmount)) {
            betPlaced = true;
            std::cout << "Ai pariat " << player.getCurrentBet() << "\n";
        }
        else {
            std::cout << "Miza invalida\n";
        }
    }

    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    displayGameState();
    //std::cout << deck.getSize() << "\n";

    /*if (player.hasBlackjack() && dealer.hasBlackjack()) {
        player.pushBet();
    }
    else if (player.hasBlackjack() && !dealer.hasBlackjack()) {
        std::cout << "Ai Blackjack, ai castigat\n";
        player.receiveMoney(static_cast<int>(player.getCurrentBet() * 2.5));
    }
    else if (!player.hasBlackjack() && dealer.hasBlackjack()) {
        std::cout << "Dealeru are blackjack, ai pierdut\n";
        player.loseBet();
    }
    else {
        player.performTurn(deck);

        if (!player.isBusted())
            dealer.performTurn(deck);

        determineWinner();
    } */
    player.performTurn(deck);

    if (!player.isBusted())
        dealer.performTurn(deck);

    determineWinner();
    std::cout << "Balanta de acum este de " << player.getBalance() << " iar profitul din runda asta e de " << player.getProfit() << "\n";
}

/*void Game::playerTurn() {
    char input;
    bool turnEnded = false;

    while (!turnEnded) {
        std::cout << "Ai in mana: ";
        player.displayHand();
        std::cout << "\n";

        if (player.isBusted()) {
            turnEnded = true;
            break;
        }

        std::cout << "h pentru Hit si s pentru Stand. Ce alegi?\n";
        std::cin >> input;
        if (tolower(input) == 'h')
            player.addCard(deck.dealCard());
        else if (tolower(input) == 's')
            turnEnded = true;
        else
            std::cout << "Input invalid\n";
    }
}

void Game::dealerTurn() {
    std::cout << "Dealeru are: ";
    dealer.displayHand();
    std::cout << "\n";

    while (dealer.wantsToHit()) {
        dealer.addCard(deck.dealCard());
        std::cout << "Dealeru are: ";
        dealer.displayHand();
        std::cout << "\n";
        if (dealer.isBusted())
            break;
    }
    if (!dealer.isBusted())
        std::cout << "Dealerul s-a oprit la " << dealer.getHandScore() << "\n";
}*/

void Game::determineWinner() {
    if (player.hasBlackjack() && dealer.hasBlackjack()) {
        player.pushBet();
    }
    else if (player.hasBlackjack() && !dealer.hasBlackjack()) {
        std::cout << "Ai Blackjack, ai castigat\n";
        player.receiveMoney(static_cast<int>(player.getCurrentBet() * 2.5));
    }
    else if (!player.hasBlackjack() && dealer.hasBlackjack()) {
        std::cout << "Dealeru are blackjack, ai pierdut\n";
        player.loseBet();
    }
    else if (player.isBusted()) {
        std::cout << "AI pierdut deoarece ai dat bust\n";
        player.loseBet();
    }
    else if (dealer.isBusted()) {
        std::cout << "Ai castigat deoarece dealeru a dat bust\n";
        player.receiveMoney(player.getCurrentBet() * 2);
    }
    else if (player.getHandScore() > dealer.getHandScore()) {
        std::cout << "Ai castigat deoarece ai avut scorul mai mare decat dealeru\n";
        player.receiveMoney(player.getCurrentBet() * 2);
    }
    else if (player.getHandScore() < dealer.getHandScore()) {
        std::cout << "Ai pierdut deoarece ai avut scorul mai mic decat dealeru\n";
        player.loseBet();
    }
    else {
        std::cout << "Egal deci primesti banii inapoi\n";
        player.pushBet();
    }

}


void Game::displayGameState() const {
    std::cout << "Ai " << player.getBalance() << " bani iar miza actuala e de " << player.getCurrentBet();
    std::cout << "\n";
    std::cout << "Dealer: ";
    dealer.displayInitialHand();
    std::cout << " + cartea ascunsa \n";
}