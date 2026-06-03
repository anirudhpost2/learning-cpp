#include "Punishment.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

void Punishment::doProcess() {
    std::string baseSentence = "I will always use object-oriented design.";
    int totalLines = 100;
    int totalTypos = 8;

    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Choose 8 distinct unique random line numbers between 1 and 100 to apply typos to
    std::vector<int> typoLines;
    std::uniform_int_distribution<int> lineDist(1, totalLines);
    while (typoLines.size() < static_cast<size_t>(totalTypos)) {
        int candidate = lineDist(gen);
        if (std::find(typoLines.begin(), typoLines.end(), candidate) == typoLines.end()) {
            typoLines.push_back(candidate);
        }
    }

    std::uniform_int_distribution<int> charDist(0, baseSentence.length() - 2);
    std::uniform_int_distribution<int> typoTypeDist(0, 1);
    std::uniform_int_distribution<char> letterDist('a', 'z');

    std::cout << "\n--- Starting Execution: Punishment Lines ---\n\n";
    for (int i = 1; i <= totalLines; ++i) {
        std::cout << i << ". ";
        
        // Check if this line should receive a typo modification
        if (std::find(typoLines.begin(), typoLines.end(), i) != typoLines.end()) {
            std::string corrupted = baseSentence;
            int pos = charDist(gen);
            
            if (typoTypeDist(gen) == 0 && pos > 0) {
                // Typo type 1: Swap adjacent letters
                std::swap(corrupted[pos], corrupted[pos + 1]);
            } else {
                // Typo type 2: Replace a letter with a random lowercase character
                if (std::isalpha(corrupted[pos])) {
                    corrupted[pos] = letterDist(gen);
                }
            }
            std::cout << corrupted << " [TYPO]\n";
        } else {
            std::cout << baseSentence << "\n";
        }
    }
}