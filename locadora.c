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
#include "cliente.h"
#include "veiculos.h"
#include "locacao.h"
#include "relatorios.h"
#include "info.h"
#include "util.h"

////////////////////////////
// Assinatura das funções //
////////////////////////////

char telaPrincipal(void);

////////////////////////
// Programa principal //
////////////////////////

//Inspirado no modelo de @flgorgonio
int main(void) {
    char escolha;
    do {
        escolha = telaPrincipal();
        switch(escolha) {
            case '1': moduloCliente();
                                break;
            case '2': moduloVeiculos();
                                break;
            case '3': moduloLocacao();
                                break;
            case '4': moduloRelatorios(); 
                                break;
            case '5': moduloInfo(); 
                                break;
        }
    } while (escolha != '0');                                                      
    return 0;
}

/////////////////////////////////
// Funções do Módulo Principal //
/////////////////////////////////

char telaPrincipal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Uma Locadora de Veículos                       ///\n");
    printf("///             Developed by @rusdrael and @matheusfaria21 - Out, 2021      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Locadora de Veículos RM = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Módulo Cliente                                            ///\n");
    printf("///            2. Módulo Veículos                                           ///\n");
    printf("///            3. Módulo Locação                                            ///\n");
    printf("///            4. Módulo Relatórios                                         ///\n");
    printf("///            5. Módulo Informações                                        ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return op;
}
