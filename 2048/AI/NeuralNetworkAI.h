#pragma once

#include <string>

#include "AI.h"
#include "Table2048.h"
#include "NeuralNetwork.h"

class NeuralNetworkAI : AI
{
public:
	Table2048 m_table;
	NeuralNetwork m_network;
	double m_fitness;

	NeuralNetworkAI(const std::string& filename);
	NeuralNetworkAI(int widthLayers[], int numLayers);
	NeuralNetworkAI(NeuralNetwork network);
	NeuralNetworkAI();
	virtual char move();
};
