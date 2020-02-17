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
//vector<Imovel *> cadatrarImovel(Imobiliaria imob);
//bool leArquivo(Imobiliaria &imob);
//bool SalvaArquivo(vector<Imovel *> lista);

int main()
{
    Endereco casa = Endereco("Rua qualquer", 80, "bairro", "580--5440", "Cajazeiras");
    //Imovel teste = Imovel();
    Terreno flamengo = Terreno(Endereco("Rua da arruda", 81, "Sei la", "58000", "Salvador"), '2', true, 125000.50, "Terreno para venda", 169);
    Apartamento foda = Apartamento(Endereco("Rua foda", 69, "bairro foda", "cep foda", "cidade foda"), '0', true, 696969, "Apartamento muito foda", 6, 66, 66.66, 2, "Virado pra o lado foda", 9);
    Casa umacasa = Casa(Endereco("Rua dos bobos", 0, "Inexistente", "0000-0000-0000", "Cidade imaginaria"), '1', false, 0.50, "Casa muito engracada", 0, 0, 0, 0);

    Imobiliaria imob;
    GerenciadorDeArquivo f1;
    //vector<Imovel *> listaImoveis;
    //if (f1.leArquivo(&imob));

    imob.cadastraImovel(&flamengo);
    imob.cadastraImovel(&foda);
    imob.cadastraImovel(&umacasa);

    Front exibe;
    exibe.menu(imob);
    
    vector<Imovel*> listaImoveis = imob.getImoveis();
            

    for (size_t i = 0; i < listaImoveis.size(); i++)
    {
        cout << listaImoveis[i]->getTitulo() << endl;
    }
    
    if ( f1.SalvaArquivo(listaImoveis) )
        cout << "Arquivo Salvo" << endl;
    else
        cout << "Continue tentando" << endl;

    
    return 0;
} 