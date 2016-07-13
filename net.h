#ifndef NET_H
#define NET_H

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#include "layer.h" 

class Net {
public:

    int nLayers;
	vector<Layer> layers;
    vector<vector<int>> trainingSet;
    vector<vector<int>> validationSet;
    Net () {}
	Net (vector<int> neuronsPerLayer);

	int outputToClass(vector<int> output);
	vector<int> ClassToOutput(int classe);

	void initWeights();
    void readFile(string fileName, int mode);
	void train();
	double validation();

};

#endif