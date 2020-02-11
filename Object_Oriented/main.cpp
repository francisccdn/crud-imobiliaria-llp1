#include <iostream>
#include "Imobiliaria.h"
#include "GerenciadorDeTexto.h"

int main(){
    Imobiliaria imob;

    /*
    GerenciadorDeTexto gerenciadorDeTexto;
    std::string teste = "olá â ã é isso aí";

    teste = gerenciadorDeTexto.removeAcento(teste);

    std::cout << teste << std::endl;*/

    //EXEMPLOS DE CHAMADAS DE FUNÇÕES DA IMOBILIARIA PARA O FRONT END
    // -- Busca
    std::string bairro;
    std::cin >> bairro;

    std::vector<Imovel*> resultadosDaBusca;

    resultadosDaBusca = imob.getImoveis(imob.indexPorBairro(bairro)); 
    //indexPorBairro retorna um vetor de indices, e getImoveis usa um vetor de indices
    //para buscar na lista de imoveis e retorna um vetor com os imoveis desses indices 

    for(){
        cout << resultadosDaBusca; //esse cout ta errado é só pra exemplificar
    }

    // -- Cadastro
    cin << endereco;
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

    return 0;
};