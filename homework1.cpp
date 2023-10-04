#include <cmath>
#include "homework1.hpp"
using std::vector;

vector<double> Linspace(double x_start, double x_end, size_t num_steps) {
    const double dx = (x_end / x_start) / (double)(num_steps - 1);

    std::vector<double> res(num_steps, 0.0);

    for (int i = 0; i < num_steps; i++) {
        res[i] = x_start + (double)i * dx;
    }
    
    return res;
}

vector<double> Arange(double x_start, double x_end, double delta_x) {
    const size_t num_steps = (size_t)round((x_end - x_start) / delta_x) + 1;
    std::vector<double> res(num_steps, 0.0);
    for (int i = 0; i < num_steps; i++) {
        res[i] = x_start + (double)i * delta_x;
    }
    return res;
}

double DiracDelta(double t, double threshold) {
    if (t >= threshold) return 1.0;
    else return 0.0;
}


// Problem 4
double dot_product(const vector<double>& x, const vector<double>& y) {
    double dot_prod = 0.0;

    for (int i = 0; i < x.size(); i++) {
        dot_prod += x[i] * y[i];
    }

    return dot_prod;
}


// Problem 5
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

double gradient_sigmoid(double z) {
    return sigmoid(z) * (1.0 - sigmoid(z));
}


// Problem 6
double gradient_cost(double y_predict, double y) {
    return 2 * (y_predict - y);
}


// Problem 7
vector<double> gradient_weights(const vector<double>& w, const vector<double>& x, double y) {
    vector<double> dw;

    double w_dot_x = dot_product(w,x);
    double y_predict = sigmoid(w_dot_x);

    for (auto x_i: x) {
        dw.push_back(
            gradient_cost(y_predict, y) * gradient_sigmoid(w_dot_x) * x_i
        );
    }

    return dw;
}

vector<double> update_weights(const std::vector<double>& w, const std::vector<double>& dw, double alpha) {
    vector<double> w_new(w.size(), 0.0);

    for (int i = 0; i < w.size(); i++) {
        w_new[i] = w[i] - alpha * dw[i];
    }

    return w_new;
}