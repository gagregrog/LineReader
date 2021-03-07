/*
  LineReader - Normalize serial events.
  Created by Robert Reed, March 6th, 2021.
  Released into the public domain.
*/

#ifndef LineReader_h
#define LineReader_h

#include "Arduino.h"
#include <LineReader.h>

class LineReader
{
  public:
    LineReader(char* buf, uint8_t bufSize);
    int available();
    bool matches(int num);
    bool matches(String str);
  private:
    char* _buf;
    uint8_t _bufSize;
};

#endif
