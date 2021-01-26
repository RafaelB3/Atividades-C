#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

int main()
{
    int N, i, j;
    char S[101], s[101], F[201];
    scanf("%i", &N);
    flush_in();

    while (N > 0)
    {
        gets(S);
        gets(s);
        j = 0;
        i = 0;

        while (i < strlen(S))
        {
            while (i < strlen(S))
            {
                F[i + j] = S[i];
                i++;

                if (i >= strlen(S))
                {
                    break;
                }
                else
                {
                    F[i + j] = S[i];
                    i++;
                    break;
                }
            }

            while (j < strlen(s))
            {
                F[i + j] = s[j];
                j++;

                if (j >= strlen(s))
                {
                    break;
                }
                else
                {
                    F[i + j] = s[j];
                    j++;
                    break;
                }
            }
        }

        F[i + j] = '\0';

        printf("%s\n", F);
        N--;
    }

    return 0;
}