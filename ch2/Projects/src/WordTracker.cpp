#include "WordTracker.h"
#include <iostream>
#include <sstream>

void WordTracker::doProcess() {
    std::string input;
    std::cout << "Enter a list of words separated by spaces:\n";
    std::cin.ignore(); 
    std::getline(std::cin, input);

    list.clear(); // 
    std::stringstream ss(input);
    std::string tempWord;

    while (ss >> tempWord) {
        bool found = false;
        for (auto& item : list) {
            if (item.word == tempWord) {
                item.count++;
                found = true;
                break;
            }
        }
        if (!found) {
            list.push_back({tempWord, 1});
        }
    }

    std::cout << "\n--- Word Frequency Breakdown ---\n";
    for (const auto& item : list) {
        std::cout << item.word << ": " << item.count << "\n";
    }
}