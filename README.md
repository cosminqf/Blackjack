# Proiect Blackjack în C++

Acest proiect implementează o versiune simplă a jocului de cărți Blackjack în C++, cu o interfață bazată pe consolă. Utilizatorul poate interacționa cu jocul, vizualiza regulile și modifica anumite setări.

## Caracteristici Principale

* **Meniu Interactiv:** Navigare ușoară între opțiuni: Start Joc, Vezi Regulile, Setări, Ieșire.
* **Joc Blackjack:** Logica de bază include gestionarea cărților și a pachetului, turele jucătorului și ale dealerului, calculul scorului și determinarea câștigătorului.
* **Sistem de Pariere:** Jucătorul poate plasa pariuri, iar balanța sa este actualizată în funcție de rezultatul rundei.
* **Reguli de Joc:** Afișarea unui set de reguli simple direct în consolă.
* **Setări Configurabile:** Poți activa/dezactiva sunetul (simulat) și poți seta un prag de "Fii Responsabil" pentru balanța jucătorului. Jocul se va opri automat dacă balanța scade sub acest prag.

## Structura Proiectului

Proiectul este organizat în mai multe clase pentru o bună separare a responsabilităților:

* `ConfigOption`: Un șablon de clasă pentru opțiuni configurabile.
* `Settings`: Gestionează setările jocului.
* `Rules`: Conține și afișează regulile jocului.
* `Card`: Reprezintă o carte de joc.
* `Deck`: Gestionează pachetul de cărți (amestecare, împărțire).
* `Player`: Gestionează mâna, balanța și pariurile jucătorului.
* `Dealer`: Gestionează mâna dealerului.
* `Game`: Orchesrează logica principală a jocului (runde, câștigători).
* `main.cpp`: Punctul de intrare, gestionează meniul principal și instanțiază `Game`, `Settings` și `Rules`.

## Cum să Compilezi și să Rulezi

Pentru a compila și rula acest proiect, vei avea nevoie de un compilator C++ (cum ar fi GCC sau Clang).

1.  **Clonează Repozitoriul:**
    ```bash
    git clone [https://github.com/cosminqf/Blackjack.git](https://github.com/cosminqf/Blackjack.git)
    cd Blackjack
    ```

2.  **Compilează:**
    Asigură-te că toate fișierele `.h` și `.cpp` sunt în același director sau că ai configurat corect căile de includere.
    ```bash
    g++ -o blackjack main.cpp Game.cpp Settings.cpp Rules.cpp Card.cpp Deck.cpp Player.cpp Dealer.cpp -std=c++11
    ```

3.  **Rulează:**
    ```bash
    ./blackjack
    ```

## Utilizare

La pornire, vei vedea meniul principal:

MENU
1. Start Game
2. View Rules
3. Settings
0. Exit
Choose an option:

* **1. Start Game**: Începe o nouă sesiune de Blackjack. Jocul va continua până când decizi să ieși sau balanța ta scade sub pragul de responsabilitate.
* **2. View Rules**: Afișează un set de reguli predefinite.
* **3. Settings**: Accesează meniul de setări unde poți schimba starea sunetului și pragul "Fii Responsabil".
* **0. Exit**: Închide aplicația.

