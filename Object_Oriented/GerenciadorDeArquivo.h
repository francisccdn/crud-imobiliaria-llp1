#pragma once
#include "header.h"

class GerenciadorDeArquivo
{
private:
    
public:
    GerenciadorDeArquivo();
    bool SalvaArquivo(vector<Imovel *>);
    //vector<Imovel*> leArquivo();
    Imovel convert(Imovel);
    vector<Imovel*> leArquivo();
    
};


