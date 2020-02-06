#pragma once

#include "Imovel.h"

#include <string>

class Casa : public Imovel
{
private:
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
public:
    int getNumPavimentos();
    int getNumQuartos();
    double getAreaTerreno();
    double getAreaConstruida();

    void setNumPavimentos(int numPavimentos);
    void setNumQuartos(int numQuartos);
    void setAreaTerreno(double areaTerreno);
    void setAreaConstruida(double areaConstruida);

};