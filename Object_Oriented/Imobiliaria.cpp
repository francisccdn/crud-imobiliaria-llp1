#include "Imobiliaria.h"

void Imobiliaria::cadastraImovel(Imovel *imovelParaCadastro)
{
    listaImoveis.push_back(imovelParaCadastro);
}

void Imobiliaria::removerImoveis(std::vector<int> indexes) 
{
    for(int i : indexes)
    {
        delete listaImoveis[i];
        listaImoveis.erase(listaImoveis.begin() + i);
    }
}

void Imobiliaria::editarImovel(Imovel *novoImovel, int index) 
{
    delete listaImoveis[index];
    listaImoveis.erase(listaImoveis.begin() + index);
    listaImoveis.insert(listaImoveis.begin() + index, novoImovel);
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

std::vector<int> Imobiliaria::indexPorBairro(std::string bairroBuscado)
{
    std::vector<int> indexes;
    std::string bairroExistente;

    bairroBuscado = formatador.removeAcento(bairroBuscado);
    bairroBuscado = formatador.strToLower(bairroBuscado);

    for(int i = 0; i < listaImoveis.size(); i++)
    {
        bairroExistente = listaImoveis[i]->endereco.getBairro();
      
        bairroExistente = formatador.removeAcento(bairroExistente);
        bairroExistente = formatador.strToLower(bairroExistente);

        if(bairroExistente.find(bairroBuscado) < bairroExistente.length()){
            indexes.push_back(i);
        }
    }
    return indexes;
}

std::vector<int> Imobiliaria::indexPorCidade(std::string cidadeBuscada)
{
    std::vector<int> indexes;
    std::string cidadeExistente;

    cidadeBuscada = formatador.removeAcento(cidadeBuscada);
    cidadeBuscada = formatador.strToLower(cidadeBuscada);

    for(int i = 0; i < listaImoveis.size(); i++)
    {
        cidadeExistente = listaImoveis[i]->endereco.getBairro();
      
        cidadeExistente = formatador.removeAcento(cidadeExistente);
        cidadeExistente = formatador.strToLower(cidadeExistente);

        if(cidadeExistente.find(cidadeBuscada) < cidadeExistente.length()){
            indexes.push_back(i);
        }
    }
    return indexes;
}

std::vector<int> Imobiliaria::indexPorTitulo(std::string tituloBuscado)
{
    std::vector<int> indexes;
    std::string tituloExistente;

    tituloBuscado = formatador.removeAcento(tituloBuscado);
    tituloBuscado = formatador.strToLower(tituloBuscado);

    for(int i = 0; i < listaImoveis.size(); i++)
    {
        tituloExistente = listaImoveis[i]->endereco.getBairro();
      
        tituloExistente = formatador.removeAcento(tituloExistente);
        tituloExistente = formatador.strToLower(tituloExistente);

        if(tituloExistente.find(tituloBuscado) < tituloExistente.length()){
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
