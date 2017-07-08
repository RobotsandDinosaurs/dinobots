void Lights(int motorState) {
  unsigned long now = millis();
  if (now - lastLed > updateInterval) {
    lastLed = now;
    nextHue = random(255);
    switch(motorState) {
    case 0: // Nothing. Don't change the lights.
      break;
    case 1: // turning left; left forwards right backwards
      leftForwards();
      rightBackwards();
      if (flapper) {
        leds[7] = CHSV(nextHue, 255, 255);
        leds[15] = CHSV(nextHue, 255, 255);
      } else {
        leds[7] = CRGB::Black;
        leds[15] = CRGB::Black;
      }
      break;
    case 2: // turning right; left backwards right forwards
      leftBackwards();
      rightForwards();
      if (flapper) {
        leds[0] = CHSV(nextHue, 255, 255);
        leds[8] = CHSV(nextHue, 255, 255);
      } else {
        leds[0] = CRGB::Black;
        leds[8] = CRGB::Black;
      }
      break;
    case 3: // going backward; left backwards right backwards
      leftBackwards();
      rightBackwards();
      if (flapper) {
        leds[0] = CHSV(nextHue, 255, 255);
        leds[15] = CHSV(nextHue, 255, 255);
      } else {
        leds[0] = CRGB::Black;
        leds[15] = CRGB::Black;
      }
      break;
    case 4: // foing forward; left forwards right forwards
      leftForwards();
      rightForwards();
      if (flapper) {
        leds[7] = CHSV(nextHue, 255, 255);
        leds[8] = CHSV(nextHue, 255, 255);
      } else {
        leds[7] = CRGB::Black;
        leds[8] = CRGB::Black;
      }
      break;
    }
    flapper = !flapper;
    FastLED.show();
  }
}

void leftForwards() {
  leds[0] = leds[1];
  leds[1] = leds[2];
  leds[2] = leds[3];
  leds[3] = leds[4];
  leds[4] = leds[5];
  leds[5] = leds[6];
  leds[6] = leds[7];
}

void leftBackwards() {
  leds[7] = leds[6];
  leds[6] = leds[5];
  leds[5] = leds[4];
  leds[4] = leds[3];
  leds[3] = leds[2];
  leds[2] = leds[1];
  leds[1] = leds[0];
}

void rightForwards() {
  leds[15] = leds[14];
  leds[14] = leds[13];
  leds[13] = leds[12];
  leds[12] = leds[11];
  leds[11] = leds[10];
  leds[10] = leds[9];
  leds[9] = leds[8];
}

void rightBackwards() {
  leds[8] = leds[9];
  leds[9] = leds[10];
  leds[10] = leds[11];
  leds[11] = leds[12];
  leds[12] = leds[13];
  leds[13] = leds[14];
  leds[14] = leds[15];
}
