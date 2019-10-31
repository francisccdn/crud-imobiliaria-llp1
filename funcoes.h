#define MAX_TAMANHO 100

void cadastraImoveis();
void editaCadastro(int);
void TiraBarraN(char*);
void salvaImoveis();
void leImoveis();
void ExibeMenu();
void ExibeSubmenu();
void ExibeSubSubMenu1();
void ExibeSubSubMenu2();
void exibeImovel(imovel_t*);
void buscaPorBairro();
void buscaPorValor();
void exibeTudo();
void removeImovel();
void Menu();
void escolha();
void limpaTela();
void cabecalho();
void esperar();
int buscaPorTitulo();


imovel_t listaImoveis[MAX_TAMANHO];

int countC = 0, countD = 0, countE = 0;

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
    cabecalho();
    printf( "\t 1- Cadastrar imovel\n"
            "\t 2- Consultar imovel\n"
            "\t 3- Remover imovel\n"
            "\t 4- Editar imovel\n"
            "\t 5- Sair\n");
}
void ExibeSubmenu(){
    cabecalho();
    printf( "\t 1- Exibir todos imoveis\n"
            "\t 2- Exibir imoveis disponiveis para venda\n"
            "\t 3- Exibir imoveis disponiveis para aluguel\n"
            "\t 4- Buscar imovel por titulo\n"
            "\t 5- Buscar imovel por bairro\n"
            "\t 6- Buscar imovel por valor minimo\n"
            "\t 7- Voltar\n");
}
void ExibeSubSubMenu2(){
    cabecalho();
    printf( "Voce deseja buscar um(a): \n"
            "\t 1- Casa\n"
            "\t 2- Apartamento\n"
            "\t 3- Terreno\n"
            "\t 4- Voltar\n");
}
void ExibeSubSubMenu1(){
    cabecalho();
    printf( "Voce deseja adicionar uma: \n"
            "\t 1- Casa\n"
            "\t 2- Apartamento\n"
            "\t 3- Terreno\n"
            "\t 4- Voltar\n");
}

void exibeImovel(imovel_t *exibido){
    printf("Titulo: %s \n", exibido->titulo);
    printf("Valor: R$ %.2lf \n", exibido->preco);
    printf("Disponibilidade: ");
    switch(exibido->disponibilidade){
        case ALUGUEL:
            printf("Aluguel\n");
            break;
        case VENDA:
            printf("Venda\n");
            break;
    }

    switch(exibido->tipo){
        case CASA:
            printf("Area construida: %.0lf m² \n", exibido->imovel.casa.areaConstruida);
            printf("Area do terreno: %.0lf m²\n", exibido->imovel.casa.areaTerreno);
            printf("Numero de pavimentos: %d \n", exibido->imovel.casa.numPavimentos);
            printf("Numero de quartos: %d \n", exibido->imovel.casa.numQuartos);
            break;
        case APTO:
            printf("Numero de quartos: %d \n", exibido->imovel.apto.numQuartos);
            printf("Andar: %d \n", exibido->imovel.apto.andar);
            printf("Area: %.0lf m² \n", exibido->imovel.apto.area);
            printf("Posicao: %s \n", exibido->imovel.apto.posicao);
            printf("Preco do condominio: R$ %.2lf \n", exibido->imovel.apto.precoCondominio);
            printf("Vagas na garagem: %d \n", exibido->imovel.apto.vagasGaragem);
            break;
        case TERRENO:
            printf("Area: %lf m² \n", exibido->imovel.terreno.area);
            break;
    }

    printf("Cidade: %s \n", exibido->endereco.cidade);
    printf("Bairro: %s \n", exibido->endereco.bairro);
    printf("Endereco: %s, %d\n", exibido->endereco.logradouro, exibido->endereco.numero);
    printf("CEP: %d \n", exibido->endereco.cep);

}

int buscaPorTitulo(){
    int i;
    char titulo[MAX_TAMANHO];
    printf("Digite o Título: ");
    fgets(titulo,MAX_TAMANHO,stdin);
    TiraBarraN(titulo);

    for (i = 0; !listaImoveis[i].ultimo; i++){
        if(!(strcmp(titulo, listaImoveis[i].titulo))){
            printf("==========================================================================\n");
            exibeImovel(&listaImoveis[i]);
            printf("==========================================================================\n");
            return i;
        }
    }

    puts("Título não encontrado.");
    printf("Voltando ao menu principal\n");
    esperar(2);
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
            printf("==========================================================================\n");
            exibeImovel(&listaImoveis[i]);
            printf("==========================================================================\n");
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
        if(listaImoveis[i].preco >= valor){
            printf("==========================================================================\n");
            exibeImovel(&listaImoveis[i]);
            printf("==========================================================================\n");
        }
    }

    puts("Não existem imoveis acima desse valor.");
}

void separador(){
    printf("==========================================================================\n");
}

void exibeTudo(){
    for(int i = 0; !(listaImoveis[i].ultimo); i++){
        separador();
        exibeImovel(&listaImoveis[i]);
        separador();
    }
}

void buscaDisponibTipo(int disp, int tipo){
    if(disp == 2){
        disp = VENDA;
    }else if(disp == 3){
        disp = ALUGUEL;
    }
    for(int i = 0; !listaImoveis[i].ultimo; i++){
        if(listaImoveis[i].disponibilidade == disp && listaImoveis[i].tipo == tipo){
            exibeImovel(&listaImoveis[i]);
            separador();
        }

    }
}

