#ifndef LAYER_H
#define LAYER_H

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Layer {
public:

	vector<Neuron> neurons;

	Layer () {}
	Layer (int n_layers);


};

#endif