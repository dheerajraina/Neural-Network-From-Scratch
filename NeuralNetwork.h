#ifndef NeuralNetwork_H
#define NeuralNetwork_H
#include <iostream>
#include <vector>

using namespace std;
class NeuralNetwork
{
public:
        NeuralNetwork(const vector<int> &topology);
        void train(const vector<vector<double>> &training_inputs, const vector<vector<double>> training_outputs, const int epochs, const double learning_rate);
        vector<double> predict(const vector<double> &input);
        double calculate_loss(const vector<double> &predicted, const vector<double> &actual);

private:
        vector<int> topology;
        vector<vector<vector<double>>> weights;
        vector<vector<double>> biases;
        vector<vector<double>> layers;

        void forward(const vector<double> &input);
        void backward(const vector<double> &input, const vector<double> &expected_output, double learning_rate);
};

#endif
