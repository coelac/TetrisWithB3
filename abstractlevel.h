#ifndef ABSLEVEL_H
#define ABSLEVEL_H
#include <vector>
#include "board.h"
#include "abstractblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
//#include "../Blocks/cblock.h"

using namespace std;

class AbstractLevel {
  public:
    ~AbstractLevel();
    virtual char generateNextBlock() = 0;
};

#endif