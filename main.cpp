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

        vector<vector<double>> training_inputs;
        vector<vector<double>> training_outputs;

        generate_and_store_data("data.csv", 10);

        // nn.train(training_inputs, training_outputs, 50, 0.1);
        return 0;
}