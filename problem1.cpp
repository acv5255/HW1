#include "homework1.hpp"
#include <iostream>

int main(void) {
    std::cout << "Beginning Problem 1\n";
    std::cout << "=============================\n";

    const double L_P = -0.5;        // Roll damping coefficient
    const double L_DELTA = 0.25;    // Aileron effectiveness

    const double T_START = 0.0;
    const double T_END = 5.0;
    const double DT = 0.01;     
    const double T_AIL_STOP = 2.0;  // Time when the aileron stops

    const double P_0 = 1.0;         // Initial conditions

    std::vector<double> ts = Arange(T_START, T_END, DT); // Mesh for all time points to solve equation
    std::vector<double> ps(ts.size(), 0.0);
    ps[0] = P_0;

    // This lambda function represents the Dirac Delta function shifted to the right by two seconds
    auto Dirac = [&T_AIL_STOP] (const double t) -> double {return DiracDelta(t, T_AIL_STOP);}; 

    // Differential equation representing the rolling rate
    auto p_prime = [L_P, L_DELTA, &Dirac] (const double p, const double t) {
        return L_P * p + L_DELTA * Dirac(t);
    };

    // Lambda function to determine the rolling rate at the next time step
    auto update_roll_rate = [DT, &p_prime] (const double p, const double t) {
        double p_new = p + DT * p_prime(p, t);
        return p_new;
    };

    for (int i = 1; i < ps.size(); i++) {
        ps[i] = update_roll_rate(ps[i-1], ts[i-1]);
        std::cout << "Rate at time " << ts[i] << "s: " << ps[i] << " rad/s\n";
    }

    std::cout << "=============================\n";
    std::cout << "Finished Problem 1\n";

    return 0;
}