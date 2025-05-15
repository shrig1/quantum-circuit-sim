#include "Gates.h"
#include <cmath>
#include <iostream>
using namespace std::complex_literals;

void hadamard(Qubit& q) {
    std::cout << "------- Applying Hadamard Gate -------" << std::endl;
    std::complex<double> alpha = q.alpha;
    std::complex<double> beta = q.beta;

    q.alpha = (alpha + beta) / std::sqrt(2);
    q.beta = (alpha - beta) / std::sqrt(2);
}

void pauliX(Qubit& q) {
    std::cout << "------- Applying Pauli X Gate -------" << std::endl;
    std::swap(q.alpha, q.beta);
}

void pauliY(Qubit& q) {
    std::cout << "------- Applying Pauli Y Gate -------" << std::endl; 
    std::swap(q.alpha, q.beta);
    q.alpha *= -1.0i;
    q.beta *= 1.0i;
}

void pauliZ(Qubit& q) {
    std::cout << "------- Applying Pauli Z Gate -------" << std::endl;
    q.beta *= -1;
}

void phase(Qubit& q) {
    std::cout << "------- Applying Phase Gate -------" << std::endl;
    q.beta *= 1.0i;
}

void swap(Qubit& q1, Qubit& q2) {
    std::swap(q1, q2);
}

void t(Qubit& q) {
    std::cout << "------- Applying T Gate -------" << std::endl;
    q.beta *= std::exp(1.0i * M_PI / 4.0);
}

// Unitary gate for controlled-X (CNOT) operation
// Does matrix multiplication
void cx(Qubit& q1, Qubit& q2) {
    std::cout << "------- Applying CNOT Gate -------" << std::endl;
    // CNOT gate matrix
    std::complex<double> cnot[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}
    };
    std::complex<double> result[4] = {0, 0, 0, 0};
    std::complex<double> input[4] = {q1.alpha * q2.alpha, q1.alpha * q2.beta, q1.beta * q2.alpha, q1.beta * q2.beta};
    std::cout << "Input: " << input[0] << ", " << input[1] << ", " << input[2] << ", " << input[3] << std::endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i] += cnot[i][j] * input[j];
        }
    }

    // check if there is entanglement
    if ((result[0] * std::conj(result[0]) == 1.0) || (result[1] * std::conj(result[1]) == 1.0) ||
        (result[2] * std::conj(result[2]) == 1.0) || (result[3] * std::conj(result[3]) == 1.0)) {
        if (result[0] * std::conj(result[0]) == 1.0) {
            q1.alpha = 1;
            q1.beta = 0;
            q2.alpha = 1;
            q2.beta = 0;
        } else if (result[1] * std::conj(result[1]) == 1.0) {
            q1.alpha = 1;
            q1.beta = 0;
            q2.alpha = 0;
            q2.beta = 1;
        } else if (result[2] * std::conj(result[2]) == 1.0) {
            q1.alpha = 0;
            q1.beta = 1;
            q2.alpha = 1;
            q2.beta = 0;
        } else {
            q1.alpha = 0;
            q1.beta = 1;
            q2.alpha = 0;
            q2.beta = 1;
        }
    } else {
        std::cout << "Entangled!" << std::endl;
    }

    std::cout << "Result: " << result[0] << ", " << result[1] << ", " << result[2] << ", " << result[3] << std::endl;
}