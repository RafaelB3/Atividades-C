#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int V, *N,i;
    scanf("%i",&V);
    if(V <= 50)
    {
        N = (int)malloc(10 * sizeof(int) );

        for(i=0;i<10;i++)
        {
            N[i] = V;
            V*=2;
        }
        for(i=0;i<10;i++)
        {
            printf("N[%i] = %i\n",i,N[i]);
        }
    }
    else
    {
        printf("V > 50");
    }

    return 0;
}
