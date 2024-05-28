#include "Utils.h"
#include <iostream>
#include <random>

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