#ifndef GAME_MODEL_HPP_
#define GAME_MODEL_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "conf.h"

#include <cstdlib>
#include <ctime>

class GameModel {
public:
  enum State {
    NORMAL,
    WRONG,
    WON,
    FAILED
  };
  GameModel();
  void Init();
  void Submit(int guess);
  State GetState(int idx);
  int GetLifes();
private:
  void Won();
  void Failed();
  void Disable(int from, int to);
  State slots[SZ + 1];
  int secret;
  int lifes;
  const int number_of_guesses = 3;
};

#endif  // GAME_MODEL_HPP_