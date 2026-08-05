#include <stdio.h>

int main()
{
    int m, n, r, p;
    scanf("%d %d", &m, &n);

    int A[50][50], B[50][50], C[50][50];

    // Read Matrix A
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Read dimensions of Matrix B
    scanf("%d %d", &r, &p);

    // Check validity
    if (n != r)
    {
        printf("Invalid input");
        return 0;
    }

    // Read Matrix B
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix Multiplication
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print Result
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
