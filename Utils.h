#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>

double generate_random_number(double min, double max);

// generate XOR dataset
void generate_and_store_data(const std::string &filename, int num_examples);

// Load data from a file
void load_data(const std::string &filename, std::vector<std::vector<double>> &inputs, std::vector<std::vector<double>> &outputs);

// Activation functions
double sigmoid(double x);

double sigmoid_derivative(double x);
#endif