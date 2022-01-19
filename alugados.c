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
#include "alugados.h"
#include "util.h"

/////////////////////////////////////////
// Funções do Módulo Veículos Alugados //
/////////////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloVeiculosAlug(void) {
    char escolha;
    do {
        escolha = telaMenuVeiculosAlug();
        switch(escolha) {
            case '1': cadastrarVeiculosAlug();
                                break;
            case '2': pesquisarVeiculosAlug();
                                break;
            case '3': atualizarVeiculosAlug();
                                break;
            case '4': excluirVeiculosAlug();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarVeiculosAlug(void) {
    Alugados* alug;
    alug = telaCadastrarVeiculosAlug();
    gravarVeiculosAlug(alug);
    free(alug);
}

void pesquisarVeiculosAlug(void) {
    Alugados* alug;
	char* placaVeic;

	placaVeic = telaPesquisarVeiculosAlug();
	alug = buscarVeiculosAlug(placaVeic);
	exibirVeiculosAlug(alug);
	free(alug); 
	free(placaVeic);
}

void atualizarVeiculosAlug(void) {
    Alugados* alug;
	char* placaVeic;

	placaVeic = telaAtualizarVeiculosAlug();
	alug = buscarVeiculosAlug(placaVeic);
	if (alug == NULL) {
    	printf("\n\nVeículo Alugado não encontrado!\n\n");
  	} else {
		  alug = telaCadastrarVeiculosAlug();
		  strcpy(alug->placaVeic, placaVeic);
		  regravarVeiculosAlug(alug);
		  free(alug);
	}
	free(placaVeic);
}

void excluirVeiculosAlug(void) {
    Alugados* alug;
	char *placaVeic;

	placaVeic = telaExcluirVeiculosAlug();
	alug = (Alugados*) malloc(sizeof(Alugados));
	alug = buscarVeiculosAlug(placaVeic);
	if (alug == NULL) {
    	printf("\n\nVeículo Alugado não encontrado!\n\n");
  	} else {
		  alug->status = False;
		  regravarVeiculosAlug(alug);
		  free(alug);
	}
	free(placaVeic);
}

void telaErroArquivoAlug(void) {
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
	printf("///           = = = = = = = = = alugados  = = = = = = = = = =               ///\n");
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

char telaMenuVeiculosAlug(void) {
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
    printf("///           = = = = = = Menu Veículos Alugados  = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo veículo alugado                        ///\n");
    printf("///           2. Pesquisar os dados de um veículo alugado                 ///\n");
    printf("///           3. Atualizar o cadastro de um veículo alugado               ///\n");
    printf("///           4. Excluir um veículo alugado do sistema                    ///\n");
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


Alugados* telaCadastrarVeiculosAlug(void) {
    Alugados* alug;
        alug = (Alugados*) malloc(sizeof(Alugados));

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
    printf("///           = = = = = Cadastrar Veículos Alugados = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {    
    printf("///           Placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", alug->placaVeic);
    getchar();
} while (!validarPlacaVeic(alug->placaVeic));     
do {    
    printf("///           Nome: ");
    scanf("%[^\n]", alug->nomeVeic);
    getchar();
} while (!validarNomeVeic(alug->nomeVeic));    
do {     
    printf("///           Marca: ");
    scanf("%[^\n]", alug->marcaVeic);
    getchar();
} while (!validarMarcaVeic(alug->marcaVeic));     
do {     
    printf("///           Ano: ");
    scanf("%[^\n]", alug->anoVeic);
    getchar();
} while (!validarAnoVeic(alug->anoVeic));
alug->status = True;     
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return alug;
}

void gravarVeiculosAlug(Alugados* alug) {
	FILE* fp;

	fp = fopen("alugados.txt", "at");
	if (fp == NULL) {
		telaErroArquivoAlug();
	}
	fwrite(alug, sizeof(Alugados), 1, fp);
	fclose(fp);
}

char* telaPesquisarVeiculosAlug(void) {
    char* placaVeic;
        placaVeic = (char*) malloc(8*sizeof(char));

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
    printf("///           = = = = = Pesquisar Veículos Alugados = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return placaVeic;
}

Alugados* buscarVeiculosAlug(char* placaVeic) {
    FILE* fp;
    Alugados* alug;

    alug = (Alugados*) malloc(sizeof(Alugados));
    fp = fopen("alugados.txt", "rt");
    if (fp == NULL) {
        telaErroArquivoAlug();
    }
    while(fread(alug, sizeof(Alugados), 1, fp)) {
        if ((strcmp(alug->placaVeic, placaVeic) == 0)  && (alug->status == True)) {
            fclose(fp);
            return alug;
        }
    }
    fclose(fp);
    return NULL;
}

void exibirVeiculosAlug(Alugados* alug) {

    if (alug == NULL) {
        printf("\n= = = Veículo alugado Inexistente = = =\n");
    } else {
        printf("\n= = = Veículo alugado Cadastrado = = =\n");
        printf("Placa do veículo alugado: %s\n", alug->placaVeic);
        printf("Nome do veículo alugado: %s\n", alug->nomeVeic);
        printf("Marca do veículo alugado: %s\n", alug->marcaVeic);
        printf("Ano do veículo alugado: %s\n", alug->anoVeic);
        printf("Status: %i\n", alug->status);
    }
    getchar();
}

char* telaAtualizarVeiculosAlug(void) {
    char* placaVeic;
        placaVeic = (char*) malloc(8*sizeof(char));

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
    printf("///           = = = = = Atualizar Veículos Alugados = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return placaVeic;
}

void regravarVeiculosAlug(Alugados* alug) {
	int achou;
	FILE* fp;
	Alugados* alugLido;

	alugLido = (Alugados*) malloc(sizeof(Alugados));
	fp = fopen("alugados.txt", "r+t");
	if (fp == NULL) {
		telaErroArquivoAlug();
	}
	achou = False;
	while(fread(alugLido, sizeof(Alugados), 1, fp) && !achou) {
        if (strcmp(alugLido->placaVeic, alug->placaVeic) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Alugados), SEEK_CUR);
        fwrite(alug, sizeof(Alugados), 1, fp);
		}
	}
	fclose(fp);
	free(alugLido);
}

char* telaExcluirVeiculosAlug(void) {
    char *placaVeic;
        placaVeic = (char*) malloc(8*sizeof(char));
    
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
    printf("///           = = = = = = Excluir Veículos Alugados = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe a placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", placaVeic);
    getchar();
} while (!validarPlacaVeic(placaVeic));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return placaVeic;
}
