#include "square.h"

Square::Square() : isOccupied{false} {}

void Square::setSquare(char newChar) {
  setChar = newChar;
  isOccupied = true;
}

char Square::print() {
  if (isOccupied) {
	  return setChar;
  } else {
	  return ' ';
  }
}

bool Square::squareOccupied() {
  return isOccupied;
}