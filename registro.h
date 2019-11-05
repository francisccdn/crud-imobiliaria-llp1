#define MAX_TAMANHO 100

typedef struct{
    char logradouro[MAX_TAMANHO];
    int numero;
    char bairro[MAX_TAMANHO];
    char cidade[MAX_TAMANHO];
    int cep;
} endereco_t;

typedef struct{
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
} casa_t;

typedef struct{
    double area;
    int numQuartos;
    char posicao[MAX_TAMANHO];
    int andar;
    double precoCondominio;
    int vagasGaragem;
} apto_t;

typedef struct{
    double area;
} terreno_t;

typedef union{
    terreno_t terreno;
    casa_t casa;
    apto_t apto;
} tipoImovel_t;

typedef struct{
    char titulo[100];
    double preco;
    int disponibilidade;
    tipoImovel_t imovel;
    endereco_t endereco;
    int tipo;
    int ultimo;
} imovel_t;

typedef struct 
{
    char login[MAX_TAMANHO];
    char senha[MAX_TAMANHO];
    char nome[MAX_TAMANHO];
    char tipo[MAX_TAMANHO];
    int ultimo;
}usuario_t;

typedef struct 
{
    char login[MAX_TAMANHO];
    char senha[MAX_TAMANHO];

}login_t;