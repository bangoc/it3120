/* (C) Nguyen Ba Ngoc 2022 */

#include "bitmaps/blackcat.xpm"
#include "bitmaps/inspiration.xpm"
#include "bitmaps/gomechan.xpm"
#include "conf.h"
#include "game_controller.h"
#include "game_model.h"
#include "game_view.h"

#include <sstream>
#include <wx/wx.h>
#include <wx/wrapsizer.h>

GameView::GameView(): wxFrame(nullptr, wxID_ANY,
        "Time Flies", wxDefaultPosition, {480, 320}) {
  tool_bar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
  btn_new_game = new wxButton( tool_bar, wxID_ANY, wxT("New Game"),
      wxDefaultPosition, wxDefaultSize, 0 );
  tool_bar->AddControl(btn_new_game);
  btn_new_game->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
    controller->NewGame();
  });

  bmp_won = new wxBitmap(img_gomechan_xpm);
  bmp_failed = new wxBitmap(img_blackcat_xpm);
  bmp_progress = new wxBitmap(img_inspiration_xpm);

  tool_bar->AddSeparator();
  lbl_indicator = new wxStaticText(tool_bar, wxID_ANY,
      wxT("///"), wxDefaultPosition, {30, 30}, 0);
  lbl_indicator->Wrap(-1);
  lbl_indicator->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
      wxFONTWEIGHT_BOLD, false, wxEmptyString));
  tool_bar->AddControl(lbl_indicator);
  tool_bar->AddSeparator();
  bmp_out_come = new wxStaticBitmap(tool_bar, wxID_ANY,
      wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
  tool_bar->AddControl(bmp_out_come);
  tool_bar->Realize();

  wxWrapSizer* sizer;
  sizer = new wxWrapSizer( wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS );

  for (int i = 1; i <= SZ; ++i) {
    std::stringstream ss;
    ss << i;
    buttons[i] = new wxButton( this, wxID_ANY,
        ss.str(), wxDefaultPosition, {70, 30}, 0 );
    buttons[i]->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT,
        wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,
        false, wxEmptyString));
    buttons[i]->Bind(wxEVT_BUTTON, [&, i](wxCommandEvent& event) {
      controller->Guess(i);
    });
    sizer->Add(buttons[i], 0, wxALL, 5 );
  }

  this->SetSizer(sizer);
  this->Layout();
  this->Centre(wxBOTH);
}

void GameView::SetController(GameController *c) {
  controller = c;
}

void GameView::Update(GameModel *model) {
  int ended = 0;
  for (int i = 1; i <= SZ; ++i) {
    switch(model->GetState(i)) {
      case GameModel::NORMAL:
        buttons[i]->Enable(true);
        buttons[i]->SetBackgroundColour(
            wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        break;
      case GameModel::WRONG:
        buttons[i]->Enable(false);
        buttons[i]->SetBackgroundColour(
            wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        break;
      case GameModel::WON:
        ended = 1;
        bmp_out_come->SetBitmap(*bmp_won);
        buttons[i]->Enable(false);
        buttons[i]->SetBackgroundColour(wxColour(10, 246, 10));
        break;
      case GameModel::FAILED:
        ended = 2;
        bmp_out_come->SetBitmap(*bmp_failed);
        buttons[i]->Enable(false);
        buttons[i]->SetBackgroundColour(wxColour(246, 10, 10));
        break;
    }
  }
  int n = model->GetLifes();
  std::stringstream ss;
  for (int i = 0; i < n; ++i) {
    ss << "/";
  }
  lbl_indicator->SetLabel(ss.str());
  if (!ended) {
    bmp_out_come->SetBitmap(*bmp_progress);
  }
}