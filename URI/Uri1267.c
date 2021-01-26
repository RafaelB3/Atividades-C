#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, D, i, j;

    do
    {
        scanf("%i %i", &N, &D);

        int DxN[D][N];

        for (i = 0; i < D; i++)
        {
            for (j = 0; j < N; j++)
            {
                scanf("%i", &DxN[i][j]);
            }
        }

        for (j = 0; j < N; j++)
        {
            for (i = 0; i < D; i++)
            {
                if (DxN[i][j] == 1)
                {
                    if (i + 1 == D)
                    {
                        printf("yes\n");
                        i = D;
                        j = N;
                    }
                }
                else if (j + 1 == N)
                {
                    printf("no\n");
                    i = D;
                    j = N;
                }
                else
                {
                    j++;
                    i = -1;
                }
            }
        }
    } while (N != 0 && D != 0);

    return 0;
}