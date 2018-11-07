// Pin defines
// These are the pins for the shield!
#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// LCD details
#define LCDIDENTIFIER 0x9341
#define LANDSCAPE_USBL 0x03
#define LANDSCAPE_USBR 0x01

// Button defines
#define BUTTON_X 140
#define BUTTON_Y 100
#define BUTTON_W 200
#define BUTTON_H 120
#define BUTTON_TEXTSIZE 3

// Touchscreen defines
#define MINPRESSURE 10
#define MAXPRESSURE 1000
#define TS_MINX 70
#define TS_MAXX 920
#define TS_MINY 120
#define TS_MAXY 900

// Snake defines
#define SNAKEHEADSIZE 10
#define MAXVELOCITY 10
