#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include <iostream>
#include "abstractlevel.h"
#include "square.h"
#include "jblock.h"
#include "lblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "oblock.h"
#include "iblock.h"

using namespace std;

class AbstractLevel;

class Board {
public:
  int rows;
  int cols;
  int player;
  string levelFile;
  int levelNum;
  AbstractLevel *level; //replace with smart pointers?
  bool newGame;
  bool lost;

  vector<vector<Square>> board;
  vector<int> blockPartsPerRow;

  //unique_ptr<AbstractLevel> currLevel;

  unique_ptr<AbstractBlock> currBlock;
  unique_ptr<AbstractBlock> currBlockMove;
  unique_ptr<AbstractBlock> nextBlock;
  char nextBlockType;
  char blockType;
  int xPos;
  int yPos;
  int r;
  int blockSize;
  int turns;
  int score;
  int printPart;

public:
    Board(int player, int level, string levelFile);
    ~Board();
    void printRow(int row); // NEW 
    int getPlayer();
    bool playerLost();
    int clearedLines();
    unique_ptr<AbstractBlock> getNextBlock(); // NEW, add smart pointers?
    bool isRowFilled(int row); // ??
    void deleteRow(int row);
    void makeNewRow();
    bool specialAction;
    //void print(); delete if not needed
    void setLevel();
    unique_ptr<AbstractBlock> generateNextBlock(int x, int y, int r);
    bool validMove(); // ADDED
    void rotate(int direction);
    bool sameRotation(int rotation);
    bool down(int distance);
    void drop();
    void sideways(int direction);
    void setBlock();
    void updateBlocksPerRow();
    int updateRow(int row);
    void makeNewBlock();
    void setBlockType(char type, char replacedBlock);
    void updateCurrBlock(int xNew, int yNew, int rNew);
    //unique_ptr<AbstractBlock> getNextBlock();
    /* int getx();
    int gety();
    int getr(); */ // not used i think
    void addTurn();
    int getTurns();


    void testPrint();
};

#endif
