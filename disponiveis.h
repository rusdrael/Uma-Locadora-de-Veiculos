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

typedef struct disponiveis Disponiveis;

struct disponiveis{

    char placaVeic[8];
    char nomeVeic[51];
    char marcaVeic[51];
    char anoVeic[5];

};

///////////////////////////////////////////////////////////
// Assinatura das Funções do Módulo Veículos Disponíveis //
///////////////////////////////////////////////////////////

void moduloVeiculosDisp(void);
char telaMenuVeiculosDisp(void);
Disponiveis* telaCadastrarVeiculosDisp(void);
void telaPesquisarVeiculosDisp(void);
void telaAtualizarVeiculosDisp(void);
void telaExcluirVeiculosDisp(void);
void cadastrarVeiculosDisp(void);
void pesquisarVeiculosDisp(void);
void atualizarVeiculosDisp(void);
void excluirVeiculosDisp(void);