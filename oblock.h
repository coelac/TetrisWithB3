#ifndef OBLOCK_H
#define OBLOCK_H
#include "abstractblock.h"

class OBlock : public AbstractBlock {
  private:
    int xPos;
    int yPos;
    int rot;
    vector<BlockPart> parts;
  
    string oBlockRotationALL = "        OO  OO  ";
  public:
    OBlock(int x, int y, int r);
    void addPart(int x, int y);
    void pos0();
    void pos1();
    void pos2();
    void pos3();
    int getXPos(int part);
    int getYPos(int part);
    string printBlock();
};

#endif
