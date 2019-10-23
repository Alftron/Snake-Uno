
#ifndef GAME_H
#define GAME_H

#include "apple.h"
#include "worm.h"

class Game {

    public:
		Game(int width, int height);

    private:
        int width;
        int height;
        bool continues;
        Apple apple;
        Worm worm;

    protected:

    
};

#endif