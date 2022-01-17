#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define HeadData -999

struct Node
{
    int info;
    struct Node *link;
};

struct Node *H, *H1, *p, *q;
int i, j, k, n, data;
char ch;

Node *Allocate();
void CreateNNode(int);
void ShowAllNode();
void InsertAfter(int);
void DeleteAfter(int);

int main()
{
    p = Allocate();
    p->info = HeadData;
    p->link = p;
    n = 10;
    CreateNNode(n);
    printf("PROGREAM SINGLY CIRCULAR LINKED LIST \n");
    printf("=====================================\n");
    printf("All Data in Linked List \n");
    ShowAllNode();
    ch = ' ';
    while (ch != 'E')
    {
        printf("MENU : [I:Insert D:Delete E:Exit]");
        ch = getch();
        switch (ch)
        {
        case 'I':
            printf("\nInsert After data :");
            scanf("%d", &data);
            InsertAfter(data);
            printf("All Data in Linked List AFTER ");
            ShowAllNode();
            break;
        case 'D':
            printf("\nDelete After data :");
            scanf("%d", &data);
            DeleteAfter(data);
            printf("\nAll Data in LInked list AFTER ");
            ShowAllNode();
            break;
        }
    }
    return 0;
}

Node *Allocate() //* Allocate 1 node from storage  pool
{
    struct Node *temp;
    temp = (Node *)malloc(sizeof(Node)); //* Allocate node by size declare
    return temp;
}

void CreateNNode(int n)
{
    int i, temp;
    H = p;  //? set H -> p
    H1 = p; //? H1 -> p
    for (i = 1; i <= n; i++)
    {
        p = Allocate();
        temp = 1 + rand() % 99;
        p->info = temp;
        H1->link = p; //? Link H1 -> p
        H1 = p;       //? H1 -> p
        H1->link = H; //? Link H1 -> H
    }
}

void ShowAllNode()
{
    printf("H = %x \n", H);
    p = H->link; //? p -> Link H
    i = 1;
    while (p->info != HeadData) //? Check back to H node?
    {
        printf("%d) %x \t", i, p);
        printf("INFO : %d \t", p->info);
        printf("LINK : %x\n", p->link);
        p = p->link; // todo set p to next node
        i++;
    }
}

void InsertAfter(int data1)
{
    int temp;
    if (H->link == H) // ? check have node ?
        printf("Circular Linked List have no node!!....\n");
    else
    {
        H1 = H->link;                //? H1 -> Link H
        while (H1->info != HeadData) //? Check back to H node ?
        {
            if (H1->info == data1) //? check data1 == info ?
            {
                p = Allocate();
                printf("\nInsert data :");
                scanf("%d", &temp);
                p->info = temp;     //? info p = temp
                p->link = H1->link; //? link p -> link H1
                H1->link = p;       //? link H1 -> p
            }
            H1 = H1->link; // todo set H1 to next node
        }
    }
}

void DeleteAfter(int data1)
{
    int temp;
    if (H->link == H) //? check have node ?
        printf("Circular Linked List have no node!!....\n");
    else
    {
        H1 = H->link;                //? H1 -> Link H
        while (H1->info != HeadData) //? Check back to H node ?
        {
            if (H1->info == data1) //? check data1 == info ?
            {
                if (H1->link == H) //? check node is H ?
                    printf("This is the Head");
                else
                {
                    p = H1->link;     //? p -> next node (Link H1 )
                    if (p->link == H) //?  check p is last node ?
                        H1->link = H; //? set Link H1 -> H
                    else
                        H1->link = p->link; //? Link H1 -> Link p
                    free(p);                //? free node to memory
                }
            }
            H1 = H1->link; // todo set H1 to next node
        }
    }
}
