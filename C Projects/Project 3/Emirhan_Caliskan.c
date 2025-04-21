#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define COURSE_1_COUNT 4
#define COURSE_2_COUNT 3
#define START_POSITION 16 * 8 + 8
char board[BOARD_SIZE * BOARD_SIZE];
int player_position = START_POSITION;
int ects = 0;
int movements = 0;
int flag1 = 0;
int flag2 = 0;
int last_position = '.';

void initialize_game();
void print_board();
void move_player(char direction);

int main()
{
    srand(time(NULL));
    initialize_game();
    print_board();

    char direction;
    while (1)
    {
        printf("\nTotal ECTS: %d", ects);
        printf("\nEnter direction (w/a/s/d) to move: ");
        scanf(" %c", &direction);
        move_player(direction);
        print_board();
        movements++;

        if (player_position == 16 * 16 - 1)
        {
            printf("\nCongratulations! You reached the X.\n");
            printf("Total ECTS: %d\n", ects);
            printf("Total movements: %d\n", movements);
            break;
        }
    }

    return 0;
}

void initialize_game()
{
    int i;
    int k;
    int points;
    int count1 = 0;
    int count2 = 0;
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        board[i] = '.';
    }
    for (k = 0; k < 9; k++)
    {
        for (i = 0; i < 9; i++)
        {

            board[(4 + k) * BOARD_SIZE + 4 + i] = '#';
        }
    }
    for (k = 0; k < 7; k++)
    {
        for (i = 0; i < 7; i++)
        {
            if (k >= 1 && k <= 5)
            {
                if (i >= 1 && i <= 5)
                {
                    board[(5 + k) * BOARD_SIZE + 5 + i] = '.';
                }
                else
                {
                    points = rand() % (3);
                    if (points == 0 || points == 2)
                    {
                        board[(5 + k) * BOARD_SIZE + 5 + i] = '.';
                    }
                    else if (points == 1)
                    {
                        if (count2 >= COURSE_2_COUNT)
                        {
                            board[(5 + k) * BOARD_SIZE + 5 + i] = '.';
                        }
                        else
                        {
                            board[(5 + k) * BOARD_SIZE + 5 + i] = '2';
                            count2++;
                        }
                    }
                }
            }
            else
            {
                points = rand() % (3);
                if (points == 0 || points == 2)
                {
                    board[(5 + k) * BOARD_SIZE + 5 + i] = '.';
                }
                else if (points == 1)
                {
                    if (count2 >= COURSE_2_COUNT)
                    {
                        board[(5 + k) * BOARD_SIZE + 5 + i] = '.';
                    }
                    else
                    {
                        board[(5 + k) * BOARD_SIZE + 5 + i] = '2';
                        count2++;
                    }
                }
            }
        }
    }
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < 5; i++)
        {

            board[(6 + k) * BOARD_SIZE + 6 + i] = '#';
        }
    }

    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < 3; i++)
        {
            if (k == 1)
            {
                if (i == 1)
                {
                    board[(7 + k) * BOARD_SIZE + 7 + i] = '.';
                }
                else
                {
                    points = rand() % (3);
                    if (points == 0)
                    {

                        board[(7 + k) * BOARD_SIZE + 7 + i] = '.';
                    }
                    else if (points == 1 || points == 2)
                    {
                        if (count1 >= COURSE_1_COUNT)
                        {
                            board[(7 + k) * BOARD_SIZE + 7 + i] = '.';
                        }
                        else
                        {
                            board[(7 + k) * BOARD_SIZE + 7 + i] = '1';
                            count1++;
                        }
                    }
                }
            }
            else
            {
                points = rand() % (4);
                if (points == 0)
                {
                    board[(7 + k) * BOARD_SIZE + 7 + i] = '.';
                }
                else if (points == 1 || points == 2 || points == 3)
                {
                    if (count1 >= COURSE_1_COUNT)
                    {
                        board[(7 + k) * BOARD_SIZE + 7 + i] = '.';
                    }
                    else
                    {
                        board[(7 + k) * BOARD_SIZE + 7 + i] = '1';
                        count1++;
                    }
                }
            }
        }
    }
    board[BOARD_SIZE * BOARD_SIZE - 1] = 'X';
    board[START_POSITION] = 'P';
}

void print_board()
{

    int i;
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        if (i % 16 == 0)
        {
            printf("\n");
        }
        printf("%c ", board[i]);
    }
}
void move_player(char direction)
{
    int new_position;
    switch (direction)
    {
    case 'w':
        new_position = (player_position - BOARD_SIZE + (BOARD_SIZE * BOARD_SIZE)) % (BOARD_SIZE * BOARD_SIZE);
        break;
    case 's':
        new_position = (player_position + BOARD_SIZE) % (BOARD_SIZE * BOARD_SIZE);
        break;
    case 'a':
        new_position = player_position - 1;
        break;
    case 'd':
        new_position = player_position + 1;
        break;
    default:
        return;
    }

    if (board[new_position] == '1')
    {
        ects += 8;
        printf("\nYou collected a first grade course! ECTS +8\n");
        if (ects >= 32)
        {
            flag1 = 1;
        }
        if (last_position == '#')
        {
            board[player_position] = '#';
        }
        else
        {
            board[player_position] = '.';
        }
        player_position = new_position;
        board[new_position] = 'P';
        last_position = '.';
    }
    else if (board[new_position] == '2')
    {
        ects += 8;
        printf("\nYou collected a first grade course! ECTS +8\n");
        if (ects >= 56)
        {
            flag2 = 1;
            flag1 = 1;
        }
        if (last_position == '#')
        {
            board[player_position] = '#';
        }
        else
        {
            board[player_position] = '.';
        }
        player_position = new_position;
        board[new_position] = 'P';
        last_position = '.';
    }
    else if (board[new_position] == '#')
    {

        if (flag2 == 1 && flag1 == 1)
        {
            if (last_position == '#')
            {
                board[player_position] = '#';
            }
            else
            {
                board[player_position] = '.';
            }
            player_position = new_position;
            board[new_position] = 'P';
            last_position = '#';
        }
        else if (flag1 == 1 && flag2 == 0)
        {
            int i = 0, k = 0;
            int flag = 0;
            for (k = 0; k < 9; k++)
            {
                for (i = 0; i < 9; i++)
                {
                    if (k >= 1 && k <= 7)
                    {
                        if (i >= 1 && i <= 7)
                        {
                        }
                        else
                        {
                            if (new_position == (4 + k) * BOARD_SIZE + 4 + i)
                            {
                                flag = 1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        if (new_position == (4 + k) * BOARD_SIZE + 4 + i)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if (flag == 1)
            {
                printf("You can't pass through the wall");
            }
            else
            {
                if (last_position == '#')
                {
                    board[player_position] = '#';
                }
                else
                {
                    board[player_position] = '.';
                }
                player_position = new_position;
                board[new_position] = 'P';
                last_position = '#';
            }
        }
        else
        {
            printf("You can't pass through the wall.");
        }
    }
    else
    {

        if (last_position == '#')
        {
            board[player_position] = '#';
        }
        else
        {
            board[player_position] = '.';
        }
        player_position = new_position;
        board[new_position] = 'P';
        last_position = '.';
    }
}
