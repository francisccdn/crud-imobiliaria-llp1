#include "Front.h"
#include "menu.h"

void Front::menu(Imobiliaria &imob )
{
    int opcao, subopcao, subsubopcao, verificacao, aux;
    int imovelEscolhido;
    double valor;
    string name1, name2;
    GerenciadorDeTexto str;
    Apartamento ap;
    Casa c1;
    Terreno t1;
    Casa *ptrC1 = &c1;
    Apartamento *ptrAp = &ap;
    Terreno *ptrT1 = &t1;
    int disp;
    char tipo;
    int tip;
    int num;
    //listaImoveis = imob.getImoveis();
    while (1)
    {
        limpaTela();
        ExibeMenu();
        printf("Digite a opcao desejada: ");
        cin >> opcao;
        if (opcao == 7)
        {
            break;
        }
        if(opcao>7 || opcao<0){
            puts("Opcao invalida");
            break;
        }
        switch (opcao)
        {
        case 1: //Cadastra imoveis
            limpaTela();
            while (1)
            {
                cabecalho();
                printf("Voce deseja adicionar um(a): \n"
                       "\t 1- Apartamento\n"
                       "\t 2- Casa\n"
                       "\t 3- Terreno\n"
                       "\t 4- Voltar\n");
                tip = inputInteiro();
                if (tip > 0 || tip < 5){
                    puts("Opcao invalida");
                    break;
                }
            }
            switch (tip)
            {
            case APTO:

                ap.setTipo('0');
                ap.setTitulo(inputStr("Digite o titulo: "));
                while (1)
                {
                    limpaTela();
                    cabecalho();
                    puts("O imovel esta disponivel para?");
                    puts("\t1 - Aluguel");
                    puts("\t2 - Venda");

                    cin >> disp;
                    cin.ignore();
                    if (disp == 1 || disp == 2)
                        break;
                    puts("Opcao invalida");
                }
                ap.setDisponibilidade(disp == 1 ? false : true);
                cout << "Digite o valor: " << endl;
                ap.setValor(inputValor());
                printf("Digite o numero de quartos: ");
                ap.setNumQuartos(inputInteiro());
                printf("Digite a quantidade de vagas na garagem: ");
                ap.setNumVagas(inputInteiro());
                printf("Digite o preco do condominio: ");
                ap.setValorCondominio(inputValor());
                ap.setPosicao(inputStr("Digite a posicao do apartamento: "));
                printf("Digite a area do apartamento: ");
                ap.setArea(inputValor());
                printf("Digite o andar: ");
                ap.setAndar(inputInteiro());
                //printf("Digite o CEP(Sem o digito): ");
                //cep(ap);
                ap.endereco.setCidade(inputStr("Digite a cidade: "));
                ap.endereco.setBairro(inputStr("Digite o bairro: "));
                ap.endereco.setLogradouro(inputStr("Digite a rua: "));
                printf("Digite o numero: ");
                num = inputInteiro();
                ap.endereco.setNumero(num);
                imob.cadastraImovel(ptrAp);
                break;
            case CASA:
                c1.setTipo('1');
                c1.setTitulo(inputStr("Digite o titulo: "));
                while (1)
                {
                    puts("O imovel esta disponivel para?");
                    puts("\t1 - Aluguel");
                    puts("\t2 - Venda");
                    cin >> disp;
                    cin.ignore();
                    if (disp == 1 || disp == 2)
                        break;
                    puts("Opcao invalida");
                }
                c1.setDisponibilidade(disp == 1 ? false : true);
                cout << "Digite o valor: " << endl;
                c1.setValor(inputValor());
                printf("Digite o numero de quartos: ");
                c1.setNumQuartos(inputInteiro());
                printf("Digite o numero de pavimentos: ");
                c1.setNumPavimentos(inputInteiro());
                printf("Digite a area do terreno: ");
                c1.setArea(inputValor());
                printf("Digite a area construida: ");
                c1.setAreaConstruida(inputValor());

                //printf("Digite o CEP(Sem o digito): ");
                //cep(ap);

                c1.endereco.setCidade(inputStr("Digite a cidade: "));
                c1.endereco.setBairro(inputStr("Digite o bairro: "));
                c1.endereco.setLogradouro(inputStr("Digite a rua: "));
                printf("Digite o numero: ");
                num = inputInteiro();
                c1.endereco.setNumero(num);
                *ptrC1 = c1;
                imob.cadastraImovel(ptrC1);
                break;
            case TERRENO:
                t1.setTipo('2');
                t1.setTitulo(inputStr("Digite o titulo: "));
                while (1)
                {
                    puts("O imovel esta disponivel para?");
                    puts("\t1 - Aluguel");
                    puts("\t2 - Venda");
                    cin >> disp;
                    cin.ignore();
                    if (disp == 1 || disp == 2)
                        break;
                    puts("Opcao invalida");
                }
                t1.setDisponibilidade(disp == 1 ? false : true);
                cout << "Digite o valor: " << endl;
                t1.setValor(inputValor());
                printf("Digite a area do terreno: ");
                t1.setArea(inputValor());
                //printf("Digite o CEP(Sem o digito): ");
                //cep(ap);
                t1.endereco.setCidade(inputStr("Digite a cidade: "));
                t1.endereco.setBairro(inputStr("Digite o bairro: "));
                t1.endereco.setLogradouro(inputStr("Digite a rua: "));
                printf("Digite o numero: ");
                num = inputInteiro();
                t1.endereco.setNumero(num);
                *ptrT1=t1;
                imob.cadastraImovel(ptrT1);
                break;
            }
            break;

        case 2: //Listar imoveis
            //limpaTela();
            exibeMenuListar();
            printf("Digite a opcao desejada: ");
            subopcao = inputInteiro();
            if (subopcao == 7)
            {
                break;
            }

            switch (subopcao)
            {
            case 1:
                //limpaTela();
                cabecalho();
                outputImoveis(imob.getImoveis(), 1);
                printf("Para voltar digite 1\n");
                verificacao = inputInteiro();
                if (verificacao == 1)
                    break;
            case 2: //Exibe imoveis por  tipo
                //limpaTela();
                ExibeSubSubMenu();
                printf("Digite a opcao desejada: ");
                subsubopcao = inputInteiro();
                if (subsubopcao == 4)
                {
                    break;
                }
                switch (subsubopcao)
                {

                case 1: //Apartamento
                    //limpaTela();
                    cabecalho();
                    outputImoveis(imob.getImoveis(imob.indexPorTipo('0')), 2);
                    break;
                case 2: //Casa
                    //limpaTela();
                    cabecalho();
                    outputImoveis(imob.getImoveis(imob.indexPorTipo('1')), 2);
                    break;
                case 3: //Terreno
                    //limpaTela();
                    cabecalho();
                    outputImoveis(imob.getImoveis(imob.indexPorTipo('2')), 2);
                    break;
                default:
                    puts("Opcao invalida");
                    break;
                }
                
                printf("Para voltar digite 1\n");
                verificacao = inputInteiro();
                if (verificacao == 1)
                    break;

            case 3: //Imoveis por Disponibilidade
                //limpaTela();
                exibeMenuDisp();
                printf("Digite a opcao desejada: ");
                subsubopcao = inputInteiro();

                if (subsubopcao == 3)
                {
                    break;
                }
                else if (subsubopcao > 3 || subsubopcao < 1)
                {
                    puts("Opcao invalida");
                    break;
                }
                switch (subsubopcao)
                {
                case 1:
                    //limpaTela();
                    cabecalho();
                    outputImoveis(imob.getImoveis(imob.indexPorDisponibilidade(true)), 2);
                    break;
                case 2:
                    //limpaTela();
                    cabecalho();
                    outputImoveis(imob.getImoveis(imob.indexPorDisponibilidade(false)), 2);
                    break;
                default:
                    break;
                }
                printf("Para voltar digite 1\n");
                verificacao = inputInteiro();
                if (verificacao == 1)
                    break;
            } 
        case 3: //Buscar imoveis
            //limpaTela();
            cabecalho();
            buscar(imob);/*
        case 4: //Remover Imovel
            //limpaTela();
            cabecalho();
            buscar(listaImoveis, imob);
            printf("Para voltar digite 1\n");
            verificacao = inputInteiro();
            if (verificacao == 1)
                break;
        case 5: //Editar Imovel
            //limpaTela();
            cabecalho();
            buscar(listaImoveis, imob);
            printf("Para voltar digite 1\n");
            verificacao = inputInteiro();
            if (verificacao == 1)
                break;
        default:
            puts("Opcao invalida");
            break;*/
        }
    }
}
void Front::buscar(Imobiliaria &imob)
{
    int opcao;
    int imovelEscolhido;
    double valor;
    bool disp;
    string name1;
    string name2;
    GerenciadorDeTexto str;
    vector<int> index;
    //listaImoveis = imob.getImoveis();
    exibeMenuBuscar();
    opcao = inputInteiro();
    if (opcao == 9)
        return;
    switch (opcao)
    {
    case 1:
        name1 = inputStr("Digite o titulo: ");
        cout << name1 << endl;
        index = imob.indexPorTitulo(name1);
        if (index.empty())
            cout << "Titulo nao encontrado!" << endl;
        else
            outputImoveis(imob.getImoveis(index), 2);
        break;
    case 2:
        name1 = inputStr("Digite o Bairro: ");
        outputImoveis(imob.getImoveis(imob.indexPorBairro(name1)), 2);
        break;
    case 3:
        name1 = inputStr("Digite a cidade: ");
        outputImoveis(imob.getImoveis(imob.indexPorCidade(name1)), 2);
        break;
    case 4:
        cout << "Digite o valor: ";
        valor = inputValor();
        outputImoveis(imob.getImoveis(imob.indexPorValor(valor)), 2);
        break;
    case 5:
        name1 = inputStr("Digite o bairro:");
        cout << "Digite o valor: ";
        valor = inputValor();
        outputImoveis(imob.getImoveis(imob.combinarFiltros(imob.indexPorValor(valor), imob.indexPorBairro(name1))), 2);
        break;
    case 6:
        name1 = inputStr("Digite a cidade");
        cout << "Digite o valor: ";
        valor = inputValor();

        outputImoveis(imob.getImoveis(imob.combinarFiltros(imob.indexPorValor(valor), imob.indexPorCidade(name1))), 2);
        break;
    case 7:
        while (1)
        {
            exibeDisp();
            if (inputInteiro() != 1 || inputInteiro() != 2)
                cout << "Opcao invalida\n";
            else
            {
                disp = inputInteiro() == 1 ? true : false;
                printf("Digite o bairro: ");
                cin.ignore();
                getline(cin, name1);
                if (str.verificaStr(name1))
                    break;
            }
        }
        outputImoveis(imob.getImoveis(imob.combinarFiltros(imob.indexPorDisponibilidade(disp), imob.indexPorBairro(name1))), 2);
        break;
    case 8:
        while (1)
        {
            exibeDisp();
            if (inputInteiro() != 1 || inputInteiro() != 2)
                cout << "Opcao invalida\n";
            else
            {
                disp = inputInteiro() == 1 ? true : false;
                printf("Digite a cidade: ");
                cin.ignore();
                getline(cin, name1);
                if (str.verificaStr(name1))
                    break;
            }
        }
        outputImoveis(imob.getImoveis(imob.combinarFiltros(imob.indexPorDisponibilidade(disp), imob.indexPorCidade(name1))), 2);
        break;
    default:
        cout << "Escolha outra opcao" << endl;
    }
}
void Front::outputImovel(std::ostream &output, Imovel &imovel, int tipo)
{
    Imovel *ptr = &imovel;
    if (tipo == 1)
    {
        output << "Título: " << ptr->getTitulo() << "\n"
               << fixed << setprecision(2) << "Valor: " << ptr->getValor()<<"\n"
               << "Cidade: " << ptr->endereco.getCidade() << "\n"
               << "Bairro: " << ptr->endereco.getBairro() << "\n";
    }
    if (tipo == 2)
    {
        output << "Título: " << ptr->getTitulo() << "\n"
               << fixed << setprecision(2) << "Valor: " << ptr->getValor() << "\n"
               << "Disponibilidade: " << (ptr->getDisponiblidade() ? "Venda\n" : "Aluguel\n");
        if (ptr->getTipo() == '0')
        {
            output << "Numero de quartos: " << (((Apartamento *)ptr)->getNumQuartos()) << "\n"
                   << "Vagas na garagem: " << (((Apartamento *)ptr)->getNumVagas()) << "\n"
                   << "Andar: " << (((Apartamento *)ptr)->getAndar()) << "\n"
                   << "Area : " << (((Apartamento *)ptr)->getArea()) << "m²\n"
                   << "Posicao: " << (((Apartamento *)ptr)->getPosicao()) << "\n"
                   << "Preco do condominio: " << ((Apartamento *)ptr)->getValorCondominio() << "\n";
        }
        if (ptr->getTipo() == '1')
        {
            output << "Area construida: " << (((Casa *)ptr)->getAreaConstruida()) << "\n"
                   << "Area do terreno: " << (((Casa *)ptr)->getAreaTerreno()) << "\n"
                   << "Numero de pavimentos: " << (((Casa *)ptr)->getNumPavimentos()) << "\n"
                   << "Numero de quartos: " << (((Casa *)ptr)->getNumQuartos()) << "\n";
        }
        if (ptr->getTipo() == '2')
        {
            output << "Area: " << (((Terreno *)ptr)->getArea()) << "\n";
        }
        output << ptr->endereco.getAsString();
    }
}
void Front::outputImoveis(vector<Imovel *> lista, int tipo)
{
    cout << setw(15) << "Exibindo " << lista.size() << " imoveis\n";
    for (size_t i = 0; i < lista.size(); i++)
    {
        separador();
        cout << setw(15) << i + 1 << endl;
        separador();
        outputImovel(cout, *lista[i], tipo);
    }
}
/*vector<Imovel *> Front::getLista()
{
    return listaImoveis;
}

void cep(Apartamento &ap)
{
    Endereco endereco;
    int j, count = 0;
    char cep[MAX];
    while (1)
    {
        cin >> cep;
        if (strlen(cep) == 8)
        {

            for (j = 0; j <= (strlen(cep)); j++)
            {

                if (isdigit(cep[j]))
                    count++;
            }
        }
        if (count == 8)
        {
            buscaCep(cep, ap);
        }
        else
            printf("Digite um  cep válido:");
    }
}



void buscaCep(char *str, Apartamento &ap)
{
    FILE *fp;
    Endereco endereco;
    char cep1[MAX], linha[2000];
    char *tok, *estado, *cidade, *rua, *cep, *bairro;

    int c, t = 0;

    char *id;

    fp = fopen("ceps.csv", "r");

    if (!fp)
    {
        puts("Erro ao abrir");
        return;
    }
    while (1)
    {
        fgets(linha, 2000, fp);
        if (feof(fp))
            break;
        c = 0;
        tok = strtok(linha, ";");
        cep = tok;

        if (strcmp(tok, str) == 0)
        {
            estado = strtok(NULL, ";");
            c++;
            cidade = strtok(NULL, ";");
            ap.endereco.setCidade(cidade);
            c++;
            bairro = strtok(NULL, ";");
            ap.endereco.setBairro(bairro);
            c++;
            rua = strtok(NULL, ";");
            int tamanho = strlen(rua);
            rua[tamanho] = '\0';
            ap.endereco.setLogradouro(rua);
            c++;
        }
    }
    fclose(fp);

    return;
}*/