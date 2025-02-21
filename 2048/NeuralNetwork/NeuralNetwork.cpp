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

NeuralNetwork::NeuralNetwork(int numInputs, int widthLayers[], int numLayers)
{
	if (widthLayers == 0) { return; }
	m_Layers.push_back( NeuronLayer(numInputs, widthLayers[0]) );

	for (int i = 1; i < numLayers; i++) {
		m_Layers.push_back( NeuronLayer(widthLayers[i - 1], widthLayers[i]) );
	}
	
}

NeuralNetwork::NeuralNetwork(const std::string& filename)
{
	std::ifstream inFile(filename);
	load(inFile);
	inFile.close();
}



std::vector<double> NeuralNetwork::forward(std::vector<double> inputs) 
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

void NeuralNetwork::mutate(double mutationRate)
{
	for (NeuronLayer& layer : m_Layers) {
		layer.mutate(mutationRate);
	}
}

NeuralNetwork NeuralNetwork::crossover(NeuralNetwork parent)
{
	std::vector<NeuronLayer> result;
	for (int i = 0; i < m_Layers.size(); i++) {
		result.emplace_back(m_Layers[i].crossover(parent.m_Layers[i]));
	}
	return result;
}

void NeuralNetwork::save(std::ostream& out)
{
	out << m_Layers.size() << "\n";
	for (NeuronLayer& layer : m_Layers) {
		layer.save(out);
	}
}

void NeuralNetwork::load(std::istream& in)
{
	int numLayers;
	in >> numLayers;
	m_Layers.resize(numLayers, NeuronLayer(0, 0)); // Assicurati di avere un costruttore adeguato
	for (NeuronLayer& layer : m_Layers) {
		layer.load(in);
	}
}


