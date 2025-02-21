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

Neuron Neuron::crossover(Neuron parent)
{
    std::vector<double> weights1 = m_Weights;
    std::vector<double> weights2 = parent.m_Weights;

    std::vector<double> childWeights;
    // Per ogni peso, scegliamo casualmente da quale genitore prelevarlo
    for (int i = 0; i < weights1.size(); i++) {
        if (rand() % 2 == 0) {
            childWeights.push_back(weights1[i]);
        }
        else {
            childWeights.push_back(weights2[i]);
        }
    }
    // Per il bias, facciamo lo stesso
    double childBias = (rand() % 2 == 0) ? m_Bias : parent.m_Bias;

    return Neuron(childBias, childWeights);
}

void Neuron::save(std::ostream& out)
{
    // Salviamo prima il bias, poi il numero di pesi, e infine i pesi
    out << m_Bias << " " << m_Weights.size() << " ";
    for (double weight : m_Weights) {
        out << weight << " ";
    }
    out << "\n";
}

void Neuron::load(std::istream& in)
{
    int numWeights;
    in >> m_Bias >> numWeights;
    m_Weights.resize(numWeights);
    for (int i = 0; i < numWeights; i++) {
        in >> m_Weights[i];
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
