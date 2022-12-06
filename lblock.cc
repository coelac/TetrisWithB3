#include "lblock.h"

LBlock::LBlock(int x, int y, int r) : xPos{x}, yPos{y}, rot{r} {
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

void LBlock::addPart(int x, int y) {
  parts.push_back(BlockPart(x, y));
}

void LBlock::pos0() {
  addPart(xPos + 2, yPos + 1);
  addPart(xPos, yPos);
  addPart(xPos + 1, yPos);
  addPart(xPos + 2, yPos);
}

void LBlock::pos1() {
  addPart(xPos, yPos + 2);
  addPart(xPos, yPos + 1);
  addPart(xPos, yPos);
  addPart(xPos + 1, yPos);
}

void LBlock::pos2() {
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos + 2, yPos + 1);
  addPart(xPos, yPos);
}

void LBlock::pos3() {
  addPart(xPos, yPos + 2);
  addPart(xPos + 1, yPos + 2);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos + 1, yPos);
}

int LBlock::getXPos(int part) {
  return parts[part].getXPos();
}

int LBlock::getYPos(int part) {
  return parts[part].getYPos();
}

string LBlock::printBlock() {
    if (rot == 1) { // UP
        return lBlockRotationUP;
    } else if (rot == 2) { // LEFT
        return lBlockRotationLEFT;
    } else if (rot == 3) { // RIGHT
        return lBlockRotationRIGHT;
    }

    return lBlockRotationDOWN;
}
