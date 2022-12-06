#ifndef LEVELZERO_H
#define LEVELZERO_H
#include "abstractlevel.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class LevelZero : public AbstractLevel {
  string fileName;
  vector<char> fileBlocks;
  int index;

  public:
    LevelZero(int i, string f);
    ~LevelZero();
    void readFile();
    char generateNextBlock();
};

#endif