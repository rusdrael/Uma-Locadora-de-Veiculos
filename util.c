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
#include <ctype.h>

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

////////////////////////////
// Validar Letra e Dígito //
////////////////////////////

//Inspirado no modelo de @flgorgonio
int ehLetraDig(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else if (c >= '0' && c <= '9') {
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

int validarEmail(char email[]) {
  int tam = strlen(email);
  int arrobas = 0;
  int pontos = 0;
  int posicaoArroba = 0;
  int posicaoPonto = 0;
  for(int i = 0; i < tam; i++){
    if (email[i] == '@'){
      arrobas+=1;
      posicaoArroba = i;
      if (!(email[i+1] >= 'a' && email[i+1] <= 'z')){
        return 0;
      }
    }
  }
  if(arrobas != 1){
    return 0;
  }
  for (int i = 0; i < tam; i++){
    if(email[i] == '.'){
      pontos += 1;
      posicaoPonto = i;
      if (email[i+1] == '.'){
        return 0;
      }
    }
  
  }
  if (pontos == 0 || posicaoPonto <= posicaoArroba){
    return 0;
  }

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
int validarCelular(char* celular) {
  int tam;
  tam = strlen(celular);
  if (tam != 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(celular[i])) {
        return 0;
    }
  }
  return 1;
}

//////////////////////
// Validação do CPF //
//////////////////////

//Inspirado no modelo de @flgorgonio
int validarCpf(char cpf[]) {
  int soma;
  int d1;
  int d2;
  int tam = strlen(cpf);
  if (tam != 11) {
    return 0;
  }
  for(int i = 0; i<11;i++){
    if ((cpf[i] - '0') < 0 || (cpf[i] - '0') > 9){
    return 0;
    }
  }
  soma = 0;
  for(int i = 0; i<9;i++){
  soma += ((cpf[i] - '0') * (10 - i));
  }
  d1 = 11 - (soma % 11);
  if (d1 == 10 || d1 == 11){
    d1 = 0;
  }
  if (d1 != (cpf[9] - '0')){
    return 0;
  }
  soma = 0;
  for(int i = 0; i<10;i++){
    soma += (cpf[i]-'0') * (11 - i);
  }
  d2 = 11 - (soma%11);
  if (d2 == 10 || d2 == 11){
    d2 = 0;
  }
  if (d2 != (cpf[10] - '0')){
    return 0;
  }
  return 1;
}

////////////////////////////
// Validação da PlacaVeic //
////////////////////////////

int validarPlacaVeic(char* placaVeic) {
  // Ainda não implementada
	return 1;
}

///////////////////////////
// Validação do NomeVeic //
///////////////////////////

//Inspirado no modelo de @flgorgonio
int validarNomeVeic(char* nomeVeic) {
  for (int i=0; nomeVeic[i]!='\0'; i++) {
    if (!ehLetraDig(nomeVeic[i])) {
      return 0;
    }
  }
	return 1;
}

////////////////////////////
// Validação da MarcaVeic //
////////////////////////////

//Inspirado no modelo de @flgorgonio
int validarMarcaVeic(char* marcaVeic) {
  for (int i=0; marcaVeic[i]!='\0'; i++) {
    if (!ehLetra(marcaVeic[i])) {
      return 0;
    }
  }
	return 1;
}

//////////////////////////
// Validação do AnoVeic //
//////////////////////////

//Inspirado no modelo de @flgorgonio
int validarAnoVeic(char* anoVeic) {
  int tam;
  tam = strlen(anoVeic);
  if (tam != 4) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(anoVeic[i])) {
        return 0;
    }
  }
  return 1;
}
