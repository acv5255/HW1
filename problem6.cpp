#include "homework1.hpp"
#include <iostream>

const double Y = 1.0;
const double Y_PREDICT = 0.504421;
const double DC_EXPECTED = -0.991158;

int main(void) {
    std::cout << "===== Problem 6 =====\n";

    double dc = gradient_cost(Y_PREDICT, Y);

    std::cout << "Predicted dC = " << DC_EXPECTED << std::endl;
    std::cout << "Computed dC = " << dc << std::endl;
    std::cout << "Error: " << DC_EXPECTED - dc << std::endl;

    return 0;
}