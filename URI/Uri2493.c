#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int X, Y, Z;
} expr;
typedef struct
{
    char N[50], R;
    int E;
} resp;

int cmpNome(const void *a, const void *b);

int main()
{
    int T, i,j, X, Y, Z, Certos, W[50];
    char c;
    expr Exprecoes[50];
    resp Respostas[50];

    while (scanf("%i", &T) != EOF)
    {
        for (i = 0; i < T; i++)
        {
            scanf("%i %i %c %i", &Exprecoes[i].X, &Exprecoes[i].Y, &c, &Exprecoes[i].Z);
        }
        for (i = 0; i < T; i++)
        {
            scanf("%s %i %c", Respostas[i].N, &Respostas[i].E, &Respostas[i].R);
        }

        Certos = 0;
        j = 0;
        qsort(Respostas, T, sizeof(resp), cmpNome);
        for (i = 0; i < T; i++)
        {
            X = Exprecoes[Respostas[i].E - 1].X;
            Y = Exprecoes[Respostas[i].E - 1].Y;
            Z = Exprecoes[Respostas[i].E - 1].Z;

            if (Respostas[i].R == '+')
            {
                if (X + Y == Z)
                {
                    Certos++;                    
                }
                else
                {
                    W[j] = i;
                    j++;
                }
            }
            else if (Respostas[i].R == '-')
            {
                if (X - Y == Z)
                {
                    Certos++;                    
                }
                else
                {
                    W[j] = i;
                    j++;
                }
            }
            else if (Respostas[i].R == '*')
            {
                if (X * Y == Z)
                {
                    Certos++;                    
                }
                else
                {
                    W[j] = i;
                    j++;
                }
            }
            else if (Respostas[i].R == 'I')
            {
                if (X + Y != Z && X - Y != Z && X * Y != Z)
                {
                    Certos++;                    
                }
                else
                {
                    W[j] = i;
                    j++;
                }
            }
        }

        if (Certos == T)
        {
            printf("You Shall All Pass!\n");
        }
        else if (Certos == 0)
        {
            printf("None Shall Pass!\n");
        }
        else
        {
           

            for (i = 0; i < j; i++)
            {                
                if (i < j - 1)
                {
                    printf("%s ", Respostas[W[i]].N);
                }
                else
                {
                    printf("%s\n", Respostas[W[i]].N);
                }                                
            }
        }
    }

    return 0;
}

int cmpNome(const void *a, const void *b)
{
    resp *p1 = (resp *)a;
    resp *p2 = (resp *)b;

    return strcmp(p1->N, p2->N);
}