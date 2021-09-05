#include <stdio.h>
#include <stdlib.h>

int main()
{

    char nome_da_pecas[6][10] = {"Mancal", "Biela", "Frange", "Pistao", "Anel", "Bloco"};
    char setor[4][8] = {"Setor1","Setor2","Setor3","Setor4"};
    float preco_pecas[6][4]= {678,200,100,90,50,340,120,89,12,20,55,56,190,456,300,230,234,120,80,100,2000,1890,1000,800};
    float valor_total_peca[6], valor_total_setor[6];
    int i,j;

    for(i=0; i<6; i++)
    {
        for(j=0; j<4; j++)
        {
            valor_total_peca[i]+=preco_pecas[i][j];
        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<6; j++)
        {
            valor_total_setor[i]+=preco_pecas[j][i];
        }
    }

    printf("\n ---------------------------- RELATORIO  ---------------------------------");
    printf("\n -------------------------------------------------------------------------");
    printf("\n  PECAS   |  SETOR 1   |  SETOR 2   |  SETOR 3   |  SETOR 4  |  TOTAL"  );
    printf("\n -------------------------------------------------------------------------");
    for(i=0; i<6; i++)
    {
        printf("\n ");
        printf(" %-10s", nome_da_pecas[i]);
        for(j=0; j<4; j++)
        {
            printf(" R$%-10.2f",preco_pecas[i][j]);

        }
        printf("R$%.2f",valor_total_peca[i]);
    }
    printf("\n -------------------------------------------------------------------------");

    printf("\n\n\n");
    printf("\n\t\t\t--------------------------------------------------");
    printf("\n\t\t\t SETOR 1   |  SETOR 2   |  SETOR 3   |  SETOR 4  "  );
    printf("\n -------------------------------------------------------------------------");

    printf("\n ");
    printf(" TOTAL DOS SETORES \t");
    for(i=0; i<4; i++)
    {
        printf(" R$%-10.2f", valor_total_setor[i]);
    }

    printf("\n -------------------------------------------------------------------------");

    printf("\n\n\n\n GLORIA A DEUS O/ \n\n By SABRINA SILVA \n\n\n\n");

    system("pause");

}
