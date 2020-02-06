#include "Imobiliaria.h"

void Imobiliaria::cadastraImovel(Imovel imovelParaCadastro)
{
    listaImoveis.push_back(&imovelParaCadastro);

}

void Imobiliaria::removerImoveis(std::vector<int> indexes) 
{
    for(int i : indexes)
    {
        listaImoveis.erase(listaImoveis.begin() + i);
    }
}

void Imobiliaria::editarImovel(Imovel novoImovel, int index) 
{
    listaImoveis.erase(listaImoveis.begin() + index);
    listaImoveis.insert(listaImoveis.begin() + index, &novoImovel);
}

std::vector<Imovel*> Imobiliaria::getImoveis()
{
    return listaImoveis;
}

std::vector<Imovel*> Imobiliaria::getImoveis(std::vector<int> indexes)
{
    std::vector<Imovel*> imoveisRetorno;
    for (int i : indexes)
    {
        imoveisRetorno.push_back(listaImoveis[i]);
    }
    return imoveisRetorno;
}

std::vector<int> Imobiliaria::indexPorTipo(char tipo)
{
    std::vector<int> indexes;
    for(int i = 0; i < listaImoveis.size(); i++){
        if(listaImoveis[i]->getTipo() == tipo){
            indexes.push_back(i);
        }
    }
    return indexes;
}

std::vector<int> Imobiliaria::indexPorDisponibilidade(bool disp)
{
    std::vector<int> indexes;
    for(int i = 0; i < listaImoveis.size(); i++){
        if(listaImoveis[i]->getDisponiblidade() == disp){
            indexes.push_back(i);
        }
    }
    return indexes;
}

std::vector<int> Imobiliaria::indexPorBairro(std::string bairro)
{
    std::vector<int> indexes;
    for(int i = 0; i < listaImoveis.size(); i++){
        if(listaImoveis[i]->endereco.getBairro() == bairro){
            indexes.push_back(i);
        }
    }
    return indexes;
}

std::vector<int> Imobiliaria::indexPorCidade(std::string cidade)
{
    std::vector<int> indexes;
    for(int i = 0; i < listaImoveis.size(); i++){
        if(listaImoveis[i]->endereco.getCidade() == cidade){
            indexes.push_back(i);
        }
    }
    return indexes;
}

std::vector<int> Imobiliaria::indexPorTitulo(std::string titulo)
{
    std::vector<int> indexes;
    for(int i = 0; i < listaImoveis.size(); i++){
        if(listaImoveis[i]->getTitulo() == titulo){
            indexes.push_back(i);
        }
    }
    return indexes;
}

std::vector<int> Imobiliaria::indexPorValor(double valor)
{
    std::vector<int> indexes;
    for(int i = 0; i < listaImoveis.size(); i++){
        if(listaImoveis[i]->getValor() <= valor){
            indexes.push_back(i);
        }
    }
    return indexes;
}
