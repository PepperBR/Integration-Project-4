#include "ui/Ui.h"
#include <limits>

static bool execute = true;

Ui::Ui()
    : menu_options({
    MenuOptions
    {1, "Filtrar modelos por linha", [this] () {listarModelosPorLinha(); }},
    {2, "Ver todas as linhas", [this] () {exibirLinhasDisponiveisMenu(); }},
    {3, "Ver catálogo de opções", [this] () {listarTodosModelosGenerico(true); }},
    {4, "Ver catálogo de modelos adicionados", [this] () {listarTodosModelosGenerico(false); }},
    {5, "Adicionar novo modelo", [this] () {menuAdicionarModelo(); }},
    {6, "Remover modelo", [this] () {menuRemoverModelo(); }},
    {7, "Ler medição de fase", [this] () {menuLeituraFases(); }},
    {8, "Sair", [this] () {finalizarPrograma(); }}
}){}

void Ui::run() {
    while (execute) {
        exibirMenuInicial();
        auto option = collectUserOpInput();

        if(option == -1)
        {
            std::cout << "\n[ERRO] Entrada inválida. Por favor, digite um número.\n";
            limparInput();
            pausar();
        }
        else{
            bool opcaoEncontrada = false;

            for (const auto &seletected_menu : menu_options)
            {
                if(option == seletected_menu.op)
                {
                    seletected_menu.menu_exec();
                    opcaoEncontrada = true;
                }
            }

            if (!opcaoEncontrada) {
                std::cout << "\n[ERRO] A opção [" << option << "] não existe no menu.\n";
                limparInput();
                pausar();
            }
        }
    }
}

void Ui::finalizarPrograma() {
    execute = false;
}


void Ui::listarModelosPorLinha() {
    exibirMenuLinhas();
    
    limparInput();
    std::string nomeLinha;
    std::getline(std::cin, nomeLinha);

    std::cout << "\n=== Modelos da Linha " << nomeLinha << " ===\n";
    auto modelos_linha = catalog.getLineModels(nomeLinha);
    if (modelos_linha.size() == 0){
        std::cout << "[ERRO] Nenhum modelo encontrado nesta linha.\n";
    }else{
        for(auto & modelo : modelos_linha)
        {
            std::cout << std::get<1>(modelo) << std::endl;
        }
    }
    pausar();
}

void Ui::exibirLinhasDisponiveisMenu() {
    std::cout << "\n=== Linhas Existentes ===\n";
    for (const auto & linha : catalog.getLines())
    {
        std::cout << "- " << linha << "\n";
    }
    limparInput();
    pausar();
}

void Ui::listarTodosModelosGenerico(bool is_template) {
    for (const auto & linha : catalog.getLines())
    {
        std::cout << "\n=== Linha: " << linha << " ===\n";
        auto modelos_linha = catalog.getLineModels(linha);
        for(auto & modelo : modelos_linha)
        {
            if(std::get<2>(modelo) == is_template)
            {
                std::cout << std::get<0>(modelo) << " | " << std::get<1>(modelo) << "\n";
            }
        }
    }

    limparInput();
    pausar();
}

void Ui::menuAdicionarModelo() {
    exibirLinhasDisponiveis();
    std::string line, name;

    std::cout << "\nEscolha a linha: ";
    limparInput();
    std::getline(std::cin, line);   

    bool existe = false;
    for (const auto & linha : catalog.getLines())
    {
        if (linha == line){
            existe = true;
        }   
    }
    if (!existe) {
        std::cout << "[Erro] Entrada inválida. Escreva o nome de uma linha que existe.\n";
        pausar();
        return;
    }

    exibirModelosLinha(line);

    std::cout << "\nDigite o ID do template que deseja criar um novo modelo : ";
    auto option_ID = collectUserOpInput();

    if(option_ID == -1) {
        std::cout << "[ERRO] Entrada inválida. Use apenas numeros para o ID.\n";
        limparInput();
        pausar();
        return;
    }

    auto & meter = catalog.getTemplateByID(option_ID);
    if(!meter)
    {
        catalog.addNewModel(option_ID);
        std::cout << "Modelo adicionado com sucesso!\n";
    }else{
        std::cout << "[Erro] Entrada inválida. Escolha um modelo que pertence a linha.\n";
    }
    limparInput();
    pausar();
}

