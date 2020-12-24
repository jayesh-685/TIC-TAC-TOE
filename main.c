#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int turnCount = 1;
int input = 0;

void drawBoard();
bool markBoard();
bool checkForWin();

int main()
{

    while(turnCount <= 9)
    {
        drawBoard();

        scanf("%d", &input);

        if(!markBoard())
            turnCount++;

        checkForWin();
        if(checkForWin() == true)
            break;
    }

    drawBoard();

    if(checkForWin())
    {
        if(turnCount%2 == 1)
            printf("\t\aPlayer 2 won the game!\n");
        else if(turnCount%2 == 0)
            printf("\t\aPlayer 1 won the game!\n");
    }
    else
        printf("Game draw");


    return 0;
}

bool markBoard()
{
    bool invalidMove = false;
    if(input < 1 || input > 9 || board[input] == '*' || board[input] == '+')
    {
        printf("\tInvalid input\n");
        invalidMove = true;
    }

    if(turnCount%2 == 1)
        board[input] = '*';
    else if(turnCount%2 == 0)
        board[input] = '+';

    return invalidMove;
}

bool checkForWin()
{
    bool gameWon = false;

    for(int i=1; i<=7; i+=3)
    {
        if(board[i] == board[i+1] && board[i+1] == board[i+2])
            gameWon = true;
    }

    for(int i=1; i<=7; ++i)
    {
        if(board[i] == board[i+3] && board[i+3] == board[i+6])
            gameWon = true;
    }

    if(board[1] == board[5] && board[5] == board[9])
            gameWon = true;
    else if(board[3] == board[5] && board[5] == board[7])
            gameWon = true;

    return gameWon;
}
void drawBoard()
{
    system("clear");

    printf("\tTIC-TAC-TOE GAME\n\n\n");
    printf("\tPlayer 1(*)  Player 2(+)\n\n\n");

    printf("\t   |     |\n");
    printf("\t%c  |  %c  |  %c\n", board[7], board[8], board[9]);
    printf("       ----|-----|----\n");
    printf("\t%c  |  %c  |  %c\n", board[4], board[5], board[6]);
    printf("       ----|-----|----\n");
    printf("\t%c  |  %c  |  %c\n", board[1], board[2], board[3]);
    printf("\t   |     |\n\n\n");

    if(checkForWin() == false)
        printf("\n\tPlayer %d turn: ", turnCount%2 == 1?1:2);

}
