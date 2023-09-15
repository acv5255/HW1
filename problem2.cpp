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
    // Parameters
    const double K = -1.5;
    const double DT = 0.01;         // Time step
    const double L_p = 0.4;         // Roll damping coefficient
    const double L_delta = -0.5;    // Aileron effectiveness

    const double p_0 = 1.0;         // Initial conditions
    const double t_start = 0.0;
    const double t_end = 5.0;

    std::vector<double> ts = Arange(t_start, t_end, DT);
    std::vector<double> ps(ts.size(), 0.0);
    ps[0] = p_0;

    auto delta_t = [K] (double p) { return -K * p; };   // The autopilot control
    auto p_prime = [L_p, L_delta, &delta_t] (double p, double t) {
        // Lambda function representing the time derivative of the rolling rate
        return L_p * p + L_delta * delta_t(p);
    };

    auto step = [DT, &p_prime] (double p, double t) {
        const double p_new = p + DT * p_prime(p, t);
        std::cout << "Rate at time " << t << "s: " << p_new << " rad/s\n";
        return p_new;
    };

    std::cout << "Beginning simulation for problem 2\n";
    std::cout << "==================================\n\n";
    for (int i = 0; i < ps.size() -1; i++) {
        ps[i+1] = step(ps[i], ts[i]);
    }
    std::cout << "==================================\n";
    std::cout << "Finished simulation for problem 2\n";

    return 0;
}