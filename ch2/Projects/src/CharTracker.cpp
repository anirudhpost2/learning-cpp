#include "../include/CharTracker.h"
#include <iostream>
#include <cctype>

CharTracker::CharTracker() : frequencies(26, 0) {}

void CharTracker::doProcess() {
    std::string document;
    std::cout << "Enter text to analyze character frequencies:\n";
    std::cin.ignore(); // Flush newline buffer from previous choices
    std::getline(std::cin, document);

    // Reset frequencies for multiple executions
    std::fill(frequencies.begin(), frequencies.end(), 0);

    for (char ch : document) {
        if (std::isalpha(ch)) {
            frequencies[std::tolower(ch) - 'a']++;
        }
    }

    std::cout << "\n--- Character Frequency Plot ---\n";
    for (int i = 0; i < 26; ++i) {
        if (frequencies[i] > 0) { // Only plot characters that appear
            std::cout << static_cast<char>('A' + i) << " | ";
            for (int j = 0; j < frequencies[i]; ++j) {
                std::cout << "*";
            }
            std::cout << " (" << frequencies[i] << ")\n";
        }
    }
}