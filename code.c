/*
    Title   : Tic Tac Toe game
    Author  : Lomik Parmar
    Date    : 2025-02-21
*/
#include <stdio.h>
#include <conio.h>
int x, y; // global var to use in main and digitPlace function and no need to return from digitPlace fun.

int isFilled(char board[3][3])
{ // check whether there is any place remains to fill.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '*')
            {
                return 1; // return TRUE value if there is atleast one place to fill.
            }
        }
    }
    return 0; // Game will stop to take input when there is no place to fill.
}
int isAvailable(int x, int y, char board[3][3])
{ // Check that entered number place is filled with O/X or not.
    if (board[x][y] == 'O' || board[x][y] == 'X')
    {
        return 0; // Return FALSE if place is filled with O or X.
    }
    return 1;
}
void digitPlace(int place)
{ // Determine location in board.
    switch (place)
    {
    case 1:
        x = 0;
        y = 0;
        break;

    case 2:
        x = 0;
        y = 1;
        break;

    case 3:
        x = 0;
        y = 2;
        break;

    case 4:
        x = 1;
        y = 0;
        break;

    case 5:
        x = 1;
        y = 1;
        break;

    case 6:
        x = 1;
        y = 2;
        break;

    case 7:
        x = 2;
        y = 0;
        break;

    case 8:
        x = 2;
        y = 1;
        break;

    case 9:
        x = 2;
        y = 2;
        break;

    default:
        printf("Invalid input!!");
    }
}

void printBoard(char board[3][3])
{ // To print any 3x3 array
    printf("\n\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c\t", board[i][j]);
        }
        printf("\n\n");
    }
}
int check(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '*')
        {
            return 1;
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '*')
        {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '*')
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '*')
    {
        return 1;
    }
    return 0;
}
int main()
{
    int place, move = 1;
    char board[3][3] = {{'*', '*', '*'},
                        {'*', '*', '*'},
                        {'*', '*', '*'}};

    printBoard(board);

    printf("First move for \'O\'");
    while (isFilled(board)) // Acts as infinite loop, when there is blank space for input.
    {
        scanf("\n\n%d", &place);
        digitPlace(place); // location of entered digit in board/array.

        if (isAvailable(x, y, board))
        {                      // this will execute only if all conditions are satisfied and then move will be count.
            if (move % 2 != 0) // Odd for move of O.
            {
                board[x][y] = 'O';
            }
            else // Even for move of X.
            {
                board[x][y] = 'X';
            }
            if (check(board) == 1) // Check after every moves if game is over then declare result.
            {
                if (move % 2 != 0) // Check is last move played by O ?
                {
                    printf("\n\nO is winner!!\n\n");
                }
                else
                {
                    printf("\n\nX is winner!!\n\n");
                }
                return 0;
            }
            move++; // Move will be count if O/X is placed in board.
        }
        else
        {
            printf("Invalid input!!");
        }
        printBoard(board); // Print board after each move.
    }
    return 0;
}