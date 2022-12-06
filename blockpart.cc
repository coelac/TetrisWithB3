#include "blockpart.h"
using namespace std;

BlockPart::BlockPart(int x, int y) : x{x}, y{y} {}

int BlockPart::getXPos() {
  return x;
}

int BlockPart::getYPos() {
  return y;
}

