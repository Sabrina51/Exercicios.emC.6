#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//STRUCT
typedef struct controle_de_estoque
{
    char codigo[5];//[10];
    char descricao[10];//[50];
    float preco_da_venda;//[5];
    float preco_da_compra;//[5];
    int quantidade;//[5];

} controle_de_estoque;

//DECLARACAO DE VARIAVEIS GLOBAIS
struct controle_de_estoque ITEN;

//PONTEIRO ARQUIVO
FILE *ptr;

//FUNCOES
cadastrar_produto()
{

    char opcao_cadastro[2];

    ptr = fopen("D:dados.txt", "ab");

    if(ptr == NULL)
    {
        printf(" ERRO NA ABERTURA DO ARQUIVO!!");
        system("pause");
    }
    else
    {
        printf(" \n --------------- CADASTRAR PRODUTOS ---------------");
        printf(" \n --------------------------------------------------\n");

        do
        {
            printf(" \n Digite o c�digo do produto: ");
            gets(ITEN.codigo);
            fflush(stdin);

            printf(" Digite a descri��o do produto: ");
            gets(ITEN.descricao);

            printf(" Digite o pre�o de compra: ");
            scanf("%f", &ITEN.preco_da_compra);

            printf(" Digite o pre�o de venda: ");
            scanf("%f", &ITEN.preco_da_venda);

            printf(" Digite a quantidade: ");
            scanf("%d", &ITEN.quantidade);
            fflush(stdin);

            fwrite(&ITEN,sizeof(controle_de_estoque),1,ptr);

            printf(" \n Deseja cadastrar outro produto? (s/n)");
            gets(opcao_cadastro);

            system("cls");
        }
        while(strcasecmp(opcao_cadastro,"n")!=0);
    }
    fclose(ptr);
}

exibir_produtos()
{

    ptr = fopen("D:dados.txt", "rb");

    if(ptr == NULL)
    {
        printf(" ERRO NA LEITURA DO ARQUIVO!!");
        system("pause");
    }
    else
    {
        printf(" \n \t\t\t PRODUTOS EM ESTOQUE \n");
        printf(" ---------------------------------------------------------------------");
        printf(" \n  C�D  |  DESCRI��O   |   COMPRA      |   VENDA       |   EM ESTOQUE\n");
        printf(" ------+--------------+---------------+---------------+---------------");

        while(fread(&ITEN,sizeof(controle_de_estoque),1,ptr))
        {
            printf("\n  %s \t",ITEN.codigo);
            printf("  %-10s \t", ITEN.descricao);
            printf("  R$%.2f \t",ITEN.preco_da_compra);
            printf("  R$%.2f \t",ITEN.preco_da_venda);
            printf("  %d unidades\t",ITEN.quantidade);
        }

        printf(" \n ---------------------------------------------------------------------\n");

        system("pause");
        system("cls");
    }
    fclose(ptr);
}

busca_de_produto()
{

    char opcao_busca[2];
    char busca_pelo_codigo[5];
    int validacao_da_busca = 0;

    printf(" \n --------------- BUSCAR PRODUTOS ---------------");
    printf(" \n -----------------------------------------------\n");

    do
    {
        ptr = fopen("D:dados.txt", "rb");

        if(ptr == NULL)
        {
            printf(" ERRO NA LEITURA DO ARQUIVO!!");
            system("pause");
        }
        else
        {
            printf(" \n Digite o c�digo do produto: ");
            gets(busca_pelo_codigo);

            while(fread(&ITEN,sizeof(controle_de_estoque),1,ptr))
            {
                if(strcasecmp(busca_pelo_codigo,ITEN.codigo)==0)
                {
                    printf(" \n ----------------------------");
                    printf("\n Descri��o - %s", ITEN.descricao);
                    printf(" \n ----------------------------");
                    printf("\n Pre�o de compra - R$%.2f",ITEN.preco_da_compra);
                    printf("\n Pre�o para venda - R$%.2f",ITEN.preco_da_venda);
                    printf("\n Quantidade - %d unidades",ITEN.quantidade);
                    printf(" \n ----------------------------");
                    validacao_da_busca = -1;
                    break;
                }
            }
            if(validacao_da_busca == 0)
                printf(" \n C�digo n�o encontrado!");

            fclose(ptr);

            printf(" \n\n Deseja buscar outro produto? (s/n)");
            gets(opcao_busca);
            system("cls");
        }
    }
    while(strcasecmp(opcao_busca,"n")!=0);
}

