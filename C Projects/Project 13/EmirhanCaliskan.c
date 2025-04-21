#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the Species structure */
typedef struct Species {
    char *class;
    char *order;
    char *family;
    char *genus;
    char *species;
    struct Species *next;
} Species;

/* Head of the linked list */
Species *head = NULL;

/* Function to add a new species */
void addSpecies() {
    Species *newSpecies = (Species*)malloc(sizeof(Species));
    char arr[50];

    printf("Enter Species information:\n");

    /* Get class information from the user and copy it to memory */
    printf("Class: ");
    scanf("%s", arr);
    newSpecies->class = (char*)malloc(strlen(arr) + 1);
    strcpy(newSpecies->class, arr);

    /* Get order information from the user and copy it to memory */
    printf("Order: ");
    scanf("%s", arr);
    newSpecies->order = (char*)malloc(strlen(arr) + 1);
    strcpy(newSpecies->order, arr);

    /* Get family information from the user and copy it to memory */
    printf("Family: ");
    scanf("%s", arr);
    newSpecies->family = (char*)malloc(strlen(arr) + 1);
    strcpy(newSpecies->family, arr);

    /* Get genus information from the user and copy it to memory */
    printf("Genus: ");
    scanf("%s", arr);
    newSpecies->genus = (char*)malloc(strlen(arr) + 1);
    strcpy(newSpecies->genus, arr);

    /* Get species information from the user and copy it to memory */
    printf("Species: ");
    scanf("%s", arr);
    newSpecies->species = (char*)malloc(strlen(arr) + 1);
    strcpy(newSpecies->species, arr);

    /* Add the new species to the linked list */
    newSpecies->next = head;
    head = newSpecies;
}

/* Function to sort species based on a given criterion */
void sortSpecies(char criterion[10]) {
    if (head == NULL) return;
    Species *i, *j;
    char *temp;

    /* Bubble sort based on the criterion */
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if ((strcmp(criterion, "class") == 0 && strcmp(i->class, j->class) > 0) ||
                (strcmp(criterion, "order") == 0 && strcmp(i->order, j->order) > 0) ||
                (strcmp(criterion, "family") == 0 && strcmp(i->family, j->family) > 0) ||
                (strcmp(criterion, "genus") == 0 && strcmp(i->genus, j->genus) > 0) ||
                (strcmp(criterion, "species") == 0 && strcmp(i->species, j->species) > 0)) {

                /* Swap the values */
                temp = i->class; i->class = j->class; j->class = temp;
                temp = i->order; i->order = j->order; j->order = temp;
                temp = i->family; i->family = j->family; j->family = temp;
                temp = i->genus; i->genus = j->genus; j->genus = temp;
                temp = i->species; i->species = j->species; j->species = temp;
            }
        }
    }
}

/* Function to print all species */
void printSpecies() {
    Species *temp = head;

    /* Traverse the linked list and print each species */
    while (temp != NULL) {
        printf("Class: %s\n", temp->class);
        printf("Order: %s\n", temp->order);
        printf("Family: %s\n", temp->family);
        printf("Genus: %s\n", temp->genus);
        printf("Species: %s\n\n", temp->species);
        temp = temp->next;
    }
}

/* Function to modify an existing species */
void modifySpecies() {
    char oldSpecies[50];
    char arr[50];
    printf("Enter Species information to modify:\n");
    printf("Old Species: "); scanf("%s", oldSpecies);
    
    Species *temp = head;

    /* Traverse the linked list to find the species to modify */
    while (temp != NULL) {
        if (strcmp(temp->species, oldSpecies) == 0) {
            printf("Enter new information:\n");

            /* Get new class information and copy it to memory */
            printf("New Class: ");
            scanf("%s", arr);
            temp->class = (char*)realloc(temp->class, strlen(arr) + 1);
            strcpy(temp->class, arr);

            /* Get new order information and copy it to memory */
            printf("New Order: ");
            scanf("%s", arr);
            temp->order = (char*)realloc(temp->order, strlen(arr) + 1);
            strcpy(temp->order, arr);

            /* Get new family information and copy it to memory */
            printf("New Family: ");
            scanf("%s", arr);
            temp->family = (char*)realloc(temp->family, strlen(arr) + 1);
            strcpy(temp->family, arr);

            /* Get new genus information and copy it to memory */
            printf("New Genus: ");
            scanf("%s", arr);
            temp->genus = (char*)realloc(temp->genus, strlen(arr) + 1);
            strcpy(temp->genus, arr);

            /* Get new species information and copy it to memory */
            printf("New Species: ");
            scanf("%s", arr);
            temp->species = (char*)realloc(temp->species, strlen(arr) + 1);
            strcpy(temp->species, arr);

            printf("Species modified successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Species not found.\n");
}

/* Function to delete a species */
void deleteSpecies() {
    char speciesToDelete[50];
    printf("Enter Species to delete: "); scanf("%s", speciesToDelete);
    
    Species *temp = head, *prev = NULL;

    /* Check if the species to delete is the head of the list */
    if (temp != NULL && strcmp(temp->species, speciesToDelete) == 0) {
        head = temp->next;
        free(temp->class);
        free(temp->order);
        free(temp->family);
        free(temp->genus);
        free(temp->species);
        free(temp);
        printf("Species deleted successfully.\n");
        return;
    }

    /* Traverse the list to find the species to delete */
    while (temp != NULL && strcmp(temp->species, speciesToDelete) != 0) {
        prev = temp;
        temp = temp->next;
    }

    /* If species is not found */
    if (temp == NULL) {
        printf("Species not found.\n");
        return;
    }

    /* Unlink the node from the linked list and free memory */
    prev->next = temp->next;
    free(temp->class);
    free(temp->order);
    free(temp->family);
    free(temp->genus);
    free(temp->species);
    free(temp);
    printf("Species deleted successfully.\n");
}

/* Menu function to provide options to the user */
void menu() {
    int choice;
    char criterion[10];
    
    while (1) {
        printf("\n1. Add Species\n");
        printf("2. List Species\n");
        printf("3. Modify Species\n");
        printf("4. Delete Species\n");
        printf("5. Sort Species\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSpecies();
                break;
            case 2:
                printSpecies();
                break;
            case 3:
                modifySpecies();
                break;
            case 4:
                deleteSpecies();
                break;
            case 5:
                printf("Enter list criteria (class, order, family, genus, species): ");
                scanf("%s", criterion);
                sortSpecies(criterion);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

/* Main function to start the program */
int main() {
    menu();
    return 0;
}
