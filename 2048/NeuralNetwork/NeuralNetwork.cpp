#include "NeuralNetwork.h"

double NeuralNetwork::activation(double x)
{
	if (x > 0){
		return x;
	}
	return 0;
}

NeuralNetwork::NeuralNetwork(std::vector<NeuronLayer> layers)
	: m_Layers(layers) {}

std::vector<double> NeuralNetwork::forward(static std::vector<double> inputs) 
{
	std::vector<double> intermediate;
	for (int i = 0; i < inputs.size(); i++) {
		intermediate.push_back(inputs[i]);
	}

	for (int i = 0; i < m_Layers.size(); i++) {
		intermediate = m_Layers[i].forward(intermediate);
		intermediate[i] = activation(intermediate[i]);
		
	}
	return intermediate;
}


