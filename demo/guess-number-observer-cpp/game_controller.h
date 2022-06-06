#ifndef GAME_CONTROLLER_H_
#define GAME_CONTROLLER_H_

/* (C) Nguyen Ba Ngoc 2022 */

class GameModel;

class GameController {
public:
  GameController(GameModel *model_);
  void NewGame();
  void Guess(int number);
private:
  GameModel *model;
};

#endif  // GAME_CONTROLLER_H_