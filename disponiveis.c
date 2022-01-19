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
#include "disponiveis.h"
#include "util.h"

////////////////////////////////////////////
// Funções do Módulo Veículos Disponíveis //
////////////////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloVeiculosDisp(void) {
    char escolha;
    do {
        escolha = telaMenuVeiculosDisp();
        switch(escolha) {
            case '1': cadastrarVeiculosDisp();
                                break;
            case '2': pesquisarVeiculosDisp();
                                break;
            case '3': atualizarVeiculosDisp();
                                break;
            case '4': excluirVeiculosDisp();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarVeiculosDisp(void) {
    Disponiveis* disp;
    disp = telaCadastrarVeiculosDisp();
    gravarVeiculosDisp(disp);
    free(disp);
}

void pesquisarVeiculosDisp(void) {
    Disponiveis* disp;
	char* placaVeic;

	placaVeic = telaPesquisarVeiculosDisp();
	disp = buscarVeiculosDisp(placaVeic);
	exibirVeiculosDisp(disp);
	free(disp); 
	free(placaVeic);
}

void atualizarVeiculosDisp(void) {
    Disponiveis* disp;
	char* placaVeic;

	placaVeic = telaAtualizarVeiculosDisp();
	disp = buscarVeiculosDisp(placaVeic);
	if (disp == NULL) {
    	printf("\n\nVeículo disponível não encontrado!\n\n");
  	} else {
		  disp = telaCadastrarVeiculosDisp();
		  strcpy(disp->placaVeic, placaVeic);
		  regravarVeiculosDisp(disp);
		  free(disp);
	}
	free(placaVeic);
}

void excluirVeiculosDisp(void) {
    Disponiveis* disp;
	char *placaVeic;

	placaVeic = telaExcluirVeiculosDisp();
	disp = (Disponiveis*) malloc(sizeof(Disponiveis));
	disp = buscarVeiculosDisp(placaVeic);
	if (disp == NULL) {
    	printf("\n\nVeículo disponível não encontrado!\n\n");
  	} else {
		  disp->status = False;
		  regravarVeiculosDisp(disp);
		  free(disp);
	}
	free(placaVeic);
}

void telaErroArquivoDisp(void) {
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
	printf("///           = = = = = = = = = disponíveis = = = = = = = = =                ///\n");
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

char telaMenuVeiculosDisp(void) {
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
    printf("///           = = = = = Menu Veículos Disponíveis = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo veículo disponível                     ///\n");
    printf("///           2. Pesquisar os dados de um veículo disponível              ///\n");
    printf("///           3. Atualizar o cadastro de um veículo disponível            ///\n");
    printf("///           4. Excluir um veículo disponível do sistema                 ///\n");
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


Disponiveis* telaCadastrarVeiculosDisp(void) {
    Disponiveis* disp;
        disp = (Disponiveis*) malloc(sizeof(Disponiveis));

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
    printf("///           = = = = Cadastrar Veículos Disponíveis  = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {    
    printf("///           Placa (Apenas números e letras maiúsculas): ");
    scanf("%[^\n]", disp->placaVeic);
    getchar();
} while (!validarPlacaVeic(disp->placaVeic));     
do {    
    printf("///           Nome: ");
    scanf("%[^\n]", disp->nomeVeic);
    getchar();
} while (!validarNomeVeic(disp->nomeVeic));    
do {     
    printf("///           Marca: ");
    scanf("%[^\n]", disp->marcaVeic);
    getchar();
} while (!validarMarcaVeic(disp->marcaVeic));     
do {     
    printf("///           Ano: ");
    scanf("%[^\n]", disp->anoVeic);
    getchar();
} while (!validarAnoVeic(disp->anoVeic));
disp->status = True;      
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return disp;
}

void gravarVeiculosDisp(Disponiveis* disp) {
	FILE* fp;

	fp = fopen("disponiveis.txt", "at");
	if (fp == NULL) {
		telaErroArquivoDisp();
	}
	fwrite(disp, sizeof(Disponiveis), 1, fp);
	fclose(fp);
}

char* telaPesquisarVeiculosDisp(void) {
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
    printf("///           = = = = Pesquisar Veículos Disponíveis  = = = =             ///\n");
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

Disponiveis* buscarVeiculosDisp(char* placaVeic) {
    FILE* fp;
    Disponiveis* disp;

    disp = (Disponiveis*) malloc(sizeof(Disponiveis));
    fp = fopen("disponiveis.txt", "rt");
    if (fp == NULL) {
        telaErroArquivoDisp();
    }
    while(fread(disp, sizeof(Disponiveis), 1, fp)) {
        if ((strcmp(disp->placaVeic, placaVeic) == 0)  && (disp->status == True)) {
            fclose(fp);
            return disp;
        }
    }
    fclose(fp);
    return NULL;
}

void exibirVeiculosDisp(Disponiveis* disp) {

    if (disp == NULL) {
        printf("\n= = = Veículo disponível Inexistente = = =\n");
    } else {
        printf("\n= = = Veículo disponível Cadastrado = = =\n");
        printf("Placa do veículo disponível: %s\n", disp->placaVeic);
        printf("Nome do veículo disponível: %s\n", disp->nomeVeic);
        printf("Marca do veículo disponível: %s\n", disp->marcaVeic);
        printf("Ano do veículo disponível: %s\n", disp->anoVeic);
        printf("Status: %i\n", disp->status);
    }
    getchar();
}

char* telaAtualizarVeiculosDisp(void) {
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
    printf("///           = = = = Atualizar Veículos Disponíveis  = = = =             ///\n");
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

void regravarVeiculosDisp(Disponiveis* disp) {
	int achou;
	FILE* fp;
	Disponiveis* dispLido;

	dispLido = (Disponiveis*) malloc(sizeof(Disponiveis));
	fp = fopen("disponiveis.txt", "r+t");
	if (fp == NULL) {
		telaErroArquivoDisp();
	}
	achou = False;
	while(fread(dispLido, sizeof(Disponiveis), 1, fp) && !achou) {
        if (strcmp(dispLido->placaVeic, disp->placaVeic) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Disponiveis), SEEK_CUR);
        fwrite(disp, sizeof(Disponiveis), 1, fp);
		}
	}
	fclose(fp);
	free(dispLido);
}

char* telaExcluirVeiculosDisp(void) {
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
    printf("///           = = = = Excluir Veículos Disponíveis  = = = = =             ///\n");
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
