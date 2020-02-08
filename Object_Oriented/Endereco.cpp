#include "Endereco.h"

Endereco::Endereco(){
    logradouro = "Rua sem nome";
    numero = 0;
    bairro = "Bairro inexistente";
    cep = "58000-000";
    cidade = "Desconhecida";
}

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
    void Endereco::setEndereco(std::string l, int n, std::string b, std::string cp, std::string cd){
        logradouro = l;
        numero = n;
        bairro = b;
        cep = cp;
        cidade = cd;
    };
    