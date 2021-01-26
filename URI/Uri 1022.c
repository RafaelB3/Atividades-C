#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {int num,den;}Rac;

Rac SomaRac(Rac, Rac);
Rac SubtraiRac(Rac, Rac);
Rac MulRac(Rac, Rac);
Rac DivRac(Rac, Rac);
Rac SimplRac(Rac);
int MDC(int, int);

int main()
{
    Rac X, Y;
    int N, i;
    char C1, Op;
    scanf("%i", &N);

    if (N >= 1 && N <= 10000)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%i %c %i %c %i %c %i", &X.num, &C1, &X.den, &Op, &Y.num, &C1, &Y.den);

            if (Op == '+' )
            {
                Rac R;

                R = SomaRac(X, Y);
                printf("%i/%i", R.num, R.den);

                R = SimplRac(R);
                printf(" = %i/%i\n", R.num,R.den);

            }
            else if (Op == '-')
            {
                Rac R;
                
                R = SubtraiRac(X, Y);
                printf("%i/%i", R.num, R.den);

                R = SimplRac(R);
                printf(" = %i/%i\n", R.num,R.den);
            }
            else if (Op == '*')
            {
                Rac R;
                
                R = MulRac(X, Y);
                printf("%i/%i", R.num, R.den);

                R = SimplRac(R);
                printf(" = %i/%i\n", R.num,R.den);
            }
            else if (Op == '/')
            {
                Rac R;
                
                R = DivRac(X, Y);
                printf("%i/%i", R.num, R.den);

                R = SimplRac(R);
                printf(" = %i/%i\n", R.num,R.den);
            }
        }       
    }
               
    return 0;
}

Rac SomaRac(Rac X, Rac Y)
{	Rac res;

	res.num = X.num * Y.den + Y.num * X.den;
	res.den = X.den * Y.den;
	
	return res;
}

Rac SubtraiRac(Rac X, Rac Y)
{	Rac res;

	res.num = X.num * Y.den - Y.num * X.den;
	res.den = X.den * Y.den;
	
	return res;
}

Rac MulRac(Rac X, Rac Y)
{	Rac res;

	res.num = X.num * Y.num;
	res.den = X.den * Y.den;
	
	return res;
}

Rac DivRac(Rac X, Rac Y)
{	Rac res;

	res.num = X.num * Y.den;
	res.den = Y.num * X.den;
	
	return res;
}

Rac SimplRac(Rac R)
{	Rac res;

	res.num = R.num / MDC(R.num, R.den);
	res.den = R.den / MDC(R.num, R.den);
	
	return res;
}

int MDC(int m, int n)
{	if (m < 0) m = -m;
	if (n < 0) n = -n;

	if (m % n == 0)
		return n;
	else
		return MDC(n, m % n);
}
