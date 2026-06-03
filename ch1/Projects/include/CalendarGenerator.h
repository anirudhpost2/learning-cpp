#ifndef CALENDAR_GENERATOR_H
#define CALENDAR_GENERATOR_H

#include <string>
#include <vector>

class CalendarGenerator {
private:
    bool isLeapYear(int year) const;
    int getMonthDays(int month, int year) const;
    int getStartDayIndex(const std::string& dayStr) const;
public:
    void doProcess();
};

#endif