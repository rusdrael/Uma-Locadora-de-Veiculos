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
    cli = telaCadastrarCliente();
    gravarCliente(cli);
    free(cli);
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
		  cli = telaCadastrarCliente();
		  strcpy(cli->cpf, cpf);
		  regravarCliente(cli);
		  free(cli);
	}
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


Cliente* telaCadastrarCliente(void) {
    Cliente* cli;
        cli = (Cliente*) malloc(sizeof(Cliente));
    
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
    do {
        printf("///           CPF (apenas números): ");
        scanf("%[^\n]", cli->cpf);
        getchar();
    } while (!validarCpf(cli->cpf));
    do {
        printf("///           Nome completo: ");
        scanf("%[^\n]", cli->nome);
        getchar();
    } while (!validarNome(cli->nome)); 
    do {
        printf("///           E-mail: ");
        scanf("%[^\n]", cli->email);
        getchar();
    } while (!validarEmail(cli->email));
    do {
        printf("///           Data de Nascimento (dd/mm/aaaa):  ");
        scanf("%[^\n]", cli->nasc);
        getchar();
    } while (!validarData(cli->nasc));  
    do {
        printf("///           Celular  (apenas números): ");
        scanf("%[^\n]", cli->celular);
        getchar();
    } while (!validarCelular(cli->celular));
    cli->status = True;
        printf("///                                                                       ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");

        return cli;
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
    while(fread(cli, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cli->cpf, cpf) == 0)  && (cli->status == True)) {
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
        printf("CPF: %s\n", cli->cpf);
        printf("Nome do cliente: %s\n", cli->nome);
        printf("E-mail: %s\n", cli->email);
        printf("Celular: %s\n", cli->celular);
        printf("Status: %i\n", cli->status);
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
	achou = False;
	while(fread(cliLido, sizeof(Cliente), 1, fp) && !achou) {
        if (strcmp(cliLido->cpf, cli->cpf) == 0) {
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
