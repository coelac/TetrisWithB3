#ifndef SBLOCK_H
#define SBLOCK_H
#include "abstractblock.h"

class SBlock : public AbstractBlock {
  public:
    int xPos;
    int yPos;
    int rot;
    vector<BlockPart> parts;
  
    string sBlockRotationVERT = "    S   SS   S  ";
    string sBlockRotationHORI = "         SS SS  ";
  public:
    SBlock(int x, int y, int r);
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
