#ifndef TBLOCK_H
#define TBLOCK_H
#include "abstractblock.h"

class TBlock : public AbstractBlock {
  private:
    int xPos;
    int yPos;
    int rot;
    vector<BlockPart> parts;
  
    string tBlockRotationUP = "        TTT  T          TTT  T  ";
    string tBlockRotationRIGHT = "     T  TT   T       T  TT   T  ";
    string tBlockRotationDOWN = "         T  TTT          T  TTT ";
    string tBlockRotationLEFT = "    T   TT  T       T   TT  T   ";
  public:
    TBlock(int x, int y, int r);
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
