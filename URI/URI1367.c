#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, Tempo, S, P, W;
    char Problema, Judge;

    do
    {
        scanf("%i", &N);
        if (N = 0)
        {
            break;
        }
        
        S = 0;
        P = 0;
        W = 0;

        while (N--)
        {
            scanf("%c %i %s", &Problema, &Tempo, Judge);
            if (strcmp(Judge, "correct"))
            {
                S++;
                P += Tempo;
            }
            else
            {
                W++;
            }
            
        }

        printf("\n%i %i", S, P);
    } while (1);

    return 0;
}