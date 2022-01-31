#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MaxNode 40

struct Node
{
    int info;
    struct Node *lson;
    struct Node *rson;
};

struct Node *T, *address[MaxNode];
int i, N, info[MaxNode];
char ch;

Node *Allocate()
{
    struct Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    return temp;
}

void CreateTreeNP(int n)
{
    int i, temp, Father;
    struct Node *p, *FatherPT;
    T = NULL;
    for (i = 1; i <= n; i++)
    {
        p = Allocate();
        temp = 1 + rand() % 99;
        info[i] = temp;
        address[i] = p;
        p->info = temp;
        p->lson = NULL;
        p->rson = NULL;
        if (T == NULL)
        {
            T = p;
        }
        else
        {
            Father = i / 2;
            FatherPT = address[Father];
            if (FatherPT->lson == NULL)
                FatherPT->lson = p;
            else
                FatherPT->rson = p;
        }
    }
}

void ShowTree()
{
    int j, level, start, ends;
    j = 1;
    level = 1;
    printf("\n");
    while (info[j] != 0)
    {
        start = pow(2, level) / 2;
        ends = pow(2, level) - 1;
        for (j = start; j <= ends; j++)
            if (info[j] != 0)
            {
                switch (level)
                {
                case 1:
                    printf("%40d", info[j]);
                    break;
                case 2:
                    if (j == 2)
                        printf("%20d", info[j]);
                    else
                        printf("%40d", info[j]);
                    break;
                case 3:
                    if (j == 4)
                        printf("%10d", info[j]);
                    else
                        printf("%20d", info[j]);
                    break;
                case 4:
                    if (j == 8)
                        printf("%5d", info[j]);
                    else
                        printf("%10d", info[j]);
                    break;
                case 5:
                    if (j == 16)
                        printf("%d", info[j]);
                    else
                        printf("%5d", info[j]);
                    break;
                }
            }
        printf("\n");
        level++;
    }
}

void Re_PreOrder(struct Node *i)
{
    if (i != NULL)
    {
        printf(" %d", i->info);
        Re_PreOrder(i->rson);
        Re_PreOrder(i->lson);
    }
}
void Re_InOrder(struct Node *i)
{
    if (i != NULL)
    {
        Re_InOrder(i->rson);
        printf(" %d", i->info);
        Re_InOrder(i->lson);
    }
}
void Re_PostOrder(struct Node *i)
{
    if (i != NULL)
    {
        Re_PostOrder(i->rson);
        Re_PostOrder(i->lson);
        printf(" %d", i->info);
    }
}

void PreOrder(struct Node *i)
{
    if (i != NULL)
    {
        printf(" %d", i->info);
        PreOrder(i->lson);
        PreOrder(i->rson);
    }
}
void InOrder(struct Node *i)
{
    if (i != NULL)
    {
        InOrder(i->lson);
        printf(" %d", i->info);
        InOrder(i->rson);
    }
}
void PostOrder(struct Node *i)
{
    if (i != NULL)
    {
        PostOrder(i->lson);
        PostOrder(i->rson);
        printf(" %d", i->info);
    }
}

int main()
{
    N = 31;
    CreateTreeNP(N);
    while (ch != 'E')
    {
        printf("\nTree (NODE Pointer)\n");
        printf("========================================================\n");
        printf("N : %d\n", N);
        printf("Sequence of data ");
        for (i = 1; i <= N; i++)
            printf("%d ", info[i]);
        ShowTree();
        printf("\nMenu => P: PreOrder [R-TL-TR]      I:InOrder [TL-R-TR]      O:PostOrder [TL-TR-R] ");
        printf("\n     => L: Re-PreOrder [R-TR-TL]   K:Re-InOrder [TR-R-TL]   J:Re-PostOrder [TR-TL-R]  E:Exit ");
        ch = getch();
        printf("\n------------------------------------------------------\n");
        switch (ch)
        {
        case 'P':
            printf("PRE ORDER TRAVERSAL : ");
            PreOrder(T);
            printf("\n**************************************************\n");
            break;
        case 'I':
            printf("IN ORDER TRAVERSAL : ");
            InOrder(T);
            printf("\n**************************************************\n");
            break;
        case 'O':
            printf("POST ORDER TRAVERSAL : ");
            PostOrder(T);
            printf("\n**************************************************\n");
            break;
        case 'L':
            printf("RE-PRE ORDER TRAVERSAL : ");
            Re_PreOrder(T);
            printf("\n**************************************************\n");
            break;
        case 'K':
            printf("RE-IN ORDER TRAVERSAL : ");
            Re_InOrder(T);
            printf("\n**************************************************\n");
            break;
        case 'J':
            printf("RE-POST ORDER TRAVERSAL : ");
            Re_PostOrder(T);
            printf("\n**************************************************\n");
            break;
        }
    }
    return 0;
}