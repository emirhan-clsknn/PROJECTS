#include <stdio.h>

int drugA(float age) {
    if (age < 18) {
        return 25;
    } else if (age >= 18 && age <= 65) {
        return 45;
    } else if (age > 65) {
        return 30;
    }
}

int drugB(float age) {
    if (age < 18) {
        return 2 * drugA(age);
    } else if (age >= 18 && age <= 65) {
        return 5 * drugA(age);
    } else if (age > 65) {
        return 3 * drugA(age);
    }
}

int drugC(float age, float X) {
    if (age < 18) {
        return 30 + drugB(age) - (3 * X) / 2;
    } else if (age >= 18 && age <= 65) {
        return 40 + 2 * drugB(age) - (3 * X);
    } else if (age > 65) {
        return 35 + drugB(age) - (5 * X) / 2;
    }
}

int main() {
    float age = 0;
    float A, B, C;
    char gender;
    float X;

    printf("Enter your age: ");
    scanf("%f", &age);

    getchar();

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    switch (gender) {
        case 'M':
            X = drugA(age) / 2;
            break;
        case 'F':
            X = drugB(age) / 3;
            break;
        default:
            return 0;
    }

    A = drugA(age);
    B = drugB(age);
    C = drugC(age, X);

    printf("Drug A: %.2f\n", A);
    printf("Drug B: %.2f\n", B);
    printf("Drug C: %.2f\n", C);

    return 0;
}

