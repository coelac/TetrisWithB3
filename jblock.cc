#include "jblock.h"

JBlock::JBlock(int x, int y, int r) : xPos{x}, yPos{y}, rot{r} {
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

void JBlock::addPart(int x, int y) {
  parts.push_back(BlockPart(x, y));
}

void JBlock::pos0() {
  addPart(xPos, yPos + 1);
  addPart(xPos, yPos);
  addPart(xPos + 1, yPos);
  addPart(xPos + 2, yPos);
}

void JBlock::pos1() {
  addPart(xPos, yPos + 2);
  addPart(xPos + 1, yPos + 2);
  addPart(xPos, yPos + 1);
  addPart(xPos, yPos);
}

void JBlock::pos2() {
  addPart(xPos, yPos + 1);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos + 2, yPos + 1);
  addPart(xPos + 2, yPos);
}

void JBlock::pos3() {
  addPart(xPos + 1, yPos + 2);
  addPart(xPos + 1, yPos + 1);
  addPart(xPos, yPos);
  addPart(xPos + 1, yPos);
}

int JBlock::getXPos(int part) {
  return parts[part].getXPos();
}

int JBlock::getYPos(int part) {
  return parts[part].getYPos();
}

string JBlock::printBlock() {
    if (rot == 1) { // UP
        return jBlockRotationUP;
    } else if (rot == 2) { // LEFT
        return jBlockRotationLEFT;
    } else if (rot == 3) { // RIGHT
        return jBlockRotationRIGHT;
    }

    return jBlockRotationDOWN;
}
