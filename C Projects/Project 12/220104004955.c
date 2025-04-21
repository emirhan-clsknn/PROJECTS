#include "customDict.h"  /* Include the custom dictionary header file */
#include <stdio.h>       /* Include the standard input-output library */
#include <stdlib.h>      /* Include the standard library for memory allocation */
#include "customDict.c"  /* Include the custom dictionary implementation file */
#include <string.h>      /* Include the string manipulation library */

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Load CSV file\n");
    printf("2. Print dictionary\n");
    printf("3. Add item\n");
    printf("4. Delete item\n");
    printf("5. Search item\n");
    printf("6. Sort dictionary\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    CustomDict* dict = create_dict();  /* Create a new dictionary */
    int choice;  /* Variable to store user's menu choice */
    char filename[256];  /* Variable to store the CSV filename */
    char key[256]={' '};  /* Variable to store the key */
    char type;  /* Variable to store the type of values */
    int value_count;  /* Variable to store the number of values */
    int i;
    while (1) {  /* Infinite loop for the menu */
        print_menu();  /* Print the menu */
        scanf("%d", &choice);  /* Get the user's choice */

        switch (choice) {
            case 1:
                printf("Enter the CSV filename: ");
                scanf("%s", filename);
                if (!read_csv(dict, filename)) {  /* Attempt to read the CSV file */
                    printf("Failed to read CSV file\n");  /* Print an error message if reading fails */
                } else {
                    printf("CSV file loaded successfully\n");  /* Print a success message if reading succeeds */
                }
                break;

            case 2:
                print_dict(dict);  /* Print the dictionary */
                break;

            case 3:
                printf("Enter the key: ");
                scanf("%s", key+1);
                printf("Enter the type (i for int, f for float, d for double, c for char): ");
                scanf(" %c", &type);
                printf("Enter the number of values: ");
                scanf("%u", &value_count);

                Value* values = (Value*)malloc(value_count * sizeof(Value));  /* Allocate memory for the values */
                printf("Enter the values: ");
                for (i = 0; i < value_count; i++) {
                    switch (type) {
                        case 'i':
                            values[i].i = (int*)malloc(sizeof(int));
                            scanf("%d", values[i].i);  /* Read an integer value */
                            break;
                        case 'f':
                            values[i].f = (float*)malloc(sizeof(float));
                            scanf("%f", values[i].f);  /* Read a float value */
                            break;
                        case 'd':
                            values[i].d = (double*)malloc(sizeof(double));
                            scanf("%lf", values[i].d);  /* Read a double value */
                            break;
                        case 'c':
                            values[i].c = (char*)malloc(sizeof(char));
                            scanf(" %c", values[i].c);  /* Read a char value */
                            break;
                        default:
                            printf("Invalid type\n");
                            break;
                    }
                }
                
                add_item(dict, key, values, type, value_count);  /* Add the item to the dictionary */
                printf("Item added successfully\n");

                /* Free the temporary values array */
                for (i = 0; i < value_count; i++) {
                    switch (type) {
                        case 'i':
                            free(values[i].i);
                            break;
                        case 'f':
                            free(values[i].f);
                            break;
                        case 'd':
                            free(values[i].d);
                            break;
                        case 'c':
                            free(values[i].c);
                            break;
                    }
                }
                free(values);  /* Free the values array */
                break;

            case 4:
                printf("Enter the key to delete: ");
                scanf("%s", key);
                delete_item(dict, key);  /* Delete the item from the dictionary */
                printf("Item deleted successfully\n");
                break;

            case 5:
                printf("Enter the key to search: ");
                scanf("%s", key);
                Value* found = search_item(dict, key);  /* Search for the item in the dictionary */
                if (found) {
                    printf("Found item with key '%s': ", key);
                    int found_index = 0;
                    for ( i = 0; i < dict->size; i++) {
                        if (strcmp(dict->items[i].key+1, key) == 0) {
                            found_index = i;
                            break;
                        }
                    }
                    for (i = 0; i < dict->items[found_index].value_count; i++) {
                        switch (dict->items[found_index].type) {
                            case 'i':
                                printf("%d ", found[i].i[0]);
                                break;
                            case 'f':
                                printf("%f ", found[i].f[0]);
                                break;
                            case 'd':
                                printf("%lf ", found[i].d[0]);
                                break;
                            case 'c':
                                printf("%c ", found[i].c[0]);
                                break;
                        }
                    }
                    printf("\n");
                } else {
                    printf("Item with key '%s' not found\n", key);  /* Print a message if the item is not found */
                }
                break;

            case 6:
                sort_dict(dict);  /* Sort the dictionary */
                printf("Dictionary sorted successfully\n");
                break;

            case 7:
                free_dict(dict);  /* Free the dictionary memory */
                printf("Exiting...\n");
                return 0;  /* Exit the program */

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;  /* Return 0 from main (not necessary here due to the infinite loop and exit case) */
}
