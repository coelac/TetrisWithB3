#ifndef BLIND_H
#define BLIND_H
#include "abstractboard.h"
#include "decorator.h"

using namespace std;

class Blind : public Decorator {
	public:
		Blind(AbstractBoard* absBoard);
		void applyEffect(Board &b) override;
};

#endif