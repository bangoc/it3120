#ifndef CLOCK_CONTROLLER_H_
#define CLOCK_CONTROLLER_H_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "clock_view.h"
#include "clock_model.h"

class ClockController {
private:
  wxPanel *view = nullptr;
  ClockModel *model = nullptr;
public:
  ClockController(wxPanel *my_view, ClockModel *my_model):
      view(my_view), model(my_model) {
  }
  void Tick() {
    model->Advance();
    view->Refresh();
  }
  void Reset() {
    model->Init();
    view->Refresh();
  }
};

#endif  // CLOCK_CONTROLLER_H_