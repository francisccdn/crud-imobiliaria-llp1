#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 100

enum {ALUGUEL = 1, VENDA = 2};
enum {CASA = 1, APTO = 2, TERRENO = 3};

typedef struct{
    char logradouro[MAX_TAMANHO];
    int numero;
    char bairro[MAX_TAMANHO];
    char cidade[MAX_TAMANHO];
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
    char posicao[MAX_TAMANHO];
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

void cadastraImoveis();
void editaCadastro(int);
void TiraBarraN(char*);
void salvaImoveis();
void leImoveis();
void ExibeMenu();
void ExibeSubmenu();
void ExibeSubsubmenu();
void exibeImovel(imovel_t*);
int buscaPorTitulo();
void buscaPorBairro();
void buscaPorValor();
void exibeTudo();
void removeImovel();
void Menu();
void escolha();

imovel_t listaImoveis[MAX_TAMANHO];

int countC=0,countD=0,countE=0;

int main(void){
    leImoveis(listaImoveis);

    /*listaImoveis[0].tipo = TERRENO;
    strcpy(listaImoveis[0].titulo, "Terreno pra vender");
    listaImoveis[0].preco = 10.31;
    listaImoveis[0].imovel.terreno.area = 312;
    strcpy(listaImoveis[0].endereco.bairro,"Mangabeira");
    listaImoveis[0].disponibilidade = VENDA;
    listaImoveis[0].ultimo = 0;

    listaImoveis[1].tipo = TERRENO;
    strcpy(listaImoveis[1].titulo, "Terreno pra alugar");
    listaImoveis[1].preco = 14.1;
    listaImoveis[1].imovel.terreno.area = 512;
    strcpy(listaImoveis[1].endereco.bairro,"Alto do Mateus");
    listaImoveis[1].disponibilidade = ALUGUEL;
    listaImoveis[1].ultimo = 0;

    listaImoveis[2].tipo = TERRENO;
    strcpy(listaImoveis[2].titulo, "Terreno pra alugar 2");
    listaImoveis[2].preco = 14.1;
    listaImoveis[2].imovel.terreno.area = 512;
    strcpy(listaImoveis[2].endereco.bairro,"Alto do Mateus");
    listaImoveis[2].disponibilidade = ALUGUEL;
    listaImoveis[2].ultimo = 0;

    listaImoveis[3].tipo = CASA;
    strcpy(listaImoveis[3].titulo, "Casa pra alugar");
    listaImoveis[3].preco = 14.1;
    listaImoveis[3].imovel.casa.areaConstruida = 512;
    strcpy(listaImoveis[3].endereco.bairro,"Alto do Mateus");
    listaImoveis[3].disponibilidade = ALUGUEL;
    listaImoveis[3].ultimo = 0;

    listaImoveis[4].ultimo = 1;*/
    Menu();

    //salvaImoveis();

    return 0;
}

void TiraBarraN(char*str){
    int i;
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='\n')
            str[i]='\0';
    }
}

void salvaImoveis(){
    FILE *fp;
    fp = fopen("imoveis.bin", "wb");

    fwrite(listaImoveis, sizeof(imovel_t), MAX_TAMANHO, fp);

    fclose(fp);
}

void leImoveis(){
    FILE *fp;
    fp = fopen("imoveis.bin", "rb");

    fread(listaImoveis, sizeof(imovel_t), MAX_TAMANHO, fp);

    fclose(fp);
}

