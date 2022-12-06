#include "leveltwo.h"

LevelTwo::LevelTwo() {}

LevelTwo::~LevelTwo() {}

char LevelTwo::generateNextBlock() {
  int value = rand() % (5 - 0 + 1) + 0; // between 0-6

  if (value == 0 ) { return 'I'; }
  else if (value == 1) { return 'J'; }
  else if (value == 2) { return 'L'; }
  else if (value == 3) { return 'O'; }
  else if (value == 4) { return 'S'; }
  else if (value == 5) { return 'Z'; }
/*
  if (value == 0 ) { return new IBlock(0, 0, 0); }
  else if (value == 1) { return new JBlock(0, 0, 0); }
  else if (value == 2) { return new LBlock(0, 0, 0); }
  else if (value == 3) { return new OBlock(0, 0, 0); }
  else if (value == 4) { return new SBlock(0, 0, 0); }
  else if (value == 5) { return new ZBlock(0, 0, 0); }
  */
  return 'T';
}