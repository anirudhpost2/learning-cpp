#include "BirthdayParadox.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

void BirthdayParadox::doProcess() {
    const int totalExperiments = 15; // Set to at least 10 matching spec layout constraints
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dayDist(1, 365);

    std::cout << "\n--- Run Birthday Paradox Simulation Experiments ---\n\n";
    std::cout << std::setw(10) << "Group Size" 
              << std::setw(15) << "Total Tests" 
              << std::setw(18) << "Matches Found" 
              << std::setw(18) << "Empirical %" << "\n";
    std::cout << "------------------------------------------------------------- \n";

    // Run tests incrementing group sizes from 5 up to 100 dynamically
    for (int n = 5; n <= 100; n += 5) {
        int successfulMatches = 0;

        for (int exp = 0; exp < totalExperiments; ++exp) {
            std::vector<int> groupBirthdays;
            groupBirthdays.reserve(n);
            bool hasSharedBirthday = false;

            for (int p = 0; p < n; ++p) {
                int birthday = dayDist(gen);
                
                // If the element already matches a value inside our array vector, collision found
                if (std::find(groupBirthdays.begin(), groupBirthdays.end(), birthday) != groupBirthdays.end()) {
                    hasSharedBirthday = true;
                }
                groupBirthdays.push_back(birthday);
            }

            if (hasSharedBirthday) {
                successfulMatches++;
            }
        }

        double statisticalPercentage = (static_cast<double>(successfulMatches) / totalExperiments) * 100.0;
        std::cout << std::setw(10) << n 
                  << std::setw(15) << totalExperiments 
                  << std::setw(18) << successfulMatches 
                  << std::setw(17) << std::fixed << std::setprecision(1) << statisticalPercentage << "%\n";
    }
}