void ExibeMenu(){
    //printf("\e[H\e[2J"); //(Comando ta dando aguia na função buscar por titulo)
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

void exibeImovel(imovel_t *exibido){
    printf("Titulo: %s \n", exibido->titulo);
    printf("Valor: %lf \n", exibido->preco);
    printf("Disponibilidade: ");
    switch(exibido->disponibilidade){
        case ALUGUEL:
            printf("Aluguel.\n");
            break;
        case VENDA:
            printf("Venda.\n");
            break;
    }

    switch(exibido->tipo){
        case CASA:
            printf("Area construida: %lf \n", exibido->imovel.casa.areaConstruida);
            printf("Area do terreno: %lf \n", exibido->imovel.casa.areaTerreno);
            printf("Numero de pavimentos: %d \n", exibido->imovel.casa.numPavimentos);
            printf("Numero de quartos: %d \n", exibido->imovel.casa.numQuartos);
            break;
        case APTO:
            printf("Numero de quartos: %d \n", exibido->imovel.apto.numQuartos);
            printf("Andar: %d \n", exibido->imovel.apto.andar);
            printf("Area: %lf \n", exibido->imovel.apto.area);
            printf("Posicao: %s \n", exibido->imovel.apto.posicao);
            printf("Preco do condominio: %lf \n", exibido->imovel.apto.precoCondominio);
            printf("Vagas na garagem: %d \n", exibido->imovel.apto.vagasGaragem);
            break;
        case TERRENO:
            printf("Area: %lf \n", exibido->imovel.terreno.area);
            break;
    }

    printf("Cidade: %s \n", exibido->endereco.cidade);
    printf("Bairro: %s \n", exibido->endereco.bairro);
    printf("Endereco: %s, %d\n", exibido->endereco.logradouro, exibido->endereco.numero);
    printf("CEP: %d \n", exibido->endereco.cep);

    printf("\n");
}

int buscaPorTitulo(){
    int i;
    char titulo[MAX_TAMANHO];
    printf("Digite o Título: ");
    fgets(titulo,MAX_TAMANHO,stdin);
    TiraBarraN(titulo);
    
    for (i = 0; !listaImoveis[i].ultimo; i++){
        if(!(strcmp(titulo, listaImoveis[i].titulo))){
            exibeImovel(&listaImoveis[i]);
            return i;
        }
    }

    puts("Título não encontrado.");
    return -1;
}

void buscaPorBairro(){
    int i;
    char bairro[MAX_TAMANHO];
    printf("Digite o Bairro: ");
    fgets(bairro,MAX_TAMANHO,stdin);
    TiraBarraN(bairro);
    
    for ( i = 0; !listaImoveis[i].ultimo; i++){
        if(!(strcmp(bairro, listaImoveis[i].endereco.bairro))){
            exibeImovel(&listaImoveis[i]);
            return ;
        }
    }

    puts("Bairro não encontrado.");
}
void buscaPorValor(){
    int i;
    float valor;

    printf("Digite o Valor: ");
    scanf("%f",&valor);

    for ( i = 0; !listaImoveis[i].ultimo; i++){
        if(listaImoveis[i].preco >= valor)
            exibeImovel(&listaImoveis[i]);
    }   

    puts("Não existem imoveis acima desse valor.");
}

void exibeTudo(){
    for(int i = 0; !(listaImoveis[i].ultimo); i++){
        exibeImovel(&listaImoveis[i]);
    }
}

void buscaDisponibTipo(int disp, int tipo){
    if(disp == 2){
        disp = VENDA;
    }else if(disp == 3){
        disp = ALUGUEL;
    }

    for(int i = 0; !listaImoveis[i].ultimo; i++){
        if(listaImoveis[i].disponibilidade == disp && listaImoveis[i].tipo == tipo)
            exibeImovel(&listaImoveis[i]);
    }
}

void Menu(){
    int opcao, subopcao, subsubopcao;
    int imovelEscolhido;
    while (1){
        ExibeMenu();
        printf("Digite a opcao desejada: ");
        scanf("%d%*c", &opcao);
        if (opcao == 5){
            if((countC+countD+countE)>0){
                puts("Deseja salvar suas alterações?");
                escolha();
                scanf("%d",&opcao);
                if(opcao){
                    salvaImoveis();
                    puts("Alterações salvas com sucesso!");
                }
            }
        break;
        }
        switch (opcao){
            case 1:
                countC++;
                cadastraImoveis();
                break;
            case 2:
                ExibeSubmenu();
                printf("Digite a opcao desejada: ");
                scanf("%d%*c", &subopcao);
                if (subopcao == 7){
                    break;
                }

                switch (subopcao){
                    case 1:
                        exibeTudo();
                        break;
                    case 2: //Venda
                    case 3: //Aluguel
                        ExibeSubsubmenu();
                        printf("Digite a opcao desejada: ");
                        scanf("%d%*c", &subsubopcao);

                        if (subsubopcao == 4){
                            break;
                        }
                        else if(subsubopcao > 4 || subsubopcao < 1){
                            puts("Opcao invalida");
                            break;
                        }

                        buscaDisponibTipo(subopcao, subsubopcao);
                        break;
                    case 4:
                        buscaPorTitulo();
                        break;
                    case 5:
                        buscaPorBairro();
                        break;
                    case 6:
                        buscaPorValor();
                        break;
                    default:
                        puts("Opcao invalida");
                        break;
                }
            break;
            case 3:
                countD++;
                removeImovel();
                break;
            case 4:
                countE++;
                imovelEscolhido = buscaPorTitulo();
                editaCadastro(imovelEscolhido);
                break;
            default:
                puts("Opcao invalida");
                break;
        }
    }
}   

void cadastraImoveis(){
    int i = 0;
    while(!listaImoveis[i].ultimo){
        i++;
    }

    editaCadastro(i);

    puts("Cadastro concluido!");

    listaImoveis[i].ultimo = 0;
    listaImoveis[i+1].ultimo = 1;
}

void editaCadastro(int i){
    int  opcaoTipo = 0, opcaoDisp = 0;

    //aluguel ou venda?
    while (opcaoDisp == 0) {
        puts("O imovel esta disponivel para aluguel ou venda?");
        puts("\t1 - Aluguel.");
        puts("\t2 - Venda.");
        printf("Digite a opcao desejada: ");
        scanf("%d%*c", &opcaoDisp);
        listaImoveis[i].disponibilidade = opcaoDisp;

        if(opcaoDisp != 1 && opcaoDisp != 2){
            puts("Opcao invalida");
            opcaoDisp = 0;
        }
    }

    printf("Digite o titulo: ");
    fgets(listaImoveis[i].titulo, MAX_TAMANHO, stdin);
    TiraBarraN(listaImoveis[i].titulo);
    printf("Digite o preco: ");
    scanf("%lf", &listaImoveis[i].preco);

    while (opcaoTipo == 0) {
        ExibeSubsubmenu();
        printf("Digite o tipo de imovel: ");
        scanf("%d%*c", &opcaoTipo);
        listaImoveis[i].tipo = opcaoTipo;

        switch (opcaoTipo) {
            case CASA:
                printf("Digite o numero de quartos: ");
                scanf("%d", &listaImoveis[i].imovel.casa.numQuartos);
                printf("Digite o numero de pavimentos: ");
                scanf("%d", &listaImoveis[i].imovel.casa.numPavimentos);
                printf("Digite a area do terreno: ");
                scanf("%lf", &listaImoveis[i].imovel.casa.areaTerreno);
                printf("Digite a area construida: ");
                scanf("%lf%*c", &listaImoveis[i].imovel.casa.areaConstruida);
                break;
            case APTO:
                printf("Digite o numero de quartos: ");
                scanf("%d", &listaImoveis[i].imovel.apto.numQuartos);
                printf("Digite a qauntidade de vagas na garagem: ");
                scanf("%d", &listaImoveis[i].imovel.apto.vagasGaragem);
                printf("Digite o preco do condominio: ");
                scanf("%lf", &listaImoveis[i].imovel.apto.precoCondominio);
                printf("Digite o numero de quartos: ");
                fgets(listaImoveis[i].imovel.apto.posicao, MAX_TAMANHO, stdin);
                printf("Digite a area do apartamento: ");
                scanf("%lf", &listaImoveis[i].imovel.apto.area);
                printf("Digite o andar: ");
                scanf("%d%*c", &listaImoveis[i].imovel.apto.andar);
                break;
            case TERRENO:
                printf("Digite a area do terreno: ");
                scanf("%lf%*c", &listaImoveis[i].imovel.terreno.area);
                break;
            case 4://Voltar
                puts("Operacao cancelada.");
                return;
            default:
                puts("Opção invalida.");
                opcaoTipo = 0;
                break;
        }
    }

    printf("Digite a cidade: ");
    fgets(listaImoveis[i].endereco.cidade, MAX_TAMANHO, stdin);
    TiraBarraN(listaImoveis[i].endereco.cidade);
    printf("Digite o bairro: ");
    fgets(listaImoveis[i].endereco.bairro, MAX_TAMANHO, stdin);
    TiraBarraN(listaImoveis[i].endereco.bairro);
    printf("Digite a rua: ");
    fgets(listaImoveis[i].endereco.logradouro, MAX_TAMANHO, stdin);
    TiraBarraN(listaImoveis[i].endereco.logradouro);
    printf("Digite o numero: ");
    scanf("%d", &listaImoveis[i].endereco.numero);
    printf("Digite o CEP: ");
    scanf("%d", &listaImoveis[i].endereco.cep);

}
void escolha(){
    puts("0-NAO");
    puts("1-SIM");
}
void removeImovel(){
    int c, i, j;
    i = buscaPorTitulo();
    if(i != -1){
        printf("Deseja realmente excluir o imovel?\n");
        escolha();
        scanf("%d",&c);
        if(c)
        {
            for(j = i; j < MAX_TAMANHO; j++){
                listaImoveis[j] = listaImoveis[j+1];
            }
            puts("Imovel excluido com sucesso!");
        }
        else
            ExibeMenu();
    }
}
