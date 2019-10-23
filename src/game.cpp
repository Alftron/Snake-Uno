
#include "game.h"

Game::Game(int width, int height) {
	this->width = width;
	this->height = height;
    this->continues = true;
    createApple();
    this->worm = new Worm(width/2, height/2, Direction::DOWN);
}

bool Game::continueGame() {
    return this->continues;
}

int Game::getHeight() {
    return this->height;
}

int Game::getWidth() {
    return this->width;
}

void Game::createApple() {
    this->apple = new Apple(0,0);
}

Apple *Game::getApple() {
    return this->apple;
}

Worm *Game::getWorm() {
    return this->worm;
}
