#pragma once

#include "Imovel.h"

class Terreno : public Imovel
{
protected:
    double area;

public:
    Terreno();
    Terreno(Endereco endereco, char tipo, bool disponibilidade, double valor, std::string titulo, double area);
    double getArea();
    void setArea(double area);
};