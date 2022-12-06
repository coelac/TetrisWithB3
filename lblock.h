#ifndef LBLOCK_H
#define LBLOCK_H
#include "abstractblock.h"

class LBlock : public AbstractBlock {
  private:
    int xPos;
    int yPos;
    int rot;
    vector<BlockPart> parts;
  
    string lBlockRotationUP = "    L   L   LL  ";
    string lBlockRotationRIGHT = "    LL   L   L  ";
    string lBlockRotationDOWN = "          L LLL ";
    string lBlockRotationLEFT = "        LLL L   ";
  public:
    LBlock(int x, int y, int r);
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
