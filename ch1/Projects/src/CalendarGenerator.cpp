#include "CalendarGenerator.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

bool CalendarGenerator::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CalendarGenerator::getMonthDays(int month, int year) const {
    std::vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 1 && isLeapYear(year)) return 29; // February leap fix
    return days[month];
}

int CalendarGenerator::getStartDayIndex(const std::string& dayStr) const {
    std::vector<std::string> daysOfWeek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (size_t i = 0; i < daysOfWeek.size(); ++i) {
        if (dayStr == daysOfWeek[i]) return i;
    }
    return 0; // Fallback default index
}

void CalendarGenerator::doProcess() {
    std::string startDay;
    int year;
    
    std::cout << "Enter starting day of the year (e.g., Wednesday): ";
    std::cin >> startDay;
    std::cout << "Enter a 4-digit year: ";
    std::cin >> year;

    std::vector<std::string> months = {
        "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
        "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"
    };

    int currentDayIndex = getStartDayIndex(startDay);
    const int width = 28; // Standard 4 characters per column spacing matching days list layout

    std::cout << "\n==============================\n";
    std::cout << "        CALENDAR FOR " << year << "   \n";
    std::cout << "==============================\n";

    for (int m = 0; m < 12; ++m) {
        // Print Month Title Centered
        int padding = (width - months[m].length()) / 2;
        std::cout << "\n" << std::string(padding, ' ') << months[m] << "\n";
        std::cout << " Sun Mon Tue Wed Thu Fri Sat\n";

        // Print initial white space offsets for starting positions
        for (int i = 0; i < currentDayIndex; ++i) {
            std::cout << "    ";
        }

        int totalDays = getMonthDays(m, year);
        for (int day = 1; day <= totalDays; ++day) {
            std::cout << std::setw(4) << day;
            currentDayIndex++;
            
            if (currentDayIndex == 7) {
                std::cout << "\n";
                currentDayIndex = 0;
            }
        }
        if (currentDayIndex != 0) {
            std::cout << "\n";
        }
    }
}