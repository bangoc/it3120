/* (C) Nguyen Ba Ngoc 2022 */

#include "game_model.h"
#include "game_view.h"

class Application : public wxApp {
  bool OnInit() override {
    view = new GameView();
    model = new GameModel();
    model->Attach(view);
    view->Show();
    return true;
  }
  int OnExit() override {
    delete model;

    // TODO: view should be freed automatically by wxwidgets??
    // delete view;

    return wxApp::OnExit();
  }
private:
  GameView *view;
  GameModel *model;
};

wxIMPLEMENT_APP(Application);