#ifndef GATES_H
#define GATES_H

#include "Qubit.h"

// std::complex<double>* applyGate(Qubit& q, std::complex<double>* gate);

// Single Qubit Gates 
void hadamard(Qubit& q);
void pauliX(Qubit& q);
void pauliY(Qubit& q);
void pauliZ(Qubit& q);
void phase(Qubit& q);
void t(Qubit& q);

// Double Qubit Gates 
void swap(Qubit& q1, Qubit& q2);
void cx(Qubit& c, Qubit& t);

#endif