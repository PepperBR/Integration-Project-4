#include "ui/MainFrame.h"

const std::vector<std::string> lines = {"Apolo", "Ares", "Cronos", "Zeus"};

const std::vector<std::string> meters = {
    "Apolo 6031", "Zeus 8021", "Zeus 8023", "Zeus 8031",
    "Cronos 7023", "Cronos 7023 L", "Cronos 7023 2.5", "Cronos 6021 L",
    "Cronos 6021 A", "Cronos 6003", "Cronos 6001 A", "Ares 7021", "Ares 8023",
    "Ares 7023", "Ares 7031", "Ares 8023 15", "Ares 8023 200"
};

enum IDs {
    BUTTON_ID_1 = 1, 
    BUTTON_ID_2,
    CHOICE_ID_3, 
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
    auto channel = grpc::CreateChannel("localhost:50055", grpc::InsecureChannelCredentials());
    m_client = std::make_unique<MeterClient>(channel);

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
    
    wxArrayString choicesListAvailableLines;
    choicesListAvailableLines.Add("Medidores Disponíveis da Linha");
    choicesListAvailableLines.Add("Medidores Disponíveis de Apolo");
    choicesListAvailableLines.Add("Medidores Disponíveis de Ares");
    choicesListAvailableLines.Add("Medidores Disponíveis de Cronos");
    choicesListAvailableLines.Add("Medidores Disponíveis de Zeus");

    wxArrayString choicesListCreatedLines;
    choicesListCreatedLines.Add("Medidores Criados da Linha");
    choicesListCreatedLines.Add("Medidores Criados de Apolo");
    choicesListCreatedLines.Add("Medidores Criados de Ares");
    choicesListCreatedLines.Add("Medidores Criados de Cronos");
    choicesListCreatedLines.Add("Medidores Criados de Zeus");

    wxArrayString choicesListOptionsCreateModels;
    choicesListOptionsCreateModels.Add("Adicionar Novo Medidor");
    choicesListOptionsCreateModels.Add("Adicionar Novo Apolo 6031");
    choicesListOptionsCreateModels.Add("Adicionar Novo Zeus 8021");
    choicesListOptionsCreateModels.Add("Adicionar Novo Zeus 8023");
    choicesListOptionsCreateModels.Add("Adicionar Novo Zeus 8031");
    choicesListOptionsCreateModels.Add("Adicionar Novo Cronos 7023");
    choicesListOptionsCreateModels.Add("Adicionar Novo Cronos 7023 L");
    choicesListOptionsCreateModels.Add("Adicionar Novo Cronos 7023 2.5");
    choicesListOptionsCreateModels.Add("Adicionar Novo Cronos 6021 L");
    choicesListOptionsCreateModels.Add("Adicionar Novo Cronos 6021 A");
    choicesListOptionsCreateModels.Add("Adicionar Novo Cronos 6003");
    choicesListOptionsCreateModels.Add("Adicionar Novo Cronos 6001 A");
    choicesListOptionsCreateModels.Add("Adicionar Novo Ares 7021");
    choicesListOptionsCreateModels.Add("Adicionar Novo Ares 8023");
    choicesListOptionsCreateModels.Add("Adicionar Novo Ares 7023");
    choicesListOptionsCreateModels.Add("Adicionar Novo Ares 7031");
    choicesListOptionsCreateModels.Add("Adicionar Novo Ares 8023 15");
    choicesListOptionsCreateModels.Add("Adicionar Novo Ares 8023 200");

    wxArrayString choicesListRemoveCreatedModels;
    choicesListRemoveCreatedModels.Add("Remover Medidor ");

    wxArrayString choicesListMesuareCreatedModels;
    choicesListMesuareCreatedModels.Add("Ler Medições do Medidor ");
    
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
        wxSize defaultButtonSize = wxSize(340, 35);

