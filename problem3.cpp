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

int main(void) {
    return 0;
}