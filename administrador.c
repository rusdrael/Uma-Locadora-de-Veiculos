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
#include "administrador.h"
#include "util.h"

/////////////////////////////////////
// Funções do Módulo Administrador //
/////////////////////////////////////

//Inspirado no modelo de @flgorgonio
void moduloAdministrador(void) {
    char escolha;
    do {
        escolha = telaMenuAdministrador();
        switch(escolha) {
            case '1': cadastrarAdministrador();
                                break;
            case '2': pesquisarAdministrador();
                                break;
            case '3': atualizarAdministrador();
                                break;
            case '4': excluirAdministrador();
                                break;
        }
    } while (escolha != '0');                                                      
}


void cadastrarAdministrador(void) {
    Administrador* admin;
    admin = telaCadastrarAdministrador();
    gravarAdministrador(admin);
    free(admin);
}

void pesquisarAdministrador(void) {
    Administrador* admin;
	char* cpf;

	cpf = telaPesquisarAdministrador();
	admin = buscarAdministrador(cpf);
	exibirAdministrador(admin);
	free(admin); 
	free(cpf);
}

void atualizarAdministrador(void) {
   Administrador* admin;
	char* cpf;

	cpf = telaAtualizarAdministrador();
	admin = buscarAdministrador(cpf);
	if (admin == NULL) {
    	printf("\n\nAdministrador não encontrado!\n\n");
  	} else {
		  admin = telaCadastrarAdministrador();
		  strcpy(admin->cpf, cpf);
		  regravarAdministrador(admin);
		  free(admin);
	}
	free(cpf);
}

void excluirAdministrador(void) {
    Administrador* admin;
	char *cpf;

	cpf = telaExcluirAdministrador();
	admin = (Administrador*) malloc(sizeof(Administrador));
	admin = buscarAdministrador(cpf);
	if (admin == NULL) {
    	printf("\n\nAdministrador não encontrado!\n\n");
  	} else {
		  admin->status = False;
		  regravarAdministrador(admin);
		  free(admin);
	}
	free(cpf);
}

void telaErroArquivoAdmin(void) {
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
	printf("///           = = com informações sobre os administradores  =               ///\n");
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

char telaMenuAdministrador(void) {
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
    printf("///           = = = = = = = Menu Administrador  = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar um novo administrador                          ///\n");
    printf("///           2. Pesquisar os dados de um administrador                   ///\n");
    printf("///           3. Atualizar o cadastro de um administrador                 ///\n");
    printf("///           4. Excluir um administrador do sistema                      ///\n");
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


Administrador* telaCadastrarAdministrador(void) {
    Administrador* admin;
        admin = (Administrador*) malloc(sizeof(Administrador));

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
        printf("///           = = = = = = Cadastrar Administrador = = = = = =             ///\n");
        printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
        printf("///                                                                       ///\n");
    do {
        printf("///           CPF (apenas números): ");
        scanf("%[^\n]", admin->cpf);
        getchar();
    } while (!validarCpf(admin->cpf));  
    do {
        printf("///           Nome completo: ");
        scanf("%[^\n]", admin->nome);
        getchar();
    } while (!validarNome(admin->nome));    
    do {
        printf("///           E-mail: ");
        scanf("%[^\n]", admin->email);
        getchar(); 
    } while (!validarEmail(admin->email));   
    do {
        printf("///           Data de Nascimento (dd/mm/aaaa):  ");
        scanf("%[^\n]", admin->nasc);
        getchar();
    } while (!validarData(admin->nasc));      
    do {
        printf("///           Celular  (apenas números): ");
        scanf("%[^\n]", admin->celular);
        getchar();
    } while (!validarCelular(admin->celular));
    admin->status = True;
        printf("///                                                                       ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");

        return admin;
}

void gravarAdministrador(Administrador* admin) {
	FILE* fp;

	fp = fopen("administradores.dat", "ab");
	if (fp == NULL) {
		telaErroArquivoAdmin();
	}
	fwrite(admin, sizeof(Administrador), 1, fp);
	fclose(fp);
}

char* telaPesquisarAdministrador(void) {
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
    printf("///           = = = = = Pesquisar Administrador = = = = = = =             ///\n");
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

Administrador* buscarAdministrador(char* cpf) {
    FILE* fp;
    Administrador* admin;

    admin = (Administrador*) malloc(sizeof(Administrador));
    fp = fopen("administradores.dat", "rb");
    if (fp == NULL) {
        telaErroArquivoAdmin();
    }
    while(fread(admin, sizeof(Administrador), 1, fp)) {
        if ((strcmp(admin->cpf, cpf) == 0)  && (admin->status == True)) {
            fclose(fp);
            return admin;
        }
    }
    fclose(fp);
    return NULL;
}

void exibirAdministrador(Administrador* admin) {

    if (admin == NULL) {
        printf("\n= = = Administrador Inexistente = = =\n");
    } else {
        printf("\n= = = Administrador Cadastrado = = =\n");
        printf("CPF: %s\n", admin->cpf);
        printf("Nome do administrador: %s\n", admin->nome);
        printf("E-mail: %s\n", admin->email);
        printf("Celular: %s\n", admin->celular);
        printf("Status: %i\n", admin->status);
    }
    getchar();
}

char* telaAtualizarAdministrador(void) {
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
    printf("///           = = = = = = Atualizar Administrador = = = = = =             ///\n");
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

void regravarAdministrador(Administrador* admin) {
	int achou;
	FILE* fp;
	Administrador* adminLido;

	adminLido = (Administrador*) malloc(sizeof(Administrador));
	fp = fopen("administradores.dat", "r+b");
	if (fp == NULL) {
		telaErroArquivoAdmin();
	}
	achou = False;
	while(fread(adminLido, sizeof(Administrador), 1, fp) && !achou) {
        if (strcmp(adminLido->cpf, admin->cpf) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Administrador), SEEK_CUR);
        fwrite(admin, sizeof(Administrador), 1, fp);
		}
	}
	fclose(fp);
	free(adminLido);
}

char* telaExcluirAdministrador(void) {
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
    printf("///           = = = = = = Excluir Administrador = = = = = = =             ///\n");
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