void Menu(){
    int opcao, subopcao, subsubopcao, verificacao;
    int imovelEscolhido;
    while (1){
        limpaTela();
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
                limpaTela();
                countC++;
                cadastraImoveis();
                break;
            case 2:
                limpaTela();
                ExibeSubmenu();
                printf("Digite a opcao desejada: ");
                scanf("%d%*c", &subopcao);
                if (subopcao == 7){
                    break;
                }

                switch (subopcao){
                    case 1:
                        limpaTela();
                        cabecalho();
                        exibeTudo();
                        printf("Para voltar digite 1\n");
                        scanf("%d%*c", &verificacao);
                        if (verificacao == 1)
                            break;
                    case 2: //Venda
                    case 3: //Aluguel
                        limpaTela();
                        ExibeSubSubMenu2();
                        printf("Digite a opcao desejada: ");
                        scanf("%d%*c", &subsubopcao);

                        if (subsubopcao == 4){
                            break;
                        }
                        else if(subsubopcao > 4 || subsubopcao < 1){
                            puts("Opcao invalida");
                            break;
                        }
                        limpaTela();
                        cabecalho();
                        buscaDisponibTipo(subopcao, subsubopcao);
                        printf("Para voltar digite 1\n");
                        scanf("%d%*c", &verificacao);
                        if (verificacao == 1)
                            break;
                    case 4:
                        limpaTela();
                        cabecalho();
                        buscaPorTitulo();
                        printf("Para voltar digite 1\n");
                        scanf("%d%*c", &verificacao);
                        if (verificacao == 1)
                            break;
                    case 5:
                        limpaTela();
                        cabecalho();
                        buscaPorBairro();
                        printf("Para voltar digite 1\n");
                        scanf("%d%*c", &verificacao);
                        if (verificacao == 1)
                            break;
                    case 6:
                        limpaTela();
                        cabecalho();
                        buscaPorValor();
                        printf("Para voltar digite 1\n");
                        scanf("%d%*c", &verificacao);
                        if (verificacao == 1)
                            break;
                    default:
                        puts("Opcao invalida");
                        break;
                }
                break;
            case 3:
                countD++;
                limpaTela();
                cabecalho();
                removeImovel();
                break;
            case 4:
                countE++;
                limpaTela();
                cabecalho();
                if( (imovelEscolhido=buscaPorTitulo())>0){
                    printf("Deseja realmente editar o imovel?\n");
                    escolha();
                    scanf("%d",&verificacao);
                    limpaTela();
                    if(verificacao==1)
                        editaCadastro(imovelEscolhido);
                    printf("Edicao concluida!\nVoltando ao menu principal\n");
                    esperar(2);
                }
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

    puts("Cadastro concluido!\nVoltando ao menu principal.");
    esperar(2);
    listaImoveis[i].ultimo = 0;
    listaImoveis[i+1].ultimo = 1;
}

void editaCadastro(int i){
    int  opcaoTipo = 0, opcaoDisp = 0;

    //aluguel ou venda?
    while (opcaoDisp == 0) {
        cabecalho();
        puts("O imovel esta disponivel para aluguel ou venda?");
        puts("\t1 - Aluguel");
        puts("\t2 - Venda");
        printf("Digite a opcao desejada: ");
        scanf("%d%*c", &opcaoDisp);
        listaImoveis[i].disponibilidade = opcaoDisp;

        if(opcaoDisp != 1 && opcaoDisp != 2){
            puts("Opcao invalida");
            opcaoDisp = 0;
            limpaTela();
        }
    }

    printf("Digite o titulo: ");
    fgets(listaImoveis[i].titulo, MAX_TAMANHO, stdin);
    TiraBarraN(listaImoveis[i].titulo);
    printf("Digite o preco: ");
    scanf("%lf", &listaImoveis[i].preco);
    esperar(1);
    limpaTela();
    while (opcaoTipo == 0) {
        ExibeSubSubMenu1();
        printf("Digite o tipo de imovel: ");
        scanf("%d%*c", &opcaoTipo);
        listaImoveis[i].tipo = opcaoTipo;
        limpaTela();
        cabecalho();
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
                scanf("%lf%*c", &listaImoveis[i].imovel.apto.precoCondominio);
                printf("Digite a posicao do apartamento: ");
                fgets(listaImoveis[i].imovel.apto.posicao, MAX_TAMANHO, stdin);
                TiraBarraN(listaImoveis[i].imovel.apto.posicao);
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
    puts("0- Nao");
    puts("1- Sim");
}
void removeImovel(){
    int c, i, j;
    i = buscaPorTitulo();
    if(i != -1){
        printf("Deseja realmente excluir o imovel?\n");
        while(1){
            escolha();
            scanf("%d",&c);
            if(c==0){
                ExibeMenu();
                break;
            }
            if(c==1)
            {
                for(j = i; j < MAX_TAMANHO; j++){
                    listaImoveis[j] = listaImoveis[j+1];
                }
                puts("Imovel excluido com sucesso!");
                break;
            }

        }
    }
}
void limpaTela(){
    printf("\e[H\e[2J");
}
void cabecalho(){
    printf("==========================================================================\n"
           "||\t\t   Sistema de gerenciamento de imoveis       \t\t||"
           "==========================================================================\n");
}
void esperar(int segundos){
    clock_t fim;
    fim = clock () + segundos * CLOCKS_PER_SEC;
    while (clock() < fim) {}
}
