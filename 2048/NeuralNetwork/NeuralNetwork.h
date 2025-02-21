 #pragma once

#include <vector>
#include <string>
#include <fstream>
#include "NeuronLayer.h"

class NeuralNetwork
{
private:
	std::vector<NeuronLayer> m_Layers;
	
	double activation(double x);
public:
	NeuralNetwork(std::vector<NeuronLayer> layers);
	NeuralNetwork(int numInputs, int widthLayers[], int numLayers); //Num Layers è il numero di di interi dell'array widthLayers[]
	NeuralNetwork(const std::string& filename);

	std::vector<double> forward(std::vector<double> inputs);
	void mutate(double mutationRate);
	NeuralNetwork crossover(NeuralNetwork parent);

	void save(std::ostream& out);
	void load(std::istream& in);

};
