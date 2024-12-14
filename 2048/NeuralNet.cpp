#include "NeuralNet.h"

double NeuralNet::activation(double x)
{
	return x;
}

NeuralNet::NeuralNet(std::vector<NeuronLayer> layers)
	: m_Layers(layers) {}

std::vector<double> NeuralNet::forward(std::vector<double> inputs)
{
	std::vector<double> intermediate;
	for (int i = 0; i < inputs.size(); i++) {
		intermediate.push_back(inputs[i]);
	}

	for (int i = 0; i < m_Layers.size(); i++) {
		intermediate = m_Layers[i].forward(intermediate);
		/*
		for (int i = 0; i < intermediate.size(); i++) {
			intermediate[i] = ReLu
		}
		*/
	}
	return intermediate;
}


