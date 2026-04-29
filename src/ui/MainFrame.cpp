#include "ui/MainFrame.h"
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
    this->SetSize(wxSize(1008, 567));

    wxPanel* panel = new wxPanel(this);

    wxBoxSizer* horizontalLayout = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    buttonSizer->AddStretchSpacer();

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
        wxButton* btn = new wxButton(panel, currentID, nomes[i]);
        btn->SetMinSize(wxSize(-1, 35));
        btn->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

        buttonSizer->Add(btn, 0, wxCENTER | wxBOTTOM, 10);
    }

    buttonSizer->AddStretchSpacer();

    horizontalLayout->AddStretchSpacer(1); 

    horizontalLayout->Add(buttonSizer, 1, wxALIGN_CENTER_VERTICAL);

    panel->SetSizer(horizontalLayout);
    
    CreateStatusBar(); 
    this->Centre();
}

void MainFrame::OnButtonClicked(wxCommandEvent& event)
{
    int id = event.GetId();
    wxButton* botao = static_cast<wxButton*>(event.GetEventObject());
    wxString nomeBotao = botao->GetLabel();
    wxString acao;

    switch (id) {
        case 1: 
            acao = "Solicitando lista de todas as linhas."; 
            break;
        case 2: 
            acao = "Acessando catálogo de medidores disponíveis."; 
            break;
        case 3: 
            acao = "Filtrando medidores por linha específica."; 
            break;
        case 4: 
            acao = "Exibindo banco de dados de medidores criados."; 
            break;
        case 5: 
            acao = "Filtrando medidores criados por linha."; 
            break;
        case 6: 
            acao = "Iniciando processo de cadastro de novo medidor."; 
            break;
        case 7: 
            acao = "Preparando exclusão de medidor."; 
            break;
        case 8: 
            acao = "Coletando dados de medições em tempo real."; 
            break;
        default: 
            acao = "Ação não mapeada."; 
            break;
    }   

    wxLogStatus("[ID %d] %s: %s", id, nomeBotao, acao);
}