#include "ui/App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame* main_frame = new MainFrame("C++ GUI");
    main_frame->Show();
    return true;
}