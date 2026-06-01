#include "../include/Animal.h"
#include <iostream>
#include <random>

Animal::Animal(std::string sp, bool gender, float str) 
    : species(sp), isMale(gender), strength(str) {}

std::string Animal::getSpecies() const { return species; }
bool Animal::getGender() const { return isMale; }
float Animal::getStrength() const { return strength; }
std::string Animal::getGenderStr() const { return isMale ? "Male" : "Female"; }

std::shared_ptr<Animal> Animal::collide(std::shared_ptr<Animal>& a1, std::shared_ptr<Animal>& a2) {
    if (a1->getSpecies() != a2->getSpecies()) {
        std::cout << "Mismatched interaction. No fallout.\n";
        return nullptr;
    }
    
    if (a1->getGender() != a2->getGender()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> strDist(1.0f, 10.0f);
        std::bernoulli_distribution genDist(0.5);

        std::cout << "Mating event triggered between " << a1->getSpecies() << " parameters.\n";
        return std::make_shared<Animal>(a1->getSpecies(), genDist(gen), strDist(gen));
    } else {
        std::cout << "Same-sex territory dispute combat initiated!\n";
        if (a1->getStrength() >= a2->getStrength()) {
            std::cout << "First instance retains domain. Secondary instance destroyed.\n";
            a2 = nullptr;
        } else {
            std::cout << "Secondary instance conquers. Primary instance destroyed.\n";
            a1 = nullptr;
        }
        return nullptr;
    }
}