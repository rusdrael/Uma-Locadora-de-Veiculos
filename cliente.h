///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Uma Locadora de Veículos                       ///
///          Developed by @rusdrael and @matheusfaria21 - Out, 2021         ///
///////////////////////////////////////////////////////////////////////////////

////////////////
// Estruturas //
////////////////

typedef struct cliente Cliente;

struct cliente{

    char cpf[12];
    char nome[51];
    char email[51];
    char nasc[11];
    char celular[12];

};

//////////////////////////////////////////////
// Assinatura das Funções do Módulo Cliente //
//////////////////////////////////////////////

void moduloCliente(void);
char telaMenuCliente(void);
Cliente* telaCadastrarCliente(void);
void telaPesquisarCliente(void);
void telaAtualizarCliente(void);
void telaExcluirCliente(void);
void cadastrarCliente(void);
void pesquisarCliente(void);
void atualizarCliente(void);
void excluirCliente(void);