#include "GerenciadorDeArquivo.h"

string toStringApartamento(Imovel *);
string toStringCasa(Imovel &);
string toStringTerreno(Imovel &);
void outputLine(std::ostream &output, Imovel &record);
GerenciadorDeArquivo::GerenciadorDeArquivo()
{
}
Imovel GerenciadorDeArquivo::convert(Imovel imovel)
{
}
bool GerenciadorDeArquivo::SalvaArquivo(vector<Imovel *> lista)
{
    ofstream outputFile("imoveis.dat", ios::binary);
    vector<Imovel *> lista2;
    if (!outputFile)
    {
        cerr << "Erro ao tentar abrir o arquivo" << endl;
        exit(1);
    }
    Apartamento ap;
    Terreno t1;
    Casa c1;
    for (size_t i = 0; i < lista.size(); i++)
    {
        if (lista[i]->getTipo() == '0')
        {
            ap.setTitulo(lista[i]->getTitulo());
            ap.setValor(lista[i]->getValor());
            ap.setDisponibilidade(lista[i]->getDisponiblidade());
            ap.setTipo(lista[i]->getTipo());
            ap.setNumQuartos(((Apartamento *)lista[i])->getAndar());
            ap.setNumVagas(((Apartamento *)lista[i])->getNumVagas());
            ap.setValorCondominio(((Apartamento *)lista[i])->getValorCondominio());
            ap.setPosicao(((Apartamento *)lista[i])->getPosicao());
            outputFile.write(reinterpret_cast<const char *>(&ap),
                             sizeof(Apartamento));
        }
        if (lista[i]->getTipo() == '1')
        {
            c1.setTitulo(lista[i]->getTitulo());
            c1.setValor(lista[i]->getValor());
            c1.setDisponibilidade(lista[i]->getDisponiblidade());
            c1.setTipo(lista[i]->getTipo());
            c1.setAreaTerreno(((Casa *)lista[i])->getAreaTerreno());
            c1.setAreaConstruida(((Casa *)lista[i])->getAreaConstruida());
            c1.setNumPavimentos(((Casa *)lista[i])->getNumPavimentos());
            c1.setNumQuartos(((Casa *)lista[i])->getNumQuartos());

            outputFile.write(reinterpret_cast<const char *>(&t1),
                             sizeof(Imovel));
        }
        if (lista[i]->getTipo() == '2')
        {
            t1.setTitulo(lista[i]->getTitulo());
            t1.setValor(lista[i]->getValor());
            t1.setDisponibilidade(lista[i]->getDisponiblidade());
            t1.setTipo(lista[i]->getTipo());
            t1.setArea(((Terreno *)lista[i])->getArea());
            outputFile.write(reinterpret_cast<const char *>(&c1),
                             sizeof(Imovel));
        }
    }
    outputFile.close();
}

vector<Imovel *> GerenciadorDeArquivo::leArquivo()
{
    vector<Imovel *> lista;
    char tipo;
    Imovel i;
    Apartamento ap;
    Terreno terreno;
    Casa casa;
    ifstream inFile("imoveis.dat", ios::in);
    if (!inFile)
    {
        cerr << "Erro ao tentar abrir o arquivo" << endl;
        exit(1);
    }

    while (inFile && !inFile.eof())
    {
        inFile.read(reinterpret_cast<char *>(&tipo), sizeof(char));
        inFile.seekg(-1, inFile.cur);

        if (tipo == '0')
        {
            inFile.read(reinterpret_cast<char *>(&casa), sizeof(Apartamento));
            outputLine(cout, i);
            Apartamento *temp = new Apartamento();
            *temp = ap;
            lista.push_back(temp);
        }
        if (tipo == '1')
        {
            inFile.read(reinterpret_cast<char *>(&casa), sizeof(Casa));
            outputLine(cout, i);
            Casa *temp = new Casa();
            *temp = casa;
            lista.push_back(temp);
        }
        if (tipo == '2')
        {
            inFile.read(reinterpret_cast<char *>(&terreno), sizeof(Terreno));
            outputLine(cout,i);
            Terreno *temp = new Terreno();
            *temp = terreno;
            lista.push_back (temp);
        }
    }
    inFile.close();

    return lista;
}
void outputLine(std::ostream &output, Imovel &record)
{
    Imovel *ptr = &record;
    output << record.getTitulo()<<"\n"<<
        record.getValor() << "\n"
           << record.getTipo() << "\n"
           << record.getDisponiblidade() << "\n"
           << endl;
}
