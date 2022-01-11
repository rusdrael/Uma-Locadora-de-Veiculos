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
#include "administrador.h"
#include "util.h"

/////////////////////////////////////
// Funções do Módulo Administrador //
/////////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloAdministrador(void) {
    char escolha;
    do {
        escolha = telaMenuAdministrador();
        switch(escolha) {
            case '1': cadastrarAdministrador();
                                break;
            case '2': pesquisarAdministrador();
                                break;
            case '3': atualizarAdministrador();
                                break;
            case '4': excluirAdministrador();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarAdministrador(void) {
    Administrador* admin;

    admin = telaCadastrarAdministrador();
    free(admin);
}

void pesquisarAdministrador(void) {
    telaPesquisarAdministrador();
}

void atualizarAdministrador(void) {
    telaAtualizarAdministrador();
}

void excluirAdministrador(void) {
    telaExcluirAdministrador();
}


char telaMenuAdministrador(void) {
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
    printf("///           = = = = = = = Menu Administrador  = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo administrador                          ///\n");
    printf("///           2. Pesquisar os dados de um administrador                   ///\n");
    printf("///           3. Atualizar o cadastro de um administrador                 ///\n");
    printf("///           4. Excluir um administrador do sistema                      ///\n");
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


Administrador* telaCadastrarAdministrador(void) {
    Administrador* admin;
        admin = (Administrador*) malloc(sizeof(Administrador));

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
        printf("///           = = = = = = Cadastrar Administrador = = = = = =             ///\n");
        printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
        printf("///                                                                       ///\n");
    do {
        printf("///           CPF (apenas números): ");
        scanf("%[^\n]", admin->cpf);
        getchar();
    } while (!validarCpf(admin->cpf));  
    do {
        printf("///           Nome completo: ");
        scanf("%[^\n]", admin->nome);
        getchar();
    } while (!validarNome(admin->nome));    
    do {
        printf("///           E-mail: ");
        scanf("%[^\n]", admin->email);
        getchar(); 
    } while (!validarEmail(admin->email));   
    do {
        printf("///           Data de Nascimento (dd/mm/aaaa):  ");
        scanf("%[^\n]", admin->nasc);
        getchar();
    } while (!validarData(admin->nasc));      
    do {
        printf("///           Celular  (apenas números): ");
        scanf("%[^\n]", admin->celular);
        getchar();
    } while (!validarCelular(admin->celular));
        printf("///                                                                       ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");

        return admin;
}


void telaPesquisarAdministrador(void) {
    char cpf[12];

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
    printf("///           = = = = = Pesquisar Administrador = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[^\n]", cpf);
    getchar();
} while (!validarCpf(cpf));      
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaAtualizarAdministrador(void) {
    char cpf[12];

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
    printf("///           = = = = = = Atualizar Administrador = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {  
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[^\n]", cpf);
    getchar();
} while (!validarCpf(cpf));      
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaExcluirAdministrador(void) {
    char cpf[12];
    
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
    printf("///           = = = = = = Excluir Administrador = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {    
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[^\n]", cpf);
    getchar();
} while (!validarCpf(cpf));      
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
