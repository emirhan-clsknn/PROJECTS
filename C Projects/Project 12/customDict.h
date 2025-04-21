#ifndef CUSTOM_DICT_H
#define CUSTOM_DICT_H

/* Union to hold different types of values */
typedef union {
    int *i;      /* Pointer to int */
    float *f;    /* Pointer to float */
    double *d;   /* Pointer to double */
    char *c;     /* Pointer to char */
} Value;

/* Structure to hold an item in the dictionary */
typedef struct {
    char *key;               /* Key of the item */
    Value *values;           /* Array of values */
    int value_count; /* Number of values */
    char type;               /* Type of the values ('i' for int, 'f' for float, 'd' for double, 'c' for char) */
} Item;

/* Structure to hold the custom dictionary */
typedef struct {
    Item *items;             /* Array of items */
    int size;       /* Current size of the dictionary */
    int capacity;   /* Capacity of the dictionary */
} CustomDict;

/* Function to create a new dictionary */
CustomDict* create_dict();

/* Function to resize the dictionary */
void resize_dict(CustomDict* dict);

/* Function to add an item to the dictionary */
void add_item(CustomDict* dict, const char* key, const Value* value, char type, int value_count);

/* Function to delete an item from the dictionary */
void delete_item(CustomDict* dict, const char* key);

/* Function to set the value of an item in the dictionary */
void set_value(CustomDict* dict, const char* key, const Value* value, int value_count);

/* Function to search for an item in the dictionary */
Value* search_item(CustomDict* dict, const char* key);

/* Function to sort the dictionary */
void sort_dict(CustomDict* dict);

/* Function to print the dictionary */
void print_dict(const CustomDict* dict);

/* Function to free the dictionary */
void free_dict(CustomDict* dict);

/* Function to read a CSV file and load it into the dictionary */
int read_csv(CustomDict* dict, const char* filename);

#endif /* CUSTOM_DICT_H*/
