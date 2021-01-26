#include <stdio.h>

int main()
{
    int i, j = 0, k, N, Lado[6];

    scanf("%i", &N);

    while (j < N)
    {
        j++;

        for (i = 0; i < 6; i++)
        {
            scanf("%i", &Lado[i]);
        }

        if (Lado[0] + Lado[5] == 7 && Lado[1] + Lado[3] == 7 && Lado[2] + Lado[4] == 7)
        {
            for (i = 0; i < 6; i++)
            {
                if (Lado[i] > 6 || Lado[i] < 1)
                {
                    printf("NAO\n");
                    break;
                }
            }

            if(i == 6)    
            {
                for (i = 0; i < 6; i++)
                {
                    for (k = i+1; k < 6; k++)
                    {
                        if (Lado[i] == Lado[k])
                        {
                            printf("NAO\n");
                            i = 6;
                        }
                        else if (i == 4 && k == 5)
                        {
                            printf("SIM\n");
                        }
                    }
                }
            }            
        }
        else
        {
            printf("NAO\n");
        }
    }

    return 0;
}