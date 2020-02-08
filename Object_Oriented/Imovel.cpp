#include "Imovel.h"

Imovel::Imovel(){
    endereco = Endereco();
    tipo = '0';
    disponibilidade = true;
    valor = 0.0;
    titulo = "Sem titulo.";
};

Imovel::Imovel(Endereco endereco, char tipo, bool disponibilidade, double valor, std::string titulo){
    this -> endereco = endereco;
    this -> tipo = tipo;
    this -> disponibilidade = disponibilidade;
    this -> valor = valor;
    this -> titulo = titulo;
};

char Imovel::getTipo(){
    return tipo;
};
bool Imovel::getDisponiblidade(){
    return disponibilidade;
};
double Imovel::getValor(){
    return valor;
};
std::string Imovel::getTitulo(){
    return titulo;
};

void Imovel::setTipo(char t){
    tipo = t;
};
void Imovel::setDisponibilidade(bool disp){
    disponibilidade = disp;
};
void Imovel::setValor(double v){
    valor = v;
};
void Imovel::setTitulo(std::string tit){
    titulo = tit;
};