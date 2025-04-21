#include <stdio.h>
#include <string.h>

void recursive_helper(const char* str, int start, int end) {
    if (end - start + 1 < 2) {
        return;
    }
    
    if (str[start] == str[end]) {
        int i;
        for (i = start; i <= end; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    
    if (end > start) {
        recursive_helper(str, start + 1, end); 
        recursive_helper(str, start, end - 1); 
    }
}

void print_special_substrings(const char* str) {
    int len = strlen(str);
    recursive_helper(str, 0, len - 1);
}

int main() {
    const char* input = "abaca";
    
    printf("Substrings that start and end with the same character:\n");
    print_special_substrings(input);
    return 0;
}

