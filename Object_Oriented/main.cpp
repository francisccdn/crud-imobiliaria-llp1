#include <iostream>
#include "Endereco.h"
#include "Imovel.h"
#include "Terreno.h"

int main(){
   Endereco casa = Endereco("Rua qualquer", 80, "bairro", "580--5440", "Cajazeiras");
   Imovel teste = Imovel();
   Terreno flamengo = Terreno(Endereco("Rua da arruda", 81, "Sei la", "58000", "Salvador"), '2', true, 125000.50, "Terreno para venda", 169);

    std::cout << flamengo.getTipo() << std::endl;
    std::cout << flamengo.getDisponiblidade() << std::endl;
    std::cout << flamengo.getValor() << std::endl;
    std::cout << flamengo.getTitulo() << std::endl << std::endl;

    std::cout << flamengo.endereco.getLogradouro() << std::endl;
    std::cout << flamengo.endereco.getNumero() << std::endl;
    std::cout << flamengo.endereco.getBairro() << std::endl;
    std::cout << flamengo.endereco.getCep() << std::endl;
    std::cout << flamengo.endereco.getCidade() << std::endl << std::endl; 

    std::cout << "area: " << flamengo.getArea() << std::endl;

    //flamengo.setArea(125.60);

    //std::cout << "area: " << flamengo.getArea() << std::endl;
};