#include <stdio.h>

int fillArray(double arr[], int size) {
    printf("Enter %d numbers:\n", size);
    int i;
    for (i = 0; i < size; i++) {
        scanf("%lf", &arr[i]); 
    }
    return 0;
}

int main() {
    double arr[5];
    fillArray(arr, 5);

    printf("Array elements:\n");
    int i;
    for (i = 0; i < 5; i++) {
        printf("%.2lf ", arr[i]);
    }
    
    return 0;
}

