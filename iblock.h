#ifndef IBLOCK_H
#define IBLOCK_H
#include "abstractblock.h"

class IBlock : public AbstractBlock {
  public:
    int xPos;
    int yPos;
    int rot;
    vector<BlockPart> parts;
  
    string iBlockRotationVERT = "I   I   I   I   ";
    string iBlockRotationHORI = "            IIII";
  public:
    IBlock(int x, int y, int r);
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
