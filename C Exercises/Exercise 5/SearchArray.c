#include <stdio.h>

int searchQuery(char target[], char query[]) {
    int i, j;
    int targetLen = 0;
    int queryLen = 0;

    while (target[targetLen] != '\0'){
        targetLen++;}
    while (query[queryLen] != '\0'){
        queryLen++;}

    for (i = 0; i <= targetLen - queryLen; i++) {
        for (j = 0; j < queryLen; j++) {
            if (target[i + j] != query[j])
                break;
        }
        if (j == queryLen) 
            return i;
    }
    return -1;
}

int main() {
    char target[] = "Many that live deserve death. And some that die deserve life. Can you give it to them?";
    char query[] = "Many";
    
    int result = searchQuery(target, query);
    
    if (result == -1) {
        printf("There is no query like that");
    } else {
        printf("\"%s\" is contained in target at position %d.\n", query, result);
    }
    return 0;
}

