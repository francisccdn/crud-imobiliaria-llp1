#include <stdio.h>
#include <string.h>
#include "registro.h"
#include "funcoes.h"
#define MAX_TAMANHO 100

int main(void){
    leImoveis(listaImoveis);

    listaImoveis[0].tipo = TERRENO;
    strcpy(listaImoveis[0].titulo, "Terreno pra vender");
    listaImoveis[0].preco = 10.31;
    listaImoveis[0].imovel.terreno.area = 312;
    strcpy(listaImoveis[0].endereco.bairro,"Mangabeira");
    listaImoveis[0].disponibilidade = VENDA;
    listaImoveis[0].ultimo = 0;

    listaImoveis[1].tipo = TERRENO;
    strcpy(listaImoveis[1].titulo, "Terreno pra alugar");
    listaImoveis[1].preco = 14.1;
    listaImoveis[1].imovel.terreno.area = 512;
    strcpy(listaImoveis[1].endereco.bairro,"Alto do Mateus");
    listaImoveis[1].disponibilidade = ALUGUEL;
    listaImoveis[1].ultimo = 0;

    listaImoveis[2].tipo = TERRENO;
    strcpy(listaImoveis[2].titulo, "Terreno pra alugar 2");
    listaImoveis[2].preco = 14.1;
    listaImoveis[2].imovel.terreno.area = 512;
    strcpy(listaImoveis[2].endereco.bairro,"Alto do Mateus");
    listaImoveis[2].disponibilidade = ALUGUEL;
    listaImoveis[2].ultimo = 0;

    listaImoveis[3].tipo = CASA;
    strcpy(listaImoveis[3].titulo, "Casa pra alugar");
    listaImoveis[3].preco = 14.1;
    listaImoveis[3].imovel.casa.areaConstruida = 512;
    strcpy(listaImoveis[3].endereco.bairro,"Alto do Mateus");
    listaImoveis[3].disponibilidade = ALUGUEL;
    listaImoveis[3].ultimo = 0;

    listaImoveis[4].ultimo = 1;
    Menu();

    //salvaImoveis();

    return 0;
}

