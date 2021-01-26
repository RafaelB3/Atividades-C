#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, M, i, j, c, R;

    do
    {
        scanf("%i %i", &N, &M);
        int Pack[M];

        for (i = 0; i < M; i++)
        {
            scanf("%i", &Pack[i]);
        }

        R = 0;
        for (j = 1; j <= N; j++)
        {
            c = 0;

            for (i = 0; i < M; i++)
            {
                if (Pack[i] == j)
                {
                    c++;
                }
            }
            if (c > 1)
            {
                R++;
            }
        }
        if (N != 0 && M != 0)
        {
            printf("%i\n", R);
        }
    } while (N != 0 && M != 0);

    return 0;
}