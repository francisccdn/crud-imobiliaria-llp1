#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "registro.h"
#include "funcoes.h"

#define MAX_TAMANHO 100

imovel_t listaImoveis[MAX_TAMANHO];
usuario_t usuarios[MAX_TAMANHO];
login_t entrada[0];

int main(void){
    leImoveis(listaImoveis);
    lerArquivoUsuarios();
    contarUsuarios();
    printf("%d", contarUsuarios());
    logon(contarUsuarios());
    //Menu();
    return 0;
}