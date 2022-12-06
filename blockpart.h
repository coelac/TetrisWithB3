#ifndef BLOCKPART_H
#define BLOCKPART_H

#include <iostream>

class BlockPart {
  public:
    int x;
    int y;
  public:
    BlockPart(int x, int y);
    int getXPos();
    int getYPos();
};

#endif
