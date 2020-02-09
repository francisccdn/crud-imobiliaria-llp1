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
    void Endereco::setEndereco(std::string logradouro, int numero, std::string bairro, std::string cep, std::string cidade){
        this -> logradouro = logradouro;
        this -> numero = numero;
        this -> bairro = bairro;
        this -> cep = cep;
        this -> cidade = cidade;
    };

    std::string Endereco::getAsString(){
        std::string parte1, parte2, parte3, parte4, parte5, saida1, saida2;
        parte1 = getLogradouro();
        parte2 = std::to_string(getNumero());
        parte3 = getBairro();
        parte4 = getCep();
        parte5 = getCidade();
        
        saida1 = parte1 + ", " + parte2 + ", " + parte3 + ", " + parte4 + ", " + parte5 + ".";
        saida2 = "Rua: " + parte1 + ", " + parte2 + "\n" + "Bairro: " + parte3 + "\n" + "Cep: " + parte4 + "\n" + "Cidade: " + parte5;


        return saida2;  
    };
    