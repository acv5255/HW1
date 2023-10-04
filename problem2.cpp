/*
    Instead of letting the pilot control the aircraft, we 
    implement an autopilot with a feedback control law using 
    the following equation:
                    delta_t = - K * p_t
    As an aerospace engineer, we are to design the feedback 
    control gain, K in [-3,3].

    With dt = 0.01 and this feedback control law, write a program
    to predict the roll rate of the aircraft up to 5 seconds
    and print out  the result at every time step.
 */

#include "homework1.hpp"
#include <iostream>

int main(void) {
    std::cout << "Beginning Problem 2\n";
    std::cout << "=============================\n";
    // Parameters
    const double K = 1.5;
    const double DT = 0.01;         // Time step
    const double L_p = 0.1;         // Roll damping coefficient
    const double L_delta = 1.0;    // Aileron effectiveness

    const double P_0 = 1.0;         // Initial conditions
    const double T_START = 0.0;
    const double T_END = 5.0;

    std::vector<double> ts = Arange(T_START, T_END, DT);
    std::vector<double> ps(ts.size(), 0.0);
    ps[0] = P_0;

    auto delta_t = [&K] (double p) { return -K * p; };   // The autopilot control
    auto p_prime = [&L_p, &L_delta, &delta_t] (double p) {
        // Lambda function representing the time derivative of the rolling rate
        return L_p * p + L_delta * delta_t(p);
    };

    // Lambda function to update the rolling rate using previously-defined lambda functions
    auto update_roll_rate = [&DT, &p_prime] (double p) {
        return p + DT * p_prime(p);
    };

    
    for (int i = 1; i < ps.size(); i++) {
        ps[i] = update_roll_rate(ps[i-1]);
        std::cout << "Rate at time " << ts[i] << "s: " << ps[i] << " rad/s\n";
    }

    std::cout << "=============================\n";
    std::cout << "Finished Problem 2\n";

    return 0;
}