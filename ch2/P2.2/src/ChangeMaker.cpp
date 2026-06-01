#include "ChangeMaker.h"
#include <iostream>
#include <cmath>

ChangeMaker::ChangeMaker() {
    registerDenominations = {
        {10000, "$100 Bill"}, {5000, "$50 Bill"}, {2000, "$20 Bill"},
        {1000, "$10 Bill"},  {500, "$5 Bill"},   {100, "$1 Bill"},
        {25, "Quarter"},      {10, "Dime"},       {5, "Nickel"}, {1, "Penny"}
    };
}

void ChangeMaker::calculateChange(double charged, double given) const {
    int changeDue = static_cast<int>(std::round((given - charged) * 100));

    if (changeDue < 0) {
        std::cout << "Insufficient funds.\n";
        return;
    }
    if (changeDue == 0) {
        std::cout << "Exact payment. No change owed.\n";
        return;
    }

    std::cout << "\nOptimal Change Returned:\n";
    for (const auto& item : registerDenominations) {
        if (changeDue >= item.valueInCents) {
            int count = changeDue / item.valueInCents;
            changeDue %= item.valueInCents;
            std::cout << count << " x " << item.name << "\n";
        }
    }
}