#ifndef SQUARE_H
#define SQUARE_H

using namespace std;

class Board;

class Square {
  private:
    bool isOccupied;
    char setChar;
  public:
    Square();
    void setSquare(char newChar);
    char print();
    bool squareOccupied();
};

#endif
