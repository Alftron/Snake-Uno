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
bool gameRunning;

void setup()
{
  Serial.begin(9600);
  Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());
  tft.reset();
  tft.begin(LCDIDENTIFIER);
  tft.setRotation(LANDSCAPE_USBL);
  gameRunning = false;
  drawMainMenu();
}

void loop()
{
    while (!gameRunning)
        // Waiting for our game to start by pressing the start button
    {
        //digitalWrite(13, HIGH);
        TSPoint p = ts.getPoint();
        //digitalWrite(13, LOW);
        // For some reason if we're sharing pins like we do on the shield we need to force the pinmodes on shared pins
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
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
            gameRunning = true;
            drawGameBoard();
        }
    }

    while (gameRunning)
    {
        // Our game has started!
    }

}

void drawGameBoard()
{
    tft.fillScreen(BLACK);
    tft.drawRect(0,0,320,240,WHITE);
}

void drawMainMenu()
{
    tft.fillScreen(BLACK);
    // create buttons
    startButton.initButton(&tft, tft.width()/2, tft.height()/2, BUTTON_W, BUTTON_H, WHITE, BLACK, WHITE, "Start!", BUTTON_TEXTSIZE);
    startButton.drawButton();
}
