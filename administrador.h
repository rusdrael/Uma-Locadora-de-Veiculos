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

typedef struct administrador Administrador;

struct administrador{

    char cpf[12];
    char nome[51];
    char email[51];
    char nasc[11];
    char celular[12];
    int status;
};

////////////////////////////////////////////////////
// Assinatura das Funções do Módulo Administrador //
////////////////////////////////////////////////////

void telaErroArquivoAdmin(void);

void moduloAdministrador(void);
char telaMenuAdministrador(void);

Administrador* telaCadastrarAdministrador(void);
void cadastrarAdministrador(void);
void gravarAdministrador(Administrador*);

void pesquisarAdministrador(void);
char* telaPesquisarAdministrador(void);
Administrador* buscarAdministrador(char*);
void exibirAdministrador(Administrador*);

void atualizarAdministrador(void);
char* telaAtualizarAdministrador(void);
void regravarAdministrador(Administrador*);

void excluirAdministrador(void);
char* telaExcluirAdministrador(void);