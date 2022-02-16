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
#include "locacao.h"
#include "cliente.h"
#include "veiculos.h"
#include "relatorios.h"
#include "util.h"
#include <time.h>

typedef struct locacao Locacao;

/////////////////////////////////////
// Funções do Módulo Administrador //
/////////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloLocacao(void) {
    char escolha;
    do {
        escolha = telaMenuLocacao();
        switch(escolha) {
            case '1': locarVeiculo();
                                break;
            case '2': devolverVeiculo();
                                break;
            case '3': veiculosDisponiveis();
                                break;
        }
    } while (escolha != '0');                                                      
}


void locarVeiculo(void) {
    Locacao *loc;
    Cliente *cli;
    char* cpf;
    Veiculos *veic;
    char* placaVeic;
    cpf = telaPesquisarCliente();
    cli = buscarCliente(cpf);
    placaVeic = telaPesquisarVeiculos();
    veic = buscarVeiculos(placaVeic);
    if (cli == NULL || veic == NULL || veic->status != 'D'){
        printf("Dados incorretos!");
        getchar();
    }
    else{
        loc = telaLocarVeiculo(cli->cpf, veic->placaVeic, veic->valor);
        if (loc==NULL){
        printf("Empréstimo cancelado!");
        getchar();
        }
        gravarLocacao(loc);
        veic->status = 'A';
        cli->quantidadeAlugueis+=1;
        veic->quantidadeAlugueis+=1;
        regravarVeiculos(veic);
        regravarCliente(cli);
    }
    free(cpf);
    free(cli);
    free(placaVeic);
    free(veic);
    free(loc);
}

void devolverVeiculo(void) {
    Locacao *loc;
    Veiculos *veic;
    char* cpf;
    char* placaVeic;
    cpf = telaPesquisarCliente();
    placaVeic = telaPesquisarVeiculos();
    veic = buscarVeiculos(placaVeic);
    loc = buscarLocacao(cpf, placaVeic);
    if (loc == NULL || loc->status!='N'){
        printf("Locação não encontrada!");
        getchar();
    }
    else{
        loc = telaDevolverVeiculo(loc);
        loc->status = 'P';
        veic->status = 'D';
        regravarVeiculos(veic);
        regravarLocacao(loc);
    }
    free(cpf);
    free(placaVeic);
    free(veic);
    free(loc);
}

void telaErroArquivoLocacao(void) {
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
	printf("///           = = com informações sobre as locações = = = = =             ///\n");
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

char telaMenuLocacao(void) {
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
    printf("///           = = = = = = = = = Menu Locação  = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Locar um veículo                                         ///\n");
    printf("///           2. Devolver veículo                                         ///\n");
    printf("///           3. Listar veículos disponíveis                              ///\n");
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


Locacao* telaLocarVeiculo(char* cpf, char* placaVeic, float valor) {
    char confirmacao[2];
    time_t agora;
    char datahora[100];
    agora = time(NULL);
    strftime( datahora, sizeof(datahora), "%Y.%m.%d - %H:%M:%S", localtime( &agora ));
    Locacao *loc;

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
        printf("///           = = = = = = = = = Locar Veículo = = = = = = = =             ///\n");
        printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
        printf("///                                                                       ///\n");
        loc = (Locacao*) malloc(sizeof(Locacao));
        printf("///           Confirma a locação (s/n): ");
        scanf("%[^\n]", confirmacao);
        getchar();
        while (validaConfirmacao(confirmacao) == 0){
            printf("///           Ação inválida!: ");
            scanf("%[^\n]", confirmacao);
            getchar();
        }
        if(strcmp (confirmacao, "S") == 0 || strcmp (confirmacao, "s") == 0){
            strcpy(loc->cpf, cpf);
            strcpy(loc->placaVeic, placaVeic);
            loc->valorPago = valor;
            strcpy(loc->data, datahora);
            loc->status='N';
        }
        else{
            free(loc);
            return NULL;
        }   
        printf("///                                                                       ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");

        return loc;
}

void gravarLocacao(Locacao* loc) {
	FILE* fp;

	fp = fopen("locacoes.dat", "ab");
	if (fp == NULL) {
		telaErroArquivoLocacao();
	}
	fwrite(loc, sizeof(Locacao), 1, fp);
	fclose(fp);
}

Locacao* telaDevolverVeiculo(Locacao* loc) {
    int dias;
    float multa;

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
    printf("///           = = = = = = = = Devolver Veículo  = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           CPF: %s\n", loc->cpf);
    printf("///           Placa: %s\n", loc->placaVeic);
    printf("///           Data: %s\n", loc->data);
    dias = difDatas(loc->data) + 1;
    if(dias>=7){
        multa = (dias - 7) * 2;
        loc->valorPago+=multa;
        printf("///     Valor com multa: %.2f\n", loc->valorPago);  
    }
    else{
        printf("///     Valor: %.2f\n", loc->valorPago);
    }
    getchar();
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return loc;
}

///Diferença de datas - Adaptado de: https://pt.stackoverflow.com/questions/126793/como-declarar-uma-vari%C3%A1vel-de-data-em-c
int difDatas( char datahora1[] )
{
    time_t t1;
    time_t t2;
    double dias;
    struct tm tm; 
    int ano, mes; 
    char datahora2[] = "2021.05.14 - 13:10:20";
    time_t agora;
    agora = time(NULL);
    strftime( datahora2, sizeof(datahora2), "%Y.%m.%d - %H:%M:%S", localtime( &agora ) );

    sscanf( datahora1, "%d.%d.%d - %d:%d:%d", &ano, &mes, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec );

    tm.tm_year = ano - 1900;
    tm.tm_mon = mes - 1;

    t1 = mktime( &tm );

    sscanf( datahora2, "%d.%d.%d - %d:%d:%d", &ano, &mes, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec );

    tm.tm_year = ano - 1900;
    tm.tm_mon = mes - 1;

    t2 = mktime( &tm );
    dias = difftime(t2,t1)/86400;

    return dias;
}

Locacao* buscarLocacao(char* cpf, char* placaVeic) {
    FILE* fp;
    Locacao* loc;

    loc = (Locacao*) malloc(sizeof(Locacao));
    fp = fopen("locacoes.dat", "rb");
    if (fp == NULL) {
        telaErroArquivoLocacao();
    }
    while(!feof(fp)) {
        fread(loc, sizeof(Locacao), 1, fp);
        if ((strcmp(loc->cpf, cpf) == 0)  && (strcmp(loc->placaVeic, placaVeic) == 0) && (loc->status != 'P')) {
            fclose(fp);
            return loc;
        }
    }
    fclose(fp);
    return NULL;
}

void regravarLocacao(Locacao* loc) {
	int achou;
	FILE* fp;
	Locacao* locLido;

	locLido = (Locacao*) malloc(sizeof(Locacao));
	fp = fopen("locacoes.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivoLocacao();
	}
	achou = 0;
	while(fread(locLido, sizeof(Locacao), 1, fp) && !achou) {
        if ((strcmp(locLido->cpf, loc->cpf) == 0) && (strcmp(locLido->placaVeic, loc->placaVeic) == 0 && (strcmp(locLido->data, loc->data) == 0) )) {
			achou = 1;
			fseek(fp, -1*sizeof(Locacao), SEEK_CUR);
        fwrite(loc, sizeof(Locacao), 1, fp);
		}
	}
	fclose(fp);
	free(locLido);
}
