#include "iostream"
#include <vector>
#include "NeuralNetwork.h"
#include "Utils.h"

using namespace std;

int main()
{
        cout << "Neural Network" << endl;

        vector<int> topology = {2, 4, 1}; // More complex topology with one hidden layer of 4 neurons
        NeuralNetwork nn(topology);

        vector<vector<double>> training_inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        vector<vector<double>> training_outputs = {{0}, {1}, {1}, {0}};

        nn.train(training_inputs, training_outputs, 1000, 0.1);
        return 0;
}