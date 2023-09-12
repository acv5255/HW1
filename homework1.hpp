#pragma once
#include <functional>
#include <vector>

// Problem 1
std::vector<double> Linspace(double x_start, double x_end, size_t num_steps);
std::vector<double> Arange(double x_start, double x_end, double delta_x);
double DiracDelta(double t, double threshold);
std::vector<double> EulersMethod(std::function<double(double)>, std::vector<double>& ts);


// Problem 4
double dot_product(const std::vector<double>& x, const std::vector<double>& y);


// Problem 5
double sigmoid(double z);
double gradient_sigmoid(double z);

// Problem 6
double gradient_cost(double y_predict, double y);

// Problem 7
double gradient_weights(const std::vector<double>& w, const std::vector<double>& x, double y);
double update_weights(const std::vector<double>& w, const std::vector<double>& dw, double alpha);

// Problem 8