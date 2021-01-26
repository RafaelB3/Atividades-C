#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void empilhar(char *, char *, int *);
int desempilha(char *, char , int *);

int main ()
{
    int i, j=0;
    char str[1000], pilha[1000];
    while(scanf("%i", &i) != EOF)
    {
        j=0;
        scanf("%s", str);
        i=0;
        for (i = 0; i < strlen(str); i++)        
        {
            if (str[i] == '(')
            {
                empilhar(pilha, &str[i],&j);
            }   

            if (str[i] == ')')
            {
                if (desempilha(pilha,'(', &j) == 0)
                {
                    j = -1;
                    printf("incorrect\n"); 
                    break;                   
                }
            }
        }

        if (j == 0)
        {
            printf("correct\n");
        }
        else if(j > 0)
        {
            printf("incorrect\n");
        }
    }

    return 0;
}

void empilhar(char *pilha, char *c, int *i)
{
    pilha[*i] = *c;
    *i = *i + 1;
}

int desempilha(char *pilha, char c, int *j)
{
    if (pilha[*j-1] == c)
    {
        *j = *j - 1;
        return 1;
    }
    else
    {
        return 0;
    }        
}
