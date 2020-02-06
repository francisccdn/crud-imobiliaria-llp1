#pragma once

#include "Endereco.h"
#include <string>

class Imovel
{
private:
    Endereco endereco; 
    char tipo;
    bool disponibilidade;
    double valor;
    std::string titulo;

public:

    Imovel();
    Imovel(Endereco endereco, char tipo, bool disponibilidade, double valor, std::string titulo);

    char getTipo();
    bool getDisponiblidade();
    double getValor();
    std::string getTitulo;

    void setTipo(char tipo);
    void setDisponibilidade(bool disp);
    void setValor(double valor);
    void setTitulo(std::string titulo);
};