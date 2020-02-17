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
    Front(Imobiliaria *imob);
    
    void menu();
    void buscar();
    void outputImovel(std::ostream &output, Imovel &imovel, int);
    void outputImoveis(vector<Imovel *> lista, int);
    //vector<Imovel *> getLista();
};
