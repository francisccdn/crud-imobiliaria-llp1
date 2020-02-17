#include <iostream>
#include "Imobiliaria.h"
#include "GerenciadorDeTexto.h"
#include "GerenciadorDeArquivo.h"
#include "Front.h"
//#include "menu.h"
void outputImovel(std::ostream &output, Imovel &imovel, int tipo);
void outputImoveis(vector<Imovel *> lista, int tipo);
void buscar(vector<Imovel *> listaImoveis, Imobiliaria imob);
void menu(vector<Imovel *> listaImoveis, Imobiliaria &imob);
vector<Imovel *> cadatrarImovel(Imobiliaria imob);
bool leArquivo(Imobiliaria & imob);
bool SalvaArquivo(vector<Imovel*>lista);
int main()
{   
    vector<Imovel*>listaImoveis;
    /*vector<Imovel*>listaImoveis1(3);
    Endereco casa = Endereco("Rua qualquer", 80, "bairro", "580--5440", "Cajazeiras");
    //Imovel teste = Imovel();
    Terreno flamengo = Terreno(Endereco("Rua da arruda", 81, "Sei la", "58000", "Salvador"), '2', true, 125000.50, "Terreno para venda", 169);
    Apartamento foda = Apartamento(Endereco("Rua foda", 69, "bairro foda", "cep foda", "cidade foda"), '0', true, 696969, "Apartamento muito foda", 6, 66, 66.66, 2, "Virado pra o lado foda", 9);
    Casa umacasa = Casa(Endereco("Rua dos bobos", 0, "Inexistente", "0000-0000-0000", "Cidade imaginaria"), '1', false, 0.50, "Casa muito engracada", 0, 0, 0, 0);

    listaImoveis[0]= &foda;
    listaImoveis[1]= &flamengo;
    listaImoveis[2]= &umacasa;*/
    Imobiliaria imob;
    //GerenciadorDeArquivo f1=GerenciadorDeArquivo(&imob);
    //vector<Imovel *> listaImoveis;
    if(leArquivo(imob))
        ;
    Front exibe=Front(&imob);
    exibe.menu();
    //imob.setImoveis(listaImoveis);
    //outputImoveis(imob.getImoveis(), 2);
    //menu(listaImoveis, imob);
    listaImoveis=imob.getImoveis();
    for (size_t i = 0; i < listaImoveis.size(); i++)
    {
        cout<<listaImoveis[i]->getTitulo()<<endl;
    }
    
    if (SalvaArquivo(imob.getImoveis()))
        cout << "Arquivo Salvo" << endl;
    else
    {
        cout << "Continue tentando" << endl;
    }
    //f1.outputImoveis(listaImoveis);

    return 0;
}
bool SalvaArquivo(vector<Imovel*>lista)
{
    ofstream outputFile("imoveis.dat",ios::binary);
   
    if (!outputFile)
    {
        cerr << "Erro ao tentar abrir o arquivo" << endl;
        exit(1);
    }
    Apartamento ap;
    Terreno t1;
    Casa c1;
    cout<<lista.size()<<endl;
    for (size_t i = 0; i < lista.size(); i++)
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
    }
    outputFile.close();
}

