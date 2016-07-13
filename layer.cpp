#include "layer.h"

Layer::Layer(int nNeurons, Layer* _prevLayer){
	prevLayer = _prevLayer;
	for (int i = 0; i < nNeurons; ++i) {
		neurons[i] = Neuron();
	}
}
