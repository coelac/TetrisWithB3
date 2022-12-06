#ifndef HEAVY_H
#define HEAVY_H
#include "abstractboard.h"
#include "decorator.h"

using namespace std;

class Heavy : public Decorator {
	public:
		Heavy(AbstractBoard* absBoard);
		void applyEffect(Board &b) override;
};

#endif