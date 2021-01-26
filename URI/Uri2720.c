#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Id, V;
} gift;

int cmpVol(const void *a, const void *b)
{
    gift *g1 = (gift *)a;
    gift *g2 = (gift *)b;

    if (g1->V == g2->V)
    {
        return (g1->Id - g2->Id);
    }
    else
    {
        return (g2->V - g1->V);
    }
}

int cmpId(const void *a, const void *b)
{
    gift *g1 = (gift *)a;
    gift *g2 = (gift *)b;

    return (g1->Id - g2->Id);
}

int main()
{
    int T, K, N, A, L, C, i;
    gift *Gifts;

    scanf("%i", &T);

    do
    {
        scanf("%i%i", &N, &K);

        Gifts = (gift *)malloc(sizeof(gift) * N);

        for (i = 0; i < N; i++)
        {
            scanf("%i%i%i%i", &Gifts[i].Id, &A, &L, &C);
            Gifts[i].V = A * L * C;
        }

        qsort(Gifts, N, sizeof(gift), cmpVol);
        qsort(Gifts, K, sizeof(gift), cmpId);

        for (i = 0; i < K; i++)
        {
            if (i + 1 < K)
            {
                printf("%i ", Gifts[i].Id);
            }
            else
            {
                printf("%i\n", Gifts[i].Id);
            }
        }

        free(Gifts);

        T--;
    } while (T > 0);

    return 0;
}