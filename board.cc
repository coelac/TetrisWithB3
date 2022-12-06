#include "board.h"
#include "levelzero.h"
#include "levelone.h"
#include "leveltwo.h"

using namespace std;

Board::Board(int player, int level, string levelFile) : rows{18}, cols{11}, player{player}, levelNum{level}, level{nullptr}, newGame{true}, lost{false}, blockSize{4}, score{0}, levelFile{levelFile} {
  for (int i = 0; i < rows; ++i) {
    makeNewRow();
    blockPartsPerRow.push_back(0);
  }
  makeNewBlock();
}

/*Board::~Board() {
//  delete currBlock;
//  delete nextBlock;
  //delete level;
}*/

int Board::getPlayer() {
  return player;
}

void Board::printRow(int row) {
	int partNum = 0;
	for (int i = 0; i < cols; ++i) {
		if (partNum < blockSize && currBlock->getYPos(partNum) == i &&
				currBlock->getXPos(partNum) == i) {
			cout << blockType;
			partNum += 1;
		} else {
			cout << board[row][i].print();
		}
	}
}



/*
void Board::print() {
  cout << "Level:     " << levelNum << endl; // correct num of spaces???
  cout << "Score:" << score << endl; // double digit score
  cout << "-----------" << endl;

  for (int r = 0; r <= rows; r++) {
    for (int c = 0; c <= cols; c++) {
      if (board[r][c].show && board[r][c].isOccupied) { board[r][c].print(); }
      else { cout << " "; }
    }
  }
  
  cout << "-----------" << endl;
  cout << "Next:" << endl;
  //..nextBlock...; // what rotation will the next block be in?
}
*/

void Board::deleteRow(int y) {
  board.erase(board.begin() + y); // y - 1?
  makeNewRow();
  
  blockPartsPerRow.erase(blockPartsPerRow.begin() + y); // y - 1?
  blockPartsPerRow.push_back(0);
}

void Board::makeNewRow() {

  vector<Square> newRow;
  for (int i = 0; i < cols; ++i) {
    newRow.push_back(Square());
  }
  board.push_back(newRow);
}

unique_ptr<AbstractBlock> Board::generateNextBlock(int x, int y, int r) {
  unique_ptr<AbstractBlock> makeBlock;
	
  switch (blockType) {
    case 'I': 
      makeBlock = make_unique<IBlock>(x, y, r);
      break;
    case 'J': 
      makeBlock = make_unique<JBlock>(x, y, r);
      break;
    case 'L': 
      makeBlock = make_unique<LBlock>(x, y, r);
      break;
    case 'O': 
      makeBlock = make_unique<OBlock>(x, y, r);
      break;
    case 'S': 
      makeBlock = make_unique<SBlock>(x, y, r);
      break;
    case 'Z': 
      makeBlock = make_unique<ZBlock>(x, y, r);
      break;
    case 'T': 
      makeBlock = make_unique<TBlock>(x, y, r);
      break;
    }
  return makeBlock;
}

bool Board::validMove() {
  for (int i = 0; i < blockSize; ++i) {
    int x = currBlockMove->getXPos(i);
    int y = currBlockMove->getYPos(i);
    if (y < 0 || y >= rows || x < 0 || x >= cols) {
            return false;
    }
    if (board[y][x].squareOccupied()) {
      return false;
    }
  }
  return true;
}

bool Board::down(int distance) {
  currBlockMove = generateNextBlock(xPos, yPos - distance, r);
  if (validMove()) {
    updateCurrBlock(xPos, yPos - distance, r);
    return true;
  } else {
    return false;
  }
}

void Board::drop() {
  bool canDrop = true;
  while (canDrop) {
    canDrop = down(1);
  }
  setBlock();
  makeNewBlock();
}

void Board::setBlock() {
  int rowsDeleted = 0;
  for (int i = 0; i < blockSize; ++i) {
    int x = currBlock->getXPos(i);
    int y = currBlock->getYPos(i);
    board[y][x].setSquare(blockType);
    if (y > 14) {
      lost = true;
    }
    rowsDeleted += updateRow(y);
  }
  if (rowsDeleted >= 2) {
    specialAction = true;
  }
}

