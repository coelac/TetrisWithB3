#ifndef ABSBOARD_H
#define ABSBOARD_H

class Board;

class AbstractBoard {
    public:
        virtual void applyEffect(Board &board) = 0;
};

#endif