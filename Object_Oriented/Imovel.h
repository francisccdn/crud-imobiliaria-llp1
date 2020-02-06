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
    std::string getAsString();
    std::string getLogradouro();
    int getNumero();
    std::string getBairro();
    std::string getCep();
    std::string getCidade();

    void setEndereco(std::string logradouro, int numero, std::string bairro, std::string cep, std::string cidade);

};

class Imovel
{
private:
    Endereco endereco; 
    char tipo;
    bool disponibilidade;
    double valor;
    std::string titulo;

public:
    char getTipo();
    bool getDisponiblidade();
    double getValor();
    std::string getTitulo;

    void setTipo(char tipo);
    void setDisponibilidade(bool disp);
    void setValor(double valor);
    void setTitulo(std::string titulo);
};

class Terreno : public Imovel
{
private:
    double area;

public:
    double getArea();
    void setArea(double area);
};

class Casa : public Imovel
{
private:
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
public:
    int getNumPavimentos();
    int getNumQuartos();
    double getAreaTerreno();
    double getAreaConstruida();

    void setNumPavimentos(int numPavimentos);
    void setNumQuartos(int numQuartos);
    void setAreaTerreno(double areaTerreno);
    void setAreaConstruida(double areaConstruida);

};

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