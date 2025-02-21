#pragma once

#include <string>

#include "NeuralNetworkAI.h"

class AITrainer {
public:
	std::vector<NeuralNetworkAI> m_generation;
	int m_generationNumber;
	std::string m_name;

	//numero reti generate, forma reti
	void createGen(std::string name, int numNetworks, int widthLayers[], int numLayers); 
	//numero di partite e salva i points il risultato medio delle partite
	void playGen(int numMatches);
	//despawna tutte le reti neurali tranne le n migliori
	void selection(int n);
	void save();
	void load(std::string nameGeneration, int generation);

	NeuralNetworkAI tournamentSelection(int tournamentSize);

};