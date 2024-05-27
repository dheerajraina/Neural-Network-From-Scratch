#include "iostream"
#include <vector>
#include <cmath>
#include <cstdlib>
#include "NeuralNetwork.h"

using namespace std;

int main()
{
        cout << "Neural Network" << endl;

        vector<int> topology = {2, 4, 1}; // More complex topology with one hidden layer of 4 neurons
        NeuralNetwork nn(topology);

        return 0;
}