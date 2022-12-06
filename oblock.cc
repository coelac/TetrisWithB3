#include "oblock.h"

OBlock::OBlock(int x, int y, int r) : xPos{x}, yPos{y}, rot{r} {
  pos0();
}

void OBlock::addPart(int x, int y) {
  parts.push_back(BlockPart(x, y));
}

void OBlock::pos0() {
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos, yPos);
  addPart(xPos + 1, yPos);
}

int OBlock::getXPos(int part) {
  return parts[part].getXPos();
}

int OBlock::getYPos(int part) {
  return parts[part].getYPos();
}

string OBlock::printBlock() {
    return oBlockRotationALL;
}

void OBlock::pos1() {};
void OBlock::pos2() {};
void OBlock::pos3() {};