#pragma once

#include <iostream>
#include <functional>
#include <string>
#include "core/Catalog.h"

struct MenuOptions 
{
    int op;
    std::string description;
    std::function<void()> menu_exec;
};

class Ui 
{
private:
    Catalog catalog;
    const std::vector<MenuOptions> menu_options;
    
    void finalizarPrograma();

    void listarModelosPorLinha(); 
    void exibirLinhasDisponiveisMenu();
    void listarTodosModelosGenerico(bool is_template);
    void menuAdicionarModelo();
    void menuRemoverModelo();
    
    void menuLeituraFases();
    void exibirMenuInicial();
    void exibirMenuTitle();
    void exibirMenuLinhas();
    void exibirLinhasDisponiveis();
    void exibirModelosLinha (std::string & linha);
    void listarModelosComId(bool is_template);
    
    int collectUserOpInput();
    void limparInput();
    void pausar();

public:
    Ui();
    void run();
};