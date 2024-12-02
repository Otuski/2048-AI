#include <iostream>
#include <cstdlib>
#include "Tabella2048.h"

void menu();
bool nextTurn(int table[4][4]);
char processInput();

int main() {
    /*
    menu();

    int table[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            table[i][j] = 0;
        }
    }
    
    nextTurn(table);

    while (true) {
        nextTurn(table);
        clearScreen();
        printTable(table);
        char letter = processInput();//DA FARE: bisogna anche verificare la validità della mossa

        switch (letter) {
        case 'A':
        case 'a':
            moveA(table);
            break;
        case 'W':
        case 'w':
            moveW(table);
            break;
        case 'S':
        case 's':
            moveS(table);
            break;
        case 'D':
        case 'd':
            moveD(table);
        }
            
    }
    */

    Tabella2048 tabella;
    tabella.avviaGioco();
    

    
}

/*void menu() {
    std::cout << "\n\t\t\t\t\t=============== 2048 ===============\n\n";
    std::cout << "\t\t\t\t\tWELCOME TO PUZZLE 2048\n";
    std::cout << "\t\t\t\t\t> CONTROLS\n";
    std::cout << "\t\t\t\t\t  FOR MOVES: 'W', 'S', 'A', 'D'\n";
    std::cout << "\t\t\t\t\t  GO BACKWARD: 'P'\n";
    std::cout << "\t\t\t\t\t  RESTART THE GAME: 'R'\n";
    std::cout << "\t\t\t\t\t  EXIT: 'U'\n";
    std::cout << "\n\t\t\t\t\tPRESS ANY KEY TO START THE GAME....\n";
    processInput();
    clearScreen();
}*/

/*bool nextTurn(int matrice[4][4]) {
    // Trova le posizioni degli zeri nella matrice
    int posizioniZero[16][2]; // Al massimo ci sono 16 posizioni per una matrice 4x4
    int conteggioZero = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrice[i][j] == 0) {
                posizioniZero[conteggioZero][0] = i;
                posizioniZero[conteggioZero][1] = j;
                ++conteggioZero;
            }
        }
    }

    // Se non ci sono zeri, ritorna falso
    if (conteggioZero == 0) {
        return false;
    }

    // Scegli una posizione casuale tra quelle degli zeri
    std::srand(unsigned int(std::time(nullptr))); // Inizializza il generatore di numeri casuali
    int indiceCasuale = std::rand() % conteggioZero;

    int i = posizioniZero[indiceCasuale][0];
    int j = posizioniZero[indiceCasuale][1];

    // Imposta la posizione scelta a 2
    matrice[i][j] = 2;

    return true;
}

char processInput() {
    std::string input;
    std::cout << "\t\t\t\t\t";
    std::cin >> input;

    // Verifica che l'input non sia vuoto
    if (input.empty()) {
        std::cout << "Input non valido: stringa vuota.\n";
        return 'n';
    }

    // Prendi il primo carattere della stringa
    return input[0];
}
*/
