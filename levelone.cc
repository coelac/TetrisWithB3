#include "levelone.h"

LevelOne::LevelOne() {}

LevelOne::~LevelOne() {}

char LevelOne::generateNextBlock() {
  int i = rand() % (11 - 0 + 1) + 0; // between 0-6
/*
  if (blocks[i] == 'I') { return new IBlock(0, 0, 0); }
  else if (blocks[i] == 'J') { return new JBlock(0, 0, 0); }
  else if (blocks[i] == 'L') { return new LBlock(0, 0, 0); }
  else if (blocks[i] == 'O') { return new OBlock(0, 0, 0); }
  else if (blocks[i] == 'S') { return new SBlock(0, 0, 0); }
  else if (blocks[i] == 'Z') { return new ZBlock(0, 0, 0); }
  */
  return blocks[i];
}