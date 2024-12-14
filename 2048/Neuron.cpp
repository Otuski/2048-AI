#include "Neuron.h"

Neuron::Neuron(double bias, std::vector<double> weights)
	: m_Bias(bias), m_Weights(weights) {}

double Neuron::forward(std::vector<double> inputs)
{
	double sum = 0;
	for (int i = 0; i < m_Weights.size(); i++) {
		sum += inputs[i] * m_Weights[i];
	}
	return sum + m_Bias;
}
