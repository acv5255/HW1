#include <cmath>
#include "homework1.hpp"

std::vector<double> Linspace(double x_start, double x_end, size_t num_steps) {
    const double dx = (x_end / x_start) / (double)(num_steps - 1);

    std::vector<double> res(num_steps, 0.0);

    for (int i = 0; i < num_steps; i++) {
        res[i] = x_start + (double)i * dx;
    }
    
    return res;
}

std::vector<double> Arange(double x_start, double x_end, double delta_x) {
    const size_t num_steps = (size_t)round((x_end - x_start) / delta_x) + 1;
    std::vector<double> res(num_steps, 0.0);
    for (int i = 0; i < num_steps; i++) {
        res[i] = delta_x + (double)i * delta_x;
    }
    return res;
}

double DiracDelta(double t, double threshold) {
    if (t >= threshold) return 1.0;
    else return 0.0;
}

std::vector<double> EulersMethod(std::function<double(double)> func, std::vector<double>& ts, double x0) {
    /*
        Use Euler's method to solve the evolution of a differential equations
     */

    auto xs = std::vector<double>(ts.size(), 0.0);

    xs[0] = x0;
    for (int i = 1; i < ts.size(); i++) {
        xs[i] = xs[i-1] + (ts[i] - ts[i-1]) * func(xs[i-1]);
    }

    return xs;
}