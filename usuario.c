s#include <stdio.h>
#include <string.h>
#include <time.h>
#include "registro.h"
#include "funcoes.h"
#include "usuario.h"

#define MAX_TAMANHO 100



imovel_t listaImoveis[MAX_TAMANHO];

usuario_t usuarios[MAX_TAMANHO];

int main(void)
{

	//usuarios[0].ultimo=1;

	lerArquivoUsuarios();

	//cadastraUsuario();

	exibeUsuario(0);

	exibeUsuario(1);
	exibeUsuario(2);
	
	salvaAquivoUsuarios();
	return(0);

}


