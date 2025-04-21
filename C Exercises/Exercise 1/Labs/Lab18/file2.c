#include <stdio.h>

#define MAX_ENTRIES 100
#define SENTINEL_LOW -0.02
#define SENTINEL_HIGH -0.01

void readList(double list[], int *size) {
    double num;
    int i = 0;
    printf("Enter a list of real numbers (with sentinel in range [%f, %f]): ", SENTINEL_LOW, SENTINEL_HIGH);
    while (scanf("%lf", &num) && !(num >= SENTINEL_LOW && num <= SENTINEL_HIGH)) {
        list[i++] = num;
        if (i >= MAX_ENTRIES) break;
    }
    *size = i;
}

int findSubList(double list[], int size, double target, int *startIndex, int *endIndex) {
    for (int start = 0; start < size; start++) {
        double sum = 0;
        for (int end = start; end < size; end++) {
            sum += list[end];
            if (sum == target) {
                *startIndex = start;
                *endIndex = end;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    double list[MAX_ENTRIES];
    int size;
    double target;
    int startIndex, endIndex;

    readList(list, &size);
    
    printf("Enter the target sum: ");
    scanf("%lf", &target);

    if (findSubList(list, size, target, &startIndex, &endIndex)) {
        printf("The first sub-list is: ");
        for (int i = startIndex; i <= endIndex; i++) {
            printf("%lf ", list[i]);
        }
        printf("\n");
    } else {
        printf("No sub-list.\n");
    }

    return 0;
}
