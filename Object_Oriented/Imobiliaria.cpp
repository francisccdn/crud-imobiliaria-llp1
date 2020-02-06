#include "Imobiliaria.h"

bool Imobiliaria::cadastraImovel(Imovel imovel){}
bool Imobiliaria::removerImoveis(std::vector<int>){}
bool Imobiliaria::editarImovel(Imovel, int){}

std::vector<Imovel> Imobiliaria::getImoveis(){}
std::vector<Imovel> Imobiliaria::getImoveis(std::vector<int>){}

std::vector<int> Imobiliaria::indexPorTipo(char){}
std::vector<int> Imobiliaria::indexPorDisponibilidade(bool){}
std::vector<int> Imobiliaria::indexPorBairro(std::string){}
std::vector<int> Imobiliaria::indexPorCidade(std::string){}
std::vector<int> Imobiliaria::indexPorTitulo(std::string){}
std::vector<int> Imobiliaria::indexPorValor(double){}