/* (C) Nguyen Ba Ngoc 2022 */

#include "game_controller.h"
#include "game_model.h"
#include "game_view.h"

GameController::GameController(GameModel *model_)
    : model(model_){
}

void GameController::NewGame() {
  model->Init();
}

void GameController::Guess(int number) {
  model->Submit(number);
}