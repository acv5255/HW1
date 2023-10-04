#include "homework1.hpp"
#include <iostream>



int main(void) {
    std::cout << "Beginning Problem 5\n";
    std::cout << "=============================\n";

    const double Z = 0.0176835;
    const double SIGMA_Z = 0.504421;
    const double SIGMA_PRIME_Z = 0.24998;
    const double TOLERANCE = 1e-12;

    double sigmoid_test = sigmoid(Z);
    double sigmoid_prime_test = gradient_sigmoid(Z);

    std::cout << "Sigmoid expected: " << SIGMA_Z << ", got " 
        << sigmoid(Z) << ", error = " << SIGMA_Z - sigmoid_test << "\n";

    std::cout << "Gradient Sigmoid expected: " << SIGMA_PRIME_Z << ", got " 
        << gradient_sigmoid(Z) << ", error = " << SIGMA_PRIME_Z - sigmoid_prime_test << "\n";

    std::cout << "=============================\n";
    std::cout << "Finished Problem 5\n";

    return 0;
}