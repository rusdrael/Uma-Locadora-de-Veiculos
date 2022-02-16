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
#include "veiculos.h"
#include "util.h"
#include "cliente.h"

typedef struct veiculos Veiculos;

////////////////////////////////
// Funções do Módulo Veículos //
////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloVeiculos(void) {
    char escolha;
    do {
        escolha = telaMenuVeiculos();
        switch(escolha) {
            case '1': cadastrarVeiculos();
                                break;
            case '2': pesquisarVeiculos();
                                break;
            case '3': atualizarVeiculos();
                                break;
            case '4': excluirVeiculos();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarVeiculos(void) {
    Veiculos *veic;
    veic = telaCadastrarVeiculos(1);
    if (veic == NULL){
        printf("Veículo já cadastrado!");
    }
    else{
    gravarVeiculos(veic);
    free(veic);
    }
}

void pesquisarVeiculos(void) {
    Veiculos* veic;
	char* placa;

	placa = telaPesquisarVeiculos();
	veic = buscarVeiculos(placa);
	exibirVeiculos(veic);
	free(veic); 
	free(placa);
}

void atualizarVeiculos(void) {
    Veiculos* veic;
	char* placa;

	placa = telaAtualizarVeiculos();
	veic = buscarVeiculos(placa);
	if (veic == NULL) {
    	printf("\n\nVeículo não encontrado!\n\n");
  	} else {
		  veic = telaCadastrarVeiculos(2);
		  strcpy(veic->placaVeic, placa);
		  regravarVeiculos(veic);
	}
    free(veic);
	free(placa);
}

void excluirVeiculos(void) {
    Veiculos* veic;
	char *placa;
  char confirmacao[2];
	placa = telaExcluirVeiculos();
	veic = (Veiculos*) malloc(sizeof(Veiculos));
	veic = buscarVeiculos(placa);
	if (veic == NULL) {
        printf("\n\nVeículo não encontrado!\n\n");
    } 
    else {
        printf("Digite 's' para continuar a exclusão ou 'n' para interromper: ");
        scanf("%[^\n]", confirmacao);
        getchar();
    while (validaConfirmacao(confirmacao) == 0){
        printf("///           Ação inválida!: ");
        scanf("%[^\n]", confirmacao);
	    getchar();
    }
    if (confirmacao[0] == 'S' || confirmacao[0] == 's'){
	    veic->statusCadastro = 'X';
		regravarVeiculos(veic);
    free(veic);	  
    }
    else if(confirmacao[0] == 'N' || confirmacao[0] == 'n'){
      printf("Ação interrompida!");
    }
	}
	free(placa);
}

void telaErroArquivoVeic(void) {
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
	printf("///           = = = = = = =  Ops! Ocorreu em erro = = = = = =             ///\n");
	printf("///           = = =  Não foi possível acessar o arquivo = = =             ///\n");
	printf("///           = = = = com informações sobre os veículos = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = =  Pedimos desculpas pelos inconvenientes = =             ///\n");
	printf("///           = = =  mas este programa será finalizado! = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
	getchar();
	exit(1);
}

char telaMenuVeiculos(void) {
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
    printf("///           = = = = = = = = = Menu Veículos = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo veículo                                ///\n");
    printf("///           2. Pesquisar os dados de um veículo                         ///\n");
    printf("///           3. Atualizar o cadastro de um veículo                       ///\n");
    printf("///           4. Excluir um veículo do sistema                            ///\n");
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


Veiculos* telaCadastrarVeiculos(int tipo) {
    Veiculos* veic;
        char placa[8];

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
    printf("///           = = = = = = = Cadastrar Veículos  = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");   
    printf("///           Placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", placa);
    getchar();
    while (validarPlacaVeic(placa) == 0){
        printf("///       Placa inválida!: ");
        scanf("%[^\n]", placa);
        getchar();
    }
    if((buscarVeiculosCadastrado(placa) !=NULL) && (tipo == 1) ){
        return NULL;
        free(veic);
    }
    else{
        veic = (Veiculos*) malloc(sizeof(Veiculos));
        strcpy(veic->placaVeic, placa);
            printf("///           Nome:");
        scanf("%[^\n]", veic->nomeVeic);
        getchar();
        while (validarNomeVeic(veic->nomeVeic) == 0){
            printf("///           Nome inválido!: ");
            scanf("%[^\n]", veic->nomeVeic);
            getchar();  
        }        
            printf("///           Marca: ");
        scanf("%[^\n]", veic->marcaVeic);
        getchar();
        while (validarMarcaVeic(veic->marcaVeic) == 0){         
            printf("///           Marca inválida!: ");
            scanf("%[^\n]", veic->marcaVeic);
            getchar();
        }
            printf("///           Ano: ");
        scanf("%[^\n]", veic->anoVeic);
        getchar();
        while (!validarAnoVeic(veic->anoVeic) == 0){
            printf("///           Ano inválido!: ");
            scanf("%[^\n]", veic->anoVeic);
            getchar();
        }
            printf("///           Valor do aluguel: ");
        scanf("%f", &veic->valor);
        getchar();
        while (validarValor(veic->valor) == 0){
            printf("///           Valor inválido!: ");
            scanf("%f", &veic->valor);
	        getchar();
        }
        veic->status = 'D';
        veic->quantidadeAlugueis = 0;
        veic->statusCadastro = 'C';      
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return veic;
    }
}

void gravarVeiculos(Veiculos* veic) {
	FILE* fp;

	fp = fopen("veiculos.dat", "ab");
	if (fp == NULL) {
		telaErroArquivoVeic();
	}
	fwrite(veic, sizeof(Veiculos), 1, fp);
	fclose(fp);
}

char* telaPesquisarVeiculos(void) {
    char* placa;
        placa = (char*) malloc(8*sizeof(char));

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
    printf("///           = = = = = = = Pesquisar Veículos  = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", placa);
    getchar();
} while (!validarPlacaVeic(placa));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return placa;
}

Veiculos* buscarVeiculos(char* placa) {
    FILE* fp;
    Veiculos* veic;

    veic = (Veiculos*) malloc(sizeof(Veiculos));
    fp = fopen("veiculos.dat", "rb");
    if (fp == NULL) {
        telaErroArquivoVeic();
    }
    while(!feof(fp)) {
        fread(veic, sizeof(Veiculos), 1, fp);
        if ((strcmp(veic->placaVeic, placa) == 0)  && (veic->statusCadastro == 'C')) {
            fclose(fp);
            return veic;
        }
    }
    fclose(fp);
    return NULL;
}

void exibirVeiculos(Veiculos* veic) {

    if (veic == NULL) {
        printf("\n= = = Veículo Inexistente = = =\n");
    } else {
        printf("\n= = = Veículo Cadastrado = = =\n");
        printf("Placa do veículo: %s\n", veic->placaVeic);
        printf("Nome do veículo: %s\n", veic->nomeVeic);
        printf("Marca do veículo: %s\n", veic->marcaVeic);
        printf("Ano do veículo: %s\n", veic->anoVeic);
        printf("Valor: %.2f\n", veic->valor);
        printf("Quantidade de Aluguéis: %i\n", veic->quantidadeAlugueis);
        if(veic->status == 'D'){
            printf("Disponível\n");
        }
        else{
            printf("Alugado\n");
        }
    }
    getchar();
}

char* telaAtualizarVeiculos(void) {
    char* placa;
        placa = (char*) malloc(8*sizeof(char));

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
    printf("///           = = = = = = = Atualizar Veículos  = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", placa);
    getchar();
} while (!validarPlacaVeic(placa));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return placa;
}

void regravarVeiculos(Veiculos* veic) {
	int achou;
	FILE* fp;
	Veiculos* veicLido;

	veicLido = (Veiculos*) malloc(sizeof(Veiculos));
	fp = fopen("veiculos.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivoVeic();
	}
	achou = 0;
	while(fread(veicLido, sizeof(Veiculos), 1, fp) && !achou) {
        if (strcmp(veicLido->placaVeic, veic->placaVeic) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Veiculos), SEEK_CUR);
        fwrite(veic, sizeof(Veiculos), 1, fp);
		}
	}
	fclose(fp);
	free(veicLido);
}

char* telaExcluirVeiculos(void) {
    char *placa;
        placa = (char*) malloc(8*sizeof(char));
    
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
    printf("///           = = = = = = = = Excluir Veículos  = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", placa);
    getchar();
} while (!validarPlacaVeic(placa));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return placa;
}

Veiculos* buscarVeiculosCadastrado(char* placa) {
  FILE* fp;
  Veiculos* veic;

  veic = (Veiculos*) malloc(sizeof(Veiculos));
  fp = fopen("veiculos.dat", "rb");
  if (fp == NULL) {
    return NULL;
  }
  while(!feof(fp)) {
    fread(veic, sizeof(Veiculos), 1, fp);
    if (strcmp(veic->placaVeic, placa) == 0  && (veic->statusCadastro == 'C')) {
      fclose(fp);
      return veic;
    }
  }
  fclose(fp);
  return NULL;
}
