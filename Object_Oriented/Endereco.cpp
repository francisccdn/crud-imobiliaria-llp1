#include "Endereco.h"

Endereco::Endereco(std::string logradouro, int numero, std::string bairro, std::string cep, std::string cidade){
    this -> logradouro = logradouro;
    this -> numero = numero;
    this -> bairro = bairro;
    this -> cep = cep;
    this -> cidade = cidade;
};

    std::string Endereco::getLogradouro(){
        return logradouro;
    }
    int Endereco::getNumero(){
        return numero;
    }
    std::string Endereco::getBairro(){
        return bairro;
    }
    std::string Endereco::getCep(){
        return cep;
    }
    std::string Endereco::getCidade(){
        return cidade;
    };