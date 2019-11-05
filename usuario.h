#define MAX_TAMANHO 100

usuario_t usuarios[MAX_TAMANHO];


void lerArquivoUsuarios()
{
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
void salvaAquivoUsuarios()
{
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
void tipo()
{
	puts("Deseja cadastrar o usuario como:");
	puts("1-Administrador");
	puts("2-Comum");
}
void editaCadastroU(int i)
{
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
void exibeUsuario(int i)
{
	printf("==========================================================================\n");
	printf("Nome: %s\n",usuarios[i].nome);
	printf("Login: %s\n",usuarios[i].login);
	printf("Senha: %s\n",usuarios[i].senha);
	printf("Tipo: %s\n",usuarios[i].tipo);
	printf("==========================================================================\n");
}

void cadastraUsuario()
{
	int i;
	for(i=0;!(usuarios[i].ultimo);i++)
		puts("cheguei"); //Enquanto usuario não é 1, faça i++;
			
	editaCadastroU(i);

	usuarios[i].ultimo = 0;
	usuarios[i+1].ultimo = 1;

	puts("Cadastro realizado com sucesso!");

}
int buscaUsario()
{
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
void removeUsuario()
{
	
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

