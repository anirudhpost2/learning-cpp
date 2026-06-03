#include <iostream>
#include <vector>
#include <memory>

#include "Punishment.h"
#include "CalendarGenerator.h"
#include "BirthdayParadox.h"

int main() {
    std::cout << "1. Punished Lines Generator (P-1.1)\n";
    std::cout << "2. Yearly Text Calendar Grid (P-1.2)\n";
    std::cout << "3. Birthday Paradox Experiment (P-1.3)\n";
    std::cout << "Choice: ";
    
    int choice;
    if (!(std::cin >> choice)) {
        std::cout << "Invalid dynamic choice token selection input sequence. Termination executed.\n";
        return 1;
    }

    switch (choice) {
        case 1: {
            Punishment p;
            p.doProcess();
            break;
        }
        case 2: {
            CalendarGenerator cg;
            cg.doProcess();
            break;
        }
        case 3: {
            BirthdayParadox bp;
            bp.doProcess();
            break;
        }
        default:
            std::cout << "Index selection sequence outside bounded arrays.\n";
    }

    std::cout << "Completed Execution\n=========\n";
    return 0;
}