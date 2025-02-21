#pragma once

#include <vector>
#include <ostream>
#include <istream>

class Neuron
{
private:
	double m_Bias;
	std::vector<double> m_Weights;
public:
	Neuron(double bias, std::vector<double> weights);
	Neuron(int numInputs);

	double forward(std::vector<double> input);
	void mutate(double mutationRate);
	Neuron crossover(Neuron parent);

	void save(std::ostream& out);
	void load(std::istream& in);
};

