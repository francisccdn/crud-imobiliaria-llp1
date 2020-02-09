#include <iostream>
#include "Endereco.h"
#include "Imovel.h"
#include "Terreno.h"
#include "Apartamento.h"
#include "Casa.h"

int main(){
    Endereco casa = Endereco("Rua qualquer", 80, "bairro", "580--5440", "Cajazeiras");
    Imovel teste = Imovel();
    Terreno flamengo = Terreno(Endereco("Rua da arruda", 81, "Sei la", "58000", "Salvador"), '2', true, 125000.50, "Terreno para venda", 169);
    Apartamento foda = Apartamento(Endereco("Rua foda", 69, "bairro foda", "cep foda", "cidade foda"), '0', true, 696969, "Apartamento muito foda", 6, 66, 66.66, 2, "Virado pra o lado foda", 9);
    Casa umacasa = Casa(Endereco("Rua dos bobos", 0, "Inexistente", "0000-0000-0000", "Cidade imaginaria"), '1', false, 0.50, "Casa muito engracada", 0, 0, 0, 0);

    /*std::cout << flamengo.getTipo() << std::endl;
    std::cout << flamengo.getDisponiblidade() << std::endl;
    std::cout << flamengo.getValor() << std::endl;
    std::cout << flamengo.getTitulo() << std::endl << std::endl;

    std::cout << flamengo.endereco.getLogradouro() << std::endl;
    std::cout << flamengo.endereco.getNumero() << std::endl;
    std::cout << flamengo.endereco.getBairro() << std::endl;
    std::cout << flamengo.endereco.getCep() << std::endl;
    std::cout << flamengo.endereco.getCidade() << std::endl << std::endl; 

    std::cout << "area: " << flamengo.getArea() << std::endl;

    flamengo.setArea(125.60);

    std::cout << "area: " << flamengo.getArea() << std::endl;*/

    std::cout << "Tipo: " << foda.getTipo() << std::endl;
    std::cout << "Disponibilidade: "<< foda.getDisponiblidade() << std::endl;
    std::cout << "Valor: " << foda.getValor() << std::endl;
    std::cout << "Titulo: " << foda.getTitulo() << std::endl << std::endl;

    std::cout << "Logradouro: " << foda.endereco.getLogradouro() << std::endl;
    std::cout << "Numero: " << foda.endereco.getNumero() << std::endl;
    std::cout << "Bairro: " << foda.endereco.getBairro() << std::endl;
    std::cout << "CEP: " << foda.endereco.getCep() << std::endl;
    std::cout << "Cidade: " << foda.endereco.getCidade() << std::endl << std::endl;

    std::cout << "Andar: " << foda.getAndar() << std::endl;
    std::cout << "Area: " << foda.getArea() << std::endl;
    std::cout << "Quartos: " << foda.getNumQuartos() << std::endl;
    std::cout << "Valor condominio: " << foda.getValorCondominio() << std::endl;
    std::cout << "Posicao: " << foda.getPosicao() << std::endl;
    std::cout << "Vagas: " << foda.getNumVagas() << std::endl << std::endl; 

    foda.setNumVagas(596);

    std::cout << "Vagas: " << foda.getNumVagas() << std::endl << std::endl;
    

    std::cout << "Tipo: " << umacasa.getTipo() << std::endl;
    std::cout << "Disponibilidade: "<< umacasa.getDisponiblidade() << std::endl;
    std::cout << "Valor: " << umacasa.getValor() << std::endl;
    std::cout << "Titulo: " << umacasa.getTitulo() << std::endl << std::endl;

    std::cout << "Logradouro: " << umacasa.endereco.getLogradouro() << std::endl;
    std::cout << "Numero: " << umacasa.endereco.getNumero() << std::endl;
    std::cout << "Bairro: " << umacasa.endereco.getBairro() << std::endl;
    std::cout << "CEP: " << umacasa.endereco.getCep() << std::endl;
    std::cout << "Cidade: " << umacasa.endereco.getCidade() << std::endl << std::endl;

    std::cout << "Numero de pavimentos: " << umacasa.getNumPavimentos() << std::endl;
    std::cout << "Quartos: " << umacasa.getNumQuartos() << std::endl;
    std::cout << "Area do terreno: " << umacasa.getAreaTerreno() << std::endl;
    std::cout << "Area construida: " << umacasa.getAreaConstruida() << std::endl << std::endl;

    umacasa.setAreaConstruida(999);

    std::cout << "Area construida: " << umacasa.getAreaConstruida() << std::endl;

    std::cout << umacasa.endereco.getAsString() << std::endl << std::endl;
    std::cout << foda.endereco.getAsString() << std::endl;
};