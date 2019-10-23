#include <stdio.h>
#include <string.h>

enum {ALUGUEL, VENDA};
enum {CASA, APTO, TERRENO};

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
    int disponibilidade;
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
} casa_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    int disponibilidade;
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
    int disponibilidade;
    double area;
} terreno_t;

typedef union{
    terreno_t terreno;
    casa_t casa;
    apto_t apto;
} tipoImovel_t;

typedef struct{
    tipoImovel_t imovel;
    int tipo;
} imovel_t;

void ExibeMenu(){
    puts("Menuzinho");
}

void ExibeTerreno(imovel_t *exibido){
    printf("Titulo: %s \n", exibido->imovel.terreno.titulo);
    printf("Valor: %lf \n", exibido->imovel.terreno.preco);
    printf("Area: %lf \n", exibido->imovel.terreno.area);
    //printf("Disponibilidade: ", (exibido->imovel.terreno.disponibilidade == ALUGUEL) ? "Aluguel.\n" : "Venda.\n");

    //ExibeEndereco();
}
void buscaPorTitulo(char *titulo,  imovel_t lista[])
{
    int i;
    for ( i = 0; i < TAMANHO; i++)
    {
        if(!(strcmp(titulo, lista[i].imovel.terreno.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
        if(!(strcmp(titulo, lista[i].imovel.apto.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
        if(!(strcmp(titulo, lista[i].imovel.casa.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
    }
    puts("Título não encontrado.");
}

int main(void){
    int i;
    imovel_t listaImoveis[TAMANHO];

    char title[]="Terreno pra vender";
    
    listaImoveis[0].tipo = TERRENO;
    strcpy(listaImoveis[0].imovel.terreno.titulo, "Terreno pra vender\0");
    listaImoveis[0].imovel.terreno.preco = 10.31;
    listaImoveis[0].imovel.terreno.area = 312;
    listaImoveis[0].imovel.terreno.disponibilidade = ALUGUEL;
    
    ExibeTerreno(&listaImoveis[0]);
    
     buscaPorTitulo(title,listaImoveis);

    return 0;
}
