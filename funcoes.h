#define MAX_TAMANHO 100

void cadastraImoveisAdm();
void cadastraImoveisUsuario();
int editaCadastroAdm(int);
int editaCadastroUsuario(int);
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
int MenuAdm(int);
int MenuUsuario();
void escolha();
void limpaTela();
void cabecalho();
void cabecalhoAdm();
void cabecalhoUsuario();
void esperar(int);
void cep();
void verificaStr();
int buscaPorTitulo();
int tituloExiste(char[]);
double inputValor();
int inputInteiro();
void lerArquivoUsuarios();
void salvaAquivoUsuarios();
void tipo();
void editaCadastroU(int);
void exibeUsuario(int);
void cadastraUsuario();
int buscaUsario();
void removeUsuario();
int buscaCep();
int contarUsuarios();


enum {ALUGUEL = 1, VENDA = 2};
enum {CASA = 1, APTO = 2, TERRENO = 3};

imovel_t listaImoveis[MAX_TAMANHO];
usuario_t usuarios[MAX_TAMANHO];

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

    if( fp == NULL){
        puts("Erro ao abrir o arquivo");
        return;
    }
    else{
        fwrite(listaImoveis, sizeof(imovel_t), MAX_TAMANHO, fp);
        fclose(fp);
    }
    
}

void leImoveis(){
    FILE *fp;
    fp = fopen("imoveis.bin", "rb");
     if( fp == NULL){
        puts("Erro ao abrir o arquivo ou ainda não possui imoveis cadastrados");
        return;
    }
    else{
        fread(listaImoveis, sizeof(imovel_t), MAX_TAMANHO, fp);
        fclose(fp);
    }
}
void ExibeMenuUsuario(){
    cabecalhoUsuario();
    printf( "\t 1- Cadastrar imovel\n"
            "\t 2- Consultar imovel\n"
            "\t 3- Editar imovel\n"
            "\t 4- Sair\n");
}
void ExibeMenuAdm(){
    cabecalhoAdm();
    printf( "\t 1- Cadastrar imovel\n"
            "\t 2- Consultar imovel\n"
            "\t 3- Remover imovel\n"
            "\t 4- Editar imovel\n"
            "\t 5- Cadastrar usuario\n"
            "\t 6- Consultar usuario\n"
            "\t 7- Editar usuario\n"
            "\t 8- Remover usuario\n"
            "\t 9- Sair\n");
}
void ExibeSubmenuUsuario(){
    cabecalhoUsuario();
    printf( "\t 1- Exibir todos imoveis\n"
            "\t 2- Exibir imoveis disponiveis para venda\n"
            "\t 3- Exibir imoveis disponiveis para aluguel\n"
            "\t 4- Buscar imovel por titulo\n"
            "\t 5- Buscar imovel por bairro\n"
            "\t 6- Buscar imovel por valor minimo\n"
            "\t 7- Voltar\n");
}
void ExibeSubmenuAdm(){
    cabecalhoAdm();
    printf( "\t 1- Exibir todos imoveis\n"
            "\t 2- Exibir imoveis disponiveis para venda\n"
            "\t 3- Exibir imoveis disponiveis para aluguel\n"
            "\t 4- Buscar imovel por titulo\n"
            "\t 5- Buscar imovel por bairro\n"
            "\t 6- Buscar imovel por valor minimo\n"
            "\t 7- Voltar\n");
}
void ExibeSubSubMenu2Usuario(){
    cabecalhoUsuario();
    printf( "Voce deseja buscar um(a): \n"
            "\t 1- Casa\n"
            "\t 2- Apartamento\n"
            "\t 3- Terreno\n"
            "\t 4- Voltar\n");
}
void ExibeSubSubMenu2Adm(){
    cabecalhoAdm();
    printf( "Voce deseja buscar um(a): \n"
            "\t 1- Casa\n"
            "\t 2- Apartamento\n"
            "\t 3- Terreno\n"
            "\t 4- Voltar\n");
}
void ExibeSubSubMenu1Usuario(){
    cabecalhoUsuario();
    printf( "Voce deseja adicionar uma: \n"
            "\t 1- Casa\n"
            "\t 2- Apartamento\n"
            "\t 3- Terreno\n"
            "\t 4- Voltar\n");
}
void ExibeSubSubMenu1Adm(){
    cabecalhoAdm();
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
    printf("CEP: %s \n", exibido->endereco.cep);

}

