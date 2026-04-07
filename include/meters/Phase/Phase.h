#pragma once

enum class Phase {
    PhaseA,
    PhaseB,
    PhaseC,
    NumberOfPhases
};

/*
    //TODO:
    - Phase vai ser uma classe abstrata que vai conter as funções de
    leitura da Phase A, Phase B e Phase C.

    - Dependendo se for um SinglePhaseMeter, teremos a função de leitura da Phase A funcionando,
    porém caso seja pedido a leitura da Phase B, terá que ser anunciado erro, pois não é possível
    realizar leitura dessa Phase naquele tipo de medidor.

    - Será criado as Classes SinglePhaseMeter, TwoPhaseMeter e ThreePhaseMeter, teremos uma variável referente as Phases,
    PhaseA - PhaseB - PhaseC, além do número de Phases, NumberOfPhases, 
    
    - A lógica das funções será a seguinte, quando requisitado a leitura,o valor da Phase que deseja ser lida é enviado,
    1 para A, 2 para B e 3 para C, Pode ser só letras também, será retornado um número aleatório entre 0~220V, mas apenas
    após verificar com a variável referente as Phases se aquele tipo de medidor é Single, Two ou ThreePhaseMeter, 
    Ex: {ui}
        resultado = lerPhase (phase y)
        std:: cout << resultado

        {Phase}
        string lerPhase (phase y){
            Se a Phase Y estiver disponível para o medidor
                Retornar um valor aleatório, em formato de string
            Se não
                Retornar uma mensagem de que não foi possível realizar a leitura devido ao fato daquele medidor não conter aquela Phase, em formato de string
        }


*/