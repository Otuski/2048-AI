
#include "Table2048.h"

#include "NeuralNetwork.h"
#include "NeuralNetworkAI.h"
#include "RandomAI.h"


#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>
static void menu();

int main() {
    
    menu();
    /* per creare NU50
    int layers[4] = {16, 16, 14, 4};

    std::vector<double> inputs;
    inputs.resize(16, 0.5);

    NeuralNetwork nn(16, layers, 4);
    */
    //NeuralNetworkAI ai("Networks/NU50exemple.txt");

    RandomAI ai;

    char move;
    while (move = ai.move()) {
        
        ai.m_table.move(move);
        ai.m_table.print();
        std::cout << "\t\t\t\t\t" << move;
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
