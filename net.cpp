#include "net.h"

Net::Net(vector<int> neuronsPerLayer) {
	nLayers = neuronsPerLayer.size();
	layers.resize(nLayers);
	for (int i = 0; i < neuronsPerLayer.size(); ++i) {
		layers[i] = Layer(neuronsPerLayer[i]);
	}
}

int Net::outputToClass(vector<int> output) {
	for (int i = 0; i < (int) output.size(); i++)
		if (output[i] == 1)
			return i+1;
	return -1; // ERRO
}

vector<int> Net::ClassToOutput(int classe) {
	// mudar pra Ncols
	vector<int> output(7, 0);
	output[classe-1] = 1;
	return output;
}

void Net::readInput(string fileName){
	strining file = "";
	for (int i = 0; i < 42; ++i) { //Trocar 42 por Ncols * Nrows
		layers[0].setNeuronValue(i, file[i]-'0');
	}
}