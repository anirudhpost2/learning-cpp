#include "DivisionCounter.h"
#include <iostream>

int main() {
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