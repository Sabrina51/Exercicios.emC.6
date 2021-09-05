#include <stdio.h>
#include <stdlib.h>

main()
{

    char nome_do_produto[3][10];
    int i;
    float valor_unitario[3], preco_parcial = 0, preco_por_quantidade[3];
    float quantidade_de_produtos[3];

    for(i=0;i<3;i++){
        printf("\n Qual o nome do produto? ");
        fgets(nome_do_produto[i],10,stdin);

        printf(" Quantidade do produto? ");
        scanf("%f", &quantidade_de_produtos[i]);

        printf(" Valor unitario? ");
        scanf("%f", &valor_unitario[i]);
        fflush(stdin);

        preco_por_quantidade[i] = quantidade_de_produtos[i] * valor_unitario[i];
        preco_parcial = preco_parcial + preco_por_quantidade[i];
    }

    printf("\n ----------+--------+------------+---------");
    printf("\n  PRODUTO    QUANT.   VALOR UNI.    TOTAL ");
    printf("\n ----------+--------+------------+---------");

    for(i=0;i<3;i++){
        nome_do_produto[i][strlen(nome_do_produto[i])-1] = '\0';

        printf("\n  %-10s %4.0f \t %.2f  %10.2f ", nome_do_produto[i], quantidade_de_produtos[i],valor_unitario[i],preco_por_quantidade[i]);
    }

    printf("\n ------------------------------------------");

    printf("\n  TOTAL GERAL R$ %25.2f", preco_parcial);


}
