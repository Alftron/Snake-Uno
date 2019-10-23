
#ifndef GAME_H
#define GAME_H

#include "apple.h"
#include "worm.h"

class Game {

    public:
		Game(int width, int height);
        bool continueGame();
        int getHeight();
        int getWidth();
        Apple getApple();
        Worm getWorm();
        void setApple(Apple apple);
        void setWorm(Worm worm);

    private:
        int width;
        int height;
        bool continues;
        Apple apple;
        Worm worm;

    protected:
    
};

#endif