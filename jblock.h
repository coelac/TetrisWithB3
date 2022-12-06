#ifndef JBLOCK_H
#define JBLOCK_H
#include "abstractblock.h"

class JBlock : public AbstractBlock {
  private:
    int xPos;
    int yPos;
    int rot;
    vector<BlockPart> parts;
  
    string jBlockRotationUP = "     J   J  JJ  ";
    string jBlockRotationRIGHT = "     J   J  JJ  ";
    string jBlockRotationDOWN = "        J   JJJ ";
    string jBlockRotationLEFT = "    JJ  J   J   ";
  public:
    JBlock(int x, int y, int r);
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
