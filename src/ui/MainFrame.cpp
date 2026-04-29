#include "ui/MainFrame.h"

enum IDs {
    BUTTON_ID_1 = 1, 
    BUTTON_ID_2,
    BUTTON_ID_3, 
    BUTTON_ID_4,
    BUTTON_ID_5, 
    BUTTON_ID_6, 
    BUTTON_ID_7, 
    BUTTON_ID_8
};

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1008, 567),
              wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) 
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

    panelEsquerda = new wxPanel(this, wxID_ANY);
    panelEsquerda->SetBackgroundColour(wxColour(30, 30, 30));

    m_listaDados = new wxListBox(panelEsquerda, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_NEEDED_SB);
    m_listaDados->SetBackgroundColour(wxColour(45, 45, 45));
    m_listaDados->SetForegroundColour(*wxWHITE);
    m_listaDados->SetFont(wxFont(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    wxBoxSizer* vSizerEsquerda = new wxBoxSizer(wxVERTICAL);
    vSizerEsquerda->AddStretchSpacer(1);
    vSizerEsquerda->Add(m_listaDados, 3, wxEXPAND | wxLEFT | wxRIGHT, 40);
    vSizerEsquerda->AddStretchSpacer(1); 
    panelEsquerda->SetSizer(vSizerEsquerda);

    wxPanel* panelDireita = new wxPanel(this, wxID_ANY);
    wxBoxSizer* vSizerDireita = new wxBoxSizer(wxVERTICAL);
    vSizerDireita->AddStretchSpacer();

    wxArrayString nomes;
    nomes.Add("Listar linhas");
    nomes.Add("Listar todos os medidores disponíveis");
    nomes.Add("Listar medidores disponíveis da linha:");
    nomes.Add("Listar todos os medidores criados");
    nomes.Add("Listar medidores criados da linha");
    nomes.Add("Adicionar medidor");
    nomes.Add("Remover medidor");
    nomes.Add("Ler medições");

    for (size_t i = 0; i < nomes.GetCount(); ++i) {
        int currentID = BUTTON_ID_1 + i;
        wxButton* btn = new wxButton(panelDireita, currentID, nomes[i]);
        btn->SetMinSize(wxSize(-1, 35));
        btn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
        vSizerDireita->Add(btn, 0, wxCENTER | wxBOTTOM, 10);
    }
    vSizerDireita->AddStretchSpacer();
    panelDireita->SetSizer(vSizerDireita);

    mainSizer->Add(panelEsquerda, 1, wxEXPAND);
    mainSizer->Add(panelDireita, 1, wxEXPAND);

    this->SetSizer(mainSizer);
    CreateStatusBar(); 
    this->Centre();
}

void MainFrame::OnButtonClicked(wxCommandEvent& event)
{
    int id = event.GetId();
    m_listaDados->Clear(); 

    switch (id) {
        case 1:
        {
            m_listaDados->Append("--- LISTA DE LINHAS ---");
            m_listaDados->Append("Ares");
            m_listaDados->Append("Apolo");
            m_listaDados->Append("Zeus");
            m_listaDados->Append("Cronos");
            break;
        }
        case 2:
        {
            m_listaDados->Append("--- Todos os Modelos Disponíveis ---");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            break;
        }
        case 3:
        {
            m_listaDados->Append("--- Medidores Disponíveis da Linha Ares  ---");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            break;
        }
        case 4:
        {
            m_listaDados->Append("--- Todos os Medidores Criados ---");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            break;
        }
        case 5:
        {
            m_listaDados->Append("--- Medidores Criados da Linha Apolo ---");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            break;
        }
        case 6:
        {
            m_listaDados->Append("--- Novo Medidor Adicionado ---");
            m_listaDados->Append("ID: 001 -> esdrcftvgbyhnujmk,l");
            m_listaDados->Append("ID: 002 -> esdrcftvgbyhnujmk,l ");
            m_listaDados->Append("ID: 003 -> esdrcftvgbyhnujmk,l ");
            break;
        }
        case 7:
        {
            m_listaDados->Append("--- Medidor Removido ---");
            m_listaDados->Append("Sucesso");
            break;
        }
        case 8:
        {
            m_listaDados->Append("--- ESTRUTURA: MEDIÇÕES EM TEMPO REAL ---");
            m_listaDados->Append("Phase_A: 220.5 V | 10.2 A");
            m_listaDados->Append("Phase_B: 110.1 V | 05.4 A");
            break;
        }
        default:
            m_listaDados->Append(wxString::Format("Dados para o botão %d ainda não implementados.", id));
            break;
    }

    wxLogStatus("Dados carregados no display esquerdo.");
}