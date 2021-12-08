#include <stdio.h>

class CalPost
{
private:
    #define MaxStack 40
    int SP = 0;
    float ValOperandST[MaxStack];
    float ValPostfix[80];
    void push(float ValOperand);
    float pop();
    void CalPostfix(char postfix1[80]);

public:
    //Todo Public prototype function PostF_Conver
    void PostF_Conver(char postfix_in[80]);
};