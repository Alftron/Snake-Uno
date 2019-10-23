
#ifndef APPLE_H
#define APPLE_H

#include "piece.h"
#include <Arduino.h>

class Apple : Piece {
    public:
        Apple();

    private:
        int randomX;
        int randomY;

    protected:
        
};

#endif