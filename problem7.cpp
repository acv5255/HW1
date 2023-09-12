#include "homework1.hpp"
#include <iostream>
using std::vector;

const double Y = 1.0;
const vector<double> W = { 0.0001, 0.0001, 0.0001 };
const vector<double> X = {124.0, 31.89, 20.945};
const double ALPHA = 0.001;
const vector<double> DW = {-30.7235, -7.90136, -5.1855};
const vector<double> W_UPDATED = {0.0308235, 0.00800139, 0.00528955};

int main(void) {
    vector<double> dw_computed = gradient_weights(W, X, Y);
    vector<double> w_upd_computed = update_weights(W, dw_computed, ALPHA);
    return 0;
}