#include "homework1.hpp"
#include <iostream>
#include <numeric>  // For acces to std::reduce
using std::vector;


int main(void) {
    std::cout << "Beginning Problem 7\n";
    std::cout << "=============================\n";

    const double Y = 1.0;
    const vector<double> W = { 0.0001, 0.0001, 0.0001 };
    const vector<double> X = {124.0, 31.89, 20.945};
    const double ALPHA = 0.001;
    const vector<double> DW = {-30.7235, -7.90136, -5.1855};
    const vector<double> W_UPDATED = {0.0308235, 0.00800139, 0.00528955};

    vector<double> dw_computed = gradient_weights(W, X, Y);
    vector<double> w_upd_computed = update_weights(W, dw_computed, ALPHA);

    // Compute the error
    vector<double> dw_err(dw_computed.size(), 10000.0);         // Initialize errors as huge
    vector<double> w_upd_err(w_upd_computed.size(), 10000.0);

    std::cout << "Gradient of weights: [ ";
    for (int i = 0; i < W.size(); i++) {
        std::cout << dw_computed[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "Updated Weights: [ ";
    for (int i = 0; i < W.size(); i++) {
        std::cout << w_upd_computed[i] << " ";
    }
    std::cout << "]\n";

    for (int i = 0; i < dw_computed.size(); i++) {
        dw_err[i] = DW[i] - dw_computed[i];
        w_upd_err[i] = W_UPDATED[i] - w_upd_computed[i];
    }   

    // Determine the maximum absolute value of all the errors
    double max_dw_err = std::reduce(
        dw_err.cbegin(),
        dw_err.cend(),
        0.0,
        [] (const double x, const double y) {
            return std::max(std::abs(x), std::abs(y));
        }
    );

    // Determine the maximum absolute value of all the errors
    double max_w_upd_err = std::reduce(
        w_upd_err.cbegin(),
        w_upd_err.cend(),
        0.0,
        [] (const double x, const double y) {
            return std::max(std::abs(x), std::abs(y));
        }
    );

    std::cout << "Magnitude of maximum error in gradient of weights: " << max_dw_err << "\n";
    std::cout << "Magnitude of maximum error in updated weights: " << max_w_upd_err << "\n";

    std::cout << "=============================\n";
    std::cout << "Finished Problem 7\n";

    return 0;
}