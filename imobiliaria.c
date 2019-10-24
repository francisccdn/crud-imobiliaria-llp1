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
    endereco_t endereco;
    char titulo[100];
    double preco;
    int disponibilidade;
    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;
} casa_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    int disponibilidade;
    double area;
    int numQuartos;
    char posicao[50];
    int andar;
    double precoCondominio;
    int vagasGaragem;
} apto_t;

typedef struct{
    endereco_t endereco;
    char titulo[100];
    double preco;
    int disponibilidade;
    double area;
} terreno_t;

typedef union{
    terreno_t terreno;
    casa_t casa;
    apto_t apto;
} tipoImovel_t;

typedef struct{
    tipoImovel_t imovel;
    int tipo;
} imovel_t;

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
    puts("Sistema de gerenciamento de imoveis");
    printf( "\t 1- Cadastrar imovel\n"
            "\t 2- Consultar imovel\n"
            "\t 3- Remover imovel\n"
            "\t 4- Editar imovel\n"
            "\t 5- Sair\n");
}
void ExibeSubmenu(){
    printf( "\t 1- Exibir todos imoveis\n"
            "\t 2- Exibir imoveis disponiveis para venda\n"
            "\t 3- Exibir imoveis disponiveis para aluguel\n"
            "\t 4- Buscar imovel por titulo\n"
            "\t 5- Buscar imovel por bairro\n"
            "\t 6- Buscar imovel por valor minimo\n"
            "\t 7- Voltar\n");
}
void ExibeSubsubmenu(){
    printf( "\t 1- Casas\n"
            "\t 2- Apartamentos\n"
            "\t 3- Terrenos\n"
            "\t 4- Voltar\n");
}

void Menu(){
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
            /*Inserir funcao de buscar imoveis por titulo*/
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

void exibeTerreno(imovel_t *exibido){
    printf("Titulo: %s \n", exibido->imovel.terreno.titulo);
    printf("Valor: %lf \n", exibido->imovel.terreno.preco);
    printf("Area: %lf \n", exibido->imovel.terreno.area);
    printf("Disponibilidade: ");
    switch(exibido->imovel.terreno.disponibilidade){
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
void buscaPorTitulo(char *titulo,  imovel_t lista[])
{
    int i;
    for ( i = 0; i < TAMANHO; i++)
    {
        if(!(strcmp(titulo, lista[i].imovel.terreno.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
        if(!(strcmp(titulo, lista[i].imovel.apto.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
        if(!(strcmp(titulo, lista[i].imovel.casa.titulo))){
            printf("%s\n",lista[i].imovel.terreno.titulo);
            return ;
        }
    }
    puts("Título não encontrado.");
}

int main(void){
    int i;
    imovel_t listaImoveis[TAMANHO];

    Menu();

    char title[]="Terreno pra vender";

    leImoveis(listaImoveis);
    /*
    listaImoveis[0].tipo = TERRENO;
    strcpy(listaImoveis[0].imovel.terreno.titulo, "Terreno pra vender");
    listaImoveis[0].imovel.terreno.preco = 10.31;
    listaImoveis[0].imovel.terreno.area = 312;
    listaImoveis[0].imovel.terreno.disponibilidade = VENDA;

    salvaImoveis(listaImoveis);
    */
    exibeTerreno(&listaImoveis[0]);
    
    buscaPorTitulo(title,listaImoveis);

    return 0;
}
