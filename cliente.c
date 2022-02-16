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
#include "cliente.h"
#include "util.h"

typedef struct cliente Cliente;

///////////////////////////////
// Funções do Módulo Cliente //
///////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloCliente(void) {
    char escolha;
    do {
        escolha = telaMenuCliente();
        switch(escolha) {
            case '1': cadastrarCliente();
                                break;
            case '2': pesquisarCliente();
                                break;
            case '3': atualizarCliente();
                                break;
            case '4': excluirCliente();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarCliente(void) {
    Cliente* cli;
    cli = telaCadastrarCliente(1);
    if (cli == NULL){
        printf("Cliente já cadastrado!");
    }
    else{
        gravarCliente(cli);
        free(cli);
    }
}

void pesquisarCliente(void) {
    Cliente* cli;
	char* cpf;

	cpf = telaPesquisarCliente();
	cli = buscarCliente(cpf);
	exibirCliente(cli);
	free(cli); 
	free(cpf);
}

void atualizarCliente(void) {
    Cliente* cli;
	char* cpf;

	cpf = telaAtualizarCliente();
	cli = buscarCliente(cpf);
	if (cli == NULL) {
    	printf("\n\nCliente não encontrado!\n\n");
  	} else {
		  cli = telaCadastrarCliente(2);
		  strcpy(cli->cpfCliente, cpf);
		  regravarCliente(cli);
	}
    free(cli);
	free(cpf);
}

void excluirCliente(void) {
   Cliente* cli;
	char *cpf;
  char confirmacao[2];
	cpf = telaExcluirCliente();
	cli = (Cliente*) malloc(sizeof(Cliente));
	cli = buscarCliente(cpf);
	if (cli == NULL) {
    printf("\n\nCliente não encontrado!\n\n");
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
		  cli->status = 'X';
		  regravarCliente(cli);
      free(cli);
		  
    }
    else if(confirmacao[0] == 'N' || confirmacao[0] == 'n'){
      printf("Ação interrompida!");
    }
	}
	free(cpf);
}

void telaErroArquivo(void) {
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
	printf("///           = = = = com informações sobre os clientes = = =             ///\n");
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

char telaMenuCliente(void) {
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
    printf("///           = = = = = = = = = Menu Cliente  = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo cliente                                ///\n");
    printf("///           2. Pesquisar os dados de um cliente                         ///\n");
    printf("///           3. Atualizar o cadastro de um cliente                       ///\n");
    printf("///           4. Excluir um cliente do sistema                            ///\n");
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


Cliente* telaCadastrarCliente(int tipo) {
    Cliente* cli;
    char cpf[12];
    
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
    printf("///           = = = = = = = = Cadastrar Cliente = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           CPF (apenas números): ");
    scanf("%[^\n]", cpf);
    getchar();
    while (validarCpf(cpf) == 0){
        printf("///           CPF inválido!: ");
        scanf("%[^\n]", cpf);
        getchar();
    } 
    if((buscarClienteCadastrado(cpf) !=NULL) && (tipo == 1) ){
        return NULL;
        free(cli);
    }
    else{
        cli = (Cliente*) malloc(sizeof(Cliente));
        strcpy(cli->cpfCliente, cpf);
            printf("///           Nome:");
        scanf("%[^\n]", cli->nome);
        getchar();
        while (validarNome(cli->nome) == 0){
            printf("///           Nome inválido!: ");
            scanf("%[^\n]", cli->nome);
            getchar();  
        }        
            printf("///           E-mail: ");
        scanf("%[^\n]", cli->email);
        getchar();
        while (validarEmail(cli->email) == 0){
            printf("///           E-mail inválido!:  ");
            scanf("%[^\n]", cli->email);
            getchar();
        }
            printf("///           Data de nascimento (dd/mm/aaaa):  ");
        scanf("%[^\n]", cli->nasc);
        getchar();
        while (!validarData(cli->nasc) == 0){  
            printf("///           Data de nascimento inválida!:  ");
            scanf("%[^\n]", cli->nasc);
            getchar();
        }
            printf("///           Celular  (apenas números): ");
        scanf("%[^\n]", cli->celular);
        getchar();
        while (!validarCelular(cli->celular) == 0){
            printf("///           Celular inválido!:  ");
            scanf("%[^\n]", cli->celular);
            getchar();
        }
        cli->status = 'C';
        cli->quantidadeAlugueis = 0;
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return cli;
    }
}

void gravarCliente(Cliente* cli) {
	FILE* fp;

	fp = fopen("clientes.dat", "ab");
	if (fp == NULL) {
		telaErroArquivo();
	}
	fwrite(cli, sizeof(Cliente), 1, fp);
	fclose(fp);
}

char* telaPesquisarCliente(void) {
    char* cpf;
        cpf = (char*) malloc(12*sizeof(char));

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
    printf("///           = = = = = = = Pesquisar Cliente = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {    
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[^\n]", cpf);
    getchar();
} while (!validarCpf(cpf));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return cpf;
}

Cliente* buscarCliente(char* cpf) {
    FILE* fp;
    Cliente* cli;

    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErroArquivo();
    }
    while(!feof(fp)) {
        fread(cli, sizeof(Cliente), 1, fp);
        if ((strcmp(cli->cpfCliente, cpf) == 0)  && (cli->status == 'C')) {
            fclose(fp);
            return cli;
        }
    }
    fclose(fp);
    return NULL;
}

void exibirCliente(Cliente* cli) {

    if (cli == NULL) {
        printf("\n= = = Cliente Inexistente = = =\n");
    } else {
        printf("\n= = = Cliente Cadastrado = = =\n");
        printf("CPF: %s\n", cli->cpfCliente);
        printf("Nome do cliente: %s\n", cli->nome);
        printf("E-mail: %s\n", cli->email);
        printf("Celular: %s\n", cli->celular);
        printf("Quantidade de aluguéis: %i\n", cli->quantidadeAlugueis);
    }
    getchar();
}

char* telaAtualizarCliente(void) {
    char* cpf;
        cpf = (char*) malloc(12*sizeof(char));

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
    printf("///           = = = = = = = = Atualizar Cliente = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do { 
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[^\n]", cpf);
    getchar();
} while (!validarCpf(cpf));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return cpf;
}

void regravarCliente(Cliente* cli) {
	int achou;
	FILE* fp;
	Cliente* cliLido;

	cliLido = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivo();
	}
	achou = 0;
	while(fread(cliLido, sizeof(Cliente), 1, fp) && !achou) {
        if (strcmp(cliLido->cpfCliente, cli->cpfCliente) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
        fwrite(cli, sizeof(Cliente), 1, fp);
		}
	}
	fclose(fp);
	free(cliLido);
}

char* telaExcluirCliente(void) {
    char *cpf;
        cpf = (char*) malloc(12*sizeof(char));
    
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
    printf("///           = = = = = = = = Excluir Cliente = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
do {
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[^\n]", cpf);
    getchar();
} while (!validarCpf(cpf));
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    return cpf;
}

Cliente* buscarClienteCadastrado(char* cpf) {
    FILE* fp;
    Cliente* cli;

    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        return NULL;
    }
    while(!feof(fp)) {
        fread(cli, sizeof(Cliente), 1, fp);
        if ((strcmp(cli->cpfCliente, cpf) == 0)  && (cli->status == 'C')) {
            fclose(fp);
            return cli;
        }
    }
    fclose(fp);
    return NULL;
}