#include "main_window.h"

class Application : public wxApp {
  bool OnInit() override {
    (new MainWindow())->Show();
    return true;
  }
};

wxIMPLEMENT_APP(Application);