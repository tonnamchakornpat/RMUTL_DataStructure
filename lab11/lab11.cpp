#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MaxNode 100

int N, data[MaxNode];
char ch;

void CreateTreeNS(int n)
{
    int i, temp;
    for (i = 1; i <= n; i++)
    {
        temp = 1 + rand() % 99;
        data[i] = temp;
    }
}

void ShowArray()
{
    int i = 1;
    while (data[i] != 0)
    {
        printf("[%i] %d ", i, data[i]);
        i++;
    }
    printf("\n##########################################\n");
}

void ShowTree()
{
    int j, level, start, ends;
    j = 1;
    level = 1;
    printf("\n");
    while (data[j] != 0)
    {
        start = pow(2, level) / 2; //? Calculate Start node
        ends = pow(2, level) - 1;  //? Calculate END node
        for (j = start; j <= ends; j++)
            if (data[j] != 0)
            {
                switch (level)
                {
                case 1:
                    printf("%40d", data[j]);
                    break;
                case 2:
                    if (j == 2)
                        printf("%20d", data[j]);
                    else
                        printf("%40d", data[j]);
                    break;
                case 3:
                    if (j == 4)
                        printf("%10d", data[j]);
                    else
                        printf("%20d", data[j]);
                    break;
                case 4:
                    if (j == 8)
                        printf("%5d", data[j]);
                    else
                        printf("%10d", data[j]);
                    break;
                case 5:
                    if (j == 16)
                        printf("%d", data[j]);
                    else
                        printf("%5d", data[j]);
                    break;
                }
            }
        printf("\n\n");
        level++;
    }
}

void PreOrder(int i)
{
    int info, lson, rson;
    info = data[i];
    if (info != 0)
    {
        printf(" %d", data[i]);
        lson = 2 * i;
        rson = 2 * i + 1;
        PreOrder(lson);
        PreOrder(rson);
    }
}

void InOrder(int i)
{
    int info, lson, rson;
    info = data[i];
    if (info != 0)
    {
        lson = 2 * i;
        rson = 2 * i + 1;
        InOrder(lson);
        printf(" %d", data[i]);
        InOrder(rson);
    }
}

void PostOrder(int i)
{
    int info, lson, rson;
    info = data[i];
    if (info != 0)
    {
        lson = 2 * i;
        rson = 2 * i + 1;
        PostOrder(lson);
        PostOrder(rson);
        printf(" %d", data[i]);
    }
}

void Re_PostOrder(int i)
{
    int info, lson, rson;
    info = data[i];
    if (info != 0)
    {
        lson = 2 * i;
        rson = 2 * i + 1;
        Re_PostOrder(rson);
        Re_PostOrder(lson);
        printf(" %d", data[i]);
    }
}

void Re_InOrder(int i)
{
    int info, lson, rson;
    info = data[i];
    if (info != 0)
    {
        lson = 2 * i;
        rson = 2 * i + 1;
        Re_InOrder(rson);
        printf(" %d", data[i]);
        Re_InOrder(lson);
    }
}

void Re_PreOrder(int i)
{
    int info, lson, rson;
    info = data[i];
    if (info != 0)
    {
        printf(" %d", data[i]);
        lson = 2 * i;
        rson = 2 * i + 1;
        Re_PreOrder(rson);
        Re_PreOrder(lson);
    }
}

int main()
{
    N = 15;
    CreateTreeNS(N);
    while (ch != 'E')
    {
        printf("\nTree (NODE Sequence)\n");
        printf("==========================================\n");
        ShowArray();
        ShowTree();
        printf("\nMenu => P: PreOrder[R-TL-TR]      I:InOrder[TL-R-TR]      O:PostOrder[TL-TR-R] ");
        printf("\n     => L: Re-PreOrder[R-TR-TL]   K:Re-InOrder[TR-R-TL]   J:Re-PostOrder[TR-TL-R]  E:Exit ");
        ch = getch();
        printf("\n----------------------------------------\n");
        switch (ch)
        {
        case 'P':
            printf("PRE ORDER TRAVERSAL : ");
            PreOrder(1);
            printf("\n");
            break;
        case 'I':
            printf("IN ORDER TRAVERSAL : ");
            InOrder(1);
            printf("\n");
            break;
        case 'O':
            printf("POST ORDER TRAVERSAL : ");
            PostOrder(1);
            printf("\n");
            break;
        case 'L':
            printf("RE-PRE ORDER TRAVERSAL : ");
            Re_PreOrder(1);
            printf("\n");
            break;
        case 'K':
            printf("RE-IN ORDER TRAVERSAL : ");
            Re_InOrder(1);
            printf("\n");
            break;
        case 'J':
            printf("RE-POST ORDER TRAVERSAL : ");
            Re_PostOrder(1);
            printf("\n");
            break;
        }
    }
    return 0;
}