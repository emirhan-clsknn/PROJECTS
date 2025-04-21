#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toLowerStr(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void toUpperStr(char *str, int len) {
    int i;
    for (i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

void printTable(char **strings, int sizeY) {
    int i;
    for (i = 0; i < sizeY; i++) {
        printf("%s\n", strings[i]);
    }
}

int findWord(char **strings, int sizeX, int sizeY, char *target, int *foundX, int *foundY) {
    int len = strlen(target);
    char targetLower[50];
    strcpy(targetLower, target);
    toLowerStr(targetLower);
    int y, x, k;

    for (y = 0; y < sizeY; y++) {
        for (x = 0; x < sizeX; x++) {
            if (x <= sizeX - len) {
                int found = 1;
                for (k = 0; k < len; k++) {
                    if (tolower(strings[y][x + k]) != targetLower[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    for (k = 0; k < len; k++) {
                        strings[y][x + k] = toupper(strings[y][x + k]);
                    }
                    *foundX = x;
                    *foundY = y;
                    return 1;
                }
            }
            if (x >= len - 1) {
                int found = 1;
                for (k = 0; k < len; k++) {
                    if (tolower(strings[y][x - k]) != targetLower[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    for (k = 0; k < len; k++) {
                        strings[y][x - k] = toupper(strings[y][x - k]);
                    }
                    *foundX = x;
                    *foundY = y;
                    return 1;
                }
            }
            if (y <= sizeY - len) {
                int found = 1;
                for (k = 0; k < len; k++) {
                    if (tolower(strings[y + k][x]) != targetLower[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    for (k = 0; k < len; k++) {
                        strings[y + k][x] = toupper(strings[y + k][x]);
                    }
                    *foundX = x;
                    *foundY = y;
                    return 1;
                }
            }

            if (y >= len - 1) {
                int found = 1;
                for (k = 0; k < len; k++) {
                    if (tolower(strings[y - k][x]) != targetLower[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    for (k = 0; k < len; k++) {
                        strings[y - k][x] = toupper(strings[y - k][x]);
                    }
                    *foundX = x;
                    *foundY = y;
                    return 1;
                }
            }
            if (x <= sizeX - len && y <= sizeY - len) {
                int found = 1;
                for (k = 0; k < len; k++) {
                    if (tolower(strings[y + k][x + k]) != targetLower[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    for (k = 0; k < len; k++) {
                        strings[y + k][x + k] = toupper(strings[y + k][x + k]);
                    }
                    *foundX = x;
                    *foundY = y;
                    return 1;
                }
            }
            if (x >= len - 1 && y <= sizeY - len) {
                int found = 1;
                for (k = 0; k < len; k++) {
                    if (tolower(strings[y + k][x - k]) != targetLower[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    for (k = 0; k < len; k++) {
                        strings[y + k][x - k] = toupper(strings[y + k][x - k]);
                    }
                    *foundX = x;
                    *foundY = y;
                    return 1;
                }
            }
            if (x <= sizeX - len && y >= len - 1) {
                int found = 1;
                for (k = 0; k < len; k++) {
                    if (tolower(strings[y - k][x + k]) != targetLower[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    for (k = 0; k < len; k++) {
                        strings[y - k][x + k] = toupper(strings[y - k][x + k]);
                    }
                    *foundX = x;
                    *foundY = y;
                    return 1;
                }
            }
            if (x >= len - 1 && y >= len - 1) {
                int found = 1;
                for (k = 0; k < len; k++) {
                    if (tolower(strings[y - k][x - k]) != targetLower[k]) {
                        found = 0;
                        break;
                    }
                }
                if (found) {
                    for (k = 0; k < len; k++) {
                        strings[y - k][x - k] = toupper(strings[y - k][x - k]);
                    }
                    *foundX = x;
                    *foundY = y;
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    int sizeX = 0;
    int sizeY = 0;
    FILE *file = fopen("aa.txt", "r");
    if (file == NULL) {
        printf("Dosya açılamadı.\n");
        return 1;
    }

    fscanf(file, "%d %d", &sizeY, &sizeX);
    char chtr = ' ';
    while (chtr != '\n') {
        fscanf(file, "%c", &chtr);
    }

    char **strings = (char **)malloc(sizeY * sizeof(char *));
    if (strings == NULL) {
        printf("Bellek ayırma hatası!\n");
        fclose(file);
        return 1;
    }
    int i, j;

    for (i = 0; i < sizeY; i++) {
        strings[i] = (char *)malloc((sizeX + 1) * sizeof(char));
        if (strings[i] == NULL) {
            printf("Bellek ayırma hatası!\n");
            for (j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            fclose(file);
            return 1;
        }
    }

    j = 0;
    char line[50];
   while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        toLowerStr(line);
        strcpy(strings[j], line);
        j++;
        if (j == sizeY) {
            break;
        }
    }
    fclose(file);

    char target[50];
    int foundX, foundY;
    printTable(strings,sizeY);
    printf("**Welcome Puzzle Game**\n");
    while (1) {
        printf("Please Enter the word to find (or type 'exit' to quit): ");
        scanf("%s", target);
        if (strcmp(target, "exit") == 0) {
            printf("Bye Bye\n");
            break;
        }
        if (findWord(strings, sizeX, sizeY, target, &foundX, &foundY)) {
            printf("Kelime bulundu: %s (%d, %d)\n", target, foundY, foundX);
            printTable(strings, sizeY);
        } else {
            printf("Kelime bulunamadı: %s\n", target);
        }
    }

    for (i = 0; i < sizeY; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}

