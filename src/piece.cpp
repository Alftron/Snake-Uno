
#include "piece.h"

Piece::Piece(int x1, int y1) {
    this->x = x1;
    this->y = y1;
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