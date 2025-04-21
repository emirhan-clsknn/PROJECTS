#include <stdio.h>

#define NUMBER_OF_STONES 4



void initializeGame(int board[][7], int n);
void printBoard(int board[][7]);
void gamePlay(int board[][7]);
int move(int board[][7], int selected_cup, int current_player);

int main()
{
    int board[2][7]; 
    int n = NUMBER_OF_STONES;       

    initializeGame(board, n);
    printBoard(board);
    gamePlay(board);

    return 0;
}

void initializeGame(int board[][7], int n)
{
    int i;
    for (i = 0; i < 7; i++)
    {

        if (i == 0)
        {
            board[0][i] = 0;
            board[1][i] = 0;
        }
        else
        {
            board[0][i] = n;
            board[1][i] = n;
        }
    }
}

void printBoard(int board[][7])
{
    printf("+-----+----+----+----+----+----+----+-----+\n");
    printf("|     | %2d | %2d | %2d | %2d | %2d | %2d |     |\n",
           board[1][6], board[1][5], board[1][4], board[1][3], board[1][2], board[1][1]);
    printf("| %2d  |----+----+----+----+----+----| %2d  |\n", board[0][0], board[1][0]);
    printf("|     | %2d | %2d | %2d | %2d | %2d | %2d |     |\n",
           board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6]);
    printf("+-----+----+----+----+----+----+----+-----+\n");
}


void gamePlay(int board[][7])
{
    int current_player = 0;


    while (1)
    {
        int selected_cup;


        if (current_player == 0)
        {
            while (1)
            {
                printf("Player %d's turn: ", current_player + 1);
                scanf("%d", &selected_cup);
                if (selected_cup <= 6 && selected_cup >= 1)
                {
                    if (board[current_player][selected_cup] == 0)
                    {
                        printf("This cup is empty.\n");
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    printf("Invalid choice!\n");
                }
            }
        }
        else
        {
            while (1)
            {
                printf("Computer's turn: ");
                
                int max=0,max_col=0;
                int j=0;
                for (j = 1; j <= 6; j++)
                {
                    if (board[current_player][j] > max)
                    {
                        max = board[current_player][j];
                        max_col = j;
                    }
                }
                selected_cup = max_col;
                printf("%d\n", selected_cup);
                if (selected_cup <= 6 && selected_cup >= 1)
                {
                    if (board[current_player][selected_cup] == 0)
                    {
                        printf("This cup is empty.");
                    }
                    break;
                }
                else
                {
                    printf("Invalid choice");
                }
            }
        }

        current_player=move(board, selected_cup, current_player);


        int empty_count = 0;
        int empty_count1 = 0;
        int i;
        for (i = 1; i <= 6; i++)
        {
            if (board[0][i] == 0)
                empty_count++;
            if (board[1][i] == 0)
                empty_count1++;
        }
        if (empty_count == 6)
        {
            printf("Game over!\n");
            break;
        }
        if (empty_count1 == 6)
        {
            printf("Game over!\n");
            break;
        }
    }

    int player_score = board[0][0];
    int computer_score = board[1][0];
    printf("Player's score: %d\n", player_score);
    printf("Computer's score: %d\n", computer_score);
    if (player_score > computer_score)
    {
        printf("Player wins!\n");
    }
    else if (player_score < computer_score)
    {
        printf("Computer wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}


int move(int board[][7], int selected_cup, int current_player)
{
    int current_side = current_player;


    int stones = board[current_side][selected_cup];
    board[current_side][selected_cup] = 0;

    while (stones > 0)
    {
        selected_cup++;
        if (selected_cup == 7)
        {
            current_side = 1 - current_side; 
            selected_cup = 0;
        }


        if (current_side == current_player)
        {
            board[current_side][selected_cup]++;
            stones--;
            
        }
        else if (current_side != current_player && selected_cup == 0)
        {
        }
        else
        {
            board[current_side][selected_cup]++;
            stones--;
        }
        
        if (stones == 0)
        {
            printBoard(board);
            if (current_side == current_player && selected_cup == 0)
            {
                current_player = current_player;
            }
            else if (board[current_side][selected_cup] == 1)
            {
                current_player = 1 - current_player;
            }
            else
            {
                stones = board[current_side][selected_cup];
                board[current_side][selected_cup] = 0;
            }
        }
        
    }
    
    return current_player;
}
