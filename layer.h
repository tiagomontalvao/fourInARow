#ifndef LAYER_H
#define LAYER_H

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#include "neuron.h"

class Layer {
public:

	vector<Neuron> neurons;
	int nNeurons;
	Layer* prevLayer;
	Layer () {}
	Layer (int nNeurons, prevLayer);

	void setWeights(vector<double> weights);

};

#endif