/*
    Instead of using a constant gain, K, we allow K
    to change at every time step. Then, the control law
    is changed as follows:
                delta_t = -K_t * p_t
                K_{t+1} = K_t + alpha * p_t^2
    Where alpha is an adaptive rate, which you can pick
    any non-zero real number within an interval of [-2,2].
    Pick any real number within an interval of [-3,3] for K_0

    With dt=0.01s and this new feedback control law, write a 
    program to predict the roll rate of the aircraft up to 5
    seconds and print out the result at each time step
 */

#include "homework1.hpp"
#include <iostream>
#include <tuple>

using std::tuple;


int main(void) {
    std::cout << "Beginning Problem 3\n";
    std::cout << "=============================\n";

    double K = -1.5;
    const double L_p = 0.4;         // Roll damping coefficient
    const double L_delta = -0.5;    // Aileron effectiveness
    const double ALPHA = -1;        // Adaptive rate
    const double K_0 = 2.0;         // Initial gain constant
    const double DT = 0.01;         // Time step fo 0.01 seconds
    const double T_START = 0.0;
    const double T_END = 5.0;
    std::vector<double> ts = Arange(T_START, T_END, DT);

    // Initial conditions
    const double P_0 = 1.0;
    std::vector<double> ps(ts.size(), 0.0);
    ps[0] = P_0;

    auto update_K = [ALPHA] (double K, double p) { return K + ALPHA * p * p;};
    auto delta_t = [] (double K, double p) { return -K * p; };   // The autopilot control

    // Lambda function to update the rolling rate. This function returns a tuple because both rolling rate
    // and feedback control gain are updated at each time step
    auto update_roll_rate = [&update_K, &delta_t, L_p, L_delta] (double K, double p) {
        double K_new = update_K(K, p);
        double p_new = p + (L_p * p + L_delta * delta_t(K,p));

        return tuple<double,double>(K_new, p_new);
    };


    
    for (int i = 1; i < ts.size(); i++) {
        auto[K_new, p_new] = update_roll_rate(K, ps[i-1]);
        K = K_new;
        ps[i] = p_new;

        std::cout << "Rate at time t=" << ts[i] << " = " << p_new << " rad/s\n";
    }
    std::cout << "=============================\n";
    std::cout << "Finished Problem 3\n";

    return 0;
}