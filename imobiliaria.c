#include <stdio.h>
#include <string.h>

#define TAMANHO 100

enum {ALUGUEL, VENDA};
enum {CASA, APTO, TERRENO};

typedef struct{
    char logradouro[100];
    int numero;
    char bairro[50];
    char cidade[100];
    int cep;
} endereco_t;

typedef struct{
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
} casa_t;

typedef struct{
    double area;
    int numQuartos;
    char posicao[50];
    int andar;
    double precoCondominio;
    int vagasGaragem;
} apto_t;

typedef struct{
    double area;
} terreno_t;

typedef union{
    terreno_t terreno;
    casa_t casa;
    apto_t apto;
} tipoImovel_t;

typedef struct{
    char titulo[100];
    double preco;
    int disponibilidade;
    tipoImovel_t imovel;
    endereco_t endereco;
    int tipo;
    int ultimo;
} imovel_t;

void TiraBarraN(char*str){
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='\n')
            str[i]='\0';
    }
}

void salvaImoveis(imovel_t *imoveis){
    FILE *fp;
    fp = fopen("imoveis.bin", "wb");

    fwrite(imoveis, sizeof(imovel_t), TAMANHO, fp);

    fclose(fp);
}

void leImoveis(imovel_t *imoveis){
    FILE *fp;
    fp = fopen("imoveis.bin", "rb");

    fread(imoveis, sizeof(imovel_t), TAMANHO, fp);

    fclose(fp);
}

void ExibeMenu(){
    //printf("\e[H\e[2J"); (Comando ta dando aguia na função buscar por titulo)
    puts("Sistema de gerenciamento de imoveis");
    printf( "\t 1- Cadastrar imovel\n"
            "\t 2- Consultar imovel\n"
            "\t 3- Remover imovel\n"
            "\t 4- Editar imovel\n"
            "\t 5- Sair\n");
}
void ExibeSubmenu(){
    //printf("\e[H\e[2J");
    puts("Sistema de gerenciamento de imoveis");
    printf( "\t 1- Exibir todos imoveis\n"
            "\t 2- Exibir imoveis disponiveis para venda\n"
            "\t 3- Exibir imoveis disponiveis para aluguel\n"
            "\t 4- Buscar imovel por titulo\n"
            "\t 5- Buscar imovel por bairro\n"
            "\t 6- Buscar imovel por valor minimo\n"
            "\t 7- Voltar\n");
}
void ExibeSubsubmenu(){
    //printf("\e[H\e[2J");
    puts("Sistema de gerenciamento de imoveis");
    printf( "\t 1- Casas\n"
            "\t 2- Apartamentos\n"
            "\t 3- Terrenos\n"
            "\t 4- Voltar\n");
}

//Trocar por exibe imovel
void exibeTerreno(imovel_t *exibido){
    printf("Titulo: %s \n", exibido->titulo);
    printf("Valor: %lf \n", exibido->preco);
    printf("Area: %lf \n", exibido->imovel.terreno.area);
    printf("Disponibilidade: ");
    switch(exibido->disponibilidade){
        case ALUGUEL:
            printf("Aluguel.\n");
            break;
        case VENDA:
            printf("Venda.\n");
            break;
    }
    //exibeEndereco();
    printf("\n\n");
}
void buscaPorTitulo(imovel_t lista[])
{
    int i;
    char titulo[TAMANHO];
    printf("Digite o Título:");
    fgets(titulo,TAMANHO,stdin);
    TiraBarraN(titulo);
    
    printf("%s\n",lista[0].imovel.terreno.titulo);
    for ( i = 0; i < TAMANHO; i++)
    {
        if(!(strcmp(titulo, lista[i].imovel.terreno.titulo))){
            exibeTerreno(&lista[i]);
            return ;
        }
        if(!(strcmp(titulo, lista[i].imovel.apto.titulo))){
            exibeTerreno(&lista[i]);
            return ;
        }
        if(!(strcmp(titulo, lista[i].imovel.casa.titulo))){
            exibeTerreno(&lista[i]);
            return ;
        }
    }
    puts("Título não encontrado.");
}
void exibeTudo(imovel_t lista[]){
    for(int i = 0; !(lista[i].ultimo); i++)
    {
        switch (lista[i].tipo){
            case CASA:
                //exibeCasa(lista[i]);
                break;
            case APTO:
                //exibeApto(lista[i]);
                break;
            case TERRENO:
                exibeTerreno(&lista[i]);
                break;
            default:
                break;
        }
    }

}

