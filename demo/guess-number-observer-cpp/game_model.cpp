/* (C) Nguyen Ba Ngoc 2022 */

#include "conf.h"

#include "game_model.h"
#include "observer.h"

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
  Notify();
}

void GameModel::Submit(int guess) {
  if (guess == secret) {
    Won();
    Notify();
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
  Notify();
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

void GameModel::Notify() {
  for (auto it = observers.begin(); it != observers.end(); ++it) {
    it->first->Update(this);
  }
}

void GameModel::Attach(Observer *o) {
  observers[o] = 1;
  Notify();
}

void GameModel::Detach(Observer *o) {
  auto it = observers.find(o);
  if (it != observers.end()) {
    observers.erase(it);
  }
}