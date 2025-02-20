#pragma once

#include "NeuralNetworkAI.h"

class AITrainer {
public:
	std::vector<NeuralNetworkAI> m_generation;
	std::vector<int> m_points;

	//numero reti generate, forma reti
	void createGen(int numNetworks, int widthLayers[], int numLayers); 
	//numero di partite e salva i points il risultato medio delle partite
	void playGen(int numMatches);
	//despawna tutte le reti neurali tranne le 2 migliori
	void selection();
};