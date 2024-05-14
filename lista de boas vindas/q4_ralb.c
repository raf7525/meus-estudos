#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int x = 0, y = 0, soma = 0;
        scanf("%d %d", &y, &x);
        if (x > y)
        {
            for (int j = y + 1; j < x; j++)
            {
                if (j % 2 != 0)
                {
                    soma += j;
                }
            }
        }
        if (y > x)
        {
            for (int j = x + 1; j < y; j++)
            {
                if (j % 2 != 0)
                {
                    soma += j;
                }
            }
        }

        printf("%d\n", soma);
    }

    return 0;
}