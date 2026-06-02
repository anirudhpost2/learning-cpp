#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <memory>

class Animal {
protected:
    std::string species;
    bool isMale;
    float strength;

public:
    Animal(std::string sp, bool gender, float str);
    virtual ~Animal() = default;

    std::string getSpecies() const;
    bool getGender() const;
    float getStrength() const;
    std::string getGenderStr() const;

    static void collide(std::shared_ptr<Animal>& a1, std::shared_ptr<Animal>& a2);
};

#endif