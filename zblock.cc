#include "zblock.h"

ZBlock::ZBlock(int x, int y, int r) : xPos{x}, yPos{y}, rot{r} {
  if (r % 2 == 0) {
    pos0();
  } else {
    pos1();
  }
}

void ZBlock::addPart(int x, int y) {
  parts.push_back(BlockPart(x, y));
}

void ZBlock::pos0() {
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos + 1, yPos);
  addPart(xPos + 2, yPos);
}

void ZBlock::pos1() {
  addPart(xPos + 1, yPos + 2);
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos, yPos);
}

int ZBlock::getXPos(int part) {
  return parts[part].getXPos();
}

int ZBlock::getYPos(int part) {
  return parts[part].getYPos();
}

string ZBlock::printBlock() {
    if (rot % 2 == 0) { // UP
        return zBlockRotationVERT;
    }

    return zBlockRotationHORI;
}

void ZBlock::pos2() {}
void ZBlock::pos3() {}