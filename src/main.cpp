#include <Arduino.h>

#include "game.h"

static int seedPin = A0;

void setup() {
	randomSeed(analogRead(seedPin));
}

void loop() {
    Game game = Game(300, 200);

}