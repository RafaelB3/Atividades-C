#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char Nome[25], Cor[10], Tam;
} pedido;

int cmpfuncNome(const void *, const void *);

int main()
{
    int N, i, j = 0;
    pedido Pedidos[60];

    while (scanf("%i ", &N) && N != 0)
    {
        for (i = 0; i < N; i++)
        {
            gets(Pedidos[i].Nome);
            scanf("%s %c ", Pedidos[i].Cor, &Pedidos[i].Tam);
        }

        qsort(Pedidos, N, sizeof(pedido), cmpfuncNome);

        if (j)
        {
            printf("\n");
        }
        else
        {
            j++;
        }

        for (i = 0; i < N; i++)
        {
            printf("%s %c %s\n", Pedidos[i].Cor, Pedidos[i].Tam, Pedidos[i].Nome);
        }
    }

    return 0;
}

int cmpfuncNome(const void *a, const void *b)
{
    pedido *p1 = (pedido *)a;
    pedido *p2 = (pedido *)b;

    if (strcmp(p1->Cor, p2->Cor) == 0)
    {
        if (p1->Tam > p2->Tam)
        {
            return -1;
        }
        else if (p1->Tam < p2->Tam)
        {
            return 1;
        }
        else
        {
            return strcmp(p1->Nome, p2->Nome);
        }
    }
    else
    {
        return strcmp(p1->Cor, p2->Cor);
    }
}