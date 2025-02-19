#include "NeuronLayer.h"

NeuronLayer::NeuronLayer(std::vector<Neuron> neurons)
	:m_Neurons(neurons) {}

std::vector<double> NeuronLayer::forward(std::vector<double> inputs)
{
	std::vector<double> output;
	for (int i = 0; i < m_Neurons.size(); i++) {
		output.emplace_back( m_Neurons[i].forward(inputs) );
	}
	return output;
}

