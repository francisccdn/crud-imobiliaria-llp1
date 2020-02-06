#pragma once

#include "Imovel.h"

#include <string>

class Apartamento : public Imovel
{
private:
    int andar;
    double valorCondominio;
    double area;
    int numQuartos;
    std::string posicao;
    int numVagas;
public:
    int getAndar();
    double getValorCondominio();
    double getArea();
    int getNumQuartos();
    std::string getPosicao();
    int getNumVagas();

    void setAndar(int andar);
    void setValorCondominio(double valorCondomino);
    void setArea(double area);
    void setNumQuartos(int numQuartos);
    void setPosicao(std::string posicao);
    void setNumVagas(int numVagas);

};