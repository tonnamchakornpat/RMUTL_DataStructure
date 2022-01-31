#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *llink;
    struct Node *rlink;
};

struct Node *H, *H1, *p, *q;
int i, j, k, n, data;
char ch;

Node *Allocate()
{
    struct Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    return temp;
}

void CreateNNode(int n)
{
    int i, temp;
    H = NULL;
    H1 = NULL;
    for (i = 1; i <= n; i++)
    {
        p = Allocate(); //? Allocate 1 node
        temp = 1 + rand() % 99;
        p->info = temp; //? info p = temp
        if (i == 1)     //? check first node ?
            H = p;      //? H -> first node( p )
        else
            H1->rlink = p; //? set Rlink h1 to second node( p node )
        p->llink = H1;
        H1 = p;           //? H1 ->  p last node
        H1->rlink = NULL; //? set Rlink H1 = NULL
    }
}

void ShowAllNode()
{
    printf("H = %x \n", H);
    p = H; //? set p -> H ( set 2 first node for start )
    i = 1;
    while (p != NULL)
    {
        printf("%d) : %x\t", i, p);
        printf("LLINK : %x\t", p->llink);
        printf("INFO : %d\t", p->info);
        printf("RLINK : %x\n", p->rlink);
        p = p->rlink; //? set p to next node
        i++;
    }
}

void InsertAfter(int data1)
{
    int temp;
    if (H == NULL) //? check have node ?
        printf("Linked List have no Node!!..\n");
    else
    {
        H1 = H;            //? set H1 -> H ( first node )
        while (H1 != NULL) //? search data While H1 <> NULL
        {
            if (H1->info == data1) //? check info H1 == data1 ?
            {
                p = Allocate(); //? allocate 1 node
                printf("\nInsert data :");
                scanf("%d", &temp);
                p->info = temp;
                if (H1->rlink == NULL) //? check H1 is last Node ?
                {
                    p->rlink = NULL; //? rlink p = null ;
                }
                else
                {
                    p->rlink = H1->rlink; //? set rlink p to point second node ( after H1 )
                    H1->rlink->llink = p; //? set llink second node (after H1) to point p ( new node )
                }
                p->llink = H1; //? llink p -> H1
                H1->rlink = p; //? rlink H1 -> p
            }
            H1 = H1->rlink; // todo set H1 to next node
        }
    }
}

void InsertBefore(int data1)
{
    int temp;
    if (H == NULL) //? check have node ?
        printf("Linked LIst have no Node!!.\n");
    else
    {
        H1 = H;            //? set H1 -> H ( first node )
        while (H1 != NULL) //? search data While H1 <> NULL
        {
            if (H1->info == data1) //? check info H1 == data1 ?
            {
                p = Allocate();
                printf("\nInsert data :");
                scanf("%d", &temp);
                p->info = temp;
                if (H1->llink == NULL) //? check H1 is first node ?
                {
                    p->llink = NULL; //? llink p -> null
                    H = p;           //? H -> new node
                }
                else
                {
                    H1->llink->rlink = p; //? llink(rlink( p )) (rlink node before H1) -> p (new node)
                    p->llink = H1->llink; //? llink p -> llink H1
                }
                H1->llink = p; //? llink h1 -> p
                p->rlink = H1; //? rlink p -> H1
            }
            H1 = H1->rlink; // todo set H1 to next node
        }
    }
}

void DeleteBefore(int data1)
{
    int temp;
    if (H == NULL) //? check have node ?
        printf("Linked List have no Node!!..\n");
    else
    {
        H1 = H;            //? set H1 -> H ( first node ) //? H1
        while (H1 != NULL) //? search data While H1 <> NULL
        {
            if (H1->info == data1) //? check info H1 == data1 ?
            {
                if (H1->llink == NULL) //? check H1 is first node ?
                {
                    printf("No more node from here, Can't delete it!! \n");
                }
                else
                {
                    p = H1->llink;        //? p -> llink h1 ( node before H1 )
                    if (p->llink == NULL) //? If p is first node ?
                    {
                        H1->llink = NULL; //? set llink H1 = NULL
                        H = H1;           //? set H -> H1
                    }
                    else
                    {
                        H1->llink = p->llink; //? llink h1 -> llink p
                        p->llink->rlink = H1; //? rlink(llink( p )) -> H1
                    }
                    free(p); // free node to storage
                }
            }
            H1 = H1->rlink; // todo set H1 to next node
        }
    }
}

