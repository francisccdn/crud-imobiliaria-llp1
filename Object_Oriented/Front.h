#pragma once
#include "GerenciadorDeArquivo.h"

class Front
{
private:
    Imobiliaria *imob;
    /*Imovel imovel;
    Imobiliaria imob;
    vector<Imovel *> listaImoveis;
    vector<int> indices;
    GerenciadorDeArquivo arquivo;*/
public:
    
    void menu(Imobiliaria &);
    void buscar(Imobiliaria &);
    void outputImovel(std::ostream &output, Imovel &imovel, int);
    void outputImoveis(vector<Imovel *> lista, int);
    //vector<Imovel *> getLista();
};
