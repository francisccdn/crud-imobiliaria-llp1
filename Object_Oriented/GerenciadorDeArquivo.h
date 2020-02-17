#pragma once
#include "Imobiliaria.h"
#include "Imovel.h"
#include "Apartamento.h"
#include "Casa.h"
#include "Terreno.h"

class GerenciadorDeArquivo
{
private:
    
public:
    
    bool SalvaArquivo(vector<Imovel*>);
    //vector<Imovel*> leArquivo();
    bool leArquivo(Imobiliaria*);
    void outputImovel(std::ostream &,Imovel &);
    void outputImoveis(vector<Imovel*>);
    
};


