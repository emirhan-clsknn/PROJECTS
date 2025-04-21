#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
  store newStore[20];
  int choice = 0;
  int type = 0;
  int price = 0;
  char name[25];
  char information[50];
  int i = 0;
  printMenu();

  do
  {
    printf("\nEnter a choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter type of stuff (book:1,(movie:0)): ");
      scanf("%d", &type);
      if (type == 1)
      {
        printf("Enter the name of the book:");
        scanf("%s", name);
        printf("Enter the price of the book:");
        scanf("%d", &price);
        printf("Enter the author of the book:");
        scanf("%s", information);
      }
      else if (type == 0)
      {
        printf("Enter the name of the movie:");
        scanf("%s", name);
        printf("Enter the price of the movie:");
        scanf("%d", &price);
        printf("Enter the director of the movie:");
        scanf("%s", information);
      }
      else
      {
        printf("Invalid choice\n");
      }
      addNewStuff(type, price, name, information);
      break;
    case 2:
      printf("Enter type of stuff which you want to delete (book:1,(movie:0)): ");
      scanf("%d", &type);
      printf("Enter the name of the movie or book which you want to delete: ");
      scanf("%s", name);
      deleteStuff(type, name);
      break;
    case 3:
      showAllstuff();
      break;
    case 4:
      printf("!! GOOD BYE !!\n");
      break;
    default:
      printf("Invalid choice\n");
      break;
    }
  } while (choice != 4);

}