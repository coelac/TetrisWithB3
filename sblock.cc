#include "sblock.h"

SBlock::SBlock(int x, int y, int r) : xPos{x}, yPos{y}, rot{r} {
  if (rot % 2 == 0) {
    pos0();
  } else {
    pos1();
  }
}

void SBlock::addPart(int x, int y) {
  parts.push_back(BlockPart(x, y));
}

void SBlock::pos0() {
  addPart(xPos, yPos + 2);
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos + 1, yPos);
}

void SBlock::pos1() {
  addPart(xPos + 1, yPos + 1);
  addPart(xPos + 2, yPos + 1);
  addPart(xPos, yPos);
  addPart(xPos + 1, yPos);
}

int SBlock::getXPos(int part) {
  return parts[part].getXPos();
}

int SBlock::getYPos(int part) {
  return parts[part].getYPos();
}

string SBlock::printBlock() {
    if (rot % 2 == 0) { // UP
        return sBlockRotationVERT;
    }

    return sBlockRotationHORI;
}

void SBlock::pos2() {};
void SBlock::pos3() {};