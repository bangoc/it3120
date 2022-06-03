/* (C) Nguyen Ba Ngoc 2022 */

#include "game_controller.h"
#include "game_model.h"
#include "game_view.h"

class Application : public wxApp {
  bool OnInit() override {
    view = new GameView();
    model = new GameModel();
    controller = new GameController(model);
    view->SetModel(model);
    view->SetController(controller);
    view->Show();
    return true;
  }
  int OnExit() override {
    delete model;

    // TODO: view should be freed automatically by wxwidgets??
    // delete view;

    delete controller;
    return wxApp::OnExit();
  }
private:
  GameView *view;
  GameModel *model;
  GameController *controller;
};

wxIMPLEMENT_APP(Application);