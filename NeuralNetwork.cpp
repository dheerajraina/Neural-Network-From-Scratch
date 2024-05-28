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

void NeuralNetwork::forward(const vector<double> &input)
{
        layers[0] = input;
        for (int i = 1; i < topology.size(); ++i)
        {
                for (int j = 0; j < topology[i]; ++j)
                {
                        double sum = biases[i][j];
                        for (int k = 0; k < topology[i - 1]; ++k)
                        {
                                sum += layers[i - 1][k] * weights[i - 1][k][j];
                        }
                        layers[i][j] = sigmoid(sum);
                }
        }
}

void NeuralNetwork::backward(const vector<double> &input, const vector<double> &expected_output, double learning_rate)
{
        vector<vector<double>> deltas(topology.size());

        // Output layer delta
        for (int i = 0; i < topology.back(); ++i)
        {
                double error = expected_output[i] - layers.back()[i];
                deltas.back().push_back(error * sigmoid_derivative(layers.back()[i]));
        }

        // Hidden layers delta
        for (int i = topology.size() - 2; i > 0; --i)
        {
                for (int j = 0; j < topology[i]; ++j)
                {
                        double error = 0.0;
                        for (int k = 0; k < topology[i + 1]; ++k)
                        {
                                error += deltas[i + 1][k] * weights[i][j][k];
                        }
                        deltas[i].push_back(error * sigmoid_derivative(layers[i][j]));
                }
        }

        // Update weights and biases
        for (int i = 0; i < topology.size() - 1; ++i)
        {
                for (int j = 0; j < topology[i]; ++j)
                {
                        for (int k = 0; k < topology[i + 1]; ++k)
                        {
                                weights[i][j][k] += learning_rate * deltas[i + 1][k] * layers[i][j];
                        }
                }
        }

        for (int i = 1; i < topology.size(); ++i)
        {
                for (int j = 0; j < topology[i]; ++j)
                {
                        biases[i][j] += learning_rate * deltas[i][j];
                }
        }
}
