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
    const double DT = 0.01; // Time step

    return 0;
}