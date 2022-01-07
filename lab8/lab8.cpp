#include <stdio.h>
#include <conio.h>

int Number;
float Number2, ans;
int Power(int N, float M)
{
    int x;
    float y;
    if (N == 0)
    {
        printf(".............Roll back point\n");
        return 1; // Base Criteria
    }
    else
    {
        x = N - 1;
        printf("%2.2f^%d = %2.2f * %2.2f ^ %d\n", M, N, M, M, x); // todo Display before Recursive
        y = Power(x, M);
        printf("%2.2f^%d = %2.2f * %2.2f = %2.2f \n", M, N, M, y, M * y); // todo Dispaly AfterRecursive
        return M * y;
    }
} // end Fn.

int main()
{
    printf("RECURSIVE (Power) PROGRAM\n");
    printf("=============================\n");
    // N=0 ;
    while (Number != -999 || Number2 != -999)
    {
        printf("Enter Number ( -999 is END) = ");
        scanf(" %f %d", &Number2, &Number);
        if (Number >= 0 && Number2 >= 0)
        {
            printf("N != N(N-1)! \n");
            printf("-----------------Roll forward point\n");
            ans = Power(Number, Number2);
            printf("\n%.2f^%d = %.2f \n", Number2, Number, ans);
            printf("-----------------Finished\n");
            if (getch() == 'e')
                break;
        }
    }
    return 0;
}