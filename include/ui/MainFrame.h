#pragma once
#include <wx/wx.h>
#include "client/client.h"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    void OnButtonClicked(wxCommandEvent& event);
private:
    wxPanel* panelEsquerda;
    wxListBox* m_listaDados;

    wxChoice* choice;
    std::unique_ptr<MeterClient> m_client;
};