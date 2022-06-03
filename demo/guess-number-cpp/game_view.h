#ifndef GAME_VIEW_HPP_
#define GAME_VIEW_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "conf.h"

#include <wx/wx.h>

class GameController;
class GameModel;

class GameView: public wxFrame {
public:
  GameView();
  void SetController(GameController *c);
  void SetModel(GameModel *m);
  void Render();
private:
  wxButton *buttons[SZ + 1];
  wxToolBar* tool_bar;
  wxButton* btn_new_game;
  wxStaticText* lbl_indicator;
  wxStaticBitmap* bmp_out_come;
  wxBitmap *bmp_won;
  wxBitmap *bmp_failed;
  wxBitmap *bmp_progress;
  GameModel *model;
  GameController *controller;
};

#endif  // GAME_VIEW_HPP_