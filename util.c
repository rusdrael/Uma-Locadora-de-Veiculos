///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Uma Locadora de Veículos                       ///
///          Developed by @rusdrael and @matheusfaria21 - Out, 2021         ///
///////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <string.h>

/////////////////
// Limpar Tela //
/////////////////

//Criado por @flgorgonio
void limpaTela(void) {
  if (system("clear") || system("cls")) {
    // limpa a tela, Linux, Mac e Windows
  }
}

////////////////////
// Validar Dígito //
////////////////////

//Criado por @flgorgonio
int ehDigito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}

///////////////////
// Validar Letra //
///////////////////

//Criado por @flgorgonio
int ehLetra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
}

/////////////////////////////
// Verificar se é bissexto //
/////////////////////////////

//Criado por @flgorgonio
int ehBissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

//////////////////
// Validar Data //
//////////////////

//Criado por @flgorgonio
int ehData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (ehBissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return 0;
  return 1;
}

///////////////////////
// Validação do Nome //
///////////////////////

//Criado por @flgorgonio
int validarNome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!ehLetra(nome[i])) {
      return 0;
    }
  }
	return 1;
}

////////////////////////
// Validação do Email //
////////////////////////

//Criado por @flgorgonio
int validarEmail(char* email) {
  // Ainda não implementada
	return 1;
}

///////////////////////
// Validação da Data //
///////////////////////

//Criado por @flgorgonio
int validarData(char* data) {
  int tam, dia, mes, ano;
  tam = strlen(data);
  if (tam != 8) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(data[i])) {
      return 0;
    }
  }
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[2] - '0') * 10 + (data[3] - '0');
  ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + 
        (data[6] - '0') * 10 + (data[7] - '0');
  if (!ehData(dia, mes, ano)) {
    return 0;
  }
  return 1;
}

///////////////////////////
// Validação do Telefone //
///////////////////////////

//Criado por @flgorgonio
int validarFone(char* fone) {
  int tam;
  tam = strlen(fone);
  if (tam != 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(fone[i])) {
        return 0;
    }
  }
  return 1;
}

////////////////////////
// Validação da Placa //
////////////////////////

//Inspirado no modelo de @flgorgonio
int validarPlaca(char* placa) {
  // Ainda não implementada
	return 1;
}
