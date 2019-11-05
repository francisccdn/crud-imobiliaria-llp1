#include <stdio.h>
#include <string.h>
#include <time.h>
#include "registro.h"
#include "usuario.h"
#include "funcoes.h"


#define MAX_TAMANHO 100

imovel_t listaImoveis[MAX_TAMANHO];

int main(void){
    leImoveis(listaImoveis);
    lerArquivoUsuarios();
    exibeUsuario(1);
   while(1){
        logon();
        break;
    }
    Menu();
    return 0;
}