#include "customDict.h"  /* Include the custom dictionary header file */
#include <stdio.h>       /* Include the standard input-output library */
#include <stdlib.h>      /* Include the standard library for memory allocation */
#include <string.h>      /* Include the string manipulation library */

CustomDict* create_dict() {
    CustomDict* dict = (CustomDict*)malloc(sizeof(CustomDict));  /* Allocate memory for the dictionary */
    dict->size = 0;     /* Initialize dictionary size to 0 */
    dict->capacity = 0; /* Initialize dictionary capacity to 0 */
    dict->items = NULL; /* Initialize dictionary items to NULL */
    return dict;        /* Return the created dictionary */
}

void resize_dict(CustomDict* dict) {
    if (dict->capacity == 0) {
        dict->capacity = 1;  /* Set initial capacity to 1 */
    } else {
        dict->capacity *= 2; /* Double the capacity */
    }
    dict->items = (Item*)realloc(dict->items, dict->capacity * sizeof(Item)); /* Reallocate memory for the items */
}

void add_item(CustomDict* dict, const char* key, const Value* value, char type, int value_count) {
    int i;
    for (i = 0; i < dict->size; ++i) {
        if (strcmp(dict->items[i].key+1, key) == 0) {
            free(dict->items[i].values);  /* Free the existing values */
            dict->items[i].values = (Value*)malloc(value_count * sizeof(Value)); /* Allocate new memory for the values */
            memcpy(dict->items[i].values, value, value_count * sizeof(Value));   /* Copy the new values */
            dict->items[i].value_count = value_count; /* Set the new value count */
            dict->items[i].type = type; /* Set the type */
            return; /* Return since the item was updated */
        }
    }

    if (dict->size == dict->capacity) {
        resize_dict(dict); /* Resize the dictionary if it's full */
    }

    dict->items[dict->size].key = (char*)strdup(key); /* Duplicate the key */
    dict->items[dict->size].values = (Value*)malloc(value_count * sizeof(Value)); /* Allocate memory for the values */
    for (i = 0; i < value_count; ++i) {
        switch (type) {
            case 'i':
                dict->items[dict->size].values[i].i = (int*)malloc(sizeof(int));
                *(dict->items[dict->size].values[i].i) = *(value[i].i); /* Copy integer value */
                break;
            case 'f':
                dict->items[dict->size].values[i].f = (float*)malloc(sizeof(float));
                *(dict->items[dict->size].values[i].f) = *(value[i].f); /* Copy float value */
                break;
            case 'd':
                dict->items[dict->size].values[i].d = (double*)malloc(sizeof(double));
                *(dict->items[dict->size].values[i].d) = *(value[i].d); /* Copy double value */
                break;
            case 'c':
                dict->items[dict->size].values[i].c = (char*)malloc(sizeof(char));
                *(dict->items[dict->size].values[i].c) = *(value[i].c); /* Copy char value */
                break;
        }
    }
    dict->items[dict->size].value_count = value_count; /* Set the value count */
    dict->items[dict->size].type = type; /* Set the type */
    ++dict->size; /* Increment the dictionary size */
}

void delete_item(CustomDict* dict, const char* key) {
    int i, j;
    for (i = 0; i < dict->size; ++i) {
        if (strcmp(dict->items[i].key+1, key) == 0) {
            free(dict->items[i].key); /* Free the key */
            for (j = 0; j < dict->items[i].value_count; ++j) {
                switch (dict->items[i].type) {
                    case 'i':
                        free(dict->items[i].values[j].i); /* Free integer value */
                        break;
                    case 'f':
                        free(dict->items[i].values[j].f); /* Free float value */
                        break;
                    case 'd':
                        free(dict->items[i].values[j].d); /* Free double value */
                        break;
                    case 'c':
                        free(dict->items[i].values[j].c); /* Free char value */
                        break;
                }
            }
            free(dict->items[i].values); /* Free the values array */

            for (j = i; j < dict->size - 1; ++j) {
                dict->items[j] = dict->items[j + 1]; /* Shift the items */
            }

            --dict->size; /* Decrement the dictionary size */
            return; /* Return since the item was deleted */
        }
    }
}

