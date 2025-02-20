#include "NeuralNetworkAI.h"

NeuralNetworkAI::NeuralNetworkAI(const std::string& filename)
	: m_network(filename) {}

NeuralNetworkAI::NeuralNetworkAI(int numInputs, int widthLayers[], int numLayers)
	: m_network(numInputs, widthLayers, numLayers) {}

char NeuralNetworkAI::move()
{
	//appiattimento da matrice a vectore per metterlo in rete neurale
	std::vector<double> input;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			input.emplace_back(m_table.matrice[i][j]);
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
