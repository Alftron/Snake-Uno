
#ifndef GAME_H
#define GAME_H

#include "apple.h"
#include "worm.h"
#include "direction.h"

class Game {
    public:
		Game(int width, int height);
        bool continueGame();
        int getHeight();
        int getWidth();
        void createApple();
        Apple* getApple();
        Worm* getWorm();

    private:
        int width;
        int height;
        bool continues;
        Apple* apple;
        Worm* worm;

    protected:
    
};

#endif