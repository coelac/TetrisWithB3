#include "heavy.h"
#include "heavy.h"
#include "board.h"

Heavy::Heavy(AbstractBoard* ab) : Decorator{ab} {}

void Heavy::applyEffect(Board &b) {
	absBoard->applyEffect(b);
    b.setIsHeavy(true);
}