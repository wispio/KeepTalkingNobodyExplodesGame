/* Keep Talking and Nobody Explodes Bomb Replica Code*/ 


/*LIBRARIES*/
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h> //Don't really know what this it, probably for joystick.
#include <SD.h> //Probably for sd card usage
#include <Wire.h> //Try to use this later for the popper
#include <TinyWireM.h>                  // I2C Master lib for ATTinys which use USI
#include "pitches.h" //Defining frequencies for notes

/*SET PINS*/
//Menu Display
#define TFT_CS     10
#define TFT_RST    9  // you can also connect this to the Arduino reset
                      // in which case, set this #define pin to 0!
#define TFT_DC     8
#define TFT_SCLK 13   // set these to be whatever pins you like!
#define TFT_MOSI 11   //was 13 and 11 Wanna 
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

//#define SD_CS    4  // Chip select line for SD card
//#define TFT_CS  10  // Chip select line for TFT display
#define TFT_DC   8  // Data/command line for TFT
#define TFT_RST  -1  // Reset line for TFT (or connect to +5V)
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

//Failure pin is 12

//Button position definitions
#define BUTTON_NONE 0
#define BUTTON_DOWN 1
#define BUTTON_RIGHT 2
#define BUTTON_SELECT 3
#define BUTTON_UP 4
#define BUTTON_LEFT 5

//GLOBAL BOMB VARS
unsigned short numOfMod;
bool needy;
unsigned short maxTime;
bool hardcore;
unsigned short moduleArray[11] = {0};

void setup() 
{
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST7735_BLACK);
  numOfMod = selectNumberOfModules();
  needy = selectIfNeedy();
  maxTime = selectMaxTime();
  hardcore = selectIfHardcore();
  choseModules(numOfMod, needy, moduleArray);
}

//reads button
uint8_t readButton(void) {
  float a = analogRead(3);
  
  a *= 5.0;
  a /= 1024.0;
  
  Serial.print("Button read analog = ");
  Serial.println(a);
  if (a < 0.2) return BUTTON_DOWN;
  if (a < 1.0) return BUTTON_RIGHT;
  if (a < 1.5) return BUTTON_SELECT;
  if (a < 2.0) return BUTTON_UP;
  if (a < 3.2) return BUTTON_LEFT;
  else return BUTTON_NONE;
}
uint8_t buttonhistory = 0;

void loop() {
  
}

unsigned short selectNumberOfModules() 
{
 int mods;
 bool buttonState;
 bool selector;
 while(selector == false)
 {
  //Select Number of Modules
  if(buttonState == true)
    selector == true;
 }
 return mods;
}

bool selectIfNeedy()
{
  true;
  //Select on screen
  if(true)
    return true;
  else
    return false;
}

unsigned short selectMaxTime() //Returns amount of 30 second intervals
{
  short timelimit;
  bool buttonpress;
  while (true)
  {
    //select max time
    //afterwards, exit loop and return max time
    if(buttonpress == true)
      false;
  }
  return timelimit;
}

bool selectIfHardcore()
{
  bool buttonPress;
  bool selection;
  while (true)
  {
    //SelectTimeLimit Here
    if (buttonPress == true)
      false;
  }
  return selection;
}

void choseModules(unsigned int mods, bool needy, unsigned short mArray[])
{
  srand(millis());
  unsigned int posOfNeedy = rand() % mods;
  for(int i = 0; i < mods; i++)
  {
    if (needy == true)
    {
      mArray [posOfNeedy] = 11+ rand()%3;
    }
    if(i==posOfNeedy)
    {
      continue;
    }
    mArray[i] = rand() % 11;
  }
}

//Explode the party popper
void explode()
{
  pinMode(12, OUTPUT);
  while (true) digitalWrite(13, HIGH); //Hook up party popper and greeting card to it. 
}

