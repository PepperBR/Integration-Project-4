#pragma once

#include "client/client.h"
#include <memory>
#include <string>
#include <vector>
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString &title);
    void OnButtonClicked(wxCommandEvent &event);

private:
    wxPanel *panelEsquerda;
    wxListBox *m_listaDados;

    wxChoice *choiceListAvailableLines;
    wxChoice *choiceListCreatedLines;
    wxChoice *choiceListOptionsCreateModels;
    wxChoice *choiceListRemoveCreatedModels;
    wxChoice *choiceListMesuareCreatedModels;

    std::unique_ptr<MeterClient> m_client;
};
