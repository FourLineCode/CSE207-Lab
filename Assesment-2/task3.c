#include <stdio.h>
#include <string.h>

void preToPostFix(char *preFixIn, char *exprOut);
int findExprLen(char *exprIn);

int main (void)
{
    char  preFixExpr[256]  = "*+AB/CD";

    printf("\nlength: %d\n", findExprLen(preFixExpr));
   
    return 0;
}

int findExprLen (char *exprIn)
{
    int lenExpr1, lenExpr2;

    printf("%c\n", *exprIn);
    switch (*exprIn)
       {
        case '*':
        case '/':
        case '+':
        case '-':
            lenExpr1  =  findExprLen (exprIn + 1);
            lenExpr2  =  findExprLen (exprIn + 1 + lenExpr1);
            break;
        default:
            lenExpr1 = lenExpr2 = 0;
            break;
        }

    printf("%c %d %d %d\n", *exprIn, lenExpr1, lenExpr2, lenExpr1+lenExpr2+1);
    return lenExpr1 + lenExpr2 + 1;
}