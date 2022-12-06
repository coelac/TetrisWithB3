#include "decorator.h"

Decorator::Decorator(AbstractBoard* ab) : absBoard{ab} {}

void Decorator::applyEffect(Board &b) {
        absBoard->applyEffect(b);
}

Decorator::~Decorator() {}