alterar_produto()
{

    char opcao_altearacao[2];
    char busca_pelo_codigo_altera[5];
    int controle_posicao_ponteiro=0;

    ptr = fopen("D:dados.txt", "rb+");

    if(ptr == NULL)
    {
        printf(" ERRO NA LEITURA DO ARQUIVO!!");
        system("pause");
    }
    else
    {
        fflush(stdin);
        printf(" \n Digite o c�digo do produto que deseja alterar: ");
        gets(busca_pelo_codigo_altera);
        fflush(stdin);

        fread(&ITEN,sizeof(controle_de_estoque),1,ptr);

        while(!feof(ptr) && strcasecmp(busca_pelo_codigo_altera,ITEN.codigo)!=0)
        {
            fread(&ITEN,sizeof(controle_de_estoque),1,ptr);
            controle_posicao_ponteiro++;
        }

        if(feof(ptr))
        {
            printf(" \n C�digo n�o encontrado!");
            getch();
        }
        else
        {
            fseek(ptr,controle_posicao_ponteiro*sizeof(controle_de_estoque),SEEK_SET);

            printf("\n C�digo atual - %s", ITEN.codigo);
            printf("\n Novo c�digo - ");
            gets(ITEN.codigo);
            fflush(stdin);

            printf("\n Descri��o atual- %s", ITEN.descricao);
            printf("\n Nova descri��o - ");
            gets(ITEN.descricao);

            printf("\n Pre�o de compra atual - R$%.2f",ITEN.preco_da_compra);
            printf("\n Novo pre�o de compra: ");
            scanf("%f", &ITEN.preco_da_compra);

            printf("\n Pre�o para venda - R$%.2f",ITEN.preco_da_venda);
            printf("\n Novo pre�o para venda: ");
            scanf("%f", &ITEN.preco_da_venda);

            printf("\n Quantidade - %d unidades",ITEN.quantidade);
            printf("\n Nova quantidade - ");
            scanf("%d", &ITEN.quantidade);
            fflush(stdin);

            printf("\n Salvando altera��es... ");

            fwrite(&ITEN,sizeof(controle_de_estoque),1,ptr);
            system("pause");
        }
    }
    fclose(ptr);
}

main()
{

    int opcao_menu_principal;

    setlocale(LC_ALL,"");

    do
    {
        printf(" \n --------------- MENU PRINCIPAL ---------------");
        printf(" \n -                                            - ");
        printf(" \n - CADASTRO DE PRODUTOS...................[1] -");
        printf(" \n - EXIBIR ESTOQUE.........................[2] -");
        printf(" \n - BUSCAR PRODUTOS........................[3] -");
        printf(" \n - ALTERAR PRODUTO........................[4] -");
        printf(" \n - SAIR...................................[0] -");
        printf(" \n -                                            - ");
        printf(" \n ----------------------------By Sabrina Silva -\n");

        printf(" \n Op��o: ");
        scanf("%d",&opcao_menu_principal);
        fflush(stdin);
        system("cls");

        switch(opcao_menu_principal)
        {
        case 1:
            cadastrar_produto();
            break;

        case 2:
            exibir_produtos();
            break;

        case 3:
            busca_de_produto();
            break;

        case 4:
            alterar_produto();
            break;

        default:
            printf("");

        }
    }
    while(opcao_menu_principal != 0);

    printf(" \n\n\n By Sabrina Izabel dos Santos Silva \n\n\n");
}
