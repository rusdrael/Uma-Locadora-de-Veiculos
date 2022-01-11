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

};

////////////////////////////////////////////////////
// Assinatura das Funções do Módulo Administrador //
////////////////////////////////////////////////////

void moduloAdministrador(void);
char telaMenuAdministrador(void);
Administrador* telaCadastrarAdministrador(void);
void telaPesquisarAdministrador(void);
void telaAtualizarAdministrador(void);
void telaExcluirAdministrador(void);
void cadastrarAdministrador(void);
void pesquisarAdministrador(void);
void atualizarAdministrador(void);
void excluirAdministrador(void);