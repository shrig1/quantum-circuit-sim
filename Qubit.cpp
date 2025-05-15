#include "Qubit.h"
#include <iostream>

void printQubit(const Qubit& q) {
    std::cout << "Qubit id: " << q.id << std::endl;
    std::cout << "Alpha = " << q.alpha << std::endl; 
    std::cout << "Beta = " << q.beta << std::endl;
    std::cout << "|a|^2 = " << alphaProb(q) << std::endl;
    std::cout << "|b|^2 = " << betaProb(q) << std::endl;
}

std::complex<double> alphaProb(const Qubit& q) {
    return q.alpha * std::conj(q.alpha);
}

std::complex<double> betaProb(const Qubit& q) {
    return q.beta * std::conj(q.beta);
}