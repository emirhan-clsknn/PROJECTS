#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car {
    int price;
    int year;
    char *name;
    struct car *next;
} car;

car *add_new_car(car *a2, int year, char *name, int price) {
    int len = strlen(name);
    while (a2->next != NULL) {
        a2 = a2->next;
    }
    a2->next = (car *)malloc(sizeof(car));
    a2->next->price = price;
    a2->next->name = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(a2->next->name, name);
    a2->next->year = year;
    a2->next->next = NULL;
    return a2->next;
}

int main() {
    char names[20] = "audi";
    int year = 10;
    int price = 10;
    int len = strlen(names);
    car *cars = (car *)malloc(sizeof(car));
    cars->price = 1000;
    cars->year = 2000;
    cars->name = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(cars->name, names);
    cars->next = NULL;
    car *newcar = add_new_car(cars, year, names, price);
   
    printf("%d %d", newcar->year, newcar->price);
   
    free(cars->name);
    free(cars->next);
    free(cars);
    return 0;
}
