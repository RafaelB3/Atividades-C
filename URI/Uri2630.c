#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char Con[5];
    int R, G, B;
} cor;

int main()
{
    int T, i, R, G, B;
    int P;
    cor Cores[100];

    scanf("%i", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%s", Cores[i].Con);
        scanf("%i%i%i", &Cores[i].R, &Cores[i].G, &Cores[i].B);
    }

    for (i = 0; i < T; i++)
    {
        R = Cores[i].R;
        G = Cores[i].G;
        B = Cores[i].B;

        if (strcmp(Cores[i].Con, "eye") == 0)
        {
            P = (0.3 * R) + (0.59 * G) + (0.11 * B);

            printf("Caso #%i: %i\n", i + 1, P);
        }
        else if (strcmp(Cores[i].Con, "mean") == 0)
        {
            P = (R + G + B) / 3;

            printf("Caso #%i: %i\n", i + 1, P);
        }
        else if (strcmp(Cores[i].Con, "max") == 0)
        {
            P = R;

            if (P < G)
            {
                P = G;
            }

            if (P < B)
            {
                P = B;
            }
            printf("Caso #%i: %i\n", i + 1, P);
        }
        else
        {
            P = R;

            if (P > G)
            {
                P = G;
            }

            if (P > B)
            {
                P = B;
            }
            printf("Caso #%i: %i\n", i + 1, P);
        }
    }

    return 0;
}