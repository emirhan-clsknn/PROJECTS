#include <stdio.h>

int compareArrays(double arr1[], double arr2[], int sizeOfArrays, int result[]) {
    int i;
    for (i = 0; i < sizeOfArrays; i++) {
        if (arr1[i] > arr2[i]) {
            result[i] = 0; 
        } else if (arr1[i] < arr2[i]) {
            result[i] = 1; 
        } else {
            result[i] = 0; 
        }
    }
    return 0;
}

int fillArray(double arr[], int size) {
    printf("Enter %d numbers:\n", size);
    int i;
    for (i= 0; i < size; i++) {
        scanf("%lf", &arr[i]); 
    }
    return 0;
}

int main() {
    double arr1[5];
    double arr2[5];
    int result[5];

    fillArray(arr1, 5);
    fillArray(arr2, 5);
    compareArrays(arr1, arr2, 5, result);

    printf("Comparison result:\n");
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}

