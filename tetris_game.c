#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
char Matrix[21][12], fMatrix[21][12];
int score1 = 0;
typedef struct sh
{
    int block[4][4][4];
    int pts;
} shape;
shape Shape[7] = {
    {{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     25},
    {{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     50},
    {{0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     50},
    {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     50},
    {{0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     75},
    {{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
     75},
    {{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     75}};
void exit_handler()
{
    system("clear");
    printf("\nGAME OVER\nYOUR SCORE IS: %d\n", score1);
    exit(0);
}
void score()
{
    int i, j, k, l;
    for (i = 19; i >= 0; i--)
    {
        for (j = 1; j < 11; j++)
        {
            if (Matrix[i][j] == '\0')
                break;
        }
        if (j == 11)
        {
            if (i == 0)
            {
                printf("\nYOUR SCORE: %d \nGAME OVER", score1);
                exit(0);
            }
            score1 += 100;
            for (k = i; k > 0; k--)
            {
                for (l = 1; l < 11; l++)
                    fMatrix[k][l] = fMatrix[k - 1][l];
            }
        }
    }
    for (j = 1; j < 11; j++)
    {
        if (Matrix[0][j] == 1)
        {
            printf("\nGAME OVER\nYOUR SCORE IS: %d\n", score1);
            exit(0);
        }
    }
}
void initfMatrix()
{
    int i, j;
    char ch;
    for (i = 0; i < 21; i++)
        for (j = 0; j < 12; j++)
            fMatrix[i][j] = (j == 0 || i == 20 || j == 11) ? '#' : '\0';
    system("clear");
    printf("\n\n\t\t\tWELCOME TO TETRIS\n");
printf("\n\t\tInstructions:\n\t\t1.Enter 1 to rotate the piece once every time,0 to stop rotating.\n\t\t2.Enter L to move the piece left and enter R to move the piece right.\n\t\t Enter N to stop and move the piece downwards.\n\t\t3.Press Ctrl+C to quit.\n");
printf("\n\t\tPress Enter key to continue..\n");
ch=getchar();
}
void print_on_fboard(int shapeno, int rotno, int x, int y)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (Shape[shapeno].block[rotno][i][j] == 1)
                fMatrix[x + i][y + j] = (char)Shape[shapeno].block[rotno][i][j];
        }
    }
    score1 += Shape[shapeno].pts;
}
void displayBoard()
{
    int i, j;
    system("clear");
    for (i = 0; i < 21; i++)
    {
        printf("\n");
        for (j = 0; j < 12; j++)
            printf("%c",(Matrix[i][j]==(char)1) ? 'X' :(Matrix[i][j]=='\0') ? ' ':Matrix[i][j]);
    }
    printf("\n");
    printf("\nYOUR SCORE: %d\n", score1);
}
int checkposition(int shapeno, int rotno, int x, int y)
{
    int i, j, flag = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (Shape[shapeno].block[rotno][i][j] == 1)
            {
                if (x + i == 20 || y + j == 0 || y + j == 11)
                    return 0;
                else if (fMatrix[x + i][y + j] == 1)
                    return 2;
            }
        }
    }
    return 1;
}
void print_shape_on_board(int shapeno, int rotno, int x, int y)
{
    int i, j, flag = 0;
    for (i = 0; i < 21; i++)
        for (j = 0; j < 12; j++)
            Matrix[i][j] = fMatrix[i][j];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (Shape[shapeno].block[rotno][i][j] == 1)
                Matrix[x + i][y + j] = (char)Shape[shapeno].block[rotno][i][j];
        }
    }
}
int rotate_shape(int shno, int rotno)
{
    switch (shno)
    {
    case 0:
        printf("No rotations possible\n");
        break;
    case 1:
    case 2:
    case 3:
        rotno = ((rotno) + 1) % 2;
        break;
    case 4:
    case 5:
    case 6:
        rotno = ((rotno) + 1) % 4;
        break;
    }
    return rotno;
}
int main()
{
    int i, j, shno = -1, rno, py, px, flag = 0, c;
    char ch;
    signal(SIGINT, exit_handler);
    initfMatrix();
    while (1)
    {
        srand(time(0));
        shno = rand() % 7;
        rno = 0;
        px = 0;
        py = 4;
        if (checkposition(shno, rno, px, py) == 2)
        {
            system("clear");
            printf("\nGAME OVER\nYOUR SCORE IS: %d\n", score1);
            exit(0);
        }
        print_shape_on_board(shno, rno, px, py);
        displayBoard();
        printf("\nDo you want to rotate it?(1/0): ");
        scanf("%d", &c);
        while (c != 0)
        {
            rno = rotate_shape(shno, rno);
            print_shape_on_board(shno, rno, px, py);
            displayBoard();
            printf("\nDo you want to rotate it?(1/0):");
            scanf("%d", &c);
        }
        print_shape_on_board(shno, rno, px, py);
        displayBoard();
        printf("\nMove left(L) or right(R) (Press N for no movement): ");
        scanf("%c", &ch);
        while (ch != 'N')
        {
            px++;
            if (checkposition(shno, rno, px, py) == 0)
            {
                px--;
                if (px == 20)
                    flag = 1;
            }
            else if (checkposition(shno, rno, px, py) == 2)
            {
                px--;
                flag = 1;
            }
            else
            {
                print_shape_on_board(shno, rno, px, py);
                displayBoard();
            }
            flag = 0;
            switch (ch)
            {
            case 'R':
            {
                py++;
                if (checkposition(shno, rno, px, py) == 0)
                    py--;
                else if (checkposition(shno, rno, px, py) == 2)
                {
                    py--;
                    flag = 1;
                }
                else
                {
                    print_shape_on_board(shno, rno, px, py);
                    displayBoard();
                }
                break;
            }
            case 'L':
            {
                py--;
                if (checkposition(shno, rno, px, py) == 0)
                    py++;
                else if (checkposition(shno, rno, px, py) == 2)
                {
                    py++;
                    flag = 1;
                }
                else
                {
                    print_shape_on_board(shno, rno, px, py);
                    displayBoard();
                }
                break;
            }
            default:
                break;
            }
            if (flag == 1)
                break;
            printf("\n>>>");
            scanf("%c", &ch);
        }
        while (1)
        {
            px++;
            if (checkposition(shno, rno, px, py) == 0)
            {
                px--;
                break;
            }
            else if (checkposition(shno, rno, px, py) == 2)
            {
                px--;
                break;
            }
            else
            {
                print_shape_on_board(shno, rno, px, py);
                displayBoard();
            }
        }
        print_on_fboard(shno, rno, px, py);
        displayBoard();
        score();
        for (i = 0; i < 21; i++)
        {
            printf("\n");
            for (j = 0; j < 12; j++)
                printf("%c", fMatrix[i][j]);
        }
    }
    return 0;
}