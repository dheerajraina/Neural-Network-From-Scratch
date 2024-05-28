#include "iostream"
#include <vector>
#include "NeuralNetwork.h"
#include "Utils.h"

using namespace std;

int main()
{
        cout << "Neural Network" << endl;

        vector<vector<double>> training_inputs;
        vector<vector<double>> training_outputs;

        generate_and_store_data("data.csv", 10000);
        load_data("data.csv", training_inputs, training_outputs);

        vector<int> topology = {2, 4, 1}; // each element represents one layer with respective number of units (neurons)
        NeuralNetwork nn(topology);

        nn.train(training_inputs, training_outputs, 50, 0.1);
        return 0;
}