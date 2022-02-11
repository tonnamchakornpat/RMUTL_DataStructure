#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MaxData 100

int Data[MaxData];
int i, N;

void PrepareRawData(int N)
{
    int i;
    srand(time(NULL));
    for (i = 1; i <= N; i++)
        Data[i] = 1 + rand() % 99;
}

void DispData(int N)
{
    int i;
    for (i = 1; i <= N; i++)
        printf("%2d  ", Data[i]);
    printf("\n");
}

void swap(int a, int b)
{
    int temp;
    temp = Data[a];
    Data[a] = Data[b];
    Data[b] = temp;
}

void QSort(int f, int r)
{
    int f1, r1;
    bool direction ;
    direction = true ;
    f1 = f;
    r1 = r;
    while (f != r)
    {
        if (Data[f] < Data[r])
        {
            printf("%2d %2d : ", f, r);
            DispData(N);
            swap(f, r);
            printf("%2d %2d : ", f, r);
            DispData(N);
            direction = !direction;
        }
        if (direction)
            f++;
        else
            r--;
    }
    printf("k1=[%2d]-----------------------------------------------------------------\n", Data[f]);
    if ((r < r1) && (r + 1 != r1))
        QSort(r + 1, r1);
    if ((f > f1) && (f - 1 != f1))
        QSort(f1, f - 1);
}

int main()
{
    printf("ASCENDING QUICK SORT\n");
    printf("-------------------------------------------------------------------------\n");
    N = 16;
    PrepareRawData(N);
    printf("Raw Data :");
    DispData(N);
    printf("Processing Data..\n");
    printf(" F  R  ");
    for (i = 1; i <= N; i++)
        printf("(%2d)", i);
    printf("\n");
    QSort(1, N);
    printf("-------------------------------------------------------------------------\n");
    printf("Sorted Data ");
    DispData(N);
    getch();
    return 0;
}