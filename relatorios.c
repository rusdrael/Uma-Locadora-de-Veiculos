///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Uma Locadora de Veículos                       ///
///          Developed by @rusdrael and @matheusfaria21 - Out, 2021         ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "relatorios.h"
#include "cliente.h"
#include "veiculos.h"
#include "locacao.h"
#include "util.h"

//////////////////////////////////
// Funções do Módulo Relatórios //
//////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloRelatorios(void) {
    char escolha;
    do {
        escolha = telaMenuRelatorios();
        switch(escolha) {
            case '1': historicoLocacoes();
                                break;
            case '2': clientesCadastrados();
                                break;
            case '3': veiculosCadastrados();
                                break;
            case '4': locacoesPorCPF();
                                break;
            case '5': locacoesPorPlaca();
                                break;                    
        }
    } while (escolha != '0');                                                      
}

void historicoLocacoes(void) {

    telaHistoricoLocacoes();
}

void clientesCadastrados(void) {

    telaClientesCadastrados();
}

void veiculosCadastradas(void) {

    telaVeiculosCadastrados();
}

void locacoesPorCPF(void) {

    char* cpf;

	  cpf = telaPesquisarCliente();
    relatLocacoesPorCPF(cpf);
    free(cpf);
}

void locacoesPorPlaca(void) {

    char* placaVeic;

	  placaVeic = telaPesquisarVeiculos();
    relatLocacoesPorPlaca(placaVeic);
    free(placaVeic);
}

void veiculosDisponiveis(void) {

    telaVeiculosDisponiveis();
}

char telaMenuRelatorios(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = = Menu Relatórios = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Histórico de locações                                    ///\n");
    printf("///           2. Clientes cadastrados                                     ///\n");
    printf("///           3. Veículos cadastrados                                     ///\n");
    printf("///           4. Locações por CPF                                         ///\n");
    printf("///           5. Locações por Placa                                       ///\n");
    printf("///           0. Voltar ao menu anterior                                  ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada: ");                       
    scanf("%c", &op);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return op;
}

void telaHistoricoLocacoes(void) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = Histórico de Locações = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Histórico de locações:                                      ///\n");
    listaHistoricoLocacoes();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void listaHistoricoLocacoes(void) {
    FILE* fp;
    Locacao* loc;
    loc = (Locacao*) malloc(sizeof(Locacao));
    fp = fopen("locacoes.dat", "rb");
    while (fread(loc, sizeof(Locacao), 1, fp)) {
      printf("///           Data: %s                                                    ///\n", loc->data);
      printf("///           CPF: %s                                                     ///\n", loc->cpf);
      printf("///           Placa do veículo: %s                                        ///\n", loc->placaVeic);
      printf("///           Valor: %.2f                                                 ///\n", loc->valorPago);
      if (loc->status == 'N'){
        printf("///           Pagamento pendente                                          ///\n -----------------------------------------------------------------------------\n");
      }  
      else{
        printf("///           Pago                                                        ///\n -----------------------------------------------------------------------------\n");
      }
    }
    fclose(fp);
    free(loc);
}

void listaClientesCadastrados(void) {
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    while (fread(cli, sizeof(Cliente), 1, fp)) {
      if(cli->status == 'C'){
        printf("///           CPF: %s                                                     ///\n", cli->cpf);
        printf("///           Nome: %s                                                    ///\n", cli->nome);
        printf("///           Email: %s                                                   ///\n", cli->email);
        printf("///           Data de Nascimento: %s                                      ///\n", cli->nasc);
        printf("///           Telefone: %s                                                ///\n", cli->celular);
        printf("///           Qtd. de Aluguéis: %i                                        ///\n", cli->quantidadeAlugueis);
        printf("-----------------------------------------------------------------------------\n");
      }     
    }
    fclose(fp);
    free(cli);
}

void telaClientesCadastrados(void) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = Clientes Cadastrados  = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Lista de clientes:                                          ///\n");
    listaClientesCadastrados();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void listaVeiculosCadastrados(void) {
    FILE* fp;
    Veiculos* veic;
    veic = (Veiculos*) malloc(sizeof(Veiculos));
    fp = fopen("veiculos.dat", "rb");
    while (fread(veic, sizeof(Veiculos), 1, fp)) {
      if(veic->statusCadastro == 'C'){
        printf("///           Placa do Veículo: %s                                        ///\n", veic->placaVeic);
        printf("///           Nome do Veículo: %s                                         ///\n", veic->nomeVeic);
        printf("///           Marca do Veículo: %s                                        ///\n", veic->marcaVeic);
        printf("///           Ano do Veículo: %s                                          ///\n", veic->anoVeic);
        printf("///           Valor: %.2f                                                 ///\n", veic->valor);
        printf("///           Qtd. de Aluguéis: %i                                        ///\n", veic->quantidadeAlugueis);
        if (veic->status == 'D'){
          printf("///           Disponível                                                  ///\n -----------------------------------------------------------------------------\n");
        }  
        else{
          printf("///           Alugado                                                     ///\n -----------------------------------------------------------------------------\n");
        }
      }     
    }
    fclose(fp);
    free(veic);
}

