#include "net.h"

Net::Net(int n_layers) {

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