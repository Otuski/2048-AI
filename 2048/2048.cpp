
#include "Table2048.h"

#include "NeuralNetwork.h"
#include "RobinAI.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>
static void menu();

int main() {
    
    //menu();
    Table2048 tabella;

    int layers[2] = {4, 4};
    std::vector<double> inputs = {0, 0, 0, 0};
    NeuralNetwork nn(4, layers, 2);

    std::vector<double> out = nn.forward(inputs);
    
    std::ofstream outFile("network.txt");
    nn.save(outFile);
    outFile.close();

    char f;
    std::cin >> f;
    /*
    RobinAI ai(tabella);

    char move;
    while (move = ai.move()) {
        
        ai.m_table.move(move);
        ai.m_table.print();
        std::cout << "\t\t\t\t\t" << move;
    }
    std::cout << "FINE!!";
    */
    
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
