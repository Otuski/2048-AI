#include <iostream>
#include "Tabella2048.h"
#include "Neuron.h"
#include "NeuronLayer.h"
#include "NeuralNet.h"
#include "RandomAI.cpp"
#include <vector>
#include <windows.h>
static void menu();

int main() {
    
    menu();
    Tabella2048 tabella;
    RandomAI ai(tabella);
    tabella.stampa();
    int tempo = 0, scorso_punteggio = 0;
    while (true) {
        //Sleep(100);
        ai.move();
        if (ai.m_table.punteggio == scorso_punteggio) {
            tempo++;
        }
        else {
            tempo = 0;
        }
        if (tempo == 20)
            break;
        scorso_punteggio = ai.m_table.punteggio;
        std::cout << "TEMPOOOOOOO:" << tempo;
    }
    std::cout << "FINE!!";
    
}

static void menu() {
    std::cout << "\n\t\t\t\t\t=============== 2048 ===============\n\n";
    std::cout << "\t\t\t\t\tWELCOME TO PUZZLE 2048\n";
    std::cout << "\t\t\t\t\t> CONTROLS\n";
    std::cout << "\t\t\t\t\t  FOR MOVES: 'W', 'S', 'A', 'D'\n";
    std::cout << "\t\t\t\t\t  GO BACKWARD: 'P'\n";
    std::cout << "\t\t\t\t\t  RESTART THE GAME: 'R'\n";
    std::cout << "\t\t\t\t\t  EXIT: 'U'\n";
    std::cout << "\n\t\t\t\t\tPRESS ANY KEY TO START THE GAME....\n";
    std::string input;
    std::cin >> input;
    system("cls");
}
