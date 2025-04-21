#include <stdio.h>
int magic_nums[20];
int magic_count = 0;
char news_id[30];
char news[11];
void get_id_news()
{
    FILE *f = fopen("all_news_id.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int i = 0;
    char num = '0';
    while (i != 30)
    {
        news_id[i] ='0';
        i++;
    }
    i = 0;
    while (fscanf(f, "%c", &num) != EOF)
    {
        if (news_id[i+1] == '\0')
        {
            break;
        }
            news_id[i] = num;
            fscanf(f, "%c", &num);
            i++;
    }
    fclose(f);
}
void get_title()
{
    int new = 0;
    char newss = ' ';
    char chtr;
    while (news_id[new] != '0')
    {
        news[0] = 'n';
        news[1] = 'e';
        news[2] = 'w';
        news[3] = 's';
        news[4] = '/';
        news[5] = news_id[new];
        news[6] = '.';
        news[7] = 't';
        news[8] = 'x';
        news[9] = 't';
        FILE *f = fopen(news, "r");
        printf("Title of %c. ", news_id[new]);
        do
        {
            fscanf(f, "%c", &chtr);
            printf("%c", chtr);
        } while (chtr != '\n');
        fclose(f);
        new ++;
    }
}
void get_news(int new)
{
    int arr[4];
    int i = 0, element;
    int num;
    char newa;
    newa = new + '0';
    char chtr;

    news[0] = 'n';
    news[1] = 'e';
    news[2] = 'w';
    news[3] = 's';
    news[4] = '/';
    news[5] = newa;
    news[6] = '.';
    news[7] = 't';
    news[8] = 'x';
    news[9] = 't';
    FILE *f = fopen(news, "r");
    while (fscanf(f, "%c", &chtr) != EOF)
    {
        if (chtr == '#')
        {
            fscanf(f, "%d", &num);
        }
        else
        {
            printf("%c", chtr);
        }
    }
    printf("\n");
    fclose(f);
}
int read_check(int new)
{
    FILE *file = fopen("readed_news_id.txt", "r");
    char chtr;
    int num;
    int flag = 0;
    if (file == NULL)
    {
        printf("Dosya acilamadi.");
        return -1;
    }
    while (fscanf(file, "%d", &num) != EOF)
    {
        if (num == new)
        {
            flag = 1;
            return 1;
            break;
        }

        while (fscanf(file, "%c", &chtr) != EOF)
        {
            if (chtr == '\n')
            {
                break;
            }
        }
    }
    fclose(file);
    FILE *file2 = fopen("readed_news_id.txt", "a+");
    if (flag == 0)
    {
        fprintf(file2, "\n%d", new);
        fclose(file2);
        return 0;
    }
    else
    {
        fclose(file2);
        return -1;
    }
}
void print_reads()
{
    FILE *file = fopen("readed_news_id.txt", "r");
    char chtr;
    int num;
    int flag = 0;
    if (file == NULL)
    {
        printf("Dosya acilamadi.");
        return;
    }
    printf("Readed news are listed below:\n");
    while (fscanf(file, "%d", &num) != EOF)
    {
        printf("%d. news is readed\n", num);
        while (fscanf(file, "%c", &chtr) != EOF)
        {
            if (chtr == '\n')
            {
                break;
            }
        }
    }
}
void get_magic(int new)
{
    int arr[4];
    int i = 0, element;
    int num;
    char newa;
    newa = new + '0';
    char chtr;

    news[0] = 'n';
    news[1] = 'e';
    news[2] = 'w';
    news[3] = 's';
    news[4] = '/';
    news[5] = newa;
    news[6] = '.';
    news[7] = 't';
    news[8] = 'x';
    news[9] = 't';
    magic_count = 0;
    FILE *f = fopen(news, "r");
    while (fscanf(f, "%c", &chtr) != EOF)
    {
        if (chtr == '#')
        {
            fscanf(f, "%d", &num);
            magic_nums[magic_count] = num;
            magic_count++;
        }
    }
    printf("\n");
    fclose(f);
}
void find_secret(int new)
{
    int i;
    float total = 0;
    float y, x;
    for (i = 0; i < magic_count; i++)
    {
        x = magic_nums[i];
        y = (x * x * x) - (x * x) + 2;
        total += y * y;
    }
    if (new == 1)
    {
        printf("First Experiment Key = %.2f\n", total);
    }
    else if (new == 2)
    {
        printf("Second Experiment Key = %.2f\n", total);
    }
    else if (new == 3)
    {
        printf("Third Experiment Key = %.2f\n", total);
    }
    else if (new == 4)
    {
        printf("Fourth Experiment Key = %.2f\n", total);
    }
    else
    {
        printf("Wrong input\n");
    }
}
void menu()
{
    int decide;
    char choice;
    do
    {
        printf("\n*************Daily Press*************\n\n");
        printf("Today's news are listed for you :\n\n");
        get_id_news();
        get_title();
        printf("\nWhat do you want to do?\n");
        printf("a. Read a new\n");
        printf("b. List the readed news\n");
        printf("c. Get decrypted information from the news\n");
        printf("q. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
        {
            int newsIndex;
            int i = 0;
            while (news_id[i] != '0')
            {
                i++;
            }
            printf("Enter the index of the news you want to read (1-%d): ", i);
            scanf("%d", &newsIndex);
            if (newsIndex >= 1 && newsIndex <= i)
            {
                int check = read_check(newsIndex);
                if (check == 1)
                {
                    printf("This new is readed.\n");
                    printf("Do you want to read again? Yes(1) / No(0)\n");
                    scanf("%d", &decide);
                    if (decide == 1)
                    {
                        get_news(newsIndex);
                        printf("Do you want to read other news? Yes(1) / No(0)\n");
                        scanf("%d", &decide);
                        if (decide == 1)
                        {
                            break;
                        }
                        else if (decide == 0)
                        {
                            choice = 'q';
                            printf("Goodbye!\n");
                        }
                        else
                        {
                            printf("Wrong input\n");
                        }
                        break;
                    }
                    else if (decide == 0)
                    {
                        choice = 'q';
                        printf("Goodbye!\n");
                    }
                    else
                    {
                        printf("Wrong input\n");
                    }
                }
                else
                {
                    get_news(newsIndex);
                    printf("Do you want to read other news? Yes(1) / No(0)\n");
                    scanf("%d", &decide);
                    if (decide == 1)
                    {
                        break;
                    }
                    else if (decide == 0)
                    {
                        choice = 'q';
                        printf("Goodbye!\n");
                    }
                    else
                    {
                        printf("Wrong input\n");
                    }
                }
            }
            else
            {
                printf("Invalid news index!\n");
            }
            break;
        }
        case 'b':
            print_reads();
            printf("Do you want to continue? Yes(1) / No(0)\n");
            scanf("%d", &decide);
            if (decide == 1)
            {
                break;
            }
            else if (decide == 0)
            {
                choice = 'q';
                printf("Goodbye!\n");
            }
            else
            {
                printf("Wrong input\n");
            }
            break;
        case 'c':
            printf("Which news would you like to decrypt?: ");
            scanf("%d", &decide);
            get_magic(decide);
            get_news(decide);
            find_secret(decide);
            printf("Do you want to continue? Yes(1) / No(0)\n");
            scanf("%d", &decide);
            if (decide == 1)
            {
                break;
            }
            else if (decide == 0)
            {
                choice = 'q';
                printf("Goodbye!\n");
            }
            else
            {
                printf("Wrong input\n");
            }
            break;
        case 'q':
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 'q');
}
int main()
{
    menu();
    return 0;
}
