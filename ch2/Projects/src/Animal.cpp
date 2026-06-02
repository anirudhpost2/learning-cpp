#include "Animal.h"
#include <iostream>
#include <random>

Animal::Animal(std::string sp, bool gender, float str) 
    : species(sp), isMale(gender), strength(str) {}

std::string Animal::getSpecies() const { return species; }
bool Animal::getGender() const { return isMale; }
float Animal::getStrength() const { return strength; }
std::string Animal::getGenderStr() const { return isMale ? "Male" : "Female"; }

void Animal::collide(std::shared_ptr<Animal>& a1, std::shared_ptr<Animal>& a2) {
    if (!a1 || !a2) return;

    if (a1->getSpecies() != a2->getSpecies()) {
        std::cout << "Mismatched interaction. No fallout.\n";
        return;
    }
    
    if (a1->getGender() != a2->getGender()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> strDist(1.0f, 10.0f);
        std::bernoulli_distribution genDist(0.5);

        std::cout << "Mating event triggered between " << a1->getSpecies() << " parameters!\n";
        std::cout << "A new baby " << a1->getSpecies() << " was born into the ecosystem.\n";
    } else {
        std::cout << "Same-sex territory dispute combat initiated!\n";
        std::cout << "Animal 1 (" << a1->getGenderStr() << ", Str: " << a1->getStrength() << ") vs "
                  << "Animal 2 (" << a2->getGenderStr() << ", Str: " << a2->getStrength() << ")\n";

        if (a1->getStrength() >= a2->getStrength()) {
            std::cout << "First instance retains domain. Secondary instance destroyed.\n";
            a2 = nullptr; // Wipes out the loser object reference from memory
        } else {
            std::cout << "Secondary instance conquers. Primary instance destroyed.\n";
            a1 = nullptr; // Wipes out the loser object reference from memory
        }
    }
}