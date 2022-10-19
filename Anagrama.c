#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define AZUL 9
#define VERDE 10
#define CIANO 11
#define VERMELHO 12
#define ROSA 13
#define AMARELO 14
#define BRANCO 15

void cabecalho ();
void escolhe_dif ();
void fase_facil (char bancopal[30][10], int l);
int imprime_info (int erros, int acertos, char bancopal[30][10], char bancoace[30][10]);
int valida_palavra (char plida);
void imprime_erros(int erros);
void mudacor (int cor);

int main()
{
    int i, j;
    char QuadLet [5][5] = {{'D','R','C','X','G'},
        {'M','I','P','E','U'},
        {'O','N','U','A','L'},
        {'E','A','I','R','S'},
        {'F','T','B','O','V'}
    };

    cabecalho ();
    escolhe_dif ();

    return 0;
}

/// função 1
void cabecalho ()
{
    int c;
    char QuadLet [5][5] = {{'D','R','C','X','G'},
        {'M','I','P','E','U'},
        {'O','N','U','A','L'},
        {'E','A','I','R','S'},
        {'F','T','B','O','V'}
    };

    mudacor(AZUL);
    printf("=================================== ANAGRAMA GAME ==================================\n");
    mudacor(BRANCO);
    printf("Regras:\n");
    printf("1. Elabore palavras com as letras dispostas. Elas "); mudacor(ROSA); printf("NAO "); mudacor(BRANCO); printf("precisam estar em sequencia.\n");
    printf("2. Existem "); mudacor(ROSA); printf("30 palavras");mudacor(BRANCO);printf(" em cada nivel.\n");
    printf("3. Ha"); mudacor(CIANO); printf(" 15 erros"); mudacor(BRANCO); printf(" em"); mudacor(CIANO); printf(" TODAS AS FASES\n"); mudacor(BRANCO);
    printf("4. Pode repetir letras apenas se tiver mais de uma ocorrencia.\n");
    printf("5. A qualquer momento, ");mudacor(ROSA);printf("pressione o 'ENTER' ");mudacor(BRANCO);printf("para sair do jogo.\n");
    printf("6. ");mudacor(CIANO);printf("Divirta-se!\n");

    mudacor(AZUL);
    printf("===================================== VAMOS LA =====================================\n\n");
}

/// função 2
void escolhe_dif ()
{
    int opcdif, c;
    char QuadLet [5][5] = {{'D','R','C','X','G'},
        {'M','I','P','E','U'},
        {'O','N','U','A','L'},
        {'E','A','I','R','S'},
        {'F','T','B','O','V'}
    };
    char bancopal [30] [10] = {"LAGO", "PARA", "BOCA", "AMOR", "ALVO", "CASA",
                               "DOCE", "ALMA", "MEIA", "RIMA", "ERRO", "PESO", "AULA", "BOLA", "RAIO",
                               "MOLE", "MAPA", "BOLO", "GATO", "PELE", "VIDA", "FACA", "CEDO", "BASE",
                               "DANO", "ODOR", "ROXO", "CENA", "OBRA", "NOME"
                              };

    char bancopal2 [30] [10] = {"IDEIA", "MUITO", "AINDA", "FORTE", "REGRA",
                                "COISA", "MANSO", "COPOS", "CERTO", "FLUXO", "MORTE", "GENTE", "EXATO",
                                "CLARO", "CAUDA", "APOIO", "FRASE", "BRISA", "FRIAS", "SORTE", "CAMPO",
                                "PRETO", "CURVA", "CAIXA", "LINDO", "MAGIA", "PEIXE", "AVISO", "COMEU", "TENIS"
                                };

    char bancopal3 [30] [10] = {"CASUAL", "GENTIL", "EMBORA", "CIENTE",
                                "REMOTO", "ROTINA", "ORIGEM", "BRIGAS", "FIGURA", "PRIMOS", "BAIRRO",
                                "MODELO", "BOVINO", "DEPOIS", "BONITO", "ELOGIO", "ETERNO", "ANIMAL",
                                "CRIMES", "PESADO", "IRONIA", "BONITA", "DENTRO", "BURACO", "MALUCO",
                                "VISITA", "CARONA", "ABERTO", "PERFIL", "ABAIXO"
                               };

    mudacor(BRANCO);
    printf("Escolha a dificuldade do jogo: ");

    mudacor(VERDE);
    printf("\n1 -> Facil (4 letras)");

    mudacor(AMARELO);
    printf("\n2 -> Media (5 letras)");

    mudacor(VERMELHO);
    printf("\n3 -> Dificil (6 letras)\n\n");

    do
    {
        mudacor(BRANCO);
        printf("Sua escolha: ");
        scanf("%d", &opcdif);
        fflush(stdin);
    }
    while (opcdif<1 || opcdif>3);

    switch (opcdif)
    {
    case 1:
        mudacor(VERDE);
        printf("Fase escolhida: Facil\n");
        fase_facil (bancopal, 4);
        break;
    case 2:
        mudacor(AMARELO);
        printf("Fase escolhida: Media\n");
        fase_facil (bancopal2, 5);
        break;
    case 3:
        mudacor(VERMELHO);
        printf("Fase escolhida: Dificil\n");
        fase_facil (bancopal3, 6);
        break;
    default:
        break;
    }
}

