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

typedef struct locacao Locacao;
#include <time.h>
struct locacao{

    char cpfCliente[12];
    char placaVeic[8];
    char data[30];
    float valorPago;
    char status;
};

//////////////////////////////////////////////
// Assinatura das Funções do Módulo Locação //
//////////////////////////////////////////////

void telaErroArquivoLocacao(void);

void moduloLocacao(void);
char telaMenuLocacao(void);

void locarVeiculo(void);
Locacao* telaLocarVeiculo(char*, char*, float);
void gravarLocacao(Locacao*);

void devolverVeiculo(void);
Locacao* telaDevolverVeiculo(Locacao*);
Locacao* buscarLocacao(char*, char*);
void regravarLocacao(Locacao*);

int difDatas( char[] );
void telaListarVeiculo(void);