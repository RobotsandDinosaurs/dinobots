void Lights(int motorState) {
  unsigned long now = millis();
  if (now - lastLed > updateInterval) {
    lastLed = now;

    for (int i=0; i<7; i++) {
      leds[i] = leds[i+1];
      leds[15-i] = leds[i];
    }
    if (flapper) {
      nextHue = random(255);
      leds[7] = CHSV(nextHue, 255, 255);
    } else {
      leds[7] = CRGB::Black;
    }
    leds[8] = leds[7];
    flapper = !flapper;
    FastLED.show();
  }
}
