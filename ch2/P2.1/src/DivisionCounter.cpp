#include "DivisionCounter.h"
#include <iostream>

DivisionCounter::DivisionCounter(long long val) : value(val) {}

int DivisionCounter::countDivisions() const {
    if (value <= 2){
        return 0;
    } 
    long long temp = value;
    int count = 0;
    while (temp >= 2) {
        temp /= 2;
        count++;
    }
    return count;
}

int doProcess() {
    long long num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num <= 2) {
        std::cout << "The number must be greater than 2.\n";
        return 1;
    }
    
    DivisionCounter dc(num);
    std::cout << "Repeated divisions: " << dc.countDivisions() << "\n";
    return 0;
}