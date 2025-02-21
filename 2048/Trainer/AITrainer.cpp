#include "AITrainer.h"

#include <fstream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <utility>

void AITrainer::createGen(std::string name, int n, int widthLayers[], int numLayers) //può diventare costruttore
{
	for (int i = 0; i < n; i++) {
		m_generation.emplace_back(NeuralNetworkAI(widthLayers, numLayers));
	}
	m_generationNumber = 1;
	m_name = name;
}

void AITrainer::playGen(int numMatches)
{
	for (int i = 0; i < m_generation.size(); i++) {
		double sum = 0;

		for (int j = 0; j < numMatches; j++) {
			
			while (true) {
				char move = m_generation[i].move();

				//se la mossa non è valida esci (la rete neurale è deterministica quindi non cambierebbe mai scelta)
				if (!m_generation[i].m_table.isValidMove(move)) {
					break;
				}
				m_generation[i].m_table.move(move);
			}
			m_generation[i].m_fitness += m_generation[i].m_table.punteggio;
			m_generation[i].m_table = Table2048();
		}

		m_generation[i].m_fitness /= (double)numMatches;

		
	}
}

// Seleziona i migliori n individui
void AITrainer::selection(int n) {
	// Controlla che n non superi la dimensione della generazione
	if (n > m_generation.size())
		n = m_generation.size();

	// Crea un vettore di coppie (fitness, indice)
	std::vector<std::pair<double, int>> fitnessIndex;
	for (int i = 0; i < m_generation.size(); ++i) {
		fitnessIndex.emplace_back(m_generation[i].m_fitness, i);
	}

	// Ordina le coppie in ordine decrescente in base al fitness
	std::sort(fitnessIndex.begin(), fitnessIndex.end(),
		[](const std::pair<double, int>& a, const std::pair<double, int>& b) {
			return a.first > b.first;
		});

	// Preleva i primi n indici (le reti migliori)
	std::vector<NeuralNetworkAI> bests;
	std::vector<double> bestPoints;
	for (int i = 0; i < n; ++i) {
		int idx = fitnessIndex[i].second;
		bests.push_back(m_generation[idx]);
	}

	// Aggiorna la generazione e i relativi punteggi con i migliori selezionati
	m_generation = bests;
}


void AITrainer::save()
{
	for (int i = 0; i < m_generation.size(); i++) {

		// Costruisci il nome del file: "gen_<numeroGenerazione>_net_<indice>.txt"
		std::ostringstream filename;
		filename << "Networks/" << m_name << "_" << "gen_" << m_generationNumber << "_net_" << (i + 1) << ".txt";

		std::ofstream file(filename.str());
		m_generation[i].m_network.save(file);
	}
}


void AITrainer::load(std::string name, int generation)
{
	m_name = name;
	m_generationNumber = generation;
	m_generation.clear();  // Assicurati di svuotare la generazione corrente

	int index = 1;
	while (true) {
		std::ostringstream filename;
		filename << "Networks/" << m_name << "_gen_" << generation << "_net_" << index << ".txt";

		std::ifstream file(filename.str());
		if (!file.is_open()) {
			// Non esiste un file con questo indice: esci dal ciclo
			break;
		}

		NeuralNetworkAI network;
		network.m_network.load(file);
		m_generation.push_back(network);

		++index;
	}
}

NeuralNetworkAI AITrainer::tournamentSelection(int tournamentSize) {

	NeuralNetworkAI best;
	bool inizializzato = false;
	for (int i = 0; i < tournamentSize; i++) {
		int idx = rand() % m_generation.size();
		if (!inizializzato || m_generation[idx].m_fitness > best.m_fitness) {
			best = m_generation[idx];
			inizializzato = true;
		}
	}
	return best;
}

void AITrainer::crossoverTournament(int childrens, int tournamentSize) {
	for (int i = 0; i < childrens; i++) {
		NeuralNetworkAI children(tournamentSelection(tournamentSize).m_network.crossover(tournamentSelection(tournamentSize).m_network));
		m_generation.emplace_back(children);
	}
}

void AITrainer::evolve(int gens, int numMatches, int elits, int childrens, int tournamentSize)
{
	for (int i = 0; i < gens; i++) {
		
		playGen(numMatches);
		selection(elits);
		crossoverTournament(childrens, tournamentSize);
	}
}
