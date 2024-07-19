#include <Arduino.h>
#include <TFT_eSPI.h>
#include "walk.h"

TFT_eSPI   tft;

const size_t img_width = 114;
const size_t img_height = 180;

const int tftMiddleWidth = tft.width() / 2;
const int tftMiddleHeight = tft.width() / 2;

const int xPos = tftMiddleWidth - img_width / 2;
const int yPos = tftMiddleHeight - img_height / 2;

size_t currentFrame = 0;

void setup() {
    Serial.begin(115200);
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_WHITE);
    tft.setTextDatum(TC_DATUM);
    tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
}

void loop() {
    tft.pushImage(xPos, yPos, img_width, img_height, images[currentFrame++]);
    // tft.drawString(String(currentFrame), tftMiddleWidth, tftMiddleHeight, 4);
    currentFrame %= images_count;

    delay(40);
}
