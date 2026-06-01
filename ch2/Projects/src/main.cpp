#include <iostream>
#include <vector>

// Include your actual project header files
#include "../include/DivisionCounter.h"
#include "../include/ChangeMaker.h"
#include "../include/Vector.h"
#include "../include/Animal.h"

int main() {
    std::cout << "Select which project to run:\n";
    std::cout << "1. Division Counter (P-2.1)\n";
    std::cout << "2. Change Maker (P-2.2)\n";
    std::cout << "3. Numeric Vector (P-2.3)\n";
    std::cout << "4. Animal Combat Simulation (P-2.4)\n";
    std::cout << "Choice: ";
    
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "Project 1\nStart Execution\n";
            
            // Allocate memory on the heap using 'new' instead of setting it to 0
            DivisionCounter* dc = new DivisionCounter(0); 
            dc->doProcess();
            
            std::cout << "Completed Execution\n=========\n";
            delete dc; // Clean up memory safely
            break;
        }
        case 2: {
            std::cout << "Project 2\nStart Execution\n";
            
            ChangeMaker* p2 = new ChangeMaker();
            p2->doProcess();
            
            std::cout << "Completed Execution\n=========\n";
            delete p2; // Clean up memory safely
            break;
        }
        case 3: {
            std::cout << "Project 3\nStart Execution\n";
            
            // Run your P-2.3 MathVector implementation
            MathVector<Complex> cv(2);
            cv.set(0, Complex(2, 3));
            cv.set(1, Complex(1, 2));

            std::cout << "Complex Vector: ";
            cv.print();
            std::cout << "Self Dot Product: " << cv.dotProduct(cv) << "\n";
            
            std::cout << "Completed Execution\n=========\n";
            break;
        }
        case 4: {
            std::cout << "Project 4\nStart Execution\n";
            
            // Interaction Simulation
            auto tiger1 = std::make_shared<Animal>("Tiger", true, 9.1f);
            auto tiger2 = std::make_shared<Animal>("Tiger", true, 6.4f);

            std::cout << "--- Triggering Combat Dispute ---\n";
            Animal::collide(tiger1, tiger2);
            
            std::cout << "Completed Execution\n=========\n";
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
    }

    return 0;
}