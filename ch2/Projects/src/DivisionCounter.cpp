#include "../include/DivisionCounter.h"
#include <iostream>

DivisionCounter::DivisionCounter(long long val) : value(val) {}

int DivisionCounter::countDivisions() const {
    if (value <= 2) return 0;
    long long temp = value;
    int count = 0;
    while (temp >= 2) {
        temp /= 2;
        count++;
    }
    return count;
}

// Write the full code body here in the .cpp file:
void DivisionCounter::doProcess() {
    long long inputVal;
    std::cout << "Enter an integer greater than 2: ";
    std::cin >> inputVal;

    if (inputVal <= 2) {
        std::cout << "Value must be greater than 2.\n";
        return;
    }

    value = inputVal; // updating class variable
    std::cout << "Repeated divisions required: " << countDivisions() << "\n";
}