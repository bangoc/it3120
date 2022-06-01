#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <wx/wx.h>

#include "clock_view.h"
#include "clock_controller.h"

class MainWindow : public wxFrame {
public:
  MainWindow(): wxFrame(nullptr, wxID_ANY, "Clock MVC", wxDefaultPosition, {400, 320}) {
    button_tick->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      controller->Tick();
    });

    button_reset->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      controller->Reset();
    });
  }
  ~MainWindow() {
    delete model;
    delete controller;
  }

private:
  ClockModel *model = new ClockModel();
  wxPanel* view = new ClockView(this, model, wxID_ANY, {10, 10}, {380, 200});
  ClockController *controller = new ClockController(view, model);
  wxPanel* control = new wxPanel(this, wxID_ANY, {10, 220}, {380, 60});
  wxButton* button_tick = new wxButton(control, wxID_ANY, "Tick", {80, 10});
  wxButton* button_reset = new wxButton(control, wxID_ANY, "Reset", {200, 10});
};

#endif  // MAIN_WINDOW_H_