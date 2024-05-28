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

        // generate_and_store_data("data.csv", 10000);
        load_data("data.csv", training_inputs, training_outputs);

        vector<int> topology = {2, 32, 32, 1}; // each element represents one layer with respective number of units (neurons)
        NeuralNetwork nn(topology);

        nn.train(training_inputs, training_outputs, 80, 0.1);

        for (const auto &input : training_inputs)
        {
                std::vector<double> output = nn.predict(input);
                std::cout << "Input: " << input[0] << " " << input[1] << " -> Output: " << output[0] << std::endl;
        }
        return 0;
}