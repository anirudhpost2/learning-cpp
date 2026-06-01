#ifndef DIVISION_COUNTER_H
#define DIVISION_COUNTER_H

class DivisionCounter {
private:
    long long value;
public:
    DivisionCounter(long long val);
    int countDivisions() const;
};

#endif