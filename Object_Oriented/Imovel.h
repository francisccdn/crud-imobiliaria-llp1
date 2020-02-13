#pragma once

#include "Endereco.h"
#include <string>

class Imovel
{
protected:
    char tipo;
    bool disponibilidade;
    double valor;
    std::string titulo;

public:
    Endereco endereco; 

    Imovel();
    Imovel(Endereco endereco, char tipo, bool disponibilidade, double valor, std::string titulo);

    char getTipo();
    bool getDisponiblidade();
    double getValor();
    std::string getTitulo();

    void setTipo(char t);
    void setDisponibilidade(bool disp);
    void setValor(double v);
    void setTitulo(std::string tit);
};