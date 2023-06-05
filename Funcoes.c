#include "Cabecalho.h"
#include<stdio.h>
#include<stdlib.h>

//Função para criar um novo filme
Filme* criar_filme(){

    Filme* actual = (Filme*)malloc(sizeof(Filme));
    actual->informacoes = (Info*)malloc(sizeof(Info));

    printf("Nome do filme: ");
    scanf(" %[^\n]", actual->nome);
    printf("Preco do filme: ");
    scanf("%f", &actual->preco);
    printf("Nome do diretor: ");
    scanf(" %[^\n]", actual->informacoes->diretor);
    printf("Ano do filme: ");
    scanf("%d", &actual->informacoes->ano);
    printf("Genero do filme: ");
    scanf(" %[^\n]", actual->informacoes->genero);
    printf("Faixa etaria do filme: ");
    scanf("%d", &actual->informacoes->faixaEtaria);
    printf("\n");

    return actual;
}

//Função para liberar memória ao deletar um filme
void free_filme(Filme* f){
    free(f->informacoes);
    free(f);
}

//função que imprime informações de um filme
void imprimir_filme(Filme* f){
    printf("Nome: %s\n", f->nome);
    printf("Preco: %.2f\n", f->preco);
    printf("Diretor: %s\n", f->informacoes->diretor);
    printf("Ano: %d\n", f->informacoes->ano);
    printf("Genero: %s\n", f->informacoes->genero);
    printf("Faixa Etaria: %d\n", f->informacoes->faixaEtaria);
    printf("\n");
}

//FUNÇÕES DE MANIPULAÇÃO

//função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char novo[101], char dir[101]){
    strcpy(f->nome, novo);
    strcpy(f->informacoes->diretor, dir);
}

//função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo){
    f->preco = novo;
}

//função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo){
    strcpy(f->informacoes->genero, novo);
}

//Imprime na tela a tabela de filmes no formato do documento disponibilizado
void print_tabela(Filme** tabela, int tam){
    int codigo = 1;
    printf("-------------TABELA DE FILMES-------------\n\n");
    for(int i = 0; i < tam; i++){
      printf("%.4d -- %.2f R$ || %s (%s, %d) || %s %d\n", codigo, tabela[i]->preco, tabela[i]->nome, tabela[i]->informacoes->genero, tabela[i]->informacoes->faixaEtaria, tabela[i]->informacoes->diretor, tabela[i]->informacoes->ano); 

      codigo++;
    }
}

//Deleta um filme
void deletarFilme(Filme **listaFilmes, int *qtdFilmes, int indice) {
  
    if (indice < 0 || indice >= *qtdFilmes) {
        printf("Índice inválido.\n");
        return;
    }

    // Libera a memória do filme a ser excluído
    free(listaFilmes[indice]);
    
    // Desloca os filmes à direita do índice para a esquerda
    for (int i = indice; i < *qtdFilmes - 1; i++) {
        listaFilmes[i] = listaFilmes[i + 1];
    }

    // Atualiza a quantidade de filmes
    (*qtdFilmes)--;

    printf("Filme excluído com sucesso.\n");
}



