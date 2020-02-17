#include "GerenciadorDeArquivo.h"

string toStringApartamento(Imovel *);
string toStringCasa(Imovel &);
string toStringTerreno(Imovel &);
void outputLine(std::ostream &output, Imovel &record);

void GerenciadorDeArquivo::teste()
{
    for(int i = 0; i < lista.size(); i++)
    {
        cout << "DENTRO DO GERENCIADOR: " << lista[i]->getTitulo() << endl;
    }
}

bool GerenciadorDeArquivo::SalvaArquivo()
{
    fstream outputFile;
    outputFile.open("imoveis.dat", ios::ate | ios::in | ios::out | ios::app);

    if (!outputFile.is_open())
    {
        cerr << "Erro ao tentar abrir o arquivo" << endl;
        outputFile.close();
        exit(1);
    }

    Apartamento ap;
    Terreno t1;
    Casa c1;

    cout << "Salvando " << lista.size() << " imoveis." << endl;
    
    for(int i = 0; i < lista.size(); i++)
    {
        cout << "DENTRO DO SALVAR ARQUIVOS: " << lista[i]->getTitulo() << endl;
    }

    outputFile.close();

  /*  for (int i = 0; i < lista.size(); i++)
    {
        if (lista[i]->getTipo() == '0')
        {
            ap.setTitulo(lista[i]->getTitulo());
            ap.setValor(lista[i]->getValor());
            ap.setDisponibilidade(lista[i]->getDisponiblidade());
            ap.setTipo(lista[i]->getTipo());
            ap.setArea(((Apartamento *)lista[i])->getArea());
            ap.setAndar(((Apartamento *)lista[i])->getAndar());
            ap.setNumVagas(((Apartamento *)lista[i])->getNumVagas());
            ap.setValorCondominio(((Apartamento *)lista[i])->getValorCondominio());
            ap.setPosicao(((Apartamento *)lista[i])->getPosicao());
            ap.endereco.setCidade(((Apartamento *)lista[i])->endereco.getCidade());
            ap.endereco.setBairro(((Apartamento *)lista[i])->endereco.getBairro());
            ap.endereco.setLogradouro(((Apartamento *)lista[i])->endereco.getLogradouro());
            ap.endereco.setNumero(((Apartamento *)lista[i])->endereco.getNumero());
            ap.endereco.setCep(((Apartamento *)lista[i])->endereco.getCep());
            outputFile.write(reinterpret_cast<const char *>(&ap),
                                sizeof(Apartamento));
        }

        if (lista[i]->getTipo() == '1')
        {
            c1.setTitulo(lista[i]->getTitulo());
            c1.setValor(lista[i]->getValor());
            c1.setDisponibilidade(lista[i]->getDisponiblidade());
            c1.setTipo(lista[i]->getTipo());
            c1.setArea(((Casa *)lista[i])->getAreaTerreno());
            c1.setAreaConstruida(((Casa *)lista[i])->getAreaConstruida());
            c1.setNumPavimentos(((Casa *)lista[i])->getNumPavimentos());
            c1.setNumQuartos(((Casa *)lista[i])->getNumQuartos());
            c1.endereco.setCidade(((Casa *)lista[i])->endereco.getCidade());
            c1.endereco.setBairro(((Casa *)lista[i])->endereco.getBairro());
            c1.endereco.setLogradouro(((Casa *)lista[i])->endereco.getLogradouro());
            c1.endereco.setNumero(((Casa *)lista[i])->endereco.getNumero());
            c1.endereco.setCep(((Casa *)lista[i])->endereco.getCep());
            outputFile.write(reinterpret_cast<const char *>(&c1),
                                sizeof(Casa));
        }
        if (lista[i]->getTipo() == '2')
        {
            t1.setTitulo(lista[i]->getTitulo());
            t1.setValor(lista[i]->getValor());
            t1.setDisponibilidade(lista[i]->getDisponiblidade());
            t1.setTipo(lista[i]->getTipo());
            t1.setArea(((Terreno *)lista[i])->getArea());
            t1.endereco.setCidade(((Terreno *)lista[i])->endereco.getCidade());
            t1.endereco.setBairro(((Terreno *)lista[i])->endereco.getBairro());
            t1.endereco.setLogradouro(((Terreno *)lista[i])->endereco.getLogradouro());
            t1.endereco.setNumero(((Terreno *)lista[i])->endereco.getNumero());
            t1.endereco.setCep(((Terreno *)lista[i])->endereco.getCep());
            outputFile.write(reinterpret_cast<const char *>(&t1),
                                sizeof(Terreno));
        }
    }*/
}

bool GerenciadorDeArquivo::leArquivo(Imobiliaria *imob)
{
    vector<Imovel *> lista;
    char tipo;
    //Imovel i;

    Apartamento ap;
    Terreno terreno;
    Casa casa;
    ifstream inFile("imoveis.dat", ios::in);
    if (!inFile)
    {
        cerr << "Erro ao tentar abrir o arquivo" << endl;
        return 1;
    }
    inFile.read(reinterpret_cast<char *>(&tipo), sizeof(char));
    inFile.seekg(-1, inFile.cur);
    while (inFile && !inFile.eof())
    {

        if (tipo == '0')
        {
            inFile.read(reinterpret_cast<char *>(&ap), sizeof(Apartamento));
            //outputLine(cout, ap);
            Apartamento *tempAp = new Apartamento;
            *tempAp = ap;
            imob->cadastraImovel(tempAp);
        }
        if (tipo == '1')
        {
            inFile.read(reinterpret_cast<char *>(&casa), sizeof(Casa));
            //outputLine(cout, casa);
            Casa *tempC = new Casa();
            *tempC = casa;
            imob->cadastraImovel(tempC);
        }
        if (tipo == '2')
        {
            inFile.read(reinterpret_cast<char *>(&terreno), sizeof(Terreno));
            //outputLine(cout, terreno);
            Terreno *tempT = new Terreno();
            *tempT = terreno;
            imob->cadastraImovel(tempT);
        }
        inFile.read(reinterpret_cast<char *>(&tipo), sizeof(char));
        inFile.seekg(-1, inFile.cur);
    }

    inFile.close();

    return 0;
}
void outputLine(std::ostream &output, Imovel &record)
{
    Imovel *ptr = &record;
    output << record.getTitulo() << "\n"
           << setprecision(2) << fixed << record.getValor() << "\n"
           << record.getTipo() << "\n"
           << record.getDisponiblidade() << "\n"
           <<(((Apartamento*)ptr)->getAndar())<<"\n"
           << (((Apartamento*)ptr)->getPosicao())
           << endl;
}

