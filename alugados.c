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
#include "alugados.h"
#include "util.h"

/////////////////////////////////////////
// Funções do Módulo Veículos Alugados //
/////////////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloVeiculosAlug(void) {
    char escolha;
    do {
        escolha = telaMenuVeiculosAlug();
        switch(escolha) {
            case '1': cadastrarVeiculosAlug();
                                break;
            case '2': pesquisarVeiculosAlug();
                                break;
            case '3': atualizarVeiculosAlug();
                                break;
            case '4': excluirVeiculosAlug();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarVeiculosAlug(void) {
    Alugados* alug;

    alug = telaCadastrarVeiculosAlug();
    free(alug);
}

void pesquisarVeiculosAlug(void) {
    telaPesquisarVeiculosAlug();
}

void atualizarVeiculosAlug(void) {
    telaAtualizarVeiculosAlug();
}

void excluirVeiculosAlug(void) {
    telaExcluirVeiculosAlug();
}


char telaMenuVeiculosAlug(void) {
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
    printf("///           = = = = = = Menu Veículos Alugados  = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo veículo alugado                        ///\n");
    printf("///           2. Pesquisar os dados de um veículo alugado                 ///\n");
    printf("///           3. Atualizar o cadastro de um veículo alugado               ///\n");
    printf("///           4. Excluir um veículo alugado do sistema                    ///\n");
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


Alugados* telaCadastrarVeiculosAlug(void) {
    Alugados* alug;
        alug = (Alugados*) malloc(sizeof(Alugados));

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
    printf("///           = = = = = Cadastrar Veículos Alugados = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {    
    printf("///           Placa (modelo Mercosul/letras maiúsculas): ");
    scanf("%[^\n]", alug->placaVeic);
    getchar();
} while (!validarPlacaVeic(alug->placaVeic));     
do {    
    printf("///           Nome: ");
    scanf("%[^\n]", alug->nomeVeic);
    getchar();
} while (!validarNomeVeic(alug->nomeVeic));    
do {     
    printf("///           Marca: ");
    scanf("%[^\n]", alug->marcaVeic);
    getchar();
} while (!validarMarcaVeic(alug->marcaVeic));     
do {     
    printf("///           Ano: ");
    scanf("%[^\n]", alug->anoVeic);
    getchar();
} while (!validarAnoVeic(alug->anoVeic));     
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return alug;
}


void telaPesquisarVeiculosAlug(void) {
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
    printf("///           = = = = = Pesquisar Veículos Alugados = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (modelo Mercosul/letras maiúsculas): ");
    scanf("%[^\n]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaAtualizarVeiculosAlug(void) {
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
    printf("///           = = = = = Atualizar Veículos Alugados = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (modelo Mercosul/letras maiúsculas): ");
    scanf("%[^\n]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaExcluirVeiculosAlug(void) {
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
    printf("///           = = = = = = Excluir Veículos Alugados = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (modelo Mercosul/letras maiúsculas): ");
    scanf("%[^\n]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