        if (i == 2) {
            choiceListAvailableLines = new wxChoice(panelDireita, currentID, wxDefaultPosition, defaultButtonSize, choicesListAvailableLines);
            choiceListAvailableLines->Select(0);
            choiceListAvailableLines->Bind(wxEVT_CHOICE, &MainFrame::OnButtonClicked, this);
            vSizerDireita->Add(choiceListAvailableLines, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
        } else if (i == 4) {
            choiceListCreatedLines = new wxChoice(panelDireita, currentID, wxDefaultPosition, defaultButtonSize, choicesListCreatedLines);
            choiceListCreatedLines->Select(0);
            choiceListCreatedLines->Bind(wxEVT_CHOICE, &MainFrame::OnButtonClicked, this);
            vSizerDireita->Add(choiceListCreatedLines, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
        } else if (i == 5) {
            choiceListOptionsCreateModels = new wxChoice(panelDireita, currentID, wxDefaultPosition, defaultButtonSize, choicesListOptionsCreateModels);
            choiceListOptionsCreateModels->Select(0);
            choiceListOptionsCreateModels->Bind(wxEVT_CHOICE, &MainFrame::OnButtonClicked, this);
            vSizerDireita->Add(choiceListOptionsCreateModels, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
        } else if (i == 6) {
            choiceListRemoveCreatedModels = new wxChoice(panelDireita, currentID, wxDefaultPosition, defaultButtonSize, choicesListRemoveCreatedModels);
            choiceListRemoveCreatedModels->Select(0);
            choiceListRemoveCreatedModels->Bind(wxEVT_CHOICE, &MainFrame::OnButtonClicked, this);
            vSizerDireita->Add(choiceListRemoveCreatedModels, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
        } else if (i == 7) {
            choiceListMesuareCreatedModels = new wxChoice(panelDireita, currentID, wxDefaultPosition, defaultButtonSize, choicesListMesuareCreatedModels);
            choiceListMesuareCreatedModels->Select(0);
            choiceListMesuareCreatedModels->Bind(wxEVT_CHOICE, &MainFrame::OnButtonClicked, this);
            vSizerDireita->Add(choiceListMesuareCreatedModels, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
        } else {
            wxButton* button = new wxButton(panelDireita, currentID, nomes[i], wxDefaultPosition, defaultButtonSize, wxBU_LEFT);
            button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
            vSizerDireita->Add(button, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);
        }
    }
    vSizerDireita->AddStretchSpacer();
    panelDireita->SetSizer(vSizerDireita);

    mainSizer->Add(panelDireita, 1, wxEXPAND);
    mainSizer->Add(panelEsquerda, 1, wxEXPAND);

    this->SetSizer(mainSizer);
    CreateStatusBar(); 
    this->Centre();
}

void MainFrame::OnButtonClicked(wxCommandEvent& event)
{
    int selection_index_1 = choiceListAvailableLines->GetSelection();
    int selection_index_2 = choiceListCreatedLines->GetSelection();
    int selection_index_3 = choiceListOptionsCreateModels->GetSelection();
    int selection_index_4 = choiceListRemoveCreatedModels->GetSelection();
    int selection_index_5 = choiceListMesuareCreatedModels->GetSelection();

    int id = event.GetId();
    m_listaDados->Clear(); 

    if (!m_client) {
        wxMessageBox("Erro: Cliente gRPC não foi inicializado!", "Erro Crítico", wxOK | wxICON_ERROR);
        return;
    }
    try {
        switch (id) {
            case 1: {
                m_listaDados->Append("--- Lista de Linhas ---");
                Response linhas = m_client->ListLines(); 
                for (const auto& linha : linhas) {
                    m_listaDados->Append(linha);
                }
                break;
            }
            case 2: {
                m_listaDados->Append("--- Todos os Modelos Disponíveis ---");
                ResponseList lista = m_client->ListAllAvailableMeters();
                for (const auto& medidorInfo : lista) {
                    m_listaDados->Append("[" + medidorInfo[0] + "] " + medidorInfo[1] + " " + medidorInfo[2]);
                }
                break;
            }
            case 3: { 
                if (selection_index_1 != 0) {
                    m_listaDados->Append("--- Medidores Disponíveis da Linha " + lines[selection_index_1 - 1] + " ---"); 
                    auto lista = m_client->ListAvailableMeters(lines[selection_index_1 - 1]);
                    for (const auto& medidorInfo : lista) {
                        m_listaDados->Append("[" + medidorInfo[0] + "] " + medidorInfo[1] + " " + medidorInfo[2]);
                    }
                }
                break;
            }
            case 4: {
                m_listaDados->Append("--- Todos os Medidores Criados ---");
                auto lista = m_client->ListAllCreatedMeters();
                for (const auto& medidorInfo : lista) {
                    m_listaDados->Append("[" + medidorInfo[0] + "] " + medidorInfo[1] + " " + medidorInfo[2]);
                }
                break;
            }
            case 5: {
                if (selection_index_2 != 0) {
                    m_listaDados->Append("--- Medidores Criados da Linha " + lines[selection_index_2 - 1] + " ---"); 
                    auto lista = m_client->ListCreatedMeters(lines[selection_index_2 - 1]);
                    for (const auto& medidorInfo : lista) {
                        m_listaDados->Append("[" + medidorInfo[0] + "] " + medidorInfo[1] + " " + medidorInfo[2]);
                    }
                }
                break;
            }
            case 6: {
                if (selection_index_3 != 0) {
                    m_listaDados->Append("--- Medidor " + meters[selection_index_3 - 1] + " Adicionado ---"); 
                    auto medidor = m_client->AddMeter(std::to_string(selection_index_3));
                    
                    m_listaDados->Append("[" + medidor[0] + "] " + medidor[1] + " " + medidor[2]);  

                    wxString novoItem = "[" + medidor[0] + "] " + medidor[1] + " " + medidor[2];
                    choiceListRemoveCreatedModels->Append(novoItem);
                    choiceListMesuareCreatedModels->Append(novoItem);
                }
                break;
            }
            case 7: {
                if (selection_index_4 != 0) {
                    wxString selectedItem = choiceListRemoveCreatedModels->GetStringSelection();
                    m_listaDados->Append("--- Medidor Removido ---"); 
                    m_listaDados->Append(selectedItem.ToStdString());
                
                    wxString idStr = selectedItem.BeforeFirst(']').AfterFirst('[');
                    auto medidor = m_client->RemoveMeter(idStr.ToStdString());
                    m_listaDados->Append("Sucesso");

                    choiceListRemoveCreatedModels->Delete(selection_index_4);
                    choiceListMesuareCreatedModels->Delete(selection_index_4);
                    choiceListRemoveCreatedModels->Select(0);
                    choiceListMesuareCreatedModels->Select(0);
                }
                break;
            }
            case 8: {
                if (selection_index_5 != 0) {
                    wxString selectedItem = choiceListMesuareCreatedModels->GetStringSelection();
                    m_listaDados->Append("--- Leituras do Medidor ---"); 
                    m_listaDados->Append(selectedItem.ToStdString());
                    
                    wxString idStr = selectedItem.BeforeFirst(']').AfterFirst('[');
                    auto medidor = m_client->GetMeasurements(idStr.ToStdString());
                    int cont = 0;
                    for (const auto& values : medidor) {
                        m_listaDados->Append("Medição da " + std::to_string(cont + 1) + "° Fase = " + values);
                        cont++;
                    }
                }
                break;
            }
            default:
                m_listaDados->Append(wxString::Format("Dados para o botão %d ainda não implementados.", id));
                break;
        }
    } catch (const std::exception& e) {
        m_listaDados->Append("Erro na conexão gRPC: ");
        m_listaDados->Append(e.what());
    }

    wxLogStatus("Ação gRPC executada para o botão ID %d", id);
}