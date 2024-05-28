#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>

double generate_random_number(double min, double max);

// generate XOR dataset
void generate_and_store_data(const std::string &filename, int num_examples);

// Activation functions
double sigmoid(double x);

double sigmoid_derivative(double x);
#endif