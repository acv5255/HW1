#include "homework1.hpp"
#include <iostream>

int main(void) {
    const double L_p = -0.5;
    const double L_delta = 0.25;

    const double t_start = 0.0;
    const double t_end = 5.0;
    const double delta_t = 0.01;
    const double t_ail_stop = 2.0;

    const double p_0 = 1.0;

    std::vector<double> ts = Arange(t_start, t_end, delta_t);
    std::cout << "ts[0]: " << ts[0] << "\n";
    std::cout << "len(ts): " << ts.size() << "\n";
    std::vector<double> ps(ts.size(), 0.0);
    ps[0] = p_0;

    auto Dirac = [t_ail_stop] (const double t) -> double {return DiracDelta(t, t_ail_stop);};

    auto p_prime = [L_p, L_delta, &Dirac] (const double p, const double t) {
        return L_p * p + L_delta * Dirac(t);
    };

    auto step = [delta_t, &p_prime] (const double p, const double t) {
        double p_new = p + delta_t * p_prime(p, t);
        std::cout << "Rate at time " << t << "s: " << p_new << " rad/s\n";
        return p_new;
    };

    std::cout << "Beginning simulation for problem 1\n";
    std::cout << "==================================\n\n";
    for (int i = 0; i < ps.size() -1; i++) {
        ps[i+1] = step(ps[i], ts[i]);
    }
    std::cout << "==================================\n";
    std::cout << "Finished simulation for problem 1\n";


    return 0;
}