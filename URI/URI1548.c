#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int N, M, K, P[1000], Q[1000], i;

    scanf("%i", &N);

    do
    {
        K = 0;
        scanf("%i", &M);

        for (i = 0; i < M; i++)
        {
            scanf("%i", &P[i]);
            Q[i] = P[i];
        }

        qsort(P, M, sizeof(int), cmp);

        for (i = 0; i < M; i++)
        {
            if (P[i] == Q[i])
            {
                K++;
            }
        }

        printf("%i\n", K);

        N--;
    } while (N > 0);
}