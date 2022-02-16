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

typedef struct veiculos Veiculos;

struct veiculos{

    char placaVeic[8];
    char nomeVeic[51];
    char marcaVeic[51];
    char anoVeic[5];
    char status;
    float valor;
    int quantidadeAlugueis;
    char statusCadastro;
};

///////////////////////////////////////////////
// Assinatura das Funções do Módulo Veículos //
///////////////////////////////////////////////

void telaErroArquivoVeic(void);

void moduloVeiculos(void);
char telaMenuVeiculos(void);

Veiculos* telaCadastrarVeiculos(int);
void cadastrarVeiculos(void);
void gravarVeiculos(Veiculos*);

void pesquisarVeiculos(void);
char* telaPesquisarVeiculos(void);
Veiculos* buscarVeiculos(char*);
void exibirVeiculos(Veiculos*);

void atualizarVeiculos(void);
char* telaAtualizarVeiculos(void);
void regravarVeiculos(Veiculos*);

void excluirVeiculos(void);
char* telaExcluirVeiculos(void);

Veiculos* buscarVeiculosCadastro(char*);