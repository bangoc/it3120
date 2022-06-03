/* (C) Nguyen Ba Ngoc 2022 */

#include "conf.h"

#include "game_model.h"

#ifdef DEBUG
  #include <iostream>
#endif

#include <cstdlib>
#include <ctime>

GameModel::GameModel() {
  std::srand(std::time(NULL));
  Init();
}

void GameModel::Init() {
  secret = std::rand() % SZ + 1;
#ifdef DEBUG
  std::cout << secret << std::endl;
#endif  // DEBUG
  for (int i = 0; i <= SZ; ++i) {
    slots[i] = NORMAL;
  }
  lifes = number_of_guesses;
}

void GameModel::Submit(int guess) {
  if (guess == secret) {
    Won();
    return;
  }
  if (guess < secret) {
    Disable(1, guess);
  } else {
    Disable(guess, SZ);
  }
  --lifes;
  if (lifes < 1) {
    Failed();
  }
}

int GameModel::GetLifes() {
  return lifes;
}

void GameModel::Won() {
  for (int i = 1; i <= SZ; ++i) {
    slots[i] = WRONG;
  }
  slots[secret] = WON;
}

void GameModel::Failed() {
  for (int i = 1; i <= SZ; ++i) {
    slots[i] = WRONG;
  }
  slots[secret] = FAILED;
}

void GameModel::Disable(int from, int to) {
  for (int i = from; i <= to; ++i) {
    slots[i] = WRONG;
  }
}

GameModel::State GameModel::GetState(int idx) {
  return slots[idx];
}