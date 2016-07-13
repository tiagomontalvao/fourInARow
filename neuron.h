#ifndef NEURON_H
#define NEURON_H

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

#include "layer.h"

class Neuron {
public:

	double value;
	double activeValue;
	// pesos incidentes
	vector<double> weights;
	Layer* prevLayer;

	Neuron () {}
	Neuron (Layer* prevLayer);
	Neuron (Layer* prevLayer, vector<double> weights);

	void calcValue();
	void activate();
	void setWeights(vector<double> weights);

};

#endif