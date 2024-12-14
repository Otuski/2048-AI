#include <iostream>
#include "Tabella2048.h"
#include "Neuron.h"
#include "NeuronLayer.h"
#include "NeuralNet.h"
#include <vector>
static void menu();

int main() {
    /*
    menu();
    Tabella2048 tabella;
    tabella.avviaGioco();
    */

    /*
    //test neurone
    std::vector<double> inputs = { 1, 1, 1, 1};
    std::vector<double> weights = { 0, 0, 0, 0 };
    std::cout << "inputs: " << inputs[0] << " " << inputs[1] << " " << inputs[2] << " " << inputs[3] <<"\n";
    Neurone neuron(1, weights);
    std::cout << "output: " << neuron.forward(inputs);
    */

    /*
    //test layer
    std::vector<double> inputs = { 1, 1, 1, 1 };
    std::vector<double> weights = { 0, 0, 0, 0 };

    std::vector<Neuron> neurons;
    Neuron n(1, weights);
    neurons.push_back(n);
    neurons.push_back(n);

    NeuronLayer layer(neurons);

    std::vector<double> outLayer = layer.forward(inputs);

    std::cout << "inputs: " << inputs[0] << " " << inputs[1] << " " << inputs[2] << " " << inputs[3] << "\n";
    Neuron neuron(1, {1, 1} );
    std::cout << "output: " << neuron.forward(outLayer);
    */

    //test network
    std::vector<double> inputs = { 1, 1, 1, 1 };

    std::vector<Neuron> neurons;
    Neuron n(1, {1, 1, 1, 1});
    neurons.push_back(n);
    neurons.push_back(n);
    neurons.push_back(n);
    neurons.push_back(n);

    NeuronLayer layer(neurons);

    std::vector<NeuronLayer> layers({ layer, layer});

    NeuralNet net(layers);

    std::vector<double> outLayer = net.forward(inputs);

    std::cout << "inputs: " << inputs[0] << " " << inputs[1] << " " << inputs[2] << " " << inputs[3] << "\n";
    Neuron neuron(1, { 1, 1, 1, 1});
    std::cout << "output: " << neuron.forward(outLayer);
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
