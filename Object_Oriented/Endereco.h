#pragma once

#include <string>

class Endereco
{    
private:
    std::string logradouro;
    int numero;
    std::string bairro;
    std::string cep;
    std::string cidade;
public:
    Endereco();
    Endereco(std::string logradouro, int numero, std::string bairro, std::string cep, std::string cidade);
    std::string getAsString();
    std::string getLogradouro();
    int getNumero();
    std::string getBairro();
    std::string getCep();
    std::string getCidade();

    void setEndereco(std::string logradouro, int numero, std::string bairro, std::string cep, std::string cidade);

};