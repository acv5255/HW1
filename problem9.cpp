#include <iostream>
#include <cmath>
#include "homework1.hpp"

using std::vector;

const double TURBOPROP = 0.0;
const double JET = 1.0;

const vector<double> APPROACH_SPEED = { 87, 79, 92, 91 };
const vector<double> WINGSPAN = { 38.67, 52.08, 33.75, 59.25 };
const vector<double> MTOW = { 6.000, 8.000, 7.804, 16.000 };
const vector<double> ENGINE_TYPE = { JET, TURBOPROP, JET, TURBOPROP };  // Entries come from database

int main(void) {
    std::cout << "Beginning Problem 9\n";
    std::cout << "=============================\n";

    const vector<double> w = { 0.123466, -0.261987, -0.00346777 };      // Weights were determined in problem 8
    vector<double> y_predict(APPROACH_SPEED.size(), -9999.0);

    // Make the predictions
    for (int i = 0; i < APPROACH_SPEED.size(); i++) {
        vector<double> x_i = {APPROACH_SPEED[i], WINGSPAN[i], MTOW[i]};
        y_predict[i] = std::round(sigmoid(dot_product(w, x_i)));
    }
    std::cout << "\nPredictions: \n";
    std::cout << "----------------\n";

    // Calculate the number of correct
    double num_correct = 0.0;
    for (int i = 0; i < y_predict.size(); i++) {
        std::cout << "Predicted: " << y_predict[i] << ", expected " << ENGINE_TYPE[i] << "\n";
        num_correct += 1.0 - std::abs(y_predict[i] - ENGINE_TYPE[i]);
    }

    int accuracy = 100 * (int)round(num_correct / ENGINE_TYPE.size());

    std::cout << "\nAccuracy of my neural network: " << accuracy << "%\n\n";

    std::cout << "=============================\n";
    std::cout << "Finished Problem 9\n";

    return 0;
}
