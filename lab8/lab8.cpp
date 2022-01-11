#include <stdio.h>
#include <conio.h>

int Number;
float Number2, ans;
int Power(float N, int M)
{
    int x;
    float y;
    if (M == 0)
    {
        printf(".............Roll back point\n");
        return 1; // Base Criteria
    }
    else
    {
        x = M - 1;
        printf("%2.2f^%d = %2.2f * %2.2f ^ %d\n", N, M, N, N, x); // todo Display before Recursive
        y = Power(N , x );
        printf("%2.2f^%d = %2.2f * %2.2f = %2.2f \n", N, M, N, y, N * y); // todo Dispaly AfterRecursive
        return N * y;
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
            ans = Power(Number2, Number);
            printf("\n%.2f^%d = %.2f \n", Number2, Number, ans);
            printf("-----------------Finished\n");
            if (getch() == 'e')
                break;
        }
    }
    return 0;
}