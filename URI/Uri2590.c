#include <stdio.h>

int main()
{
    int T, N;

    scanf("%i", &T);

    do
    {
        scanf("%i", &N);

        switch (N % 4)
        {
            case 0:
                printf("1\n");
            break;

            case 1:
                printf("7\n");
            break;

            case 2:
                printf("9\n");
            break;

            case 3:
                printf("3\n");
            break;
        }

        T--;

    } while (T > 0);

    return 0;
}