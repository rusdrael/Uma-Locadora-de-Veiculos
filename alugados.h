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

typedef struct alugados Alugados;

struct alugados{

    char placaVeic[8];
    char nomeVeic[51];
    char marcaVeic[51];
    char anoVeic[5];
    int status;
};

////////////////////////////////////////////////////////
// Assinatura das Funções do Módulo Veículos Alugados //
////////////////////////////////////////////////////////

void telaErroArquivoAlug(void);

void moduloVeiculosAlug(void);
char telaMenuVeiculosAlug(void);

Alugados* telaCadastrarVeiculosAlug(void);
void cadastrarVeiculosAlug(void);
void gravarVeiculosAlug(Alugados*);

void pesquisarVeiculosAlug(void);
char* telaPesquisarVeiculosAlug(void);
Alugados* buscarVeiculosAlug(char*);
void exibirVeiculosAlug(Alugados*);

void atualizarVeiculosAlug(void);
char* telaAtualizarVeiculosAlug(void);
void regravarVeiculosAlug(Alugados*);

void excluirVeiculosAlug(void);
char* telaExcluirVeiculosAlug(void);