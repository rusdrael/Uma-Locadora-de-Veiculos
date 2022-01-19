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
    int status;
};

///////////////////////////////////////////////////////////
// Assinatura das Funções do Módulo Veículos Disponíveis //
///////////////////////////////////////////////////////////

void telaErroArquivoDisp(void);

void moduloVeiculosDisp(void);
char telaMenuVeiculosDisp(void);

Disponiveis* telaCadastrarVeiculosDisp(void);
void cadastrarVeiculosDisp(void);
void gravarVeiculosDisp(Disponiveis*);

void pesquisarVeiculosDisp(void);
char* telaPesquisarVeiculosDisp(void);
Disponiveis* buscarVeiculosDisp(char*);
void exibirVeiculosDisp(Disponiveis*);

void atualizarVeiculosDisp(void);
char* telaAtualizarVeiculosDisp(void);
void regravarVeiculosDisp(Disponiveis*);

void excluirVeiculosDisp(void);
char* telaExcluirVeiculosDisp(void);