/// função 3
void fase_facil (char bancopal[30][10], int l)
{
    int i, j, k, tplida, acertos=0, erros=0, c, abp, palvalidada, aba, parada=0, volt;
    char plida[10], bancoace[30][10];
    char QuadLet [5][5] = {{'D','R','C','X','G'},
        {'M','I','P','E','U'},
        {'O','N','U','A','L'},
        {'E','A','I','R','S'},
        {'F','T','B','O','V'}
    };

    mudacor(AZUL);
    printf("====================================================================================");

    int numtent=0;
    while (numtent<15 && acertos<30 && parada==0)
    {
        printf("\n\n");
        mudacor(BRANCO);
        printf(" QUADRO DE LETRAS\n\n");
        for (i=0; i<5; i++)
        {
            printf("  ");
            for (j=0; j<5; j++)
                printf("%c  ", QuadLet[i][j]);
            printf("\n");
        }

        mudacor(VERMELHO);
        printf("\n>> Numero de erros: %d\n", erros);
        imprime_erros (erros);

        mudacor(VERDE);
        printf("\n>> Numero de acertos: %d\n", acertos);

        mudacor(CIANO);
        if(acertos==0)
            printf("\nPALAVRAS ACERTADAS: 0\n");
        else
        {
            printf("\n\t   PALAVRAS ACERTADAS");
            mudacor(BRANCO);
            for (i=0; i<acertos; i++)
                {
                    if(i%6==0)
                        printf("\n");
                    printf("%6s ", bancoace[i]);
                }
            printf("\n");
        }

        mudacor(BRANCO);
        printf("\nDIGITE UMA PALAVRA (%d letras): ", l);
        fflush(stdin);
        plida[0]='\0';
        scanf("%[^\n]", plida);

        if (strlen(plida)==0)
        {
            parada=1;
            break;
        }

        tplida = strlen(plida);
        for (i=0; i<tplida; i++)
            plida[i] = toupper (plida[i]);

        palvalidada = valida_plida(plida);

        if(palvalidada == 0)
        {
            mudacor (AMARELO);
            printf("DIGITE APENAS LETRAS!\n");
            mudacor(AZUL);
            printf("====================================================================================");
        }

        mudacor(BRANCO);
        if(palvalidada == 1)
        {
            int flag=0;
            for (i=0; i<30; i++)
            {
                if (stricmp (plida, bancopal[i])==0)
                {
                    flag=1;
                    for (j=0; j<acertos; j++)
                    {
                        if (stricmp (plida, bancoace[j])==0)
                        {
                            flag=2;
                            break;
                        }
                    }
                    break;
                }
            }

            if(flag==1)
            {
                mudacor(VERDE);
                printf("VOCE ACERTOU!\n");
                mudacor(AZUL);
                printf("====================================================================================");
                strcpy (bancoace[acertos], plida);
                acertos++;
            }
            else if (flag==2)
            {
                mudacor(AMARELO);
                printf("ESTA PALAVRA JA FOI DIGITADA!\n");
                mudacor(AZUL);
                printf("====================================================================================");
            }
            else
            {
                mudacor(VERMELHO);
                printf("VOCE ERROU!\n");
                mudacor(AZUL);
                printf("\n==================================================================================");
                erros++;
                numtent++;
            }
        }
    }

    mudacor(VERMELHO);
    printf("\n================================== FIM DO JOGO ===================================\n\n");

    imprime_info(erros, acertos, bancopal, bancoace);

    mudacor(CIANO);
    printf("\nDeseja recomecar o jogo?\n");
    mudacor(BRANCO);
    printf("0 -> NAO    1 -> SIM\n");
    printf("\nSua escolha: ");
    fflush(stdin);
    scanf("%d", &volt);
    printf("\n");

    if(volt==1)
    {
        system("cls");
        main();
    }
}

