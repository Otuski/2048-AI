#include "Neuron.h"
#include <random>

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

void Neuron::mutate(double mutationRate)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);
    m_Bias += dis(gen)*mutationRate;

    for (double& weight : m_Weights) {
        weight += dis(gen)*mutationRate;
    }
}

Neuron::Neuron(int numInputs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);
    m_Bias = dis(gen);
    m_Weights.resize(numInputs);

    for (double& weight : m_Weights) {
        weight = dis(gen);
    }
}
