#include <stdio.h>
#include <string.h>

typedef enum {ALUGUEL, VENDA} disponibilidade_t;

typedef struct{
    char logradouro[100];
    int numero;
    char bairro[50];
    char cidade[100];
    int cep;
} endereco_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    disponibilidade_t disp;
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
} casa_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    disponibilidade_t disp;
    double area;
    int numQuartos;
    char posicao[50];
    int andar;
    double precoCondominio;
    int vagasGaragem;
} apto_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    disponibilidade_t disp;
    double area;
} terreno_t;

//Problema: Como verificar tipo do imovel?
typedef union{
    terreno_t terreno;
    casa_t casa;
    apto_t apto;
} imovel_t;

void ExibeMenu(){
    puts("Menuzinho");
}

int main(void){
    imovel_t listaImoveis[100];

    strcpy(listaImoveis[0].terreno.titulo, "Terreno pra vender\0");

    return 0;
}