int tituloExiste(char titulo[]){
    int i;
    for (i = 0; !listaImoveis[i].ultimo; i++){
        if(!(strcmp(titulo, listaImoveis[i].titulo))){
            return 1;
        }
    }
    return 0;
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
double inputValor(){
    float valor;
    char tempValor[MAX_TAMANHO];
    char *ptNull;
    while(1){
        fgets(tempValor, MAX_TAMANHO, stdin);
        valor = strtod(tempValor,&ptNull);
        if(valor > 0){
            break;
        }else{
            printf("Digite um Valor válido: ");
        }
    }
    return valor;
}
int inputInteiro(){
    int valor;
    char tempValor[MAX_TAMANHO];
    while(1){
        fgets(tempValor, MAX_TAMANHO, stdin);
        valor = strtol(tempValor,NULL,0);
        if(valor > 0){
            break;
        }else{
            printf("Digite um Valor válido: ");
        }
    }
    return valor;
}
void buscaPorValor(){
    int i,j,count;
    float valor;
    char tempValor[MAX_TAMANHO];
    char *ptNull;
    printf("Digite o Valor: ");
    valor = inputValor();   
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

int MenuAdm(int param){
    int opcao, subopcao, subsubopcao, verificacao, aux;
    int imovelEscolhido;
    while (1){
        limpaTela();
        ExibeMenuAdm();
        printf("Digite a opcao desejada: ");
        opcao=inputInteiro();
        if (opcao == 9){
            if((countC + countD + countE) > 0){
                puts("Deseja salvar suas alterações?");
                escolha();
                scanf("%d",&opcao);
                if(opcao){
                    salvaImoveis();
                    puts("Alterações salvas com sucesso!");
                }
            }
            return 5;
            break;
            
        }
        switch (opcao){
            case 1:
                limpaTela();
                countC++;
                cadastraImoveisAdm();
                break;
            case 2:
                limpaTela();
                ExibeSubmenuAdm();
                printf("Digite a opcao desejada: ");
                subopcao=inputInteiro();
                if (subopcao == 7){
                    break;
                }

                switch (subopcao){
                    case 1:
                        limpaTela();
                        cabecalhoAdm();
                        exibeTudo();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 2: //Venda
                    case 3: //Aluguel
                        limpaTela();
                        ExibeSubSubMenu2Adm();
                        printf("Digite a opcao desejada: ");
                        subsubopcao=inputInteiro();

                        if (subsubopcao == 4){
                            break;
                        }
                        else if(subsubopcao > 4 || subsubopcao < 1){
                            puts("Opcao invalida");
                            break;
                        }
                        limpaTela();
                        cabecalhoAdm();
                        buscaDisponibTipo(subopcao, subsubopcao);
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 4:
                        limpaTela();
                        cabecalhoAdm();
                        buscaPorTitulo();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 5:
                        limpaTela();
                        cabecalhoAdm();
                        buscaPorBairro();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 6:
                        limpaTela();
                        cabecalhoAdm();
                        buscaPorValor();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
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
                cabecalhoAdm();
                removeImovel();
                break;
            case 4:
                countE++;
                limpaTela();
                cabecalhoAdm();
                imovelEscolhido = buscaPorTitulo();
                if( imovelEscolhido > 0){
                    printf("Deseja realmente editar o imovel?\n");
                    escolha();
                    verificacao=inputInteiro();
                    limpaTela();
                    if(verificacao==1)
                        editaCadastroAdm(imovelEscolhido);
                    printf("Edicao concluida!\nVoltando ao menu principal\n");
                    esperar(2);
                }
                break;
            case 5:
                verificacao = 0;
                limpaTela();
                cabecalhoAdm();
                cadastraUsuario();
                salvaAquivoUsuarios();
                printf("Para voltar digite 1\n");
                    verificacao=inputInteiro();
                    if (verificacao == 1){
                        break;
                    }
            case 6:
                verificacao = 0;
                limpaTela();
                cabecalhoAdm();
                for (int i=0; i<param; i++){
                    exibeUsuario(i);
                }
                printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
            case 7: 
                verificacao = 0;
                limpaTela();
                cabecalhoAdm();
                aux = buscaUsario();
                printf("Insira os novos dados\n");
                editaCadastroU(aux);
                salvaAquivoUsuarios();
                printf("Para voltar digite 1\n");
                verificacao=inputInteiro();
                if (verificacao == 1)
                    break;
            case 8:
                verificacao = 0;
                limpaTela();
                cabecalhoAdm();
                removeUsuario();
                salvaAquivoUsuarios();
                printf("Para voltar digite 1\n");
                verificacao=inputInteiro();
                if (verificacao == 1)
                    break;
            default:
                puts("Opcao invalida");
                break;
        }
    }
}
int MenuUsuario(){
    int opcao, subopcao, subsubopcao, verificacao;
    int imovelEscolhido;
    while (1){
        limpaTela();
        ExibeMenuUsuario();
        printf("Digite a opcao desejada: ");
        opcao=inputInteiro();
        if (opcao == 4){
            if((countC + countD + countE) > 0){
                puts("Deseja salvar suas alterações?");
                escolha();
                scanf("%d",&opcao);
                if(opcao){
                    salvaImoveis();
                    puts("Alterações salvas com sucesso!");
                }
            }
            return 5;
            break;
            
        }
        switch (opcao){
            case 1:
                limpaTela();
                countC++;
                cadastraImoveisUsuario();
                break;
            case 2:
                limpaTela();
                ExibeSubmenuUsuario();
                printf("Digite a opcao desejada: ");
                subopcao=inputInteiro();
                if (subopcao == 7){
                    break;
                }

                switch (subopcao){
                    case 1:
                        limpaTela();
                        cabecalhoUsuario();
                        exibeTudo();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 2: //Venda
                    case 3: //Aluguel
                        limpaTela();
                        ExibeSubSubMenu2Usuario();
                        printf("Digite a opcao desejada: ");
                        subsubopcao=inputInteiro();

                        if (subsubopcao == 4){
                            break;
                        }
                        else if(subsubopcao > 4 || subsubopcao < 1){
                            puts("Opcao invalida");
                            break;
                        }
                        limpaTela();
                        cabecalhoUsuario();
                        buscaDisponibTipo(subopcao, subsubopcao);
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 4:
                        limpaTela();
                        cabecalhoUsuario();
                        buscaPorTitulo();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 5:
                        limpaTela();
                        cabecalhoUsuario();
                        buscaPorBairro();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 6:
                        limpaTela();
                        cabecalhoUsuario();
                        buscaPorValor();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    default:
                        puts("Opcao invalida");
                        break;
                }
                break;
            case 3:
                countE++;
                limpaTela();
                cabecalhoUsuario();
                imovelEscolhido = buscaPorTitulo();
                if( imovelEscolhido > 0){
                    printf("Deseja realmente editar o imovel?\n");
                    escolha();
                    verificacao=inputInteiro();
                    limpaTela();
                    if(verificacao==1)
                        editaCadastroUsuario(imovelEscolhido);
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

void cadastraImoveisAdm(){
    int i = 0;
    while(!listaImoveis[i].ultimo){
        i++;
    }
    if(editaCadastroAdm(i) == 0) {
        puts("Cadastro concluido!\nVoltando ao menu principal.");
        esperar(2);
        listaImoveis[i].ultimo = 0;
        listaImoveis[i + 1].ultimo = 1;
    }else{
        puts("Voltando ao menu principal.");
    }
}
void cadastraImoveisUsuario(){
    int i = 0;
    while(!listaImoveis[i].ultimo){
        i++;
    }
    if(editaCadastroUsuario(i) == 0) {
        puts("Cadastro concluido!\nVoltando ao menu principal.");
        esperar(2);
        listaImoveis[i].ultimo = 0;
        listaImoveis[i + 1].ultimo = 1;
    }else{
        puts("Voltando ao menu principal.");
    }
}

int editaCadastroUsuario(int i){
    int  opcaoTipo = 0, opcaoDisp = 0;
    char tempValor[MAX_TAMANHO];
    float valor;
    //aluguel ou venda?
    while (opcaoDisp == 0) {
        cabecalhoUsuario();
        puts("O imovel esta disponivel para aluguel ou venda?");
        puts("\t1 - Aluguel");
        puts("\t2 - Venda");
        printf("Digite a opcao desejada: ");
        opcaoDisp=inputInteiro();
        listaImoveis[i].disponibilidade = opcaoDisp;

        if(opcaoDisp != 1 && opcaoDisp != 2){
            puts("Opcao invalida");
            opcaoDisp = 0;
            limpaTela();
        }
    }

    printf("Digite o titulo: ");
    verificaStr(listaImoveis[i].titulo);
    while(tituloExiste(listaImoveis[i].titulo)){
        puts("Esse titulo já está em uso, por favor digite outro titulo: ");
        fgets(listaImoveis[i].titulo, MAX_TAMANHO, stdin);
        TiraBarraN(listaImoveis[i].titulo);
    }

    printf("Digite o Valor: ");
    listaImoveis[i].preco=inputValor();
    esperar(1);
    limpaTela();
    while (opcaoTipo == 0) {
        ExibeSubSubMenu1Usuario();
        printf("Digite o tipo de imovel: ");
        opcaoTipo=inputInteiro();
        listaImoveis[i].tipo = opcaoTipo;
        limpaTela();
        cabecalhoAdm();
        switch (opcaoTipo) {
            case CASA:
                printf("Digite o numero de quartos: ");
                listaImoveis[i].imovel.casa.numQuartos = inputInteiro();
                printf("Digite o numero de pavimentos: ");
                listaImoveis[i].imovel.casa.numPavimentos = inputInteiro();
                printf("Digite a area do terreno: ");
                listaImoveis[i].imovel.casa.areaTerreno = inputValor();
                printf("Digite a area construida: ");
                listaImoveis[i].imovel.casa.areaConstruida =  inputValor();
                break;
            case APTO:
                printf("Digite o numero de quartos: ");
                listaImoveis[i].imovel.apto.numQuartos = inputInteiro() ;

                printf("Digite a quantidade de vagas na garagem: ");
                listaImoveis[i].imovel.apto.vagasGaragem = inputInteiro();

                printf("Digite o preco do condominio: ");
                listaImoveis[i].imovel.apto.precoCondominio = inputValor();

                printf("Digite a posicao do apartamento: ");
                verificaStr(listaImoveis[i].imovel.apto.posicao);

                printf("Digite a area do apartamento: ");
                listaImoveis[i].imovel.apto.area = inputValor();

                printf("Digite o andar: ");
                listaImoveis[i].imovel.apto.andar = inputInteiro();
                break;
            case TERRENO:
                printf("Digite a area do terreno: ");
                listaImoveis[i].imovel.terreno.area = inputValor();
                break;
            case 4://Voltar
                puts("Operacao cancelada.");
                return -1;
            default:
                puts("Opção invalida.");
                opcaoTipo = 0;
                break;
        }
    }

    printf("Digite o CEP(Sem o digito): ");
    cep(i);
    if(!(buscaCep(listaImoveis[i].endereco.cep,i))){
        printf("Digite o numero: ");
        listaImoveis[i].endereco.numero = inputInteiro();
    }
    else{
        puts("Não encontramos o cep em nosso banco de dados!");
        printf("Digite a cidade: ");
        verificaStr(listaImoveis[i].endereco.cidade);

        printf("Digite o bairro: ");
        verificaStr(listaImoveis[i].endereco.bairro);

        printf("Digite a rua: ");
        verificaStr(listaImoveis[i].endereco.logradouro);

        printf("Digite o numero: ");
        listaImoveis[i].endereco.numero = inputInteiro();
    }
    

    return 0;
}
int editaCadastroAdm(int i){
    int  opcaoTipo = 0, opcaoDisp = 0;
    char tempValor[MAX_TAMANHO];
    float valor;
    //aluguel ou venda?
    while (opcaoDisp == 0) {
        cabecalhoAdm();
        puts("O imovel esta disponivel para aluguel ou venda?");
        puts("\t1 - Aluguel");
        puts("\t2 - Venda");
        printf("Digite a opcao desejada: ");
        opcaoDisp=inputInteiro();
        listaImoveis[i].disponibilidade = opcaoDisp;

        if(opcaoDisp != 1 && opcaoDisp != 2){
            puts("Opcao invalida");
            opcaoDisp = 0;
            limpaTela();
        }
    }

    printf("Digite o titulo: ");
    verificaStr(listaImoveis[i].titulo);
    while(tituloExiste(listaImoveis[i].titulo)){
        puts("Esse titulo já está em uso, por favor digite outro titulo: ");
        fgets(listaImoveis[i].titulo, MAX_TAMANHO, stdin);
        TiraBarraN(listaImoveis[i].titulo);
    }

    printf("Digite o Valor: ");
    listaImoveis[i].preco=inputValor();
    esperar(1);
    limpaTela();
    while (opcaoTipo == 0) {
        ExibeSubSubMenu1Adm();
        printf("Digite o tipo de imovel: ");
        opcaoTipo=inputInteiro();
        listaImoveis[i].tipo = opcaoTipo;
        limpaTela();
        cabecalhoAdm();
        switch (opcaoTipo) {
            case CASA:
                printf("Digite o numero de quartos: ");
                listaImoveis[i].imovel.casa.numQuartos = inputInteiro();
                printf("Digite o numero de pavimentos: ");
                listaImoveis[i].imovel.casa.numPavimentos = inputInteiro();
                printf("Digite a area do terreno: ");
                listaImoveis[i].imovel.casa.areaTerreno = inputValor();
                printf("Digite a area construida: ");
                listaImoveis[i].imovel.casa.areaConstruida =  inputValor();
                break;
            case APTO:
                printf("Digite o numero de quartos: ");
                listaImoveis[i].imovel.apto.numQuartos = inputInteiro() ;

                printf("Digite a quantidade de vagas na garagem: ");
                listaImoveis[i].imovel.apto.vagasGaragem = inputInteiro();

                printf("Digite o preco do condominio: ");
                listaImoveis[i].imovel.apto.precoCondominio = inputValor();

                printf("Digite a posicao do apartamento: ");
                verificaStr(listaImoveis[i].imovel.apto.posicao);

                printf("Digite a area do apartamento: ");
                listaImoveis[i].imovel.apto.area = inputValor();

                printf("Digite o andar: ");
                listaImoveis[i].imovel.apto.andar = inputInteiro();
                break;
            case TERRENO:
                printf("Digite a area do terreno: ");
                listaImoveis[i].imovel.terreno.area = inputValor();
                break;
            case 4://Voltar
                puts("Operacao cancelada.");
                return -1;
            default:
                puts("Opção invalida.");
                opcaoTipo = 0;
                break;
        }
    }

    printf("Digite o CEP(Sem o digito): ");
    cep(i);
    if(!(buscaCep(listaImoveis[i].endereco.cep,i))){
        printf("Digite o numero: ");
        listaImoveis[i].endereco.numero = inputInteiro();
    }
    else{
        puts("Não encontramos o cep em nosso banco de dados!");
        printf("Digite a cidade: ");
        verificaStr(listaImoveis[i].endereco.cidade);

        printf("Digite o bairro: ");
        verificaStr(listaImoveis[i].endereco.bairro);

        printf("Digite a rua: ");
        verificaStr(listaImoveis[i].endereco.logradouro);

        printf("Digite o numero: ");
        listaImoveis[i].endereco.numero = inputInteiro();
    }
    

    return 0;
}
int buscaCep(char *str,int i){
    FILE *fp;

    char cep1[MAX_TAMANHO], linha[2000];
    char *tok,*estado,*cidade,*rua,*cep,*bairro;

    int c, t=0;

    char *id;

    fp = fopen("ceps.csv","r");

    if(!fp){
        puts("Erro ao abrir");
        return 1;
    }
    while(1){
        fgets(linha,2000,fp);
        if(feof(fp))
            break;
        c=0;
        tok=strtok(linha,";");
        cep=tok;

        if(strcmp(tok,str)==0){
            estado=strtok(NULL,";");
            c++;
            cidade=strtok(NULL,";");
            strcpy(listaImoveis[i].endereco.cidade,cidade);
            c++;
            bairro=strtok(NULL,";");
            strcpy(listaImoveis[i].endereco.bairro,bairro);
            c++;
            rua=strtok(NULL,";");
            strcpy(listaImoveis[i].endereco.logradouro,rua);
            TiraBarraN(listaImoveis[i].endereco.logradouro);
            c++;
        }
        if(c==4){
        	printf("Cidade: %s\n",listaImoveis[i].endereco.cidade);
    		printf("Bairro: %s\n",listaImoveis[i].endereco.bairro);
    		printf("Logradouro: %s\n",listaImoveis[i].endereco.logradouro);
            return 0;
        }
        
    }
    fclose(fp);
   
    return 1;
}
void verificaStr(char *str){

    int j,count = 0;
    while(1){
        fgets(str, MAX_TAMANHO, stdin);
        TiraBarraN(str);
        for (j = 0; j <=strlen(str); j++)
        {
           if(!(isspace(str[j])) && str[j]!='\0')
                count++;
        }
        if(count > 0)
            break;
        else
            printf("Digite um caractere válido:");
    }

}
void cep(int i){
    int j,count = 0;

    while(1){

    fgets(listaImoveis[i].endereco.cep,MAX_TAMANHO,stdin);
    TiraBarraN(listaImoveis[i].endereco.cep);

    if(strlen(listaImoveis[i].endereco.cep)==8){

        for(j = 0;j <= (strlen(listaImoveis[i].endereco.cep));j++){

            if(isdigit(listaImoveis[i].endereco.cep[j]))
                count++;
        }
    }
    if(count==8)
        break;
    else
        printf("Digite um  cep válido:");
    }
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
            c=inputInteiro();
            if(c==0){
                ExibeMenuAdm();
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
void cabecalhoAdm(){
    printf("==========================================================================\n"
           "||\t\t   Sistema de gerenciamento de imoveis       \t\t||"
           "==========================================================================\n"
           "\t\t\t\t\t\t            Administrador\n");
}
void cabecalhoUsuario(){
    printf("==========================================================================\n"
           "||\t\t   Sistema de gerenciamento de imoveis       \t\t||"
           "==========================================================================\n"
           "\t\t\t\t\t\t            Usuario\n");
}
void esperar(int segundos){ //retirar essa função depois
    clock_t fim;
    fim = clock () + segundos * CLOCKS_PER_SEC;
    while (clock() < fim) {
        int x = 0;
        x++;
    }
}
void logon(int i){
    login_t entrada;
    int j, k=0;
    while(1){
        limpaTela();
        cabecalho();
        printf("\n\n\n\t\t\tUsuario: ");
        fgets(entrada.login, MAX_TAMANHO, stdin);
        TiraBarraN(entrada.login);
        for(j=0; j<i; j++){
            if(strcmp(entrada.login, usuarios[j].login) == 0){
                printf("\t\t\tSenha: ");
                fgets(entrada.senha, MAX_TAMANHO, stdin);
                TiraBarraN(entrada.senha);
                    if(strcmp(entrada.senha, usuarios[j].senha) == 0){
                        printf("%d", j);
                        if(strcmp(usuarios[j].tipo, "Administrador")==0){
                            k = MenuAdm(i);
                        }
                        if(strcmp(usuarios[j].tipo, "Usuario")== 0){
                            k = MenuUsuario();
                        }
                    }
            }
        }
        //printf ("%d %d %d\n", j, i, k);
        if (k==5){
            break;
        }
        if(j>=i){
            printf("\t\t\tCredenciais invalidas\n");
            esperar(2);
        }
        
    }
    
}
void lerArquivoUsuarios(){
	FILE *fp;
	fp = fopen("usuarios.bin","rb");

	if( fp == NULL){
        puts("Erro ao abrir o arquivo");
        return;
    }
    else{
	fread(usuarios,sizeof(usuario_t),MAX_TAMANHO,fp);

	fclose(fp);
	}
}
void salvaAquivoUsuarios(){
	FILE *fp;
	fp = fopen("usuarios.bin","wb");

	 if( fp == NULL){
        puts("Erro ao abrir o arquivo");
        return;
    }
    else{
	fwrite(usuarios,sizeof(usuario_t),MAX_TAMANHO,fp);

	fclose(fp);
	}
}
void tipo(){
	puts("Deseja cadastrar o usuario como:");
	puts("1- Administrador");
	puts("2- Comum");
}
void editaCadastroU(int i){
	int opcao=0;

	printf("Nome:");
	fgets(usuarios[i].nome,MAX_TAMANHO,stdin);
	TiraBarraN(usuarios[i].nome);

	printf("Login:");
	fgets(usuarios[i].login,MAX_TAMANHO,stdin);
	TiraBarraN(usuarios[i].login);

	printf("Senha:");
	fgets(usuarios[i].senha,MAX_TAMANHO,stdin);
	TiraBarraN(usuarios[i].senha);

    while (opcao == 0) {
        limpaTela();
        cabecalhoAdm();
        puts("Deseja cadastrar como Administrador ou Usuario?");
        puts("\t1 - Administrador");
        puts("\t2 - Usuario");
        printf("Digite a opcao desejada: ");
        opcao=inputInteiro();
        
        if(opcao==2){
			strcpy(usuarios[i].tipo,"Usuario");
			break;
		}
		if(opcao==1){
			strcpy(usuarios[i].tipo,"Administrador");
			break;
		}
        if(opcao != 1 && opcao != 2){
            puts("Opcao invalida");
            opcao = 0;
            limpaTela();
        }
    }
}
void exibeUsuario(int i){
	printf("==========================================================================\n");
	printf("Nome: %s\n",usuarios[i].nome);
	printf("Login: %s\n",usuarios[i].login);
	printf("Senha: %s\n",usuarios[i].senha);
	printf("Tipo: %s\n",usuarios[i].tipo);
	printf("==========================================================================\n");
}
void cadastraUsuario(){
	int i;
	for(i=0;!(usuarios[i].ultimo);i++){}
		//puts("cheguei"); //Enquanto usuario não é 1, faça i++;
			
	editaCadastroU(i);

	usuarios[i].ultimo = 0;
	usuarios[i+1].ultimo = 1;

	puts("Cadastro realizado com sucesso!");

}
int buscaUsario(){
	int i;
	char nome[MAX_TAMANHO];
	printf("Nome:");
	fgets(nome,MAX_TAMANHO,stdin);
	TiraBarraN(nome);
	for (i = 0; !usuarios[i].ultimo; i++){
        if(!(strcmp(nome, usuarios[i].nome))){
            printf("==========================================================================\n");
            exibeUsuario(i);
            printf("==========================================================================\n");
            return i;
        }
    }

}
void removeUsuario(){
	
	int i,j,opcao;
	i= buscaUsario();

	if(i != -1){
		puts("Deseja realmente excluir o usuario?");
		while(1){
			escolha();
			scanf("%d",&opcao);
			if(opcao==0){
				//Coloque aqui a função exibe menu de admin
				break;
			}
			if(opcao==1){
				for(j = i; j < MAX_TAMANHO;j++){
					 usuarios[j] = usuarios[j+1];
				}
				puts("Usuario removido com sucesso");
				break;	
			}
			
		}

	}

}
int contarUsuarios(){
    int i=0;
        for (i=0; i<MAX_TAMANHO; i++){
        if(strcmp(usuarios[i].login, "" )){
            //exibeUsuario(i);
        }else{
            break;
        }
    }
    return i;
}
