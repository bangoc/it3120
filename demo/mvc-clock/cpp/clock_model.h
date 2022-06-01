#ifndef CLOCK_MODEL_H_
#define CLOCK_MODEL_H_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <ctime>

class ClockModel {
private:
  int seconds;
public:
  ClockModel() {
    Init();
  }
  int GetHour() {
    int h = seconds / 3600;
    if (h > 12) {
      h %= 12;
    }
    return h;
  }
  int GetMinute() {
    return (seconds % 3600) / 60;
  }
  int GetSecond() {
    return seconds % 60;
  }
  void Advance() {
    ++seconds;
  }
  void Init() {
    time_t cur;
    struct tm *loc;
    time(&cur);
    loc = localtime(&cur);
    seconds = loc->tm_hour * 3600 + loc->tm_min * 60 + loc->tm_sec;
  }
};

#endif  // CLOCK_MODEL_H_