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

	NeuralNetwork(int numInputs, int widthLayers[], int numLayers); //Num Layers è il numero di di interi dell'array widthLayers[]

	std::vector<double> forward(std::vector<double> inputs);

};
