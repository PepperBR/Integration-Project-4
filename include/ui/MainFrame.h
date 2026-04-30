#pragma once

#include <wx/wx.h>
#include <memory>
#include <vector>
#include <string>
#include "client/client.h"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    void OnButtonClicked(wxCommandEvent& event);

private:
    wxPanel* panelEsquerda;
    wxListBox* m_listaDados;

    wxChoice* choiceListAvailableLines;
    wxChoice* choiceListCreatedLines;
    wxChoice* choiceListOptionsCreateModels;
    wxChoice* choiceListRemoveCreatedModels;
    wxChoice* choiceListMesuareCreatedModels;

    std::unique_ptr<MeterClient> m_client;
};
