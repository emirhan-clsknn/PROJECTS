#include <stdio.h>
#include <string.h>

#define MAX_COL_COUNT 80
#define MAX_ROW_COUNT 80

void search_p1(char strs[][MAX_COL_COUNT], int num_rows,
               int matches[][2], int *num_matches);
void search_p2(char strs[][MAX_COL_COUNT], int num_rows,
               int matches[][2], int *num_matches);
void search_p3(char strs[][MAX_COL_COUNT], int num_rows,
               int matches[][2], int *num_matches);
int main()
{
    FILE *file = fopen("input2.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return 1;
    }

    char strs[MAX_ROW_COUNT][MAX_COL_COUNT];
    int num_rows = 0;

    while (fgets(strs[num_rows], MAX_COL_COUNT, file) != NULL)
    {

        strs[num_rows][strcspn(strs[num_rows], "\n")] = '\0';
        num_rows++;
    }

    fclose(file);

    int matches[MAX_ROW_COUNT * MAX_COL_COUNT][2];
    int num_matches;
    int i;
    search_p1(strs, num_rows, matches, &num_matches);
    for (i = 0; i < num_matches; i++)
    {
        printf("P1 @ (%d,%d)\n", matches[i][0], matches[i][1]);
    }

    search_p2(strs, num_rows, matches, &num_matches);
    for (i = 0; i < num_matches; i++)
    {
        printf("P2 @ (%d,%d)\n", matches[i][0], matches[i][1]);
    }

    search_p3(strs, num_rows, matches, &num_matches);
    for (i = 0; i < num_matches; i++)
    {
        printf("P3 @ (%d,%d)\n", matches[i][0], matches[i][1]);
    }

    return 0;
}
void search_p1(char strs[][MAX_COL_COUNT], int num_rows,
               int matches[][2], int *num_matches)
{
    int p_lenght = strlen("***++++***++++***");
    *num_matches = 0;
    int i;
    for (i = 0; i < num_rows; i++)
    {
        char *pos = strs[i];
        while ((pos = strstr(pos, "***++++***++++***")) != NULL)
        {
            matches[*num_matches][0] = i + 1;
            matches[*num_matches][1] = (int)(pos - strs[i]) + 1;
            (*num_matches)++;
            pos += p_lenght;
        }
    }
}

void search_p2(char strs[][MAX_COL_COUNT], int num_rows,
               int matches[][2], int *num_matches)
{
    int p_lenght = strlen("+*+*+");
    *num_matches = 0;
    int col;
    int row;
    for (col = 0; col < MAX_COL_COUNT; col++)
    {
        char col_pattern[MAX_ROW_COUNT] = "";

        for (row = 0; row < num_rows; row++)
        {
            col_pattern[row] = strs[row][col];
        }

        col_pattern[num_rows] = '\0';

        char *pos = col_pattern;
        while ((pos = strstr(pos, "+*+*+")) != NULL)
        {
            matches[*num_matches][0] = (int)(pos - col_pattern) + 1;
            matches[*num_matches][1] = col + 1;
            (*num_matches)++;
            pos += p_lenght;
        }
    }
}

void search_p3(char strs[][MAX_COL_COUNT], int num_rows,
               int matches[][2], int *num_matches)
{
    int p_lenght = strlen("+++++");
    *num_matches = 0;
    int start_row;
    int start_col;
    int row, col;

    for (start_row = 0; start_row < num_rows; start_row++)
    {
        char d_pattern[MAX_COL_COUNT] = "";
        int d_lenght = 0;
        for (start_col = 0; start_col < MAX_COL_COUNT; start_col++)
        {

            d_lenght = 0;
            for (row = start_row, col = start_col; row < num_rows && col < MAX_COL_COUNT; row++, col++)
            {
                d_pattern[d_lenght++] = strs[row][col];
            }
            d_pattern[d_lenght] = '\0';
            char *pos = d_pattern;
            while ((pos = strstr(pos, "+++++")) != NULL)
            {
                printf("");
                matches[*num_matches][0] = start_row + (int)(pos - d_pattern) + 1;
                matches[*num_matches][1] = col - d_lenght + 1;
                (*num_matches)++;
                pos += p_lenght;
            }
        }
    }
}
