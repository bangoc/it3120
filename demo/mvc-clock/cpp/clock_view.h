#ifndef CLOCK_VIEW_H_
#define CLOCK_VIEW_H_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <cmath>
#include <wx/wx.h>

#include "clock_model.h"

class ClockView: public wxPanel {
  private:
    ClockModel *model = nullptr;
  public:
    ClockView(wxWindow *parent,
            ClockModel *my_model = nullptr,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr):
        model(my_model), wxPanel(parent, winid, pos, size, style, name) {
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        wxPaintDC dc(this);
        dc.DrawCircle(180, 100, 80);
        double hour_angle = 2 * M_PI * (model->GetHour() - 3) / 12;
        double minute_angle = 2 * M_PI * (model->GetMinute() - 15) / 60;
        double second_angle = 2 * M_PI * (model->GetSecond() - 15) / 60;
        dc.DrawLine(180, 100,
                    180 + (int)(30 * std::cos(hour_angle)),
                    100 + (int)(30 * std::sin(hour_angle)));
        dc.DrawLine(180, 100,
                    180 + (int)(46 * std::cos(minute_angle)),
                    100 + (int)(46 * std::sin(minute_angle)));
        dc.DrawLine(180, 100,
                    180 + (int)(46 * std::cos(second_angle)),
                    100 + (int)(46 * std::sin(second_angle)));
      });
    }
  };

#endif  // CLOCK_VIEW_H_