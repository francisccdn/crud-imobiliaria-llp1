#include <stdio.h>
#include <string.h>
#include <time.h>
#include "registro.h"
#include "funcoes.h"
#include "usuario.h"

#define MAX_TAMANHO 100

imovel_t listaImoveis[MAX_TAMANHO];

int main(void){
    leImoveis(listaImoveis);
    Menu();
    return 0;
}