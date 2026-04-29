#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    void OnButtonClicked(wxCommandEvent& event);
private:
    wxPanel* panelEsquerda;
    wxListBox* m_listaDados;
};