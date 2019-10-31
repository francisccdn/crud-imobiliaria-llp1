#include <stdio.h>
#include <string.h>
#include <time.h>
#include "registro.h"
#include "funcoes.h"

#define MAX_TAMANHO 100

enum {ALUGUEL = 1, VENDA = 2};
enum {CASA = 1, APTO = 2, TERRENO = 3};

imovel_t listaImoveis[MAX_TAMANHO];

int countC=0,countD=0,countE=0;

int main(void){
    leImoveis(listaImoveis);
    
    Menu();

    salvaImoveis();

    return 0;
}
