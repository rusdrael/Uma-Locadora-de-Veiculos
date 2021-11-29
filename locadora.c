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
#include "administrador.h"
#include "disponiveis.h"
#include "alugados.h"
#include "info.h"

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
            case '2': moduloAdministrador();
                                break;
            case '3': moduloVeiculosDisp();
                                break;
            case '4': moduloVeiculosAlug();
                                break;
            case '5': //moduloRelatorios(); 
                                break;
            case '6': moduloInfo(); 
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
    printf("///            2. Módulo Administrador                                      ///\n");
    printf("///            3. Módulo Veículos Disponíveis                               ///\n");
    printf("///            4. Módulo Veículos Alugados                                  ///\n");
    printf("///            5. Módulo Relatórios                                         ///\n");
    printf("///            6. Módulo Informações                                        ///\n");
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
