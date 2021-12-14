#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "PostCalculate/calPost.h" //? use PostF_Conver

#define MaxStack 40

char infix1[80];
char postfix_output[80]; //? create postfix_output for get Postfix and send to PostF_Conver
char OpSt[MaxStack];
int SP = 0;

void infixTOpostfix(char infix2[80]);
int precedenceST(char oper);
int precedenceIP(char oper);
int pop();
void push(char oper);
char push_postfix(char inputChar);

int main()
{
    CalPost post;
    printf("\nInsert INFIX : ");
    scanf("%[^\n]", infix1);
    printf("\n==================================\n");
    printf("INFIX to POSTFIX CONVERSION PROGRAM\n");
    printf("==================================\n");
    infixTOpostfix(infix1);
    getch();
    post.PostF_Conver(postfix_output);
    return 0;
}

// Todo get Postfix output Char to save on postfix_output
char push_postfix(char inputChar)
{
    strncat(postfix_output, &inputChar, 1);
    return inputChar;
}

void push(char oper)
{
    if (SP == MaxStack)
    {
        printf("ERROR STACK OVER FLOW!!!...\n");
    }
    else
    {
        SP = SP + 1;
        OpSt[SP] = oper;
    }
}

int pop()
{
    char oper;
    if (SP != 0)
    {
        oper = OpSt[SP];
        SP--;
        return (oper);
    }
}

int precedenceIP(char oper)
{
    switch (oper)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
        break;
    case '^':
        return 4;
    case '(':
        return 4;
    }
}

int precedenceST(char oper)
{
    switch (oper)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return 0;
    }
}

void infixTOpostfix(char infix2[80])
{
    int i, j, len;
    char ch, temp;
    printf("INFIX \t\t: %s\n", infix2);
    len = strlen(infix2);
    printf("Infix Length \t: %d \n", len);
    printf("POSTFIX IS \t: ");
    for (i = 0; i <= len; i++)
    {
        ch = infix2[i];
        if (strchr("+-*/^()", ch) == 0)
        {
            printf("%c", push_postfix(ch));
        }
        else
        {
            if (ch != ')')
            {
                if (precedenceIP(ch) > precedenceST(OpSt[SP]))
                    push(ch);
                else
                {
                    printf("%c", push_postfix(pop()));
                    while (precedenceIP(ch) <= precedenceST(OpSt[SP]) && SP != 0)
                        printf("%c", push_postfix(pop()));
                    push(ch);
                }
            }
            else
            {
                temp = pop();
                while ((temp != '('))
                {
                    printf("%c", push_postfix(temp));
                    temp = pop();
                }
            }
        }
    }
    j = SP;
    for (i = 1; i <= j; i++)
    {
        printf("%c", push_postfix(pop()));
    }
    printf("\n");
}