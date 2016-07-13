#include "neuron.h"

Neuron::Neuron(Layer* _prevLayer){
	prevLayer = _prevLayer;
	for (int i = 0; i < _prevLayer.size(); ++i)
		weights[i] = ((double) rand() / (RAND_MAX));
}

Neuron::Neuron (Layer* prevLayer, vector<double> _weights) {	
	prevLayer = _prevLayer;
	weights = _weights;
}

void Neuron::activate() {
	activeValue = 1/(1-exp(-value));
}

void Neuron::setWeights(vector<double> _weights) {
	weights = _weights;
}

void Neuron::calcValue() {
	value = 0;
	for (int i = 0; i < (*prevLayer).size(); ++i) {
		value += weights[i] * prevLayer->neurons[i].activeValue;
	}
	activate();
}
