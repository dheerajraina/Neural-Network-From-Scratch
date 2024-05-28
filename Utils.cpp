#include "Utils.h"
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;
double generate_random_number(double min, double max)
{

        // Initialize a random number generator with a random device
        random_device rd;
        mt19937 gen(rd());

        // Define a distribution to generate doubles between min and max
        uniform_real_distribution<> dis(min, max);

        // Generate and return a random double
        return dis(gen);
}

double sigmoid(double x)
{
        return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x)
{
        return x * (1.0 - x);
}

void generate_and_store_data(const string &filename, int num_examples)
{
        ofstream file(filename);
        if (!file.is_open())
        {
                cerr << "Unable to open file for writing!" << endl;
                return;
        }

        srand(time(0));
        for (int i = 0; i < num_examples; ++i)
        {
                int input1 = rand() % 2;
                int input2 = rand() % 2;
                int output = input1 ^ input2;
                file << input1 << "," << input2 << "," << output << "\n";
        }

        file.close();
        cout << "Data generated and stored in " << filename << endl;
}
