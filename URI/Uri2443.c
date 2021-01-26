#include <stdio.h>

typedef struct
{
    int Num, Den;
} Rac;

int MDC(int m, int n)
{
    if (m % n == 0)
    {
        return n;
    }
    else
    {
        return MDC(n, m % n);
    }
}

Rac SimplRac(Rac R)
{
    Rac S;

    S.Num = R.Num / MDC(R.Num, R.Den);
    S.Den = R.Den / MDC(R.Num, R.Den);

    return S;
}

int main()
{
    Rac A, B, R;

    scanf("%i %i %i %i", &A.Num, &A.Den, &B.Num, &B.Den);

    R.Num = A.Num * B.Den + B.Num * A.Den;
    R.Den = A.Den * B.Den;

    R = SimplRac(R);

    printf("%i %i\n", R.Num, R.Den);

    return 0;
}