void DeleteSelf(int data1)
{
    int temp;
    if (H == NULL) //? check have node ?
    {
        printf("Linked List have NO NODE !!..\n");
    }
    else
    {
        H1 = H;            //? set H1 -> H
        while (H1 != NULL) //? search data While H1 <> NULL
        {
            if (H1->info == data1) //? check info H1 == data1 ?
            {
                p = H1;                                   //? set P -> H1
                if (p->llink == NULL && p->rlink == NULL) //? check have one node ?
                    H = NULL;                             //? set H -> NULL
                else
                {
                    if (p->llink == NULL) //? check first node ?
                    {
                        H = p->rlink;    //? set H to point rlink p  **( next node )
                        H->llink = NULL; //? set llink H = NULL
                    }
                    else
                    {
                        if (p->rlink == NULL) //? check last node ?
                        {
                            p->llink->rlink = NULL; //? set rlink( llink( p )) -> NULL
                        }
                        else
                        {
                            p->llink->rlink = p->rlink; //? rlink(llink( p )) -> rlink p **( set rlink node before p to point node after p)
                            p->rlink->llink = p->llink; //? llink(rlink( p )) -> llink p **( set llink node node after p to point node before p )
                        }
                    }
                    free(p); // free node to storage
                }
            }
            H1 = H1->rlink; // todo set H1 to next node
        }
    }
}

void DeleteAfter(int data1)
{
    int temp;
    if (H == NULL) //? check have node ?
    {
        printf("Linked List have NO NODE !!..\n");
    }
    else
    {
        H1 = H;            //? set H1 -> H
        while (H1 != NULL) //? search data While H1 <> NULL
        {
            if (H1->info == data1) //? check info H1 == data1 ?
            {
                if (H1->rlink == NULL) //? check H1 is last node ?
                    printf("No more node from here, can't delete it!!..\n");
                else
                {
                    p = H1->rlink;        //? set p -> rlink h1 ( next node )
                    if (p->rlink == NULL) //? check p is last node ?
                        H1->rlink = NULL; //? rlink H1 -> NULL
                    else
                    {
                        H1->rlink = p->rlink; //? rlink H1 -> rlink **( set rlink H1 to point node after p)
                        p->rlink->llink = H1; //? llink(rlink( p )) -> H1 **( set llink node after p to point H1(node before p s) )
                    }
                    free(p); // free node to storage
                }
            }
            H1 = H1->rlink; // todo set H1 to next node
        }
    }
}

int main()
{

    n = 10;
    CreateNNode(n);
    printf("PROGREAM DOUBLY LINKED LIST \n");
    printf("=====================================\n");
    printf("All Data in Linked List \n");
    ShowAllNode();
    ch = ' ';
    while (ch != 'E')
    {
        printf("MENU\nB:InsertBefore\tA:InsertAfter\n");
        printf("O:DeleteBefore\tX:Delete Itself\n");
        printf("D:DeleteAfter\tE:Exit\n");
        ch = getch();
        switch (ch)
        {
        case 'B':
            printf("\nInsert After data :");
            scanf("%d", &data);
            InsertBefore(data);
            printf("\nAll Data in Linked List AFTER INSERTED\n");
            ShowAllNode();
            break;
        case 'A':
            printf("\nInsert After data :");
            scanf("%d", &data);
            InsertAfter(data);
            printf("\nAll Data in Linked List AFTER INSERTED\n");
            ShowAllNode();
            break;
        case 'O':
            printf("\nDelete Before data :");
            scanf("%d", &data);
            DeleteBefore(data);
            printf("\nAll Data in Linked List AFTER DELETE\n");
            ShowAllNode();
            break;
        case 'X':
            printf("\nDelete ItSelf data :");
            scanf("%d", &data);
            DeleteSelf(data);
            printf("\nAll Data in Linked List ITSELF DELETE\n");
            ShowAllNode();
            break;
        case 'D':
            printf("\nDelete After data :");
            scanf("%d", &data);
            DeleteAfter(data);
            printf("\nAll Data in Linked List AFTER DELETE\n");
            ShowAllNode();
            break;
        }
    }
    return 0;
}