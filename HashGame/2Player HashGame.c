#include <stdlib.h>
#include <stdio.h>

void main ()
{
    char resposta;
    char matriz [3][3];
    int jogando = 1;
    int jogador = 1; //jogador 1 -> player | jogador -> 2 player ou npc
    int contador = 0;
    int linha , coluna;
    int i, j;

    for (i = 0 ; i < 3 ; i = i + 1)
    {
        for (j = 0 ; j < 3 ; j = j + 1)
        {
            matriz[i][j] = '.';
        }
    }
        printf ("Jogo contra o Player2\n");
        while (jogando == 1)
        {
            if (jogador == 1) // vez do jogador 1
            {
                for (i = 0 ; i < 3 ; i = i + 1) //printar tabuleiro na tela (inicio)
                {
                    for (j = 0 ; j < 3 ; j = j+ 1)
                    {
                        printf ("%c" ,matriz[i][j]);
                    }
                    printf("\n");
                } //printar tabuleiro na tela (fim)
                printf ("Player 1 esta jogando\n");
                printf ("Linha:");
                scanf ("%d" , &linha);
                printf ("Coluna:");
                scanf ("%d" , &coluna);
                linha = linha - 1;
                coluna = coluna - 1;

                if (coluna <= 2 && coluna >= 0 && linha <= 2 && linha >= 0)
                {
                    if (matriz [linha][coluna] != '.')
                    {
                        printf ("Escolha outra casa\n");
                    }
                    else
                    {
                        matriz[linha][coluna] = 'X';
                        jogador = 2;
                        contador = contador + 1;
                    }
                }
                else
                {
                    printf("Jogada invalida, escolha uma linha e uma coluna entre 1 e 3\n");
                }

            }
            else // vez do jogador 2
            {
                 for (i = 0 ; i < 3 ; i = i + 1)
                {
                    for (j = 0 ; j < 3 ; j = j+ 1)
                    {
                        printf ("%c" ,matriz[i][j]);
                    }
                    printf("\n");
                }
                printf ("Player 2 esta jogando\n");
                printf ("Linha:");
                scanf ("%d" , &linha);
                printf ("Coluna:");
                scanf ("%d" , &coluna);
                linha = linha - 1;
                coluna = coluna -1;
                if (coluna <= 2 && coluna >= 0 && linha <= 2 && linha >= 0)
                {
                    if (matriz [linha][coluna] != '.')
                    {
                        printf ("Escolha outra casa\n");
                    }
                    else
                    {
                        matriz[linha][coluna] = 'O';
                        jogador = 1;
                        contador = contador + 1;
                    }
                }
                else
                {
                    printf("Jogada invalida, escolha uma linha e uma coluna entre 1 e 3\n");
                }
            }
            for (i = 0 ; i < 3 ; i = i + 1 ) //checar se venceu por colunas ou linhas:
            {
                if ((matriz[i][0] == matriz [i][1]) && (matriz[i][1] == matriz[i][2]) && (matriz[i][1] != '.'))
                {
                    if(matriz[i][1] == 'X')
                    {
                        printf("Jogador 1 Venceu!!!\n");
                        jogando = 0;
                    }
                    else
                    {
                        printf("Jogador 2 aq!!!\n");
                        jogando = 0;
                    }

                }
                if ((matriz[0][i] == matriz [1][i]) && (matriz[2][i] == matriz[1][i]) && (matriz[1][i] != '.'))
                {
                    if(matriz[0][i] == 'X')
                    {
                        printf("Jogador 1 Venceu!!!\n");
                        jogando = 0;
                    }
                    else
                    {
                        printf("Jogador 2 venceu!!!\n");
                        jogando = 0;
                    }
                }
            }
            if ((matriz[0][0]==matriz[1][1]) && (matriz[1][1]==matriz[2][2]) && (matriz[1][1]!='.')) //diagonal principal
            {
                if(matriz[1][1] =='X')
                {
                    printf("Jogador 1 Venceu!!!\n");
                    jogando = 0;
                }
                else
                {
                    printf("Jogador 2 Venceu!!!\n");
                    jogando = 0;
                }
            }
            if ((matriz[0][2]==matriz[1][1])&&(matriz[1][1]==matriz[2][0])&&(matriz[1][1]!='.')) //diagonal secundaria
            {
               if(matriz[1][1] =='X')
                {
                    printf("Jogador 1 Venceu!!!\n");
                    jogando =0;
                }
                else
                {
                    printf("Jogador 2 Venceu!!!\n");
                    jogando = 0;
                }
            }
            if (contador == 9)
            {
                jogando = 0;
                printf("Acabaram as jogadas\n");
            }
        }
    for (i = 0 ; i < 3 ; i = i + 1) //printar tabuleiro na tela
    {
        for (j = 0 ; j < 3 ; j = j + 1)
        {
            printf ("%c" ,matriz[i][j]);
        }
            printf("\n");
    }
}