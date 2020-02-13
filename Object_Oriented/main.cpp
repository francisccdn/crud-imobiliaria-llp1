#include <iostream>
#include "Imobiliaria.h"
#include "GerenciadorDeTexto.h"
#include "header.h"

int main(){

    vector<Imovel*>listaImoveis(3);
    vector<Imovel*>listaImoveis1(3);
    Endereco casa = Endereco("Rua qualquer", 80, "bairro", "580--5440", "Cajazeiras");
    //Imovel teste = Imovel();
    Terreno flamengo = Terreno(Endereco("Rua da arruda", 81, "Sei la", "58000", "Salvador"), '2', true, 125000.50, "Terreno para venda", 169);
    Apartamento foda = Apartamento(Endereco("Rua foda", 69, "bairro foda", "cep foda", "cidade foda"), '0', true, 696969, "Apartamento muito foda", 6, 66, 66.66, 2, "Virado pra o lado foda", 9);
    Casa umacasa = Casa(Endereco("Rua dos bobos", 0, "Inexistente", "0000-0000-0000", "Cidade imaginaria"), '1', false, 0.50, "Casa muito engracada", 0, 0, 0, 0);

    listaImoveis[0]= &foda;
    listaImoveis[1]= &flamengo;
    listaImoveis[2]= &umacasa;
    //cout<<listaImoveis[0]->getTitulo()<<endl;
    GerenciadorDeArquivo f1;
    if(f1.SalvaArquivo(listaImoveis))
        cout<<"Arquivo Salvo"<<endl;
    else
    {
        cout<<"Continue tentando"<<endl;
    }
    listaImoveis1=f1.leArquivo();
    Imobiliaria imob;

    /*
    GerenciadorDeTexto gerenciadorDeTexto;
    std::string teste = "olá â ã é isso aí";

    teste = gerenciadorDeTexto.removeAcento(teste);

    std::cout << teste << std::endl;*/

    //EXEMPLOS DE CHAMADAS DE FUNÇÕES DA IMOBILIARIA PARA O FRONT END
    // -- Busca
    /*std::string bairro;
    std::cin >> bairro;

    std::vector<Imovel*> resultadosDaBusca;

    resultadosDaBusca = imob.getImoveis(imob.indexPorBairro(bairro)); 
    //indexPorBairro retorna um vetor de indices, e getImoveis usa um vetor de indices
    //para buscar na lista de imoveis e retorna um vetor com os imoveis desses indices 

    for(){
        cout >> resultadosDaBusca; //esse cout ta errado é só pra exemplificar
    }

    // -- Cadastro
    cin >> endereco;
    cin << titulo;
    cin << etc;

    imob.cadastraImovel(new Apartamento(titulo, endereco, etc));

    // -- Remover
    // faz uma busca e remove com o vetor de indices
    imob.removerImoveis(imob.indexPorBairro(bairro));

    // -- Editar
    cin << endereco;
    cin << titulo;
    cin << etc;

    //aqui faz uma busca e pergunta ao usuario qual dos imoveis quer editar
    int indice;
    //salva o indice do imovel que o usuario escolher

    imob.editarImovel(new Apartamento(titulo, endereco, etc), indice);

    //FIM DOS EXEMPLOS PARA FRONT END
*/
    return 0;
};
