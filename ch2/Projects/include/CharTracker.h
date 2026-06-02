#ifndef CHAR_TRACKER_H
#define CHAR_TRACKER_H

#include <string>
#include <vector>

class CharTracker {
private:
    std::vector<int> frequencies;
public:
    CharTracker();
    void doProcess();
};

#endif