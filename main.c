#include <stdio.h>
//Multiple the N x N matrix A by the N x 1 vector x to get the N x 1 vector b. 

void printmat(int n, int m, double mat[n][m])
{
    for (int row = 0; row < n; ++row)
    {
        for (int column = 0; column < m; ++column)
        {
            printf("%lf, ", mat[row][column]);
            
        }
        printf("\n");
    }
}

void matvetmult(int n, const double A[n][n], const double x[n], double b[n])
{
    for (int i = 0; i < n; i++)
    {
        b[i] = 0;
        for (int j = 0; j < n; j++)
        {
            b[i] += A[i][j] * x[j];
        }
    }
}

int main()
{
    int n, m;
    char filename[478];
    printf("enter number of rows of martix: ");
    scanf("%d", &n);
    printf("enter number of columns of matrix: ");
    scanf("%d", &m);
    
    printf("enter filename for matrix: ");
    scanf("%s", filename);
    FILE* fin = fopen(filename, "r");
    double A[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        fscanf(fin, "%lf", &A[i][j]);
        
    printf("enter filename for vector: ");
    scanf("%s", filename);
    FILE* bin = fopen(filename, "r");
    double x[n];
    for (int i = 0; i < n; i++)
        fscanf(bin, "%lf", &x[i]);
    
    double b[n];
    
    printf("A[n][n] matrix\n");
    printmat(n, m, A);
    printf("x[n] matrix\n");
    printmat(n, 1.0, x);
    printf("matrix A * x = \n");
    matvetmult(n, A, x, b);
    printmat(1.0, n, b);


    return 0;
}

