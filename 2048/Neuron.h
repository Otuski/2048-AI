#pragma once

#include <vector>
class Neuron //potrebbe tranquillamente essere una struct
{
private:
	double m_Bias;
	std::vector<double> m_Weights;
public:
	Neuron(double bias, std::vector<double> weights);

	double forward(std::vector<double> input);
};

