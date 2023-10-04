#include <iostream>
#include "homework1.hpp"
using std::vector;

const uint32_t NUM_ITERATIONS = 500;
const double ALPHA = 0.001;             // Learning rate

const double TURBOPROP = 0.0;
const double JET = 1.0;

const vector<double> APPROACH_SPEED = { 124, 74, 103, 77, 104, 92, 130, 73 };
const vector<double> WINGSPAN = { 31.89, 51.08, 34.67, 52.00, 35.63, 56.00, 31.29, 52.00 };
const vector<double> MTOW = { 20.945, 9.170, 8.300, 9.400, 13.000, 12.500, 17.637, 9.600 };
const vector<double> ENGINE_TYPE = { JET, TURBOPROP, JET, TURBOPROP, JET, TURBOPROP, JET, TURBOPROP };


int main(void) {
    std::cout << "Beginning Problem 8\n";
    std::cout << "=============================\n";

    vector<double> w(3, 0.0001);
    double square_error = 0.0;

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        square_error = 0.0;

        for (int j = 0; j < MTOW.size(); j++) {
            const vector<double> x_j = {APPROACH_SPEED[j], WINGSPAN[j], MTOW[j]};
            const double y_j = ENGINE_TYPE[j];

            auto dw = gradient_weights(w, x_j, y_j);
            w = update_weights(w, dw, ALPHA);
            auto y_predict = sigmoid(dot_product(w,x_j));

            square_error += (y_j - y_predict) * (y_j * y_predict);
        }

        std::cout << "Mean squared error after iteration " << i + 1 << ": " << square_error / APPROACH_SPEED.size() << "\n";
    }

    std::cout << "Final weights: [" << w[0] << ", " << w[1] << ", " << w[2] << "]\n";
    std::cout << "Final mean-squared error: " << square_error / MTOW.size() << "\n";

    std::cout << "=============================\n";
    std::cout << "Finished Problem 8\n";
    return 0;
}