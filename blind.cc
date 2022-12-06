#include "blind.h"
#include "board.h"

Blind::Blind(AbstractBoard* ab) : Decorator{ab} {}

void Blind::applyEffect(Board &b) {
	absBoard->applyEffect(b);
    b.setIsBlind(true);
}