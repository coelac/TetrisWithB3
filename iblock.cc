#include "iblock.h"

IBlock::IBlock(int x, int y, int r) : xPos{x}, yPos{x}, rot{r} {
  if (r % 2 == 0) {
    pos0();
  } else {
    pos1();
  }
}

void IBlock::addPart(int x, int y) {
  parts.push_back(BlockPart(x, y));
}

void IBlock::pos0() {
  addPart(xPos + 3, yPos);
  addPart(xPos + 2, yPos);
  addPart(xPos + 1, yPos);
  addPart(xPos, yPos);
}

void IBlock::pos1() {
  addPart(xPos, yPos);
  addPart(xPos, yPos + 1);
  addPart(xPos, yPos + 2);
  addPart(xPos, yPos + 3);
}

int IBlock::getXPos(int part) {
  return parts[part].getXPos();
}

int IBlock::getYPos(int part) {
  return parts[part].getYPos();
}

string IBlock::printBlock() {
    if (rot & 2 == 0) { // UP
        return iBlockRotationVERT;
    } 

    return iBlockRotationHORI;
}

void IBlock::pos2() {};
void IBlock::pos3() {};