#define MAX_TAMANHO 100

void cadastraImoveis();
int editaCadastro(int);
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


enum {ALUGUEL = 1, VENDA = 2};
enum {CASA = 1, APTO = 2, TERRENO = 3};

imovel_t listaImoveis[MAX_TAMANHO];
usuario_t usuarios[MAX_TAMANHO];
login_t entrada[MAX_TAMANHO];

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

void Menu(){
    int opcao, subopcao, subsubopcao, verificacao;
    int imovelEscolhido;
    while (1){
        limpaTela();
        ExibeMenu();
        printf("Digite a opcao desejada: ");
        opcao=inputInteiro();
        if (opcao == 5){
            if((countC + countD + countE) > 0){
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
                subopcao=inputInteiro();
                if (subopcao == 7){
                    break;
                }

                switch (subopcao){
                    case 1:
                        limpaTela();
                        cabecalho();
                        exibeTudo();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 2: //Venda
                    case 3: //Aluguel
                        limpaTela();
                        ExibeSubSubMenu2();
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
                        cabecalho();
                        buscaDisponibTipo(subopcao, subsubopcao);
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 4:
                        limpaTela();
                        cabecalho();
                        buscaPorTitulo();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 5:
                        limpaTela();
                        cabecalho();
                        buscaPorBairro();
                        printf("Para voltar digite 1\n");
                        verificacao=inputInteiro();
                        if (verificacao == 1)
                            break;
                    case 6:
                        limpaTela();
                        cabecalho();
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
                cabecalho();
                removeImovel();
                break;
            case 4:
                countE++;
                limpaTela();
                cabecalho();
                imovelEscolhido = buscaPorTitulo();
                if( imovelEscolhido > 0){
                    printf("Deseja realmente editar o imovel?\n");
                    escolha();
                    verificacao=inputInteiro();
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
    if(editaCadastro(i) == 0) {
        puts("Cadastro concluido!\nVoltando ao menu principal.");
        esperar(2);
        listaImoveis[i].ultimo = 0;
        listaImoveis[i + 1].ultimo = 1;
    }else{
        puts("Voltando ao menu principal.");
    }
}

int editaCadastro(int i){
    int  opcaoTipo = 0, opcaoDisp = 0;
    char tempValor[MAX_TAMANHO];
    float valor;
    //aluguel ou venda?
    while (opcaoDisp == 0) {
        cabecalho();
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
    valor=inputValor();
    esperar(1);
    limpaTela();
    while (opcaoTipo == 0) {
        ExibeSubSubMenu1();
        printf("Digite o tipo de imovel: ");
        opcaoTipo=inputInteiro();
        listaImoveis[i].tipo = opcaoTipo;
        limpaTela();
        cabecalho();
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

                printf("Digite a qauntidade de vagas na garagem: ");
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

    printf("Digite a cidade: ");
    verificaStr(listaImoveis[i].endereco.cidade);

    printf("Digite o bairro: ");
    verificaStr(listaImoveis[i].endereco.bairro);

    printf("Digite a rua: ");
    verificaStr(listaImoveis[i].endereco.logradouro);

    printf("Digite o numero: ");
    listaImoveis[i].endereco.numero = inputInteiro();

    printf("Digite o CEP: ");
    cep(i);

    return 0;
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

    if(strlen(listaImoveis[i].endereco.cep)==9){

        for(j = 0;j <= (strlen(listaImoveis[i].endereco.cep));j++){

            if(isdigit(listaImoveis[i].endereco.cep[j]))
                count++;
        }
        if(listaImoveis[i].endereco.cep[5]=='-')
                count++;
    }
    if(count==9)
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
void esperar(int segundos){ //retirar essa função depois
    clock_t fim;
    fim = clock () + segundos * CLOCKS_PER_SEC;
    while (clock() < fim) {
        int x = 0;
        x++;
    }
}
void logon(){
    cabecalho;
    printf("\t\t\tUsuario: ");
    fgets(entrada[0].login, MAX_TAMANHO, stdin);
    TiraBarraN(entrada[0].login);

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
	puts("1-Administrador");
	puts("2-Comum");
}
void editaCadastroU(int i){
	int opcao;

	cabecalho();

	printf("Nome:");
	fgets(usuarios[i].nome,MAX_TAMANHO,stdin);
	TiraBarraN(usuarios[i].nome);

	printf("Login:");
	fgets(usuarios[i].login,MAX_TAMANHO,stdin);
	TiraBarraN(usuarios[i].login);

	printf("Senha:");
	fgets(usuarios[i].senha,MAX_TAMANHO,stdin);
	TiraBarraN(usuarios[i].senha);

	while(1){
		tipo();
		scanf("%d",&opcao);
		if(opcao==0){
			strcpy(usuarios[i].tipo,"Comum");
			break;
		}
		if(opcao==1){
			strcpy(usuarios[i].tipo,"Administrador");
			break;
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
	for(i=0;!(usuarios[i].ultimo);i++)
		puts("cheguei"); //Enquanto usuario não é 1, faça i++;
			
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