
#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
        Piece(int x, int y);
        int getX();
        int getY();
        bool runsInto(Piece piece);

    private:

    protected:
        int x;
        int y;

};

#endif