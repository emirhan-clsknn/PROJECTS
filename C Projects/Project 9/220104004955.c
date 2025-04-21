#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_FLOWER 100
#define MAX_MOVE 200

typedef struct
{
    char map[MAX_SIZE][MAX_SIZE];
    int width;
    int height;
    int flower_x[MAX_FLOWER];
    int flower_y[MAX_FLOWER];
} Forest;  

typedef struct
{
    int coord_x;
    int coord_y;
    int water_bottle_size;
} Botanist;

int init_game(Forest *forest, Botanist *botanist);
void display_forest(Forest *forest, Botanist *botanist);
void search(int x, Forest *forest, Botanist *botanist);
void save_last_state(Forest *forest, Botanist *botanist);

int main()
{
    Forest forest;
    Botanist botanist;

    int flower = init_game(&forest, &botanist); /*  init game flower sayısını return  ediyor*/

    search(flower, &forest, &botanist);

    return 0;
}

void search(int flower, Forest *forest, Botanist *botanist) /* recursive için flower sayısını kontrol ediyorum*/
{
   
    if (flower == 0) /*flower 0 olduğunda fonksiyon return ile duruyor ve en son halini last.txt ye kayıt ediyor */
    {
        display_forest(forest, botanist);
        printf("Congratulations! You found all rare flowers.\n");
        save_last_state(forest, botanist);
        return;
    }

    display_forest(forest, botanist);

    char move;
    printf("Enter move (r=right, l=left, u=up, d=down): ");
    scanf(" %c", &move); 

    int new_x = botanist->coord_x;
    int new_y = botanist->coord_y;

    switch (move)
    {
    case 'r':
        new_y = botanist->coord_y + 2; /*virgülleri atlamak için 2 ekliyor*/
        break;
    case 'l':
        new_y = botanist->coord_y - 2;
        break;
    case 'u':
        new_x = botanist->coord_x - 1;
        break;
    case 'd':
        new_x = botanist->coord_x + 1;
        break;
    default:
        printf("Invalid move! Try again.\n");
        search(flower, forest, botanist); 
        return; 
    }

    if (new_x < 0 || new_x >= forest->height || new_y < 0 || new_y >= forest->width * 2)  /* map dışına çıkıp çıkmadığını kontrol ediyor*/
    {
        printf("Out of bounds! Try again.\n");
        search(flower, forest, botanist);
        return;
    }

    if (forest->map[new_x][new_y] == 'X')  /* flowera denk geldiğinde yapması gerekenler*/
    {
        forest->map[botanist->coord_x][botanist->coord_y] = ' ';
        forest->map[new_x][new_y] = 'B';
        botanist->coord_x = new_x;
        botanist->coord_y = new_y;
        botanist->water_bottle_size--;
        flower--;
        printf("I've found it!\n");
    }
    else if (forest->map[new_x][new_y] != ' ') /*duvara denk gelirse */
    {
        printf("You can only move to empty spaces! Try again.\n");
        search(flower, forest, botanist);
        return;
    }

  
    forest->map[botanist->coord_x][botanist->coord_y] = ' ';
    forest->map[new_x][new_y] = 'B';
    botanist->coord_x = new_x;
    botanist->coord_y = new_y;

    search(flower, forest, botanist); 
}

int init_game(Forest *forest, Botanist *botanist)
{
    FILE *fp = fopen("init.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file");
    }
    char character;
    int flower = 0;
    int i = 0;
    int j = 0; 
    fscanf(fp, "\n%d,%d", &forest->height, &forest->width);
    fscanf(fp, "%d,%d,%d", &botanist->coord_x, &botanist->coord_y, &botanist->water_bottle_size);
    while (1)
    {
        fscanf(fp, "%c", &character);
        if (character == '\n')
        {
            break;
        }
    };

    for (i = 0; i < forest->height; i++) /* mapi arraye kayıt ediyoruz*/
    {
        fgets(forest->map[i], forest->width * 2 + 1, fp);
    }

    for (i = 0; i < forest->height; i++) /*flower sayısı ve kordinatlarını alıyoruz*/
    {
        for (j = 0; j < forest->width * 2; j++)
        {
            if (forest->map[i][j] == 'X')
            {
                forest->flower_x[flower] = i;
                forest->flower_y[flower] = j - j / 2;
                flower++;
            }
        }
    }
    forest->flower_x[flower] = -1; /*array sonuna -1 koyuyoruz kontrol için*/
    fclose(fp);

    return flower;
}

void display_forest(Forest *forest, Botanist *botanist)
{
    int i = 0;
    int j = 0; 
    for (i = 0; i < forest->height; i++) /* mapi çiziyoruz*/
    {
        printf("%s", forest->map[i], i);
    }

    int a = 0;
    
    int flower = 0;
    while (forest->flower_x[a] != -1) /*flower sayısını alıyoruz*/
    {
        a++;
    }
    
    for (i = 0; i < forest->height; i++) /*mapte kalan flower sayısı */
    {
        for (j = 0; j < forest->width * 2; j++)
        {
            if (forest->map[i][j] == 'X')
            {
                flower++;
            }
        }
    }
    printf("\nFounded flower: %d", a - flower);
    printf("\nBotanist coordinates: (%d, %d)\n", botanist->coord_x, botanist->coord_y - (botanist->coord_y / 2));
    printf("Water bottle size: %d\n", botanist->water_bottle_size);
}

void save_last_state(Forest *forest, Botanist *botanist) /*mapin son halini last.txt ye basıyoruz*/
{
    FILE *fp = fopen("last.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file");
    }
    int i = 0;

    while (forest->flower_x[i] != -1)
    {
        i++;
    }
    for (i = 0; i < forest->height; i++)
    {
        fprintf(fp, "%s", forest->map[i]);
    }
    fprintf(fp, "\nFounded flower:%d\n",i);
    fprintf(fp, "Botanist coordinates: (%d, %d)\n", botanist->coord_x, botanist->coord_y-(botanist->coord_y/2));
    fprintf(fp, "Water bottle size: %d\n", botanist->water_bottle_size);

    fclose(fp);
}
