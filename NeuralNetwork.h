#ifndef NeuralNetwork_H
#define NeuralNetwork_H
#include <iostream>
#include <vector>

class NeuralNetwork
{
public:
        NeuralNetwork(const std::vector<int> &topology);
        void train(const std::vector<std::vector<double>> &training_inputs,
                   const std::vector<std::vector<double>> &training_outputs, int epochs, double learning_rate);
        std::vector<double> predict(const std::vector<double> &input);
        double calculate_loss(const std::vector<double> &predicted, const std::vector<double> &actual);

private:
        std::vector<int> topology;
        std::vector<std::vector<std::vector<double>>> weights;
        std::vector<std::vector<double>> biases;
        std::vector<std::vector<double>> layers;

        void forward(const std::vector<double> &input);
        void backward(const std::vector<double> &input, const std::vector<double> &expected_output, double learning_rate);
};

#endif
