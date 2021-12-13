#include <stdio.h>
#include <conio.h>

int Number, ans;
int Factorial(int N)
{
    int x, y;
    if (N == 0)
    {
        printf(".............Roll back point\n");
        return 1; // Base Criteria
    }
    else
    {
        x = N - 1;
        printf("%2d != %2d * %2d!\n", N, N, x); // todo Display before Recursive
        y = Factorial(x);
        printf("%2d != %2d *%3d = %5d \n", N, N, y, y * N); // todo Dispaly AfterRecursive
        return N * y;
    }
} // end Fn.

int main()
{
    printf("RECURSIVE (FACTORIAL) PROGRAM\n");
    printf("=============================\n");
    // N=0 ;
    while (Number != -999)
    {
        printf("Enter Number ( -999 is END) = ");
        scanf(" %d", &Number);
        if (Number >= 0)
        {
            printf("N != N(N-1)! \n");
            printf("----------------Roll forward point\n");
            ans = Factorial(Number);
            printf("\nAnswer N! = %d \n", ans);
            printf("-----------------Finished\n");
            getch();
        }
    }
    return 0;
}