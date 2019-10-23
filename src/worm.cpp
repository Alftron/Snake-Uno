
#include "worm.h"

Worm::Worm(int x, int y, Direction originalDirection) {
    this->x = x;
    this->y = y;
    this->direction = originalDirection;
    this->grow = false;
}

Direction Worm::getDirection() {
	return this->direction;
}

void Worm::setDirection(Direction direction) {
	this->direction = direction;
}

void Worm::move() {
	int dx;
	int dy;
	switch (getDirection()) {
		case UP:
			dy--;
			break;
		case RIGHT:
			dx++;
			break;
		case DOWN:
			dy++;
			break;
		case LEFT:
			dx--;
			break;
	}
}