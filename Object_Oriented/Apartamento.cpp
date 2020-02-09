#include "Apartamento.h"
#include "Imovel.h"

Apartamento::Apartamento():Imovel(){
    tipo = '0';
    andar = 0;
    valorCondominio = 0;
    area = 0;
    numQuartos = 0;
    posicao = "0";
    numVagas = 0;
};

Apartamento::Apartamento(Endereco endereco, char tipo, bool disponibilidade, double valor, std::string titulo, int andar, double valorCondominio, double area, int numQuartos, std::string posicao, int numVagas):Imovel(endereco, tipo, disponibilidade, valor, titulo){
    this -> andar = andar;
    this -> valorCondominio = valorCondominio;
    this -> area = area;
    this -> numQuartos = numQuartos;
    this -> posicao = posicao;
    this -> numVagas = numVagas;
};

int Apartamento::getAndar(){
    return andar;
}
double Apartamento::getValorCondominio(){
    return valorCondominio;
};
double Apartamento::getArea(){
    return area;
};
int Apartamento::getNumQuartos(){
    return numQuartos;
};
std::string Apartamento::getPosicao(){
    return posicao;
};
int Apartamento::getNumVagas(){
    return numVagas;
};

void Apartamento::setAndar(int andar){
    this -> andar = andar;
};
void Apartamento::setValorCondominio(double valorCondominio){
    this -> valorCondominio = valorCondominio;
};
void Apartamento::setArea(double area){
    this -> area = area;
};
void Apartamento::setNumQuartos(int numQuartos){
    this -> numQuartos = numQuartos;
};
void Apartamento::setPosicao(std::string posicao){
    this -> posicao = posicao;
};
void Apartamento::setNumVagas(int numVagas){
    this -> numVagas = numVagas;
};
