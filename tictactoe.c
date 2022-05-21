#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void start();
void player();
void computer();
void insert(int choice, char play);
void display_grid();
int check(char c);

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i = 0;      //do not use
int a = 0;      //do not use
int choice;
int taken[9] = {0};

void start()
{
    int random;
    
    srand(time(NULL));
    random = (rand() % 2);

    printf("Welcome to Tic Tac Toe\n");
    printf("Player   - X\n");
    printf("Computer - O\n");

    display_grid();

    if(random == 1)
        player();
    else
        computer();
}

void player()
{
    int j, z;
    player_start:
    printf("player chance\n");
    printf("Enter choice\n->");
    scanf("%d", &choice);
    for(j = 0; j < 9; j++)
    {
        if(choice == taken[j])
        {
            printf("already taken\n");
            goto player_start;
        }            
    }
    taken[a++] = choice;

    insert(choice, 'X');
    display_grid();
    z = check('X');
    if(z == 1)
    {
        printf("\033[1;32m");
        printf("Player wins\n");
        printf("\033[0m");
        getchar();
        exit(1);
    }
    i++;
    if(i < 9)    
        computer();
}

void computer()
{
    system("CLS");
    int j, z;
    printf("computer chance :\n");
    computer_start:
    srand(time(NULL));
    choice = (rand() % 9) + 1;

    for(j = 0; j < 9; j++)
    {
        if(choice == taken[j])
            goto computer_start;
    }
    
    taken[a++] = choice;

    insert(choice, 'O');
    display_grid();
    z = check('O');
    if(z == 1)
    {
        printf("\033[1;32m");
        printf("Computer wins\n");
        printf("\033[0m");
        getchar();
        exit(1);
    }

    i++;
    if(i < 9)    
        player();
}

void insert(int choice, char play)
{
    switch(choice)
    {
        case 1:
            board[0] = play;
            break;
        case 2:
            board[1] = play;
            break;
        case 3:
            board[2] = play;
            break;
        case 4:
            board[3] = play;
            break;
        case 5:
            board[4] = play;
            break;
        case 6:
            board[5] = play;
            break;
        case 7:
            board[6] = play;
            break;
        case 8:
            board[7] = play;
            break;
        case 9:
            board[8] = play;
            break;
    }
}

void display_grid()
{
    int j, n = 1;
    printf("\033[1;31m");
    for(j = 0; j < 9; j++)
    {
        printf("%c    ", board[j]);
        if(n % 3 == 0)
            printf("\n\n");
        n++;
    }
    printf("\033[0m");
}

int check(char c)
{
    if(board[0] == c && board[1] == c && board[2] == c)
        return 1;
    if(board[3] == c && board[4] == c && board[5] == c)
        return 1;
    if(board[6] == c && board[7] == c && board[8] == c)
        return 1;
    if(board[0] == c && board[3] == c && board[6] == c)
        return 1;
    if(board[1] == c && board[4] == c && board[7] == c)
        return 1;
    if(board[2] == c && board[5] == c && board[8] == c)
        return 1;
    if(board[0] == c && board[4] == c && board[8] == c)
        return 1;
    if(board[2] == c && board[4] == c && board[6] == c)
        return 1;
}

int main()
{
    start();
    printf("\033[1;33m");
    printf("Match Tie\n");
    printf("\033[0m");
    getchar();
    return 0;
}