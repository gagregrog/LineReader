/*
  LineReader - Normalize serial events.
  Created by Robert Reed, March 6th, 2021.
  Released into the public domain.
*/

#include "Arduino.h"
#include <LineReader.h>

// constructor
LineReader::LineReader(char* buf, uint8_t bufSize)
{
  _buf = buf;
  _bufSize = bufSize;
}

// Public Members
bool LineReader::matches(int num) {
  // we do this, since we will return 0 for non-number serial input
  if (!num) {
    return matches("0");
  }

  return atoi(_buf) == num;
}

bool LineReader::matches(String str) {
  return !strcmp(_buf, str.c_str());
}

int LineReader::available()
{
  int readChar = Serial.read();

  static int pos = 0;
  int rpos;

  if (readChar > 0) {
    switch (readChar) {
      case '\r': // ignore CR
        break;
      case '\n': // return on new line
        rpos = pos;
        pos = 0; // Reset position index ready for next time
        return rpos;
      default:
        if (pos < _bufSize - 1) {
          _buf[pos++] = readChar;
          _buf[pos] = 0;
        }
    }
  }

  return 0;
}
