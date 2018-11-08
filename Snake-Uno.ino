#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>
#include "defines.h"

// LCD business
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

// Button business
Elegoo_GFX_Button startButton, resetButton;

// Touchscreen business
// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// Globals
bool g_screenDrawn = false;
bool g_gameRunning = false;
bool g_gameOver = false;
int g_snakeHeadX;
int g_snakeHeadY;
int g_velocity = 1;

void setup()
{
    Serial.begin(9600);
    Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());
    tft.reset();
    tft.begin(LCDIDENTIFIER);
    tft.setRotation(LANDSCAPE_USBL);
    g_gameRunning = false;
    drawMainMenu();
    resetSnakePos();
}

void loop()
{
    while (!g_gameRunning && !g_gameOver)
    {
        pollMainMenu();
    }

    while (!g_gameRunning && g_gameOver)
    {
        // GAME OVER SCREEN
        pollGameOver();
    }

    while (g_gameRunning)
    {
        // GAME SCREEN
        if (!g_screenDrawn)
        {
            drawGameBoard();
        }
        pollSnakePos();
    }
}

void drawGameBoard()
{
    tft.fillScreen(BLACK);
    tft.drawRect(0,0,320,240,WHITE);
    // Draw the snake starting in the middle of the screen
    tft.fillRect(g_snakeHeadX, g_snakeHeadY, SNAKEHEADSIZE, SNAKEHEADSIZE, WHITE);
    g_screenDrawn = true;
}

void drawGameOver()
{
    tft.fillScreen(BLACK);
    // create buttons
    resetButton.initButton(&tft, tft.width()/2, tft.height()/2, BUTTON_W, BUTTON_H, WHITE, BLACK, WHITE, "Restart?", BUTTON_TEXTSIZE);
    resetButton.drawButton();
}

void drawMainMenu()
{
    tft.fillScreen(BLACK);
    // create buttons
    startButton.initButton(&tft, tft.width()/2, tft.height()/2, BUTTON_W, BUTTON_H, WHITE, BLACK, WHITE, "Start!", BUTTON_TEXTSIZE);
    startButton.drawButton();
}

void pollGameOver()
{
    // GAME OVER SCREEN
    TSPoint p = ts.getPoint();
    if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
    {
        // scale from 0->1023 to tft.width
        p.x = (tft.width() - map(p.x, TS_MINX, TS_MAXX, tft.width(), 0));
        p.y = (tft.height()-map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
    }

    if (resetButton.contains(p.x, p.y))
    {
        resetButton.press(true);
    }
    else
    {
        resetButton.press(false);
    }

    if (resetButton.justPressed())
    {
        Serial.println("Reset button pressed!");
        resetButton.drawButton(true);
        delay(100);
        while (ts.isTouching())
        {
            // Loop here aimlessly if we're holding the reset button
        }  
    }

    if (resetButton.justReleased())
    {
        restartGame();
    }
}

void pollMainMenu()
{
        // START SCREEN
        TSPoint p = ts.getPoint();
        if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
        {
            // scale from 0->1023 to tft.width
            p.x = (tft.width() - map(p.x, TS_MINX, TS_MAXX, tft.width(), 0));
            p.y = (tft.height()-map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
        }

        if (startButton.contains(p.x, p.y))
        {
            startButton.press(true);
        }
        else
        {
            startButton.press(false);
        }

        if (startButton.justPressed())
        {
            Serial.println("Start button pressed!");
            startButton.drawButton(true);
            delay(100);
            while (ts.isTouching())
            {
                // Loop here aimlessly if we're holding the start button
            }
        }

        if (startButton.justReleased())
        {
            g_gameRunning = true;
        }
}
void pollSnakePos()
{
    g_snakeHeadX += g_velocity;
    Serial.println (g_snakeHeadX);
    // Move our snake horizontally
    tft.fillRect(g_snakeHeadX, g_snakeHeadY, SNAKEHEADSIZE, SNAKEHEADSIZE, WHITE);

    // Erase path behind the snake horizontally
    tft.fillRect((g_snakeHeadX-SNAKEHEADSIZE)-g_velocity, g_snakeHeadY, SNAKEHEADSIZE, SNAKEHEADSIZE, BLACK);

    // Check if we've touched the walls
    if (g_snakeHeadX == 0 || g_snakeHeadX == 320 || g_snakeHeadY == 0 || g_snakeHeadY == 240)
    {
        g_gameOver = true;
        g_gameRunning = false;
        drawGameOver();
    }
}

void resetSnakePos()
{
    // Reset snake to the starting position
    // Set where our snake will be starting
    g_snakeHeadX = tft.width()/2;
    g_snakeHeadY = tft.height()/2;
}

void restartGame();
{
    // A little function we can use to easily restart the game
    // Force a game screen redraw
    g_screenDrawn = false;
    g_gameRunning = true;
    resetSnakePos();
}
