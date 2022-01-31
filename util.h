///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Uma Locadora de Veículos                       ///
///          Developed by @rusdrael and @matheusfaria21 - Out, 2021         ///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////
// Assinatura das Validações //
///////////////////////////////

#define True 1
#define False 0

void limpaTela(void);
int ehDigito(char);
int ehLetra(char);
int ehBissexto(int);
int ehData(int, int, int);

int validarNome(char*);
int validarEmail(char*);
int validarData(char*);
int validarCelular(char*);
int validarPlaca(char*);
int validarCpf(char*);
int validarPlacaVeic(char*);
int validarNomeVeic(char*);
int validarMarcaVeic(char*);
int validarAnoVeic(char*);
int validaConfirmacao(char[]);