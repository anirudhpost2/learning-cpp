#include <iostream>
#include <vector>
#include <memory>

#include "DivisionCounter.h"
#include "ChangeMaker.h"
#include "Vector.h"
#include "Animal.h"
#include "Polygon.h"
#include "CharTracker.h"
#include "WordTracker.h"

int main() {
    std::cout << "Select which project to run:\n";
    std::cout << "1. Division Counter (P-2.1)\n";
    std::cout << "2. Change Maker (P-2.2)\n";
    std::cout << "3. Numeric Vector (P-2.3)\n";
    std::cout << "4. Animal Combat Simulation (P-2.4)\n";
    std::cout << "5. Polygon Area & Perimeter (P-2.5)\n";
    std::cout << "6. Character Frequency Tracker (P-2.6)\n";
    std::cout << "7. Word Frequency Tracker (P-2.7)\n";
    std::cout << "Choice: ";
    
    int choice;
    if (!(std::cin >> choice)) {
        std::cout << "Invalid input. Exiting.\n";
        return 1;
    }

    switch (choice) {
        case 1: {
            std::cout << "Project 1\nStart Execution\n";
            
            DivisionCounter* dc = new DivisionCounter(0); 
            dc->doProcess();
            
            std::cout << "Completed Execution\n=========\n";
            delete dc; 
            break;
        }
        case 2: {
            std::cout << "Project 2\nStart Execution\n";
            
            ChangeMaker* p2 = new ChangeMaker();
            p2->doProcess();
            
            std::cout << "Completed Execution\n=========\n";
            delete p2; 
            break;
        }
        case 3: {
            std::cout << "Project 3\nStart Execution\n";
            
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
            
            // Instantiates base Animal pointers matching your void collide() signature
            auto tiger1 = std::make_shared<Animal>("Tiger", true, 9.1f);
            auto tiger2 = std::make_shared<Animal>("Tiger", true, 6.4f);

            std::cout << "--- Triggering Combat Dispute ---\n";
            Animal::collide(tiger1, tiger2);
            
            std::cout << "Completed Execution\n=========\n";
            break;
        } 
        case 5: {
            std::cout << "Project 5\nStart Execution\n";
            Polygon* poly = new Square(); 
            poly->doProcess();
            delete poly;
            
            std::cout << "Completed Execution\n=========\n";
            break;
        }
        case 6: {
            std::cout << "Project 6\nStart Execution\n";
            CharTracker ct;
            ct.doProcess();
            
            std::cout << "Completed Execution\n=========\n";
            break;
        }
        case 7: {
            std::cout << "Project 7\nStart Execution\n";
            WordTracker wt;
            wt.doProcess();
            
            std::cout << "Completed Execution\n=========\n";
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
    }

    return 0;
}