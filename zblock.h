#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "abstractblock.h"

class ZBlock : public AbstractBlock {
  public:
    int xPos;
    int yPos;
    int rot;
    vector<BlockPart> parts;
  
    string zBlockRotationVERT = "     Z  ZZ  Z   ";
    string zBlockRotationHORI = "        ZZ   ZZ ";
  public:
    ZBlock(int x, int y, int r);
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
