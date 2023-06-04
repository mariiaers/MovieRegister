//File with all the functions that are going to be used in the project

typedef struct info {
    char diretor[101]; //101 caracteres + 1 para fim de string
    char genero[51]; 
    int ano;
    int faixaEtaria; // Use 0 para classificação livre
} Info;

typedef struct filme{
    char nome[101]; //100 caracteres + 1 para fim de string
    float preco; // Até duas casas decimais
    Info* informacoes; // Ponteiro para struct Info
} Filme;

//Function to create and return a simple pointer for the type movie
Filme* criar_filme();

//function that deletes the movie and also free memory
void free_filme(Filme* f);

//função que imprime informações de um filme
void imprimir_filme(Filme* f);

//FUNÇÕES DE MANIPULAÇÃO

//função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char novo[101], char dir[101]);

//função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo);

//função que acessa e renomeia um diretor de um filme
void set_diretor(Filme* f, char* novo);

//função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo);

//função que acessa e modifica o ano de um filme
void set_ano(Filme* f, int novo);

//função que acessa e modifica a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo);

//função que deleta um filme da lista
void deletarFilme(Filme **listaFilmes, int *qtdFilmes, int indice);