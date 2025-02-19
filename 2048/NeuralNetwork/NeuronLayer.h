#pragma once

#include <vector>
#include "Neuron.h"

class NeuronLayer
{
private:
	std::vector<Neuron> m_Neurons;
public:
	NeuronLayer(std::vector<Neuron> neurons);
	NeuronLayer(int numInputs, int width);
	
	std::vector<double> forward(std::vector<double> inputs);
	void mutate(double mutationRate);

};