void telaVeiculosCadastrados(void) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = Veículos Cadastrados  = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Lista de Veículos:                                          ///\n");
    listaVeiculosCadastrados();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void relatLocacoesPorCPF(char* cpf) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = CPF: %s  = = = = = =             ///\n", cpf);
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Histórico de Locações:                                      ///\n");
    listaLocacoesPorCPF(cpf);
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void listaLocacoesPorCPF(char* cpf) {
    FILE* fp;
    Locacao* loc;
    loc = (Locacao*) malloc(sizeof(Locacao));
    fp = fopen("locacoes.dat", "rb");
    while (fread(loc, sizeof(Locacao), 1, fp)) {
      if(strcmp(loc->cpf, cpf) == 0){
        printf("///           Data: %s                                                    ///\n", loc->data);
        printf("///           Placa do Veículo: %s                                        ///\n", loc->placaVeic);
        printf("///           Valor: %.2f                                                 ///\n", loc->valorPago);
        if (loc->status == 'N'){
          printf("///           Pagamento pendente                                          ///\n -----------------------------------------------------------------------------\n");
        }  
        else{
          printf("///           Pago                                                        ///\n -----------------------------------------------------------------------------\n");
        }
      }
    }
    fclose(fp);
    free(loc);
}

void relatLocacoesPorPlaca(char* placaVeic) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = Placa: %s = = = = = =             ///\n", placaVeic);
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Histórico de Locações:                                      ///\n");
    listaLocacoesPorPlaca(placaVeic);
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void listaLocacoesPorPlaca(char* placaVeic) {
    FILE* fp;
    Locacao* loc;
    loc = (Locacao*) malloc(sizeof(Locacao));
    fp = fopen("locacoes.dat", "rb");
    while (fread(loc, sizeof(Locacao), 1, fp)) {
      if(strcmp(loc->placaVeic, placaVeic) == 0){
        printf("///           Data: %s                                                    ///\n", loc->data);
        printf("///           CPF: %s                                                     ///\n", loc->cpf);
        printf("///           Valor: %.2f                                                 ///\n", loc->valorPago);
        if (loc->status == 'N'){
          printf("///           Pagamento pendente                                          ///\n -----------------------------------------------------------------------------\n");
        }  
        else{
          printf("///           Pago                                                        ///\n -----------------------------------------------------------------------------\n");
        }
      }
    }
    fclose(fp);
    free(loc);
}

void telaVeiculosDisponiveis(void) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          = = = = = = Locadora de Veículos RM = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///          Developed by  @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = Veículos Disponíveis  = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           Lista de Veículos:                                          ///\n");
    listaVeiculosDisponiveis();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
}

void listaVeiculosDisponiveis(void) {
    FILE* fp;
    Veiculos* veic;
    veic = (Veiculos*) malloc(sizeof(Veiculos));
    fp = fopen("veiculos.dat", "rb");
    while (fread(veic, sizeof(Veiculos), 1, fp)) {
      if(veic->status == 'D' && veic->statusCadastro == 'C'){
        printf("///           Placa do Veículo: %s                                        ///\n", veic->placaVeic);
        printf("///           Nome do Veículo: %s                                         ///\n", veic->nomeVeic);
        printf("///           Marca do Veículo: %s                                        ///\n", veic->marcaVeic);
        printf("///           Ano do Veículo: %s                                          ///\n", veic->anoVeic);
        printf("///           Valor: %.2f                                                 ///\n", veic->valor);
        printf("///           Qtd. de Aluguéis: %i                                        ///\n", veic->quantidadeAlugueis);
        if (veic->status == 'D'){
          printf("///           Disponível                                                  ///\n -----------------------------------------------------------------------------\n");
        }  
        else{
          printf("///           Alugada                                                     ///\n -----------------------------------------------------------------------------\n");
        }
      }     
    }
    fclose(fp);
    free(veic);
}