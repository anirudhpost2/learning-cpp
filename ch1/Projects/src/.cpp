#include "DivisionCounter.h"

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