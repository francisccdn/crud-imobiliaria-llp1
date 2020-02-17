#include <iostream>
#include "Imobiliaria.h"
#include "GerenciadorDeTexto.h"
#include "GerenciadorDeArquivo.h"
#include "Front.h"
//#include "menu.h"
void outputImovel(std::ostream &output, Imovel &imovel, int tipo);
void outputImoveis(vector<Imovel *> lista, int tipo);
void buscar(vector<Imovel *> listaPtr, Imobiliaria imob);
void menu(vector<Imovel *> listaPtr, Imobiliaria &imob);
//vector<Imovel *> cadatrarImovel(Imobiliaria imob);
//bool leArquivo(Imobiliaria &imob);
//bool SalvaArquivo(vector<Imovel *> lista);

int main()
{
    Imobiliaria imob;
    GerenciadorDeArquivo f1;
   
    if (f1.leArquivo(&imob));

    Front exibe;
    exibe.menu(&imob);

    f1.setLista(imob.getImoveis());
    if ( f1.SalvaArquivo() )
        cout << "Arquivo Salvo" << endl;
    else
        cout << "Continue tentando" << endl;
    
    return 0;
} 