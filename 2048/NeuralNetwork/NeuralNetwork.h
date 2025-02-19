 #pragma once

#include <vector>
#include "NeuronLayer.h"

class NeuralNetwork
{
private:
	std::vector<NeuronLayer> m_Layers;
	
	double activation(double x);
public:
	NeuralNetwork(std::vector<NeuronLayer> layers);

	std::vector<double> forward(std::vector<double> inputs);

};