void set_value(CustomDict* dict, const char* key, const Value* value, int value_count) {
    int i,j;
    for (i = 0; i < dict->size; ++i) {
        if (strcmp(dict->items[i].key+1, key) == 0) {
            for (j = 0; j < dict->items[i].value_count; ++j) {
                switch (dict->items[i].type) {
                    case 'i':
                        free(dict->items[i].values[j].i); /* Free integer value */
                        break;
                    case 'f':
                        free(dict->items[i].values[j].f); /* Free float value */
                        break;
                    case 'd':
                        free(dict->items[i].values[j].d); /* Free double value */
                        break;
                    case 'c':
                        free(dict->items[i].values[j].c); /* Free char value */
                        break;
                }
            }
            free(dict->items[i].values); /* Free the values array */
            dict->items[i].values = (Value*)malloc(value_count * sizeof(Value)); /* Allocate memory for new values */
            memcpy(dict->items[i].values, value, value_count * sizeof(Value));   /* Copy the new values */
            dict->items[i].value_count = value_count; /* Set the new value count */
            return; /* Return since the values were updated */
        }
    }
}

Value* search_item(CustomDict* dict, const char* key) {
    int i;
    for (i = 0; i < dict->size; ++i) {
        if (strcmp(dict->items[i].key+1, key) == 0) {
            return dict->items[i].values; /* Return the values if the key is found */
        }
    }
    return NULL; /* Return NULL if the key is not found */
}

int compare_items(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    return strcmp(itemA->key, itemB->key); /* Compare the keys */
}

void sort_dict(CustomDict* dict) {
    qsort(dict->items, dict->size, sizeof(Item), compare_items); /* Sort the items */
}

void print_dict(const CustomDict* dict) {
    int i,j;
    for (i = 0; i < dict->size; ++i) {
        printf("Key: %s, Values: ", dict->items[i].key);
        for (j = 0; j < dict->items[i].value_count; ++j) {
            switch (dict->items[i].type) {
                case 'i':
                    printf("%d ", *(dict->items[i].values[j].i)); /* Print integer value */
                    break;
                case 'f':
                    printf("%f ", *(dict->items[i].values[j].f)); /* Print float value */
                    break;
                case 'd':
                    printf("%lf ", *(dict->items[i].values[j].d)); /* Print double value */
                    break;
                case 'c':
                    printf("%c ", *(dict->items[i].values[j].c)); /* Print char value */
                    break;
            }
        }
        printf("\n");
    }
}

void free_dict(CustomDict* dict) {
    int i , j;
    for (i = 0; i < dict->size; ++i) {
        free(dict->items[i].key); /* Free the key */
        for (j = 0; j < dict->items[i].value_count; ++j) {
            switch (dict->items[i].type) {
                case 'i':
                    free(dict->items[i].values[j].i); /* Free integer value */
                    break;
                case 'f':
                    free(dict->items[i].values[j].f); /* Free float value */
                    break;
                case 'd':
                    free(dict->items[i].values[j].d); /* Free double value */
                    break;
                case 'c':
                    free(dict->items[i].values[j].c); /* Free char value */
                    break;
            }
        }
        free(dict->items[i].values); /* Free the values array */
    }
    free(dict->items); /* Free the items array */
    free(dict); /* Free the dictionary */
}

int read_csv(CustomDict* dict, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return 0; /* Return 0 if the file could not be opened */
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        char type = token[0]; /* Get the type from the first token */
        token = strtok(NULL, ",");
        char* key = (char*)strdup(token); /* Duplicate the key */

        Value* values = (Value*)malloc(sizeof(Value) * 10); /* Allocate memory for the values */
        int value_count = 0;

        while ((token = strtok(NULL, ","))) {
            switch (type) {
                case 'i':
                    values[value_count].i = (int*)malloc(sizeof(int));
                    *(values[value_count].i) = atoi(token); /* Parse and store integer value */
                    break;
                case 'f':
                    values[value_count].f = (float*)malloc(sizeof(float));
                    *(values[value_count].f) = atof(token); /* Parse and store float value */
                    break;
                case 'd':
                    values[value_count].d = (double*)malloc(sizeof(double));
                    *(values[value_count].d) = atof(token); /* Parse and store double value */
                    break;
                case 'c':
                    values[value_count].c = (char*)malloc(sizeof(char));
                    *(values[value_count].c) = token[0]; /* Store char value */
                    break;
            }
            value_count++; /* Increment value count */
        }

        add_item(dict, key, values, type, value_count); /* Add the item to the dictionary */
        free(values); /* Free the temporary values array */
    }

    fclose(file); /* Close the file */
    return 1; /* Return 1 if the file was read successfully */
}
