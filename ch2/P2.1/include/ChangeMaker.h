#ifndef CHANGE_MAKER_H
#define CHANGE_MAKER_H

#include <string>
#include <vector>

struct CurrencyUnit {
    int valueInCents;
    std::string name;
};

class ChangeMaker {
private:
    std::vector<CurrencyUnit> registerDenominations;
public:
    ChangeMaker();
    void calculateChange(double charged, double given) const;
    int doProcess();
};

#endif