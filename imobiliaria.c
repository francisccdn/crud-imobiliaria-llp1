#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "registro.h"
//#include "usuario.h"
#include "funcoes.h"


#define MAX_TAMANHO 100

imovel_t listaImoveis[MAX_TAMANHO];
usuario_t usuarios[MAX_TAMANHO];

int main(void){
    leImoveis(listaImoveis);
    lerArquivoUsuarios();
    contarUsuarios();
    printf("%d", contarUsuarios());
    logon(contarUsuarios());
    //Menu();
    return 0;
}