#pragma once

#include "Imovel.h"

class Terreno : public Imovel
{
private:
    double area;

public:
    double getArea();
    void setArea(double area);
};