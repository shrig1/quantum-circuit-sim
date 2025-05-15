#ifndef QUBIT_H
#define QUBIT_H

#include <complex>

struct Qubit {
    int id;                      // Qubit ID Value
    std::complex<double> alpha;  // Amplitude for |0〉
    std::complex<double> beta;   // Amplitude for |1〉

    Qubit(int id, std::complex<double> a, std::complex<double> b): id(id), alpha(a), beta(b) {}
};

void printQubit(const Qubit& q);
std::complex<double> alphaProb(const Qubit& q);
std::complex<double> betaProb(const Qubit& q);

#endif