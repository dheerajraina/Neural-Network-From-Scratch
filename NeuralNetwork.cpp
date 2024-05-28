#include <iostream>
#include <vector>
#include "NeuralNetwork.h"
#include "Utils.h"

using namespace std;

NeuralNetwork::NeuralNetwork(const vector<int> &topology) : topology(topology)
{
        srand(static_cast<unsigned>(time(0)));

        // Initialize layers and biases
        for (int i = 0; i < topology.size(); ++i)
        {
                layers.push_back(vector<double>(topology[i]));
                biases.push_back(vector<double>(topology[i]));
                for (int j = 0; j < topology[i]; ++j)
                {
                        biases[i][j] = generate_random_number(-1.0, 1.0);
                }
        }

        // Initialize weights
        for (int i = 0; i < topology.size() - 1; ++i)
        {
                weights.push_back(vector<vector<double>>(topology[i], vector<double>(topology[i + 1])));
                for (int j = 0; j < topology[i]; ++j)
                {
                        for (int k = 0; k < topology[i + 1]; ++k)
                        {
                                weights[i][j][k] = generate_random_number(-1.0, 1.0);
                        }
                }
        }
}