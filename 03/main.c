#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j,op, op_menu_principal, opcao_menu,numero_da_poltrona[48];
int validacao_poltrona =0;
char poltrona[48][10], situacao[48][10];
char escolha_poltrona[2], sair_menu[2];


escolhendo_posicao_poltrona()
{

    printf("\n ESCOLHA A POSICAO DA POLTRONA");
    printf("\n-------------------------------");
    printf("\n [0]Janela \t [1]Corredor \n\n Opcao escolhida: ");
    gets(escolha_poltrona);
    system("cls");

    if(strcmp(escolha_poltrona,"0")==0)
    {
        printf("\n POLTRONAS EXISTENTES");
        for(i=0; i<24; i++)
        {
            printf("\n N.o - %d (%s): %s",i+1,poltrona[i], situacao[i]);
            numero_da_poltrona[i] = i+1;
        }
    }
    else
    {
        printf("\n POLTRONAS EXISTENTES");
        for(i=24; i<48; i++)
        {
            printf("\n N.o - %d (%s): %s",i+1,poltrona[i], situacao[i]);
            numero_da_poltrona[i] = i+1;
        }
    }
}


escolhendo_numero_poltrona()
{

    printf("\n\n Digite o numero da poltrona desejada: ");
    scanf("%d",&op);

    validar_numero_poltrona();

    for(i=0; i<48; i++)
    {
        if(op == numero_da_poltrona[i])
            strcpy(situacao[i],"Ocupado");
    }

    //printf("\n Poltrona reservada com sucesso! \n");
}

validar_numero_poltrona()
{
    for(i=0; i<48; i++)
    {
        if(op == numero_da_poltrona[i] && strcasecmp(situacao[i],"Ocupado")==0)
            //validacao_poltrona = 0;
            //else
            //validacao_poltrona = -1;

            // if(validacao_poltrona == 0)
            printf("\n Poltrona ocupada \n");
    }
}


main()
{

    for(i=0; i<24; i++)
    {
        strcpy(poltrona[i],"janela");
    }

    for(i=24; i<48; i++)
    {
        strcpy(poltrona[i],"corredor");
    }

    for(i=0; i<48; i++)
    {
        strcpy(situacao[i],"Livre");
    }


    printf("\n [0]ESCOLHER POLTRONA");
    printf("\n [1]VER LUGARES DO ONUBUS");
    printf("\n => ");
    scanf("%d", &op_menu_principal);
    fflush(stdin);

    switch(op_menu_principal)
    {
    case 0:
        do
        {
            system("cls");
            escolhendo_posicao_poltrona();

            escolhendo_numero_poltrona();

            fflush(stdin);
            printf("\n Deseja comprar outro lugar?(s/n)");
            gets(sair_menu);

        }
        while(strcasecmp(sair_menu,"s") == 0);
        break;

    case 1:
        printf("\n  1 ");

        printf("\n POLTRONAS EXISTENTES NO ONIBUS \n");
        for(i=0; i<48; i++)
        {
            printf("\n Poltrona %d (%s): %s",i+1,poltrona[i], situacao[i]);
        }
        break;

    default:
        printf("\n  entrou no padrao ");

    }

}
