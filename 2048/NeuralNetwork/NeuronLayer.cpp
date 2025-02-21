#include "NeuronLayer.h"

NeuronLayer::NeuronLayer(std::vector<Neuron> neurons)
	:m_Neurons(neurons) {}

NeuronLayer::NeuronLayer(int numInputs, int width)
{
	for (int i = 0; i < width; i++) {
		m_Neurons.push_back(Neuron(numInputs));
	}
}

std::vector<double> NeuronLayer::forward(std::vector<double> inputs)
{
	std::vector<double> output;
	for (int i = 0; i < m_Neurons.size(); i++) {
		output.emplace_back( m_Neurons[i].forward(inputs) );
	}
	return output;
}

void NeuronLayer::mutate(double mutationRate)
{
	for (Neuron& neuron : m_Neurons) {
		neuron.mutate(mutationRate);
	}
}

NeuronLayer NeuronLayer::crossover(NeuronLayer parent)
{
	std::vector<Neuron> result;
	for (int i = 0; i < m_Neurons.size(); i++) {
		result.emplace_back(m_Neurons[i].crossover(parent.m_Neurons[i]));
	}
	return result;
}

void NeuronLayer::save(std::ostream& out)
{
	out << m_Neurons.size() << "\n";
	for (Neuron& neuron : m_Neurons) {
		neuron.save(out);
	}
}

void NeuronLayer::load(std::istream& in)
{
	int numNeurons;
	in >> numNeurons;
	m_Neurons.resize(numNeurons, Neuron(0)); // Assicurati di avere un costruttore adeguato
	for (Neuron& neuron : m_Neurons) {
		neuron.load(in);
	}
}

