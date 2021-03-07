/*
  LineReader - Normalize serial events.
  Created by Robert Reed, March 6th, 2021.
  Released into the public domain.
*/

/*
Reader Setup ----------------------------------------------------------------
*/

#include <Arduino.h>
#include <LineReader.h>

// determine the maximum length of the message you will be receiving
const uint8_t bufSize = 80;

// create a buffer to store the received message
char buf[bufSize];

LineReader reader(buf, bufSize);

void setup() {
  // Don't forget to listen to Serial events!
  Serial.begin(115200);
  delay(250);
}

void loop() {
  // Serial data was sent and terminated with a line ending
  if (reader.available()) {
    Serial.print("Message received: ");
    Serial.println(buf);

    if (!strcmp(buf, "__INIT__")) {
      Serial.println("Received initialization request!");
    }
  }
}
