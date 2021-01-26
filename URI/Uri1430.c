#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int Tempo = 0, Certos, i, len;
    char Compos[200];

    while (scanf("%s", Compos) && Compos[0] != '*')
    {
        Certos = 0;

        len = strlen(Compos);

        for (i = 0; i < len; i++)
        {

            switch (Compos[i])
            {
                case 'W':
                    Tempo += 64;
                break;

                case 'H':
                    Tempo += 32;
                break;

                case 'Q':
                    Tempo += 16;
                break;

                case 'E':
                    Tempo += 8;
                break;

                case 'S':
                    Tempo += 4;
                break;

                case 'T':
                    Tempo += 2;
                break;

                case 'X':
                    Tempo += 1;
                break;

                case '/':
                    if (Tempo == 64)
                    {
                        Certos++;
                    }

                    Tempo = 0;
                break;
            }
        }

        printf("%i\n", Certos);
    }

    return 0;
}