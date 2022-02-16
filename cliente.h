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

    char cpfCliente[12];
    char nome[51];
    char email[51];
    char nasc[11];
    char celular[12];
    int quantidadeAlugueis;
    char status;
};

//////////////////////////////////////////////
// Assinatura das Funções do Módulo Cliente //
//////////////////////////////////////////////

void telaErroArquivo(void);

void moduloCliente(void);
char telaMenuCliente(void);

Cliente* telaCadastrarCliente(int);
void cadastrarCliente(void);
void gravarCliente(Cliente*);

void pesquisarCliente(void);
char* telaPesquisarCliente(void);
Cliente* buscarCliente(char*);
void exibirCliente(Cliente*);

void atualizarCliente(void);
char* telaAtualizarCliente(void);
void regravarCliente(Cliente*);

void excluirCliente(void);
char* telaExcluirCliente(void);
Cliente* buscarClienteCadastrado(char*);