#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, i, j, S;
    char D[1000];

    scanf("%i", &N);

    while (N--)
    {

        scanf("%s", D);

        S = 0;
        for (i = 0; i < strlen(D); i++)
        {
            if (D[i] == '<')
            {
                for (j = i + 1; j < strlen(D); j++)
                {
                    if (D[j] == '>')
                    {
                        D[i] = '.';
                        D[j] = '.';
                        S++;
                        break;
                    }
                }
            }
        }

        printf("%i\n", S);
    }

    return 0;
}