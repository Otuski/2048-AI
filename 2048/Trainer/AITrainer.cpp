#include "AITrainer.h"

void AITrainer::createGen(int n, int widthLayers[], int numLayers)
{
	for (int i = 0; i < n; i++) {
		m_generation.emplace_back(NeuralNetworkAI(widthLayers, numLayers));
	}
}

void AITrainer::playGen(int numMatches)
{
	for (int i = 0; i < m_generation.size(); i++) {
		int sum = 0;

		for (int j = 0; j < numMatches; j++) {
			
			while (true) {
				char move = m_generation[i].move();
				m_generation[i].m_table.move(move);
				//se la mossa non è valida esci (la rete neurale è deterministica quindi non cambierebbe mai scelta)
				if (!m_generation[i].m_table.isValidMove(move)) {
					break;
				}
			}
			sum += m_generation[i].m_table.punteggio;
		}

		m_points.emplace_back(sum/numMatches);

		
	}
}

void AITrainer::selection()
{
	int max1 = m_points[0], max2 = m_points[1];
	int index1, index2;
	for (int i = 2; i < m_generation.size(); i++) {
		if (m_points[i] > max1 || m_points[i] > max2)
		{
			if (max1 <= max2) {
				max1 = m_points[i];
				index1 = i;
			}
			else {
				max2 = m_points[i];
				index2 = i;
			}
		}
	}

	//da continuare
	
	
}
