#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Cabecalho.h"

int main() {
    int indiceMenu = 0;
    int qtdFilmes = 0;
    int codigoFilme = 0; 
    printf("Entre com o tamanho da sua tabela: ");
    scanf("%d", &qtdFilmes);
    printf("\n");

    Filme** listafilme = (Filme**)malloc(qtdFilmes * sizeof(Filme*));

    for (int i = 0; i < qtdFilmes; i++) {
        listafilme[i] = criar_filme();
    }

    print_tabela(listafilme, qtdFilmes);

    do {
        printf("\nMENU DE OPCOES\n\n");
        printf("1 - CADASTRAR DE NOVO TITULO\n");
        printf("2 - ATUALIZAR INFO DE UM TITULO\n");
        printf("3 - EXCLUIR UM TITULO\n");
        printf("4 - FINALIZAR OPERACAO\n\n");
      
        scanf("%d", &indiceMenu);

        switch (indiceMenu) {
        case 1:
            qtdFilmes++;
            listafilme[qtdFilmes-1] = criar_filme();
            printf("Filme adicionado com sucesso!\n\n");
            print_tabela(listafilme, qtdFilmes);
            break;
        case 2:

            printf("\n");
            printf("1 - RENOMEAR TITULO\n");
            printf("2 - ATUALIZAR PRECO\n");
            printf("3 - ATUALIZAR GENERO\n\n");

            int indiceMenuMod;
            
            scanf("%d", &indiceMenuMod);

            if (indiceMenuMod == 1){   
                printf("\nDigite o código do filme que deseja alterar: ");
                scanf("%d", &codigoFilme);
                codigoFilme = codigoFilme - 1;
                char nome[101];
                char diretor[101];
                printf("Digite o novo nome: ");
                scanf(" %[^\n]", nome);
                printf("Digite o nome do novo diretor: ");
                scanf(" %[^\n]", diretor);
                printf("\n");
                set_nome(listafilme[codigoFilme], nome, diretor);
                print_tabela(listafilme, qtdFilmes);
            }
            else if (indiceMenuMod == 2){   
                printf("\nDigite o código do filme que deseja alterar: ");
                scanf("%d", &codigoFilme);
                codigoFilme = codigoFilme - 1;
                float preco;
                printf("Digite o novo preco: ");
                scanf("%f", &preco);
                printf("\n");
                set_preco(listafilme[codigoFilme], preco);
                print_tabela(listafilme, qtdFilmes);
            }
            else if (indiceMenuMod == 3){
                printf("\nDigite o código do filme que deseja alterar: ");
                scanf("%d", &codigoFilme);
                codigoFilme = codigoFilme - 1;
                char genero[51];
                printf("Digite o novo genero: ");
                scanf("  %[^\n]", genero);
              
                if((strcmp(genero, "terror") == 0) || (strcmp(genero, "Terror") == 0)){
                  printf("Digite a faixa etaria: ");
                  int faixaetaria;
                  scanf("%d", &faixaetaria);
                  
                  while(faixaetaria < 18){
                    printf("Faixa etaria invalida, insira novamente: ");
                    scanf("%d", &faixaetaria);
                  }
                  
                }
                printf("\n");
                printf("Genero atualizado com sucesso!");
                printf("\n");
                set_genero(listafilme[codigoFilme], genero);
            }

            break;

        case 3:
              printf("\n\nDigite o código do filme que deseja excluir: ");
              scanf("%d", &codigoFilme);
              codigoFilme = codigoFilme - 1;
              deletarFilme(listafilme, &qtdFilmes, codigoFilme);
              printf("\n");
              print_tabela(listafilme, qtdFilmes);
              break;

        case 4:printf("Cadastro Finalizado\n");
              break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (indiceMenu != 4);

    // Free allocated memory
    for (int i = 0; i < qtdFilmes; i++) {
        free(listafilme[i]->informacoes);
        free(listafilme[i]);
    }

    return 0;
}