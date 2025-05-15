#include <iostream>
#include <cmath>
#include <complex>
#include "Qubit.h"
#include "Gates.h"
using namespace std::complex_literals;


int main() {
    Qubit* q1 = new Qubit(1, 0, 1);
    Qubit* q2 = new Qubit(2, 1, 0);

    std::cout << "Initial Qubits:" << std::endl;
    printQubit(*q1);
    // printQubit(*q2);
    hadamard(*q1);
    hadamard(*q1);
    // cx(*q1, *q2);
    std::cout << "After Hadamard:" << std::endl;
    printQubit(*q1);
    // printQubit(*q2);
    return 0;
}