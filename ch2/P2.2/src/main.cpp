#include "ChangeMaker.h"
#include <iostream>

int main() {
    double bill, payment;
    std::cout << "Enter amount charged: ";
    std::cin >> bill;
    std::cout << "Enter amount given: ";
    std::cin >> payment;

    ChangeMaker cm;
    cm.calculateChange(bill, payment);
    return 0;
}