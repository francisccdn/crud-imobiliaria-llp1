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
<<<<<<< HEAD
    Endereco casa = Endereco("Rua qualquer", 80, "bairro", "580--5440", "Cajazeiras");
    //Imovel teste = Imovel();
    Terreno flamengo = Terreno(Endereco("Rua da arruda", 81, "Sei la", "58000", "Salvador"), true, 125000.50, "Terreno para venda", 169);
    Apartamento foda = Apartamento(Endereco("Rua foda", 69, "bairro foda", "cep foda", "cidade foda"), true, 696969, "Apartamento muito foda", 6, 66, 66.66, 2, "Virado pra o lado foda", 9);
    Casa umacasa = Casa(Endereco("Rua dos bobos", 0, "Inexistente", "0000-0000-0000", "Cidade imaginaria"), false, 0.50, "Casa muito engracada", 0, 0, 0, 0);

=======
/*    Endereco casa = Endereco("Rua qualquer", 80, "bairro", "580--5440", "Cajazeiras");
    Terreno flamengo = Terreno(Endereco("Rua da arruda", 81, "Sei la", "58000", "Salvador"), true, 125000.50, "Terreno para venda", 169);
    Apartamento foda = Apartamento(Endereco("Rua foda", 69, "bairro foda", "cep foda", "cidade foda"), true, 696969, "Apartamento muito foda", 6, 66, 66.66, 2, "Virado pra o lado foda", 9);
    Casa umacasa = Casa(Endereco("Rua dos bobos", 0, "Inexistente", "0000-0000-0000", "Cidade imaginaria"), false, 0.50, "Casa muito engracada", 0, 0, 0, 0);
    Casa outracasa = Casa(casa, false, 0.50, "Casa muito chata", 0, 0, 0, 0);
*/
>>>>>>> 72a3873273cb762ff9211ee38ce499c8c80b8f64
    Imobiliaria imob;
    GerenciadorDeArquivo f1;
   
    if (f1.leArquivo(&imob));
/*
    imob.cadastraImovel(&flamengo);
    imob.cadastraImovel(&foda);
    imob.cadastraImovel(&umacasa);
    imob.cadastraImovel(&outracasa);*/

    Front exibe;
    exibe.menu(&imob);

    vector<Imovel*> listinha = imob.getImoveis();

    for(int i = 0; i < listinha.size(); i++)
    {
        cout << "DENTRO DA MAIN: " << listinha[i]->getTitulo() << endl;
    }
    
    f1.setLista(imob.getImoveis());
    f1.teste();
    if ( f1.SalvaArquivo() )
        cout << "Arquivo Salvo" << endl;
    else
        cout << "Continue tentando" << endl;
    
    return 0;
} 