void Board::sideways(int direction) { // direction = -1 or 1
  currBlockMove = generateNextBlock(xPos + direction, yPos, r);
  if (validMove()) {
    updateCurrBlock(xPos + direction, yPos, r);
  }
}

void Board::rotate(int rotation) {
  if (sameRotation(rotation)) return;
  int rotPos = (r + rotation) % 4;
  currBlockMove = generateNextBlock(xPos, yPos, rotPos);
  if (validMove()) {
    updateCurrBlock(xPos, yPos, rotPos);
  }
}

bool Board::sameRotation(int rotation) {
  switch (blockType) {
    case 'O':
      return true;
    case 'S':
    case 'Z':
    case 'I':
      if (rotation % 2 == 0) {
        return true;
      }
  }
  return false;
}

int Board::updateRow(int y) {
  blockPartsPerRow[y] += 1;
  if (blockPartsPerRow[y] == cols) {
    deleteRow(y);
    return 1;
  }
  return 0;
}

void Board::addTurn() {
  turns += 1;
}

int Board::getTurns() {
  return turns;
}

/*
unique_ptr<AbstractBlock> Board::getNextBlock() {
  return nextBlock;
}*/

/*void Board::updateLevel(int level) {
  levelNum = level;
  switch (level) {
    case 0:
      currLevel = make_unique<LevelZero>();
      break;
    case 1:
      currLevel = make_unique<LevelOne>();
      break;
    case 2:
      currLevel = make_unique<LevelTwo>();
      break;
    case 3:
      currLevel = make_unique<LevelThree>();
      break;
    case 5:
      currLevel = make_unique<LevelFour>();
      break;
  }
}*/

void Board::makeNewBlock() {
  if (newGame) {
    nextBlockType = 'T';
    newGame = false;
  }
  blockType = nextBlockType;
  currBlockMove = generateNextBlock(0, 14, 0);
  if (validMove()) {
	 // cout << "VALID" << endl;
    updateCurrBlock(0, 14, 0);
  } else {
    lost = true;
  }
  nextBlockType = 'T';
}

bool Board::playerLost() {
  return lost;
}

void Board::updateCurrBlock(int xNew, int yNew, int rNew) {
  currBlock = move(currBlockMove);
  xPos = xNew;
  yPos = yNew;
  r = rNew;
}

void Board::setBlockType(char type, char replacedBlock) {
  if (replacedBlock == 'C') {
    blockType = type;
  } else if (replacedBlock == 'N') {
    nextBlockType = type;
  }
}

void Board::setLevel() {
  if (level != nullptr) delete level;
  
  if (levelNum == 0) {
    level = new LevelZero{-1, levelFile};
  } else if (levelNum == 1) {
    level = new LevelOne{};
  } else if (levelNum == 2) {
    level = new LevelTwo{};
  } /*else if (levelNum == 3) {
    
  } else {

  }*/
}

unique_ptr<AbstractBlock> Board::getNextBlock() {
  char block = level->generateNextBlock();

  if (block == 'I') { return make_unique<IBlock>(0, 0, 0); }
  else if (block == 'J') { return make_unique<JBlock>(0, 0, 0); }
  else if (block == 'L') { return make_unique<LBlock>(0, 0, 0); }
  else if (block == 'O') { return make_unique<OBlock>(0, 0, 0); }
  else if (block == 'S') { return make_unique<SBlock>(0, 0, 0); }
  else if (block == 'Z') { return make_unique<ZBlock>(0, 0, 0); }

  return make_unique<TBlock>(0, 0, 0);
}


void Board::testPrint() {
    int partNum = 0;
    cout << "START" << endl;
    for (int i = rows - 1; i >= 0; --i) {
        for (int j = 0; j < cols; ++j) {
            if (partNum < blockSize && currBlock->getYPos(partNum) == i &&
                    currBlock->getXPos(partNum) == j) {
                cout << blockType;
                partNum += 1;
            } else {
                cout << board[i][j].print();
            }
        }
        cout << endl;
    }
    cout << "END" << endl;
}