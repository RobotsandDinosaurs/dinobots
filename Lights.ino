void Lights(int motorState) {
  unsigned long now = millis();
  if (now - lastRainbow > updateInterval) {
    Serial.println("Doing the lights thing");
    lastRainbow = now;
    nextHue += 10;
    switch(motorState) {
    case 0: // Nothing. Don't change the lights.
      break;
    default:
      leftForwards();
      rightForwards();
      leds[3] = CHSV(nextHue, 255, 255);
      break;
    }
    FastLED.show();
  }
  if (motorState > 0) {
    if (now - lastLed > ledInterval) {
      lastLed = now;
      digitalWrite(ledPin, flapper);
      flapper = !flapper;
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void leftForwards() {
  leds[0] = leds[1];
  leds[1] = leds[2];
  leds[2] = leds[3];
}

void rightForwards() {
  leds[6] = leds[5];
  leds[5] = leds[4];
  leds[4] = leds[3];
}
