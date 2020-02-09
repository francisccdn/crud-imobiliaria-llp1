#pragma once

#include "Imovel.h"

#include <string>

class Casa : public Imovel
{
protected:
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
public:
    Casa();
    Casa(Endereco endereco, char tipo, bool disponibilidade, double valor, std::string titulo, int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida);
    int getNumPavimentos();
    int getNumQuartos();
    double getAreaTerreno();
    double getAreaConstruida();

    void setNumPavimentos(int numPavimentos);
    void setNumQuartos(int numQuartos);
    void setAreaTerreno(double areaTerreno);
    void setAreaConstruida(double areaConstruida);

};