void Ui::menuRemoverModelo() {
    listarModelosComId(false);

    std::cout << "\nID para remover: ";
    auto id = collectUserOpInput();
    if (id != -1) {
        auto result = catalog.removeModel(id);
        if(result)
        {
            std::cout << "Modelo removido com sucesso!\n";
        }
        else{
            std::cout << "[ERRO] Entrada inválida. Escolha uma opção válida.\n";
        }
    } else {
        std::cout << "\n[ERRO] Entrada inválida. Use apenas numeros para o ID.\n";
    }

    limparInput();
    pausar();
}

void Ui::menuLeituraFases() {
    listarModelosComId(false);

    std::cout << "ID do medidor que deseja realizar as leituras: ";
    auto option_ID = collectUserOpInput();

    if(option_ID == -1)
    { 
        std::cout << "[Erro] Entrada inválida. Escolha um ID válido.\n";
        limparInput();
        pausar();
        return; 
    }

    auto & meter = catalog.getMeterByID(option_ID);
    if(!meter)
    {
        std::cout << "[Erro] Entrada inválida. Escolha uma opção de ID válida.";
        limparInput();
        pausar();
        return; 
    }

    for(int cont = 0; cont < meter->getPhaseValues().size(); cont++)
    {
        std::cout << "A leitura da " << cont + 1 << "° fase é : " << meter->getPhaseValues()[cont] << "\n";
    }
    
    limparInput();
    pausar();
}

void Ui::exibirMenuInicial() 
{   
    exibirMenuTitle();
    for (const auto &menu_item : menu_options)
    {
        std::cout << "(" << menu_item.op << ")\t" << menu_item.description << "\n";
    }
    std::cout << "\nEscolha uma opção: " << std::endl;
}

void Ui::exibirMenuTitle() 
{
    std::cout << "\n==============================";
    std::cout << "\n       MENU PRINCIPAL";
    std::cout << "\n==============================\n";
}

void Ui::exibirMenuLinhas() {
    std::cout << "\n--- Digite o nome de uma das linhas abaixo ---\n";
    for (const auto & linha : catalog.getLines()) 
    {
        std::cout << "- " << linha << "\n";
    }
    std::cout << "\nLinha: ";
}

void Ui::exibirLinhasDisponiveis() {
    std::cout << "\n=== Linhas Existentes ===\n";
    for (const auto & linha : catalog.getLines())
    {
        std::cout << "- " << linha << "\n";
    }
}

void Ui::exibirModelosLinha (std::string & linha) {
    std::cout << "\n--- Modelos da Linha Selecionada ---\n";
    auto const modelos = catalog.getLineModels(linha);
    for (const auto & modelo :  modelos)
    {
        if(std::get<2>(modelo))
        {
            std::cout << "(" << std::get<0>(modelo) << ") - " << std::get<1>(modelo) << "\n";
        }
    }
}

void Ui::listarModelosComId(bool is_template) {
    std::cout << "\nID   |       Nome do modelo\n";
    std::cout << "--------------------------\n";
    for (const auto & line : catalog.getLines())
    {
        for (const auto & meter : catalog.getLineModels(line))
        {
            if(is_template == std::get<2>(meter))
            {
                std::cout << "(" << std::get<0>(meter) << ")          " << std::get<1>(meter) << "\n";
            }
        }
    }
}

int Ui::collectUserOpInput()
{
    int option;

    if (!(std::cin >> option)) 
    {
        return -1;
    }

    return option;
}

void Ui::limparInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Ui::pausar() {
    std::cout << "\nAperte Enter para continuar.\n";
    std::cin.get(); 
}