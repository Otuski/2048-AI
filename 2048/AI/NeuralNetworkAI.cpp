#include "NeuralNetworkAI.h"

#include <cmath>

NeuralNetworkAI::NeuralNetworkAI(const std::string& filename)
	: m_network(filename), m_fitness(0) {}

NeuralNetworkAI::NeuralNetworkAI(int widthLayers[], int numLayers)
	: m_network(16, widthLayers, numLayers), m_fitness(0) {}

NeuralNetworkAI::NeuralNetworkAI(NeuralNetwork network)
	:m_network(network), m_fitness(0) {}

NeuralNetworkAI::NeuralNetworkAI()
	: m_network(0, 0, 0), m_fitness(0) {}

char NeuralNetworkAI::move()
{
	//appiattimento da matrice a vectore per metterlo in rete neurale
	std::vector<double> input;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			input.emplace_back( log(m_table.matrice[i][j]) );
		}
	}

	//foreward rete neurale
	std::vector<double> output = m_network.forward(input);
	
	//trovo la mossa piu' probabile
	double max = output[0];
	int index = 0;
	for (int i = 1; i < 4; i++) {
		if (output[i] > max) {
			index = i;
			max = output[i];
		}
	}

	//conversione probabitlità in decisione
	switch(index) {
		case 0:
			return 'w';
		case 1:
			return 'a';
		case 2:
			return 's';
		case 3:
			return 'd';

	}
	return 0;
}
