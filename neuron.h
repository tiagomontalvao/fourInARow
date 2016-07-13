#ifndef NEURON_H
#define NEURON_H

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Neuron {
public:

	int value;

	Neuron () {}

	void getInput(int v);
	int propagate();

};

#endif