#include <stdio.h>
#include <string.h>
#define MAX_SCIENTISTS 100
#define MAX_FIELDS 5
#define MAX_LENGTH 70

char scientists[MAX_SCIENTISTS][MAX_FIELDS][MAX_LENGTH];
int numScientists = 0;
void swapScientists(int index1, int index2)
{
    char temp[MAX_FIELDS][MAX_LENGTH];

    int i;
    for (i = 0; i < MAX_FIELDS; i++)
    {
        strcpy(temp[i], scientists[index1][i]);
    }

    for (i = 0; i < MAX_FIELDS; i++)
    {
        strcpy(scientists[index1][i], scientists[index2][i]);
    }
    for (i = 0; i < MAX_FIELDS; i++)
    {
        strcpy(scientists[index2][i], temp[i]);
    }
}

void sort_people_by_age()
{

    int i;
    int k;
    int j;
    int age1 = 0;
    int age2 = 0;
    for (i = 0; i < numScientists - 1; i++)
    {
        for (j = 0; j < numScientists - i - 1; j++)
        {
            age1 = 0;
            age2 = 0;
            for (k = 0; scientists[j][2][k] != '\0'; k++)
            {
                if (scientists[j][2][k] == ' ')
                {
                    continue;
                }
                age1 = age1 * 10 + (scientists[j][2][k] - 48);
            }
            for (k = 0; scientists[j + 1][2][k] != '\0'; k++)
            {
                if (scientists[j + 1][2][k] == ' ')
                {
                    continue;
                }
                age2 = age2 * 10 + (scientists[j + 1][2][k] - 48);
            }

            if (age1 > age2)
            {

                swapScientists(j, j + 1);
            }
        }
    }
}
void sort_people_by_branch()
{
    int i;
    int k;
    int j;
    int age1, age2;
    for (i = 0; i < numScientists - 1; i++)
    {
        for (j = 0; j < numScientists - i - 1; j++)
        {
            if (strcmp(scientists[j][3], scientists[j + 1][3]) > 0)
            {
                swapScientists(j, j + 1);
            }
            if (strncmp(scientists[j][3], scientists[j + 1][3], 4) == 0)
            {
                age1 = 0;
                age2 = 0;
                for (k = 0; scientists[j][2][k] != '\0'; k++)
                {
                    if (scientists[j][2][k] == ' ')
                    {
                        continue;
                    }
                    age1 = age1 * 10 + (scientists[j][2][k] - 48);
                }
                for (k = 0; scientists[j + 1][2][k] != '\0'; k++)
                {
                    if (scientists[j + 1][2][k] == ' ')
                    {
                        continue;
                    }
                    age2 = age2 * 10 + (scientists[j + 1][2][k] - 48);
                }
                if (age1 > age2)
                {
                    swapScientists(j, j + 1);
                }
            }
        }
    }
}
void filter_people_by_branch()
{
    char target[100];
    printf("Enter target:");
    scanf("%s", &target);
    int count = 0;
    int i;
    printf("Name                Surname            Age                Branch1            Branch2 \n\n");
    for (i = 0; i < numScientists - 1; i++)
    {
        char *found = strstr(scientists[i][3], target);
        while (found != NULL)
        {
            printf("%-18s %-18s %-18s %-18s %-18s\n", scientists[i][0], scientists[i][1], scientists[i][2], scientists[i][3], scientists[i][4]);
            found = strstr(found + 1, target);
        }
        found = strstr(scientists[i][4], target);
        while (found != NULL)
        {
            printf("%-18s %-18s %-18s %-18s %-18s\n", scientists[i][0], scientists[i][1], scientists[i][2], scientists[i][3], scientists[i][4]);
            found = strstr(found + 1, target);
        }
    }
}
void filter_people_by_profession()
{
    int i;
    char target[50] = " COMPUTER SCIENCE";
    printf("\nName                Surname            Age                Branch1            Branch2 \n\n");
    for (i = 0; i < numScientists - 1; i++)
    {
        char *found = strstr(scientists[i][3], target);
        while (found != NULL)
        {
            if (strstr(scientists[i][4], "MATHEMATICS") == 0)
            {
                printf("%-18s %-18s %-18s %-18s %-18s\n", scientists[i][0], scientists[i][1], scientists[i][2], scientists[i][3], scientists[i][4]);
            }
            found = strstr(found + 1, target);
        }
    }
}
void printTable()
{
    int i;
    printf("Name                Surname            Age                Branch1            Branch2 \n\n");
    for (i = 0; i < numScientists; i++)
    {

        printf("%-18s %-18s %-18s %-18s %-18s\n", scientists[i][0], scientists[i][1], scientists[i][2], scientists[i][3], scientists[i][4]);
    }
}
int main()
{

    FILE *file = fopen("input1.txt", "r");
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *token;
        int fieldIndex = 0;
        token = strtok(line, ",");
        while (token != NULL && fieldIndex < MAX_FIELDS && numScientists < MAX_SCIENTISTS)
        {
            strncpy(scientists[numScientists][fieldIndex], token, MAX_LENGTH - 1);
            int len = strlen(scientists[numScientists][fieldIndex]);
            scientists[numScientists][fieldIndex][len] = '\0';
            token = strtok(NULL, ",");
            fieldIndex++;
        }
        numScientists++;
    }
    int i;
    printTable();
    int choice;
    int flag = 0;
    while (1)
    {
        if (flag == 1)
        {
            break;
        }
        printf("*****Menu*****\n");
        printf("1. Sort and display all individuals by age\n");
        printf("2. Sort and display individuals in the branch by age\n");
        printf("3. Show individuals with the branch 'SCIENCE'\n");
        printf("4. Show computer scientists who are not mathematicians\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            sort_people_by_age();
            printTable();
            break;
        case 2:
            sort_people_by_age();
            sort_people_by_branch();
            printTable();
            break;
        case 3:
            filter_people_by_branch();
            break;
        case 4:
            filter_people_by_profession();
            break;
        case 5:
            flag = 1;
            printf("Exiting...\n");
            break;
        default:

            printf("Invalid choice. Please choose a valid option.\n");
            break;
        }
    }

    return 0;
}
