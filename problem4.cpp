/*
    Write a function named "dot_product" that computes
    the dot product between two vectors of an arbitrary size
 */
#include "homework1.hpp"
#include <iostream>
#include <cmath>

using std::vector;

int main(void) {
    std::cout << "Beginning Problem 4\n";
    std::cout << "=============================\n";

    const vector<double> w(3,0.0001);
    const vector<double> x = {124.0, 31.89, 20.945};
    const double z = 0.0176835;
    const double TOLERANCE = 1e-15;

    const double dot_val = dot_product(w,x);

    // Check to make sure the values are close
    const double err = std::abs(dot_val - z);
    std::cout << "Computed dot product = " << dot_val << ", expected " << z << "\n";

    if (err < TOLERANCE) std::cout << "Function 'dot_product' correctly computed the dot product\n";
    else std::cout << "Function 'dot_product' failed to compute the dot product\n";

    std::cout << "=============================\n";
    std::cout << "Finished Problem 4\n";
}