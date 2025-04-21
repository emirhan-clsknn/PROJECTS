#include <stdio.h>

int strLength(char arr[]) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }
    return length;
}

char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

int isPalindrom(char arr[], int left, int right) {

    if (left >= right) {
        return 1; 
    }
    
    if (toLower(arr[left]) != toLower(arr[right])) {
        return 0; 
    }
    
    return isPalindrom(arr, left + 1, right - 1);
}
int main() {
    char arr[50];
    printf("Enter a word:");
    scanf("%s",arr);
    int len = strLength(arr);
    int left = 0;
    int right = len - 1;
    
    int check = isPalindrom(arr,left,right);
    
    if (check) {
        printf("It is a palindrome.\n");
    } else {
        printf("It is not a palindrome.\n");
    }
    
    return 0;
}

