#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include "Dealer.h"
#include "Settings.h"
#include "Rules.h"
#include <iostream>
#include <limits>

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
    Settings settings;
    Rules rules;

    int choice;

    std::cout << "START" << std::endl;

    do {
        std::cout << "MENU\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. View Rules\n";
        std::cout << "3. Settings\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (std::cin.fail() || choice < 0 || choice > 3) {
            std::cout << "Invalid option. Please choose a number between 0 and 3: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }

        switch (choice) {
            case 1: {
                std::cout << "A NEW ROUND STARTS \n";

                bool soundState = settings.getSoundEnabledDisabled().getValue();
                std::cout << "Sound on: " << soundState << "\n";
                int responsibleThreshold = settings.getBeResponsibleThreshold().getValue();
                std::cout << "Responsible threshold: " << responsibleThreshold << "\n";

                joc.startGame(settings);
                break;
            }
            case 2: {
                std::cout << "RULES\n";
                rules.displayGameRules();
                std::cout << "Press Enter to return to menu\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            case 3: {
                int settingChoice;
                do {
                    std::cout << "SETTINGS\n";
                    settings.printAllSettings();
                    std::cout << "1. Sound on / off\n";
                    std::cout << "2. Change 'Be responsible threshold'\n";
                    std::cout << "0. Back to menu\n";
                    std::cout << "Choose an option: ";
                    std::cin >> settingChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    while (std::cin.fail() || settingChoice < 0 || settingChoice > 2) {
                        std::cout << "Invalid option. Choose a number between 0 and 2\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> settingChoice;
                    }

                    if (settingChoice == 1) {
                        bool currentSound = settings.getSoundEnabledDisabled().getValue();
                        if (currentSound == 1)
                            std::cout << "Sound On / Off: On\n";
                        else
                            std::cout << "Sound On / Off: Off\n";
                        std::cout << "Type 1 for on and 0 for off: ";
                        int newStateInt;
                        std::cin >> newStateInt;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        while (std::cin.fail() || (newStateInt != 0 && newStateInt != 1)) {
                            std::cout << "Invalid input. Choose 1 for on and 0 for off: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin >> newStateInt;
                        }
                        settings.getSoundEnabledDisabled().updateValue(static_cast<bool>(newStateInt));
                        if (newStateInt == 1)
                            std::cout << "Sound is now on\n";
                        else
                            std::cout << "Sound is now off\n";
                    } else if (settingChoice == 2) {
                        int currentThreshold = settings.getBeResponsibleThreshold().getValue();
                        std::cout << "Current 'Be responsible threshold': " << currentThreshold << "\n";
                        std::cout << "New threshold: ";
                        int newThreshold;
                        std::cin >> newThreshold;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        while (std::cin.fail() || newThreshold < 0) {
                            std::cout << "Invalid input. Please choose a positive number: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin >> newThreshold;
                        }
                        settings.getBeResponsibleThreshold().updateValue(newThreshold);
                        std::cout << "'Be responsible threshold' was set at: " << newThreshold << "\n";
                    }

                } while (settingChoice != 0);
                break;
            }
            case 0:
                std::cout << "STOP\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
