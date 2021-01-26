#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char N[20];
    int D;
} carne;

int cmpcarne(const void *a, const void *b)
{
    carne *c1 = (carne *)a;
    carne *c2 = (carne *)b;

    return (c1->D - c2->D);
}

int main()
{
    carne Churas[10];
    int N, i;

    while (scanf("%i", &N) != EOF)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%s %i", Churas[i].N, &Churas[i].D);
        }

        qsort(Churas, N, sizeof(carne), cmpcarne);

        for (i = 0; i < N - 1; i++)
        {
            printf("%s ", Churas[i].N);
        }
        printf("%s\n", Churas[i].N);
    }

    return 0;
}