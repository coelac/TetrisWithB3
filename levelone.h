#ifndef LEVELONE_H
#define LEVELONE_H
#include "abstractlevel.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class LevelOne : public AbstractLevel {
    vector<char> blocks{'S', 'Z', 'T', 'T', 'I', 'I', 'J', 'J', 'L', 'L', 'O', 'O'};

    public:
        LevelOne();
        ~LevelOne();
        void readFile() {};
        char generateNextBlock();
};

#endif