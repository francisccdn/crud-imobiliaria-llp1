#pragma once

#include "Imovel.h"
#include <vector>
#include <string>

class Imobiliaria
{
private:
    std::vector<Imovel> listaImoveis;

public:
    bool cadastraImovel(Imovel imovel);
    bool removerImoveis(std::vector<int>);
    bool editarImovel(Imovel, int);

    std::vector<Imovel> getImoveis();
    std::vector<Imovel> getImoveis(std::vector<int>);
    
    std::vector<int> indexPorTipo(char);
    std::vector<int> indexPorDisponibilidade(bool);
    std::vector<int> indexPorBairro(std::string);
    std::vector<int> indexPorCidade(std::string);
    std::vector<int> indexPorTitulo(std::string);
    std::vector<int> indexPorValor(double);
};