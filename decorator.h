#ifndef DECORATOR_H
#define DECORATOR_H
#include "abstractboard.h"

class Decorator : public AbstractBoard {
    protected:
	    AbstractBoard* absBoard;
    public:
        Decorator(AbstractBoard* absboard);
        void applyEffect(Board &b) override;
        virtual ~Decorator();
};

#endif