void Menu(imovel_t lista[]){
    int opcao, subopcao, subsubopcao;
    while (1){
        ExibeMenu();
        printf("Digite a opcao desejada: ");
        scanf("%d%*c", &opcao);
        if (opcao == 5){
            break;
        }
        switch (opcao)
        {
        case 1:
            /* Inserir funcao de cadastro */
            break;
        case 2:
            ExibeSubmenu();
            printf("Digite a opcao desejada: ");
            scanf("%d%*c", &subopcao);
            if (subopcao == 7){
                break;
            }

            switch (subopcao)
            {
            case 1:
                /* Inserir funcao de exibir todos imoveis */
                break;
            case 2:
                ExibeSubsubmenu();
                printf("Digite a opcao desejada: ");
                scanf("%d%*c", &subsubopcao);
                if (subsubopcao == 4){
                    break;
                }
                switch (subsubopcao)
                {
                case 1:
                    /*Inserir funcao de exibir casas para venda*/
                    break;
                case 2:
                    /*Inserir funcao de exibir apartamentos para venda*/
                    break;
                case 3:
                    /*Inserir funcao de exibir terrenos para venda*/
                default:
                    puts("Opcao invalida");
                    break;
                }
                break;
            case 3:
                ExibeSubsubmenu();
                printf("Digite a opcao desejada: ");
                scanf("%d%*c", &subsubopcao);
                if (subsubopcao == 4){
                    break;
                }
                switch (subsubopcao)
                {
                case 1:
                    /*Inserir funcao de exibir casas para venda*/
                    break;
                case 2:
                    /*Inserir funcao de exibir apartamentos para venda*/
                    break;
                case 3:
                    /*Inserir funcao de exibir terrenos para venda*/
                default:
                    puts("Opcao invalida");
                    break;
                }
                break;
            case 4:
                buscaPorTitulo(lista);
                break;
            case 5:
                /*Inserir funcao de buscar imoveis por bairro*/
                break;
            case 6:
                /*Inserir funcao de buscar imoveis por valor minimo*/
                break;
            default:
                puts("Opcao invalida");
                break;
            }
        default:
            puts("Opcao invalida");
            break;
        }
    }
}

void cadastraImoveis(imovel_t *lista[]){
    int i = 0, opcao = 0;
    while(!lista[i]->ultimo){
        i++;
    }

    ExibeSubsubmenu();
    /*Tem que ter um menuzinho melhor*/
    printf("Digite a opcao desejada: ");
    scanf("%d%*c", &opcao);

    /*Opções comuns a todos*/

    switch (opcao){
        case 1://Casa

        case 2://Apto

        case 3://Terreno

        case 4://Voltar

        default:
            puts("Opção invalida.");
    }

    /*Cadastro de endereço*/

    lista[i+1]->ultimo = 1;


}

int main(void){
    int i;
    imovel_t listaImoveis[TAMANHO];
    imovel_t *ptLista = listaImoveis;

    

    char title[]="Terreno pra vender";

    //leImoveis(listaImoveis);

    listaImoveis[0].tipo = TERRENO;
    strcpy(listaImoveis[0].titulo, "Terreno pra vender");
    listaImoveis[0].preco = 10.31;
    listaImoveis[0].imovel.terreno.area = 312;
    listaImoveis[0].disponibilidade = VENDA;
    listaImoveis[0].ultimo = 0;

    listaImoveis[1].tipo = TERRENO;
    strcpy(listaImoveis[1].titulo, "Terreno pra vender 2");
    listaImoveis[1].preco = 14.1;
    listaImoveis[1].imovel.terreno.area = 512;
    listaImoveis[1].disponibilidade = ALUGUEL;
    listaImoveis[1].ultimo = 0;

    listaImoveis[2].ultimo = 1;
    Menu(listaImoveis);
    salvaImoveis(listaImoveis);

    //buscaPorTitulo(title,listaImoveis);

    return 0;
}