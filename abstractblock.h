#ifndef ABSTRACTBLOCK_H
#define ABSTRACTBLOCK_H
#include <vector>
#include <iostream>
#include "blockpart.h"

using namespace std;

class AbstractBlock {
  public:
    virtual void addPart(int x, int y) = 0;
    virtual int getXPos(int part) = 0;
    virtual int getYPos(int part) = 0;
    virtual void pos0() = 0;
    virtual void pos1() = 0;
    virtual void pos2() = 0;
    virtual void pos3() = 0;
    virtual string printBlock() = 0;
};

#endif
