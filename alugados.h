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

};

////////////////////////////////////////////////////////
// Assinatura das Funções do Módulo Veículos Alugados //
////////////////////////////////////////////////////////

void moduloVeiculosAlug(void);
char telaMenuVeiculosAlug(void);
Alugados* telaCadastrarVeiculosAlug(void);
void telaPesquisarVeiculosAlug(void);
void telaAtualizarVeiculosAlug(void);
void telaExcluirVeiculosAlug(void);
void cadastrarVeiculosAlug(void);
void pesquisarVeiculosAlug(void);
void atualizarVeiculosAlug(void);
void excluirVeiculosAlug(void);