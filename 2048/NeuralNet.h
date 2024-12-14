#pragma once
#include <vector>
#include "NeuronLayer.h"
class NeuralNet
{
private:
	std::vector<NeuronLayer> m_Layers;
	
	double activation(double x);
public:
	NeuralNet(std::vector<NeuronLayer> layers);

	std::vector<double> forward(std::vector<double> inputs);

};
