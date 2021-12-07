#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "calPost.h"


void CalPost::push(float ValOperand)
{
    if (SP == MaxStack)
    {
        printf("ERROR STACK OVER FLOW!!!...\n");
    }
    else
    {
        SP = SP + 1;
        ValOperandST[SP] = ValOperand;
    }
}

float CalPost::pop()
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

void CalPost::CalPostfix(char postfix[80])
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

void CalPost::PostF_Conver(char postfix_in[80])
{
    printf("\n==============================\n");
    printf("POSTFIX CALCULATION PROGRAM\n");
    printf("==============================\n");
    CalPostfix( postfix_in )  ;
    getch();
}
