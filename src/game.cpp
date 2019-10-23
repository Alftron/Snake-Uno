
#include "game.h"

Game::Game(int width, int height) {
	this->width = width;
	this->height = height;
    this->continues = true;
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

Apple Game::getApple() {
    return this->apple;
}

Worm Game::getWorm() {
    return this->worm;
}

void Game::setApple(Apple apple) {
    this->apple = apple;
}

void Game::setWorm(Worm worm) {
    this->worm = worm;
}
