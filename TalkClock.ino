#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUMPIXELS 64

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int pixel[8][8] = { 0 };
int pixelArr[64] = { 0 };
int digitCounter = 0;

int row = sizeof(pixel)/sizeof(pixel[0]);
int column = sizeof(pixel[0])/sizeof(pixel[0][0]);

unsigned long time;

int pixelZero[8][8] = {
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

int pixelOne[8][8] = {
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

int pixelTwo[8][8] = {
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

int pixelThree[8][8] = {
  { 0, 0, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

 int pixelFour[8][8] = {
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };
 
int pixelFive[8][8] = {
  { 0, 0, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

int pixelSix[8][8] = {
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

int pixelSeven[8][8] = {
  { 0, 0, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

int pixelEight[8][8] = {
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

int pixelNine[8][8] = {
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

int pixelClear[8][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  };

void setZero() { 
  setPixelArr(pixelZero);  
}

void setOne() {
  setPixelArr(pixelOne);  
}

void setTwo() {
  setPixelArr(pixelTwo);  
}

void setThree() {
  setPixelArr(pixelThree);  
}

void setFour() {
  setPixelArr(pixelFour);  
}

void setFive() {
  setPixelArr(pixelFive);  
}

void setSix() {
  setPixelArr(pixelSix);  
}

void setSeven() {
  setPixelArr(pixelSeven);  
}

void setEight() {
  setPixelArr(pixelEight);  
}

void setNine() {
  setPixelArr(pixelNine);  
}

void clearPixel() {
  setPixelArr(pixelClear);  
}

void setup() {

  pixels.begin();
  // put your setup code here, to run once:
  //Serial.begin(9600); //start serial communication
  //pinMode(analInput, INPUT);


}

int setPixelArr(int pxlArr[8][8])
{
  int i = 0;
  for (int x=0; x<row; x++) {
    for (int y=0; y<column; y++) {
      pixelArr[i] = pxlArr[x][y];
      i++;
    }
  }
}

void setDigit(int digit) {  
  switch (digit) {
    case 0:
        setZero();
       break;
     case 1:
        setOne();
       break;
     case 2:
        setTwo();
       break;
     case 3:
        setThree();
       break;
     case 4:
        setFour();
       break;
     case 5:
        setFive();
       break;
     case 6:
       setSix();
       break;
     case 7:
        setSeven();
       break;
     case 8:
        setEight();
       break;
     case 9:
        setNine();
       break;
     default:
        setZero();
        break;
  }
}

void updatePanel() {
  for (int i=0;i<NUMPIXELS;i++) {
    if (pixelArr[i] != 0) {
      pixels.setPixelColor(i, pixels.Color(10,0,0));
    } else {
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    pixels.show();
  } 
}

void loop() {
  setDigit(digitCounter); 
  updatePanel();
  digitCounter = ++digitCounter % 10;
  do {
      delay(1);
  } while ((millis() - time) < 1000);
  time = millis();
}
