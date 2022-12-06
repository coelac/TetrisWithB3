#include "tblock.h"

TBlock::TBlock(int x, int y, int r) : xPos{x}, yPos{y}, rot{r} {
  if (r == 0) {
    pos0();
  } else if (r == 1) {
    pos1();
  } else if (r == 2) {
    pos2();
  } else if (r == 3) {
    pos3();
  }
}

void TBlock::addPart(int x, int y) {
  parts.push_back(BlockPart(x, y));
}

void TBlock::pos0() {
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos + 2, yPos + 1);
  addPart(xPos + 1, yPos);
}

void TBlock::pos1() {
  addPart(xPos + 1, yPos + 2);
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos + 1, yPos);
}

void TBlock::pos2() {
  addPart(xPos + 1, yPos + 1);
  addPart(xPos, yPos);
  addPart(xPos + 1, yPos);
  addPart(xPos + 2, yPos);
}

void TBlock::pos3() {
  addPart(xPos, yPos + 2);
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos, yPos);
}

int TBlock::getXPos(int part) {
  return parts[part].getXPos();
}

int TBlock::getYPos(int part) {
  return parts[part].getYPos();
}

string TBlock::printBlock() {
    if (rot == 1) { // UP
        return tBlockRotationUP;
    } else if (rot == 2) { // LEFT
        return tBlockRotationLEFT;
    } else if (rot == 3) { // RIGHT
        return tBlockRotationRIGHT;
    }

    return tBlockRotationDOWN;
}
