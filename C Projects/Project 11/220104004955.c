#include <stdio.h>

int numPathsBase(int street, int avenue) {
    if (street == 1 || avenue == 1)
        return 1;
    return numPathsBase(street - 1, avenue) + numPathsBase(street, avenue - 1);
}

int main() {
    int street, avenue;
    printf("Enter the starting position (street and avenue): ");
    scanf("%d %d", &street, &avenue);
    if ((street <1 || street>6) || (avenue >6 || avenue < 1)) {
        printf("Invalid starting position!\n");
        return 1;
    }
    printf("Number of paths to return home: %d\n", numPathsBase(street, avenue));
    return 0;
}
