#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int Fa[10][10][10];
int states[2][10];

int curr, row = 0, col = 0, sr = 0, sc = 0, th = 0, in;

/* NFA function */
int nfa(char *string, int state)
{
    int i;

    for (i = 0; i <= row; i++)
    {
        if (*string)
        {
            curr = Fa[state][*string - 'a'][i];

            if (curr == -1)
                break;

            if (nfa(string + 1, curr))
                return 1;
        }
        else
        {
            if (states[1][i] == -1)
                break;

            if (state == states[1][i])
                return 1;
        }
    }

    return 0;
}

int main()
{
    FILE *fp;
    int i, j, k, flag = 0;
    char c;
    char str[100];

    /* Open input file */
    fp = fopen("Nfa_ip.txt", "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open Nfa_ip.txt\n");
        return 1;
    }

    /* Initialize final states */
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 10; j++)
        {
            states[i][j] = -1;
        }
    }

    /* Initialize transition table */
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 10; k++)
            {
                Fa[i][j][k] = -1;
            }
        }
    }

    /* Read NFA information from file */
    while (fscanf(fp, "%d", &in) != EOF)
    {
        fscanf(fp, "%c", &c);

        if (flag)
        {
            states[sr][sc++] = in;

            if (c == '\n')
            {
                sr++;
                sc = 0;
            }
        }
        else if (c == '#')
        {
            flag = 1;

            Fa[row][col][th] = in;

            printf("\nFa[%d][%d][%d] = %d",
                   row, col, th, Fa[row][col][th]);
        }
        else
        {
            Fa[row][col][th] = in;

            printf("\nFa[%d][%d][%d] = %d",
                   row, col, th, Fa[row][col][th]);

            if (c == ',')
            {
                th++;
            }
            else if (c == '\n')
            {
                col = 0;
                row++;
                th = 0;
            }
            else
            {
                col++;
                th = 0;
            }
        }
    }

    fclose(fp);

    /* Input string */
    printf("\n\nEnter the string : ");
    scanf("%99s", str);

    /* Check string using NFA */
    if (nfa(str, states[0][0]))
    {
        printf("\nString Is Accepted");
    }
    else
    {
        printf("\nString Not Accepted");
    }

    getch();

    return 0;
}