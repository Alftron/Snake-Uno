
#ifndef WORM_H
#define WORM_H

#include "piece.h"
#include "direction.h"
#include <ArduinoSTL.h>

class Worm : Piece {
	public:
        Worm(int x, int y, Direction originalDirection);
        Direction getDirection();
		void setDirection(Direction direction);
		void move();

	private:
        Direction direction;
        bool grow;
		std::vector<Piece> worm;

	protected:
};

#endif