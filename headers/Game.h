#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Menu.h"


class Game {
private:
    Deck deck;
    Player player;
    Dealer dealer;
    Menu menu;
public:
    Game();
    void startGame();
    void playRound();
    /*void playerTurn();
    void dealerTurn();*/
    void determineWinner();
    void displayGameState() const;
};



#endif //GAME_H
