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

////////////////////////////
// Assinatura das funções //
////////////////////////////

void telaSobre(void);
char telaPrincipal(void);
void telaEquipe(void);

void moduloCliente(void);
char telaMenuCliente(void);
void telaCadastrarCliente(void);
void telaPesquisarCliente(void);
void telaAlterarCliente(void);
void telaExcluirCliente(void);
void cadastrarCliente(void);
void pesquisarCliente(void);
void alterarCliente(void);
void excluirCliente(void);

void moduloAdministrador(void);
char telaMenuAdministrador(void);
void telaCadastrarAdministrador(void);
void telaPesquisarAdministrador(void);
void telaAlterarAdministrador(void);
void telaExcluirAdministrador(void);
void cadastrarAdministrador(void);
void pesquisarAdministrador(void);
void alterarAdministrador(void);
void excluirAdministrador(void);

void moduloVeiculosDisp(void);
char telaMenuVeiculosDisp(void);
void telaCadastrarVeiculosDisp(void);
void telaPesquisarVeiculosDisp(void);
void telaAlterarVeiculosDisp(void);
void telaExcluirVeiculosDisp(void);
void cadastrarVeiculosDisp(void);
void pesquisarVeiculosDisp(void);
void alterarVeiculosDisp(void);
void excluirVeiculosDisp(void);

void moduloVeiculosAlug(void);

void moduloRelatorios(void);

////////////////////////
// Programa principal //
////////////////////////

//Inspirado no modelo de @flgorgonio
int main(void) {
    char escolha;
    do {
        escolha = telaPrincipal();
        switch(escolha) {
            case '1': moduloCliente();
                                break;
            case '2': moduloAdministrador();
                                break;
            case '3': moduloVeiculosDisp();
                                break;
            case '4': moduloVeiculosAlug();
                                break;
            case '5': moduloRelatorios(); 
                                break;
        }
    } while (escolha != '0');                                                      
    return 0;
}


char telaPrincipal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Uma Locadora de Veículos                       ///\n");
    printf("///             Developed by @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Locadora de Veículos RM = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Módulo Cliente                                            ///\n");
    printf("///            2. Módulo Administrador                                      ///\n");
    printf("///            3. Módulo Veículos Disponíveis                               ///\n");
    printf("///            4. Módulo Veículos Alugados                                  ///\n");
    printf("///            5. Módulo Relatórios                                         ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return op;
}


void telaSobre(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Uma Locadora de Veículos                       ///\n");
    printf("///            Developed by @rusdrael and @matheusfaria21 - Out, 2021       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Locadora de Veículos RM = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa para o projeto que será a avaliação do curso, produzido em    ///\n");
    printf("///  linguagem C, durante a disciplina DCT1106 - Programação do curso de    ///\n");
    printf("///  Bacharelado em Sistemas de Informação da Universidade Federal do Rio   ///\n");
    printf("///  Grande do Norte. O programa contém os principais módulos e             ///\n");
    printf("///  funcionalidades que serão exigidos na avaliação dos projetos. Todos    ///\n");
    printf("///  os dados e informações utilizados neste programa são fictícios.        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void telaEquipe(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Uma Locadora de Veículos                       ///\n");
    printf("///             Developed by @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Locadora de Veículos RM = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            Este projeto foi desenvolvido por:                           ///\n");
    printf("///                                                                         ///\n");
    printf("///            Rusdrael Antony de Araújo Freire                             ///\n");
    printf("///            E-mail: antony.freire.086@ufrn.edu.br                        ///\n");
    printf("///            Matheus Marcos de Medeiros Santos Faria                      ///\n");
    printf("///            E-mail: matheus.faria.121@ufrn.edu.br                        ///\n");
    printf("///            Redes sociais: @rusdrael e @matheusfaria1_                   ///\n");
    printf("///    Repositório: https://github.com/rusdrael/Uma-Locadora-de-Veiculos    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


////////////////////
// Módulo Cliente //
////////////////////

//Inspirado no modelo de @flgorgonio
void moduloCliente(void) {
    char escolha;
    do {
        escolha = telaMenuCliente();
        switch(escolha) {
            case '1': cadastrarCliente();
                                break;
            case '2': pesquisarCliente();
                                break;
            case '3': alterarCliente();
                                break;
            case '4': excluirCliente();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarCliente(void) {
    telaCadastrarCliente();
}


void pesquisarCliente(void) {
    telaPesquisarCliente();
}

void alterarCliente(void) {
    telaAlterarCliente();
}

void excluirCliente(void) {
    telaExcluirCliente();
}


char telaMenuCliente(void) {
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
    printf("///           = = = = = = = = = Menu Cliente  = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo cliente                                ///\n");
    printf("///           2. Pesquisar os dados de um cliente                         ///\n");
    printf("///           3. Atualizar o cadastro de um cliente                       ///\n");
    printf("///           4. Excluir um cliente do sistema                            ///\n");
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


void telaCadastrarCliente(void) {
    char cpf[12];
    char nome[51];
    char email[51];
    char nasc[11];
    char celular[12];

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
    printf("///           = = = = = = = = Cadastrar Cliente = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///           Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///           E-mail: ");
    scanf("%[A-Za-z0-9@._]", email);
    getchar();
    printf("///           Data de Nascimento (dd/mm/aaaa):  ");
    scanf("%[0-9/]", nasc);
    getchar();
    printf("///           Celular  (apenas números): ");
    scanf("%[0-9]", celular);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaPesquisarCliente(void) {
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
    printf("///           = = = = = = = Pesquisar Cliente = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaAlterarCliente(void) {
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
    printf("///           = = = = = = = = Alterar Cliente = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaExcluirCliente(void) {
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
    printf("///           = = = = = = = = Excluir Cliente = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


//////////////////////////
// Módulo Administrador //
//////////////////////////

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
            case '3': alterarAdministrador();
                                break;
            case '4': excluirAdministrador();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarAdministrador(void) {
    telaCadastrarAdministrador();
}


void pesquisarAdministrador(void) {
    telaPesquisarAdministrador();
}

void alterarAdministrador(void) {
    telaAlterarAdministrador();
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


void telaCadastrarAdministrador(void) {
    char cpf[12];
    char nome[51];
    char email[51];
    char nasc[11];
    char celular[12];

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
    printf("///           CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///           Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///           E-mail: ");
    scanf("%[A-Za-z0-9@._]", email);
    getchar();
    printf("///           Data de Nascimento (dd/mm/aaaa):  ");
    scanf("%[0-9/]", nasc);
    getchar();
    printf("///           Celular  (apenas números): ");
    scanf("%[0-9]", celular);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
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
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void telaAlterarAdministrador(void) {
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
    printf("///           = = = = = = Alterar Administrador = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
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
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


/////////////////////////////////
// Módulo Veículos Disponíveis //
/////////////////////////////////


void moduloVeiculosDisp(void) {
	// modulo em desenvolvimento

}


//////////////////////////////
// Módulo Veículos Alugados //
//////////////////////////////


void moduloVeiculosAlug(void) {
	// modulo em desenvolvimento

}


////////////////////////
// Módulo Relatórios //
///////////////////////


void moduloRelatorios(void) {
	// modulo em desenvolvimento

}