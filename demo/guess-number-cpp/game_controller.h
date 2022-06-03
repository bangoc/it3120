#ifndef GAME_CONTROLLER_H_
#define GAME_CONTROLLER_H_

/* (C) Nguyen Ba Ngoc 2022 */

class GameModel;
class GameView;

class GameController {
public:
  GameController(GameModel *model_);
  void NewGame();
  void Guess(int number);
  void SetView(GameView *v);
private:
  GameModel *model;
  GameView *view;
};

#endif  // GAME_CONTROLLER_H_