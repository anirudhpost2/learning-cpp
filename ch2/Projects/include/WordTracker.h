#ifndef WORD_TRACKER_H
#define WORD_TRACKER_H

#include <string>
#include <vector>

struct WordElement {
    std::string word;
    int count;
};

class WordTracker {
private:
    std::vector<WordElement> list;
public:
    void doProcess();
};

#endif