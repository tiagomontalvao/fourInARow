#ifndef NET_H
#define NET_H

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Net {
public:


	Net () {}
	Net (int n_layers);

	int outputToClass(vector<int> output);
	vector<int> ClassToOutput(int classe);

};

#endif