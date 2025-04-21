#ifndef CUSTOMDICT_H
#define CUSTOMDICT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct books
{
    char *name;
    char *author;
} books;
typedef struct movies
{
    char *name;
    char *director;
} movies;

typedef struct store
{
    int price;
    int type;
    union stuff
    {
        movies *movie;
        books *book;
    } stuff;
} store;

void printMenu()
{
    int i, j;
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 16; j++)
        {
            if (i == 0 || i == 10)
            {
                printf("* ");
            }
            else if (j == 0 || j == 15)
            {
                printf("* ");
            }
            else
            {
                if (i == 2 && j == 2)
                {
                    printf("1.Add an stuff");
                    j += 6;
                }
                else if (i == 4 && j == 2)
                {
                    printf("2.Delete an stuffs");
                    j += 8;
                }
                else if (i == 6 && j == 2)
                {
                    printf("3.Show all stuff");
                    j += 7;
                }
                else if (i == 8 && j == 2)
                {
                    printf("4.Exit");
                    j += 2;
                }
                else
                {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
}

void addNewStuff(int type, int price, char *name, char *information)
{
    int len = strlen(name);
    store *newStuff = (store *)malloc(sizeof(store));
    newStuff->price = price;
    newStuff->type = type;
    if (type == 1)
    {
        newStuff->stuff.book = (books *)malloc(sizeof(books));
        newStuff->stuff.book->name = (char*)malloc(sizeof(char) *(len+1));
        strcpy(newStuff->stuff.book->name, name);
        newStuff->stuff.book->author = (char *)malloc(sizeof(char) * (sizeof(information) / sizeof(char)));
        strcpy(newStuff->stuff.book->author, information);
    }
    else
    {
        newStuff->stuff.movie = (movies *)malloc(sizeof(movies));
        newStuff->stuff.movie->name = (char*)malloc(sizeof(char) *(len+1));
        strcpy(newStuff->stuff.movie->name, name);
        newStuff->stuff.movie->director = (char *)malloc(sizeof(char) * (sizeof(information) / sizeof(char)));
        strcpy(newStuff->stuff.movie->director, information);
    }
   

    FILE *f = fopen("newStuff.txt", "a");
    if (type == 1)
    {
        fprintf(f, "%d %s %s %d\n", newStuff->type, newStuff->stuff.book->name, newStuff->stuff.book->author, newStuff->price);
    }
    else
    {
        fprintf(f, "%d %s %s %d\n", newStuff->type, newStuff->stuff.movie->name, newStuff->stuff.movie->director, newStuff->price);
    }
    fclose(f);
    free(newStuff->stuff.book->author);
    free(newStuff->stuff.book);
    free(newStuff->stuff.movie->director);
    free(newStuff->stuff.movie);
    free(newStuff);
}
void deleteStuff(int type1, char *name1)
{
    int type, price;
    char name[50], information[50];
    FILE *f2 = fopen("temp.txt", "w");
    FILE *f = fopen("newStuff.txt", "r");
    while (fscanf(f, "%d %s %s %d", &type, &name, &information, &price) == 4)
    {
        if (type1 == type)
        {
            if (strcmp(name1, name) == 0)
            {
                continue;
            }
            else
            {
                fprintf(f2, "%d %s %s %d\n", type, name, information, price);
            }
        }
        else
        {
            fprintf(f2, "%d %s %s %d\n", type, name, information, price);
        }
    }
    fclose(f);
    fclose(f2);
    FILE *f3 = fopen("newStuff.txt", "w");
    FILE *f4 = fopen("temp.txt", "r");
    while (fscanf(f4, "%d %s %s %d", &type, &name, &information, &price) == 4)
    {
        fprintf(f3, "%d %s %s %d\n", type, name, information, price);
    }
    fclose(f3);
    fclose(f4);
   
}
void showAllstuff()
{
    FILE *f = fopen("newStuff.txt", "r");
    int type, price;
    char name[50], information[50];
    while (fscanf(f, "%d %s %s %d", &type, &name, &information, &price) == 4)
    {
        if (type == 1)
        {
            printf("Book: ");
            printf("%s %s %d\n", name, information, price);
        }
        else
        {
            printf("Movie: ");
            printf("%s %s %d\n", name, information, price);
        }
    }
    fclose(f);
}

#endif