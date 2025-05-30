#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>

class Menu {
public:
    Menu();

    int displayMainMenu();

    void displayRules() const;
    void displaySettings() const;
};



#endif //MAINMENU_H
