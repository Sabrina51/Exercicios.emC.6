#include <stdlib.h>
#include <stdio.h>

main()
{
    int i,  posicao, count = 0;
    char op[2], nome_inputado[10], nomes[10][10];


    printf("\n Digite os nomes: \n\n");
    for(i=0; i<10; i++)
    {
        printf(" => ");
        fgets(nomes[i],15,stdin);
    }

    do
    {
        printf("\n Digite o nome que desaja saber a posicao: ");
        fgets(nome_inputado,15,stdin);

        for(i=0; i<10; i++)
        {
            if(strcmp(nomes[i], nome_inputado)==0)
            {
                count = -1;
                posicao = i;
                break;
            }
            else
                count++;
        }

        if(count == -1)
            printf("\n O nome buscado se encontra na posicao [%d] \n",posicao);

        else
            printf("\n **O nome buscado nao consta na lista** \n");

        printf("\n Nova busca?(S/N)");
        gets(op);

    }while (strcasecmp(op,"s") == 0);
}
