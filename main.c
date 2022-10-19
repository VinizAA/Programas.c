#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    float op1, op2, res;
    char opc, sn='s';

    while (tolower(sn)=='s')
    {
        scanf ("%f%c%f", &op1,&opc,&op2);

        switch (opc)
        {
        case '+':
            res = op1 + op2;
            printf("%.1f%.1c%.1f=%.1f",op1,opc,op2,res);
            break;

        case '-':
            res = op1 - op2;
            printf("%.1f%.1c%.1f=%.1f",op1,opc,op2,res);
            break;

        case '*':
            res = op1 * op2;
            printf("%.1f%.1c%.1f=%.1f",op1,opc,op2,res);
            break;

        case '/':
            if (op2>0)
            {
                res = op1/op2;
                printf("%.1f%.1c%.1f=%.1f",op1,opc,op2,res);
            }
            else
                printf("ERRO: DIVISAO POR ZERO");
            break;

        default:
            printf("INVALIDO");
        }
        printf("\nContinuar? (s/n):");
        getchar();
        scanf("%c", &sn);
    }
    return 0;
}