bool leArquivo(Imobiliaria &imob)
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
            imob.cadastraImovel(tempAp);
        }
        if (tipo == '1')
        {
            inFile.read(reinterpret_cast<char *>(&casa), sizeof(Casa));
            //outputLine(cout, casa);
            Casa *tempC = new Casa();
            *tempC = casa;
            imob.cadastraImovel(tempC);
        }
        if (tipo == '2')
        {
            inFile.read(reinterpret_cast<char *>(&terreno), sizeof(Terreno));
            //outputLine(cout, terreno);
            Terreno *tempT = new Terreno();
            *tempT = terreno;
            imob.cadastraImovel(tempT);
        }
        inFile.read(reinterpret_cast<char *>(&tipo), sizeof(char));
        inFile.seekg(-1, inFile.cur);
    }

    inFile.close();

    return 0;
}
/*
void outputImovel(std::ostream &output, Imovel &imovel, int tipo)
{
    Imovel *(((Apartamento *)lista[i]) = &imovel;
    if (tipo == 1)
    {
        output << "Título: " << (((Apartamento *)lista[i])->getTitulo() << "\n"
               << fixed << setprecision(2) << "Valor: " << (((Apartamento *)lista[i])->getValor()
               << "Cidade: " << (((Apartamento *)lista[i])->endereco.getCidade() << "\n"
               << "Bairro: " << (((Apartamento *)lista[i])->endereco.getBairro() << "\n";
    }
    if (tipo == 2)
    {
        output << "Título: " << (((Apartamento *)lista[i])->getTitulo() << "\n"
               << fixed << setprecision(2) << "Valor: " << (((Apartamento *)lista[i])->getValor() << "\n"
               << "Disponibilidade: " << ((((Apartamento *)lista[i])->getDisponiblidade() ? "Venda\n" : "Aluguel\n");
        if ((((Apartamento *)lista[i])->getTipo() == '0')
        {
            output << "Numero de quartos: " << (((Apartamento *)(((Apartamento *)lista[i]))->getNumQuartos()) << "\n"
                   << "Vagas na garagem: " << (((Apartamento *)(((Apartamento *)lista[i]))->getNumVagas()) << "\n"
                   << "Andar: " << (((Apartamento *)(((Apartamento *)lista[i]))->getAndar()) << "\n"
                   << "Area : " << (((Apartamento *)(((Apartamento *)lista[i]))->getArea()) << "m²\n"
                   << "Posicao: " << (((Apartamento *)(((Apartamento *)lista[i]))->getPosicao()) << "\n"
                   << "Preco do condominio: " << ((Apartamento *)(((Apartamento *)lista[i]))->getValorCondominio() << "\n";
        }
        if ((((Apartamento *)lista[i])->getTipo() == '1')
        {
            output << "Area construida: " << (((Casa *)(((Apartamento *)lista[i]))->getAreaConstruida()) << "\n"
                   << "Area do terreno: " << (((Casa *)(((Apartamento *)lista[i]))->getAreaTerreno()) << "\n"
                   << "Numero de pavimentos: " << (((Casa *)(((Apartamento *)lista[i]))->getNumPavimentos()) << "\n"
                   << "Numero de quartos: " << (((Casa *)(((Apartamento *)lista[i]))->getNumQuartos()) << "\n";
        }
        if ((((Apartamento *)lista[i])->getTipo() == '2')
        {
            output << "Area: " << (((Terreno *)(((Apartamento *)lista[i]))->getArea()) << "\n";
        }
        output << (((Apartamento *)lista[i])->endereco.getAsString();
    }
}
void outputImoveis(vector<Imovel *> lista, int tipo)
{
    cout << setw(15) << "Exibindo " << lista.size() << " imoveis\n";
    for (size_t i = 0; i < lista.size(); i++)
    {
        separador();
        cout << setw(15) << i + 1 << endl;
        separador();
        outputImovel(cout, *lista[i], tipo);
    }
}
void buscar(vector<Imovel *> listaImoveis, Imobiliaria &imob)
{
    int opcao;
    int imovelEscolhido;
    double valor;
    bool disp;
    string name1;
    string name2;
    GerenciadorDeTexto str;
    vector<int> index;
    //listaImoveis = imob.getImoveis();
    exibeMenuBuscar();
    opcao = inputInteiro();
    if (opcao == 9)
        return;
    switch (opcao)
    {
    case 1:
        name1 = inputStr("Digite o titulo: ");
        cout << name1 << endl;
        index = imob.indexPorTitulo(name1);
        if (index.empty())
            cout << "Titulo nao encontrado!" << endl;
        else
            outputImoveis(imob.getImoveis(index), 2);
        break;
    case 2:
        name1 = inputStr("Digite o Bairro: ");
        outputImoveis(imob.getImoveis(imob.indexPorBairro(name1)), 2);
        break;
    case 3:
        name1 = inputStr("Digite a cidade: ");
        outputImoveis(imob.getImoveis(imob.indexPorCidade(name1)), 2);
        break;
    case 4:
        cout << "Digite o valor: ";
        valor = inputValor();
        outputImoveis(imob.getImoveis(imob.indexPorValor(valor)), 2);
        break;
    case 5:
        name1 = inputStr("Digite o bairro:");
        cout << "Digite o valor: ";
        valor = inputValor();
        outputImoveis(imob.getImoveis(imob.combinarFiltros(imob.indexPorValor(valor), imob.indexPorBairro(name1))), 2);
        break;
    case 6:
        name1 = inputStr("Digite a cidade");
        cout << "Digite o valor: ";
        valor = inputValor();

        outputImoveis(imob.getImoveis(imob.combinarFiltros(imob.indexPorValor(valor), imob.indexPorCidade(name1))), 2);
        break;
    case 7:
        while (1)
        {
            exibeDisp();
            if (inputInteiro() != 1 || inputInteiro() != 2)
                cout << "Opcao invalida\n";
            else
            {
                disp = inputInteiro() == 1 ? true : false;
                printf("Digite o bairro: ");
                cin.ignore();
                getline(cin, name1);
                if (str.verificaStr(name1))
                    break;
            }
        }
        outputImoveis(imob.getImoveis(imob.combinarFiltros(imob.indexPorDisponibilidade(disp), imob.indexPorBairro(name1))), 2);
        break;
    case 8:
        while (1)
        {
            exibeDisp();
            if (inputInteiro() != 1 || inputInteiro() != 2)
                cout << "Opcao invalida\n";
            else
            {
                disp = inputInteiro() == 1 ? true : false;
                printf("Digite a cidade: ");
                cin.ignore();
                getline(cin, name1);
                if (str.verificaStr(name1))
                    break;
            }
        }
        outputImoveis(imob.getImoveis(imob.combinarFiltros(imob.indexPorDisponibilidade(disp), imob.indexPorCidade(name1))), 2);
        break;
    default:
        cout << "Escolha outra opcao" << endl;
    }
}/*
void menu(vector<Imovel *> listaImoveis, Imobiliaria &imob)
{
 /*   
vector<Imovel *> cadatrarImovel(Imobiliaria imob)
{
    GerenciadorDeTexto str;
    GerenciadorDeArquivo arq;
    string name;
    Imovel *imovel;
}
*/