#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i,j;
    int matriz[3][3] = {1,2,3,4,5,6,7,8,2};
    int menor_elemento_matriz = 9999999;
    int manor_elemento_diagonal_principal = 0;
    int impar = 0;


    printf("\n VAMOS PREENCHER A MATRIZ \n\n Digite 9 numeros \n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf(" => ");
            scanf("%d", &matriz[i][j]);
        }
    }


    printf("\n MATRIZ PRINCIPAL\n");
    for(i=0; i<3; i++){
        printf("\n ");
        for(j=0; j<3; j++)
        {
            printf("%d  ",matriz[i][j]);
            if(matriz[i][j] < menor_elemento_matriz)
                menor_elemento_matriz = matriz[i][j];

            if(matriz[i][j]%2 !=0)
                impar+=matriz[i][j];
        }

    }

    for(i=0; i<3; i++){
        if(matriz[i][i] > manor_elemento_diagonal_principal)
            manor_elemento_diagonal_principal = matriz[i][i];
    }


    printf("\n\n O Maior elemento da diagonal principal e %d", manor_elemento_diagonal_principal);

    printf("\n\n O menor elemento da matriz e %d",menor_elemento_matriz);

    printf("\n\n A soma dos numeros impares e igual a %d",impar);


    printf("\n\n\n\n GLORIA A DEUS O/ \n\n By SABRINA SILVA \n\n\n\n");

    system("pause");

}
