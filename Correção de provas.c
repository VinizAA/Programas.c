#include <stdio.h>
#include <stdlib.h>
/// Eduardo de Faria Rios Perucello RA: 22009978
/// Vinícius Afonso Alvarez - RA: 22006181
int main()
{
    int Q, i, RA, TTal;
    char Gab[50], Resp[50];
    float NOTA, PA, S, M;


    printf("Digite a quantidade de questoes da prova: ");
    do{
    scanf("%d", &Q);
    }while(Q<0 || Q>50);
    printf("\n");

    for (i=0; i<Q; i++)
    {
    printf("Digite o gabarito da questao %d: ", i+1);
    do
    {
    getchar();
    scanf("%c", &Gab[i]);
    }
    while (Gab[i]!='a' && Gab[i]!='b' && Gab[i]!='c' && Gab[i]!='d' && Gab[i]!='e');
    }

    while(RA!=9999)
    {
    printf("\nRA do aluno:");
    scanf("%d", &RA);
    if(RA!=9999){

    for (i=0; i<Q; i++)
    {
    printf("Digite a resposta do aluno na questao %d: ", i+1);
    do
    {
    getchar();
    scanf("%c", &Resp[i]);
    }
    while (Resp[i]!='a' && Resp[i]!='b' && Resp[i]!='c' && Resp[i]!='d' && Resp[i]!='e');
    }

    printf("\nRA do aluno: %d", RA);

    printf("\nGabarito da prova: ");
    for (i=0; i<Q; i++)
    printf("[%c] ", Gab[i]);

    printf("\nResposta do aluno: ");
    for (i=0; i<Q; i++)
    printf("[%c] ", Resp[i]);


    NOTA=0;

    for(i=0; i<Q; i++)
    if (Resp[i]==Gab[i])
    NOTA = NOTA + 10./Q;

    if (NOTA>=5)
    printf("\nAPROVADO: NOTA %.2f", NOTA);
    else
    printf("\nREPROVADO: NOTA %.2f", NOTA);




    }
    }

    PA=0;
    TTal=0;
    TTal++;
    if(NOTA>5)
    PA=NOTA/TTal;

    printf("\n\nPorcentagem de aprovacao: %.2f%%", PA);



    return 0;
}