/// função 4
int imprime_info (int erros, int acertos, char bancopal[30][10], char bancoace[30][10])
{
    int i, abp, aba;

    mudacor(VERMELHO);
    printf(">> Numero de erros: %d\n", erros);
    imprime_erros (erros);
    printf("\n");

    mudacor(VERDE);
    printf(">> Numero de acertos: %d\n\n", acertos);

    mudacor(CIANO);
    printf("Deseja exibir o banco de palavras?\n");
    mudacor(BRANCO);
    printf("0 -> NAO    1 -> SIM\n");
    printf("\nSua escolha: ");
    fflush(stdin);
    scanf("%d", &abp);

    if (abp==1)
    {
        mudacor(AZUL);
        printf("\n\t     BANCO DE PALAVRAS");

        mudacor(BRANCO);
        for (i=0; i<30; i++)
        {
            if(i%6==0)
                printf("\n");
            printf("%6s ", bancopal[i]);
        }
        mudacor(AZUL);
        printf("\n====================================================================================");
        printf("\n");
    }

    if(acertos==30)
    {
        mudacor(VERDE);
        printf("VOCE ACERTOU TODAS AS PALAVRAS");
        printf("\n====================================================================================");
        printf("\n");
    }

    mudacor(CIANO);
    printf("\nDeseja exibir o banco de acertos?\n");
    mudacor(BRANCO);
    printf("0 -> NAO    1 -> SIM\n");
    printf("\nSua escolha: ");
    fflush(stdin);
    scanf("%d", &aba);

    if (aba==1)
    {
        mudacor(AZUL);
        printf("\n\t     BANCO DE ACERTOS");

        if (acertos==0)
        {
            mudacor(AMARELO);
            printf("\nVOCE NAO ACERTOU NENHUM PALAVRA");
            printf("\n====================================================================================");
            printf("\n");
        }

        mudacor(BRANCO);
        for (i=0; i<acertos; i++)
        {
            if(i%6==0)
                printf("\n");
            printf("%6s ", bancoace[i]);
        }
        mudacor(AZUL);
        printf("\n====================================================================================");
        printf("\n");

    }
    return 0;
}

/// função 5
int valida_plida (char plida[])
{
    int i;
    for(i=0; plida[i]!='\0'; i++)
    {
        if(isalpha (plida[i]))
            return 1;
    }
    return 0; // soh tem letras
}

/// função 6
void imprime_erros (int erros)
{
    int k;

    for(k=1; k<=erros; k++)
        printf(" <%d> ", k);
    printf("\n");
}

/// função pra mudar a cor
void mudacor (int cor)
{
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Saida, cor);
}
