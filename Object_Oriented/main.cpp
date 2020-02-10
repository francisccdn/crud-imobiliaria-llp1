#include <iostream>
#include "Endereco.h"
#include "Imovel.h"
#include "Terreno.h"
#include "Apartamento.h"
#include "Casa.h"
#include "GerenciadorDeTexto.h"

int main(){
    GerenciadorDeTexto gerenciadorDeTexto;
    std::string teste = "áááâãààääããã";

    teste = gerenciadorDeTexto.strToLower(teste);

    std::cout << teste << std::endl;

    return 0;
    
};