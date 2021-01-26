#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int mdc(int *, int* ); 

int main()
{
    int N, F1, F2, i, MDC;

    printf("Digite N: ");
    scanf("%i",&N);

    for ( i = 0; i < N; i++)
    {
        printf("\nDigite F1 e F2: ");
        scanf("%i %i",&F1, &F2);
        
        MDC = mdc(&F1, &F2);
        printf("MDC = %i", MDC);
    }
  
    return 0;
}
 
int mdc(int *F1, int *F2)
{    
    if (*F1 < 0) *F1 = -*F1;
	if (*F2 < 0) *F2 = -*F2;

	if (*F1 % *F2 == 0)
		return *F2;
	else
    {
        int mod;
        mod = *F1 % *F2;
		return mdc(F2, &mod);
    }
}