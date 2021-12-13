///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Uma Locadora de Veículos                       ///
///          Developed by @rusdrael and @matheusfaria21 - Out, 2021         ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "disponiveis.h"
#include "util.h"

////////////////////////////////////////////
// Funções do Módulo Veículos Disponíveis //
////////////////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloVeiculosDisp(void) {
    char escolha;
    do {
        escolha = telaMenuVeiculosDisp();
        switch(escolha) {
            case '1': cadastrarVeiculosDisp();
                                break;
            case '2': pesquisarVeiculosDisp();
                                break;
            case '3': atualizarVeiculosDisp();
                                break;
            case '4': excluirVeiculosDisp();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarVeiculosDisp(void) {
    telaCadastrarVeiculosDisp();
}

void pesquisarVeiculosDisp(void) {
    telaPesquisarVeiculosDisp();
}

void atualizarVeiculosDisp(void) {
    telaAtualizarVeiculosDisp();
}

void excluirVeiculosDisp(void) {
    telaExcluirVeiculosDisp();
}


char telaMenuVeiculosDisp(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = Menu Veículos Disponíveis = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo veículo disponível                     ///\n");
    printf("///           2. Pesquisar os dados de um veículo disponível              ///\n");
    printf("///           3. Atualizar o cadastro de um veículo disponível            ///\n");
    printf("///           4. Excluir um veículo disponível do sistema                 ///\n");
    printf("///           0. Voltar ao menu anterior                                  ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada: ");                       
    scanf("%c", &op);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return op;
}


void telaCadastrarVeiculosDisp(void) {
    char placaVeic[8];
    char nomeVeic[51];
    char marcaVeic[51];
    char anoVeic[5];

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = Cadastrar Veículos Disponíveis  = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {    
    printf("///           Placa (modelo Mercosul/letras maiúsculas): ");
    scanf("%[A-Z0-9]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));     
do {    
    printf("///           Nome: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", nomeVeic);
    getchar();
} while (!validarNomeVeic(nomeVeic));    
do {     
    printf("///           Marca: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", marcaVeic);
    getchar();
} while (!validarMarcaVeic(marcaVeic));     
do {     
    printf("///           Ano: ");
    scanf("%[0-9]", anoVeic);
    getchar();
} while (!validarAnoVeic(anoVeic));     
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaPesquisarVeiculosDisp(void) {
    char placaVeic[8];

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = Pesquisar Veículos Disponíveis  = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (modelo Mercosul/letras maiúsculas): ");
    scanf("%[A-Z0-9]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaAtualizarVeiculosDisp(void) {
    char placaVeic[8];

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = Atualizar Veículos Disponíveis  = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (modelo Mercosul/letras maiúsculas): ");
    scanf("%[A-Z0-9]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaExcluirVeiculosDisp(void) {
    char placaVeic[8];
    
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = Excluir Veículos Disponíveis  = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (modelo Mercosul/letras maiúsculas): ");
    scanf("%[A-Z0-9]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
