#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define MaxStack 40

char postfix1[80] = {"AB+C-D/"};
float ValPostfix[80];
float ValOperandST[MaxStack];
int SP = 0;

void push(float ValOperand)
{
    if (SP == MaxStack)
    {
        printf("Error Stack Over Flow ");
    }
    else
    {
        SP = SP + 1;
        ValOperandST[SP] = ValOperand;
    }
    printf("%d %f",SP, ValOperandST[SP]) ;
}

float pop()
{
    float ValOperand;
    if (SP != 0)
    {
        ValOperand = ValOperandST[SP];
        SP--;
        return ValOperand;
    }
    else
        printf("\nError Stack Under Flow!!!...\n");
}

void CalPostfix(char postfix[80])
{
    float pop1, pop2, value;
    int i, len;
    char ch;
    len = strlen(postfix);
    printf("Postfix = %s \n", postfix);
    for (i = 0; i <= len - 1; i++)
    {
        ch = postfix[i];
        if (strchr("+-*/^", ch) == 0)
        {
            printf("\nAssign Number to %c : ", ch);
            scanf("%f", &ValPostfix[i]);
        }
    }
    for (i = 0; i <= len - 1; i++)
    {
        ch = postfix[i];
        if (strchr("+-*/^", ch) == 0)
        {
            push(ValPostfix[i]);
        }
        else
        {
            pop1 = pop();
            pop2 = pop();
            switch (ch)
            {
            case '+':
                value = pop2 + pop1;
                push(value);
                break;
            case '-':
                value = pop2 - pop1;
                push(value);
                break;
            case '*':
                value = pop2 * pop1;
                push(value);
                break;
            case '/':
                value = pop2 / pop1;
                push(value);
                break;
            case '^':
                value = pow(pop2, pop1);
                push(value);
                break;
            } // end sw
        }     // end if
    }         // end if
    printf("\nANS = %f ", pop());
}

int main()
{
    printf("POSTFIX CALCULATION PROGRAM\n");
    printf("=============================\n");
    CalPostfix(postfix1);
    getch();
    return 0;
}