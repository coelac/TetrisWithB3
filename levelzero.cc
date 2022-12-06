#include "levelzero.h"

LevelZero::LevelZero(int i, string f) : index{-1}, fileName{f} {}

LevelZero::~LevelZero() {}

void LevelZero::readFile() {
  char block;
  ifstream f{fileName};
  while (f >> block) {
    fileBlocks.push_back(block);
  }
}

char LevelZero::generateNextBlock() {
  readFile();
  index += 1;

  /*if (fileBlocks[index] == 'I') { return IBlock; }
  else if (fileBlocks[index] == 'J') { return new JBlock; }
  else if (fileBlocks[index] == 'L') { return new LBlock; }
  else if (fileBlocks[index] == 'O') { return new OBlock; }
  else if (fileBlocks[index] == 'S') { return new SBlock; }
  else if (fileBlocks[index] == 'Z') { return new ZBlock; }*/
  
  return fileBlocks[index];
}