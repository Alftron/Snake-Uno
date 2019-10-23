
#include "piece.h"

Piece::Piece() {
    
}

int Piece::getX() {
    return this->x;
}

int Piece::getY() {
    return this->y;
}

bool Piece::runsInto(Piece piece) {
    return this->getX() == piece.getX() && this->getY() == piece.getY();
}