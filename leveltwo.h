#ifndef LEVELTWO_H
#define LEVELTWO_H
#include "abstractlevel.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class LevelTwo : public AbstractLevel {
  vector<char> blocks{'S', 'Z', 'I', 'J', 'L', 'O', 'T'};

  public:
    LevelTwo();
    ~LevelTwo();
    char generateNextBlock();
};

#endif