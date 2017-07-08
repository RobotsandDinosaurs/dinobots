void Lights(int motorState) {
  unsigned long now = millis();
  if (now - lastLed > updateInterval) {
    lastLed = now;
    nextHue += 10;
    switch(motorState) {
    case 0: // Nothing. Don't change the lights.
      break;
    default:
      leftForwards();
      rightForwards();
      leds[4] = CHSV(nextHue, 255, 255);
      leds[5] = CHSV(nextHue, 255, 255);
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
}

void rightForwards() {
  leds[9] = leds[8];
  leds[8] = leds[7];
  leds[7] = leds[6];
  leds[6] = leds[5];
}
