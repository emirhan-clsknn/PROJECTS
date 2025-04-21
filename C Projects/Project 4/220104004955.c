#include <stdio.h>
char first_initial(FILE *id_fp, int id)
{
    id_fp = fopen("second.txt", "r");
    int fseek(FILE * id_fp, long int offset, int whence);
    int current_id;
    char initial_letter_name = '\0';
    int flag = 0;
    while (fscanf(id_fp, "%d", &current_id) != EOF)
    {

        if (flag == 1)
        {
            break;
        }
        if (current_id == id)
        {
            fscanf(id_fp, "%c", &initial_letter_name);
            fscanf(id_fp, "%c", &initial_letter_name);
            break;
        }
        else
        {
            while (1)
            {
                char current_letter;
                if (fscanf(id_fp, "%c", &current_letter) == EOF)
                {
                    flag = 1;
                    break;
                }
                if (current_letter == '\n')
                {
                    break;
                }
            }
        }
    }
    fclose(id_fp);
    return initial_letter_name;
}
char last_initial(FILE *id_fp, int id)
{
    id_fp = fopen("second.txt", "r");
    int fseek(FILE * id_fp, long int offset, int whence);
    int current_id;
    char initial_letter_lname = '\0';
    int flag = 0;
    while (fscanf(id_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }
        if (current_id == id)
        {
            fscanf(id_fp, "%c", &initial_letter_lname);
            while (1)
            {
                fscanf(id_fp, "%c", &initial_letter_lname);
                if (initial_letter_lname == ';')
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                fscanf(id_fp, "%c", &initial_letter_lname);
                break;
            }
            break;
        }
        else
        {
            while (1)
            {
                char current_letter;
                if (fscanf(id_fp, "%c", &current_letter) == EOF)
                {
                    flag = 1;
                    break;
                }
                if (current_letter == '\n')
                {
                    break;
                }
            }
        }
    }
    fclose(id_fp);
    return initial_letter_lname;
}
int get_id_fi(FILE *id_fp, char first_initial)
{
    id_fp = fopen("second.txt", "r");
    FILE *id_fp_wr;
    id_fp_wr = fopen("idOfNames.txt", "w");
    int fseek(FILE * id_fp, long int offset, int whence);
    int current_id;
    char chtr = '\0';
    int flag = 0;
    while (fscanf(id_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }

        fscanf(id_fp, "%c", &chtr);
        fscanf(id_fp, "%c", &chtr);

        if (chtr == first_initial)
        {
            fprintf(id_fp_wr, "%d \n", current_id);
        }
        else
        {
            while (1)
            {
                char current_letter;
                if (fscanf(id_fp, "%c", &current_letter) == EOF)
                {
                    flag = 1;
                    break;
                }
                if (current_letter == '\n')
                {
                    break;
                }
            }
        }
    }
    fclose(id_fp);
    fclose(id_fp_wr);
    return 0;
}
double final_avg(FILE *info_fp, int class_id)
{
    info_fp = fopen("first.txt", "r");
    int current_id;
    int midterm1 = 0;
    int midterm2 = 0;
    int final = 0;
    int course_id = 0;
    int flag = 0;
    int counter1 = 0;
    int counter2 = 0;
    double avg1 = 0;
    double avg2 = 0;

    while (fscanf(info_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }

        int check = fscanf(info_fp, ";%d;%d;%d;%d", &midterm1, &midterm2, &final, &course_id);
        if (check == 2)
        {
            continue;
        }
        else if (check == 3)
        {
            course_id = final;
            avg2 += midterm2;
            counter2++;
        }
        else if (check == 4)
        {
            avg1 += final;
            counter1++;
        }
        else
        {
            printf("This course is not exist.");
        }

        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }

    if (class_id == 102)
    {
        return avg1 / counter1;
    }
    else if (class_id == 108)
    {
        return avg2 / counter2;
    }
    else
    {
        return 0;
    }

    fclose(info_fp);
}
double midterm_avg(FILE *info_fp, int class_id)
{
    info_fp = fopen("first.txt", "r");
    int current_id;
    int midterm1 = 0;
    int midterm2 = 0;
    int final = 0;
    int course_id = 0;
    int flag = 0;
    int counter1 = 0;
    int counter2 = 0;
    double avg1 = 0;
    double avg2 = 0;

    while (fscanf(info_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }

        int check = fscanf(info_fp, ";%d;%d;%d;%d", &midterm1, &midterm2, &final, &course_id);
        if (check == 2)
        {
            continue;
        }
        else if (check == 3)
        {
            course_id = final;
            avg2 += midterm1;
            counter2++;
        }
        else if (check == 4)
        {
            avg1 += (midterm1 + midterm2) / 2;
            counter1++;
        }
        else
        {
            printf("This course is not exist.");
        }

        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }

    if (class_id == 102)
    {
        return avg1 / counter1;
    }
    else if (class_id == 108)
    {
        return avg2 / counter2;
    }
    else
    {
        return 0;
    }

    fclose(info_fp);
}
int get_id_li(FILE *id_fp, char first_initial)
{
    id_fp = fopen("second.txt", "r");
    if (id_fp == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }
    FILE *id_fp_wr;
    id_fp_wr = fopen("idOfLnames.txt", "w");
    int fseek(FILE * id_fp, long int offset, int whence);
    int current_id;
    char chtr = '\0';
    int flag = 0;
    int flag2 = 0;
    while (fscanf(id_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }

        fscanf(id_fp, "%c", &chtr);
        while (1)
        {
            fscanf(id_fp, "%c", &chtr);
            if (chtr == ';')
            {
                break;
            }
        }
        fscanf(id_fp, "%c", &chtr);
        if (chtr == first_initial)
        {
            fprintf(id_fp_wr, "%d \n", current_id);
        }
        else
        {
            while (1)
            {
                char current_letter;
                if (fscanf(id_fp, "%c", &current_letter) == EOF)
                {
                    flag = 1;
                    break;
                }
                if (current_letter == '\n')
                {
                    break;
                }
            }
        }
    }
    fclose(id_fp);
    fclose(id_fp_wr);
    return 0;
}
int average_grade(FILE *info_fp, int id)
{
    info_fp = fopen("first.txt", "r");
    double mid_avg102 = midterm_avg(info_fp, 102);
    double mid_avg108 = midterm_avg(info_fp, 108);
    double fin_avg102 = final_avg(info_fp, 102);
    double fin_avg108 = final_avg(info_fp, 108);
    double avg_mid;
    double avg_final;
    int current_id;
    int midterm1 = 0;
    int midterm2 = 0;
    int midterm = 0;
    int final = 0;
    int final1 = 0;
    int course_id = 0;
    int flag = 0;
    double midGPA = 0;
    double finalGPA = 0;
    while (fscanf(info_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }
        if (current_id == id)
        {
            int check = fscanf(info_fp, ";%d;%d;%d;%d", &midterm1, &midterm2, &final, &course_id);
            if (check == 2)
            {
                continue;
            }
            else if (check == 3)
            {
                midterm = midterm1;
                final1 = midterm2;
                course_id = final;

                if (midterm < 40 && midterm < mid_avg108)
                    midGPA = 1.0;
                else if (midterm > 40 && midterm < mid_avg108)
                    midGPA = 2.5;
                else if (midterm < 90 && midterm > mid_avg108)
                    midGPA = 3.5;
                else if (midterm > 90)
                    midGPA = 4.0;
                if (final < 40 && final < fin_avg108)
                    finalGPA = 1.0;
                else if (final > 40 && final < fin_avg108)
                    finalGPA = 2.5;
                else if (final < 90 && final > fin_avg108)
                    finalGPA = 3.5;
                else if (final > 90)
                    finalGPA = 4;

                return ((midGPA + finalGPA) / 2) * 10;
            }
            else if (check == 4)
            {
                midterm = (midterm1 + midterm2) / 2;
                final1 = final;

                if (midterm < 40 && midterm < mid_avg102)
                    midGPA = 1.0;
                else if (midterm > 40 && midterm < mid_avg102)
                    midGPA = 2.5;
                else if (midterm < 90 && midterm > mid_avg102)
                    midGPA = 3.5;
                else if (midterm > 90)
                    midGPA = 4.0;
                if (final < 40 && final < fin_avg102)
                    finalGPA = 1.0;
                else if (final > 40 && final < fin_avg102)
                    finalGPA = 2.5;
                else if (final < 90 && final > fin_avg102)
                    finalGPA = 3.5;
                else if (final > 90)
                    finalGPA = 4;
                return ((midGPA + finalGPA) / 2) * 10;
            }
            else
            {
                printf("There is a problem.");
            }
        }

        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }

    fclose(info_fp);
    return 0;
}
int pass_fail(FILE *info_fp)
{
    info_fp = fopen("first.txt", "r");
    int current_id;
    int midterm1 = 0;
    int midterm2 = 0;
    int final = 0;
    int course_id = 0;

    int flag = 0;

    while (fscanf(info_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }
        int check = fscanf(info_fp, ";%d;%d;%d;%d", &midterm1, &midterm2, &final, &course_id);
        if (check == 2)
        {
            continue;
        }
        else if (check == 3 || check == 4)
        {
            double GPA = average_grade(info_fp, current_id);
            GPA = GPA / 10;
            printf("%d:", current_id);
            if (GPA <= 1)
            {
                printf("FF :FAIL\n");
            }
            else if (GPA > 1 && GPA <= 2.5)
            {
                printf("DD :PASS\n");
            }
            else if (GPA > 2.5 && GPA <= 3)
            {
                printf("CC:PASS\n");
            }
            else if (GPA > 3 && GPA <= 3.5)
            {
                printf("BB:PASS\n");
            }
            else if (GPA > 3.5)
            {
                printf("AA:PASS\n");
            }
        }
        else
        {
            printf("There is a problem.");
        }
        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }

    fclose(info_fp);
    return 0;
}
int find_courseid(FILE *info_fp, int id)
{
    info_fp = fopen("first.txt", "r");
    int current_id;
    int flag = 0;
    int midterm1 = 0;
    int midterm2 = 0;
    int final = 0;
    int flag2 = 0;
    int course_id = 0;
    while (fscanf(info_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }
        if (current_id == id)
        {
            int check = fscanf(info_fp, ";%d;%d;%d;%d", &midterm1, &midterm2, &final, &course_id);
            if (check == 2)
            {
                printf("%d: %d", current_id, midterm2);
            }
            else if (check == 3)
            {
                printf("%d: %d", current_id, final);
            }
            else if (check == 4)
            {
                printf("%d: %d", current_id, course_id);
            }
            flag2 = 1;
        }

        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }
    if (flag2 == 1)
    {
        return 0;
    }
    else
    {
        printf("There is not this id.");
    }
    fclose(info_fp);
}
int find_classes(FILE *info_fp, int id)
{
    info_fp = fopen("first.txt", "r");
    int current_id;
    int flag = 0;
    int midterm1 = 0;
    int midterm2 = 0;
    int final = 0;
    int flag2 = 0;
    int course_id = 0;
    while (fscanf(info_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }
        if (current_id == id)
        {
            int check = fscanf(info_fp, ";%d;%d;%d;%d", &midterm1, &midterm2, &final, &course_id);
            if (check == 2)
            {
                printf("Number of Class: %d", midterm1);
            }
            else if (check == 3)
            {
                printf("Please enter an instructor id.");
                continue;
            }
            else if (check == 4)
            {
                printf("Please enter an instructor id.");
                continue;
            }
            else
            {
                printf("Please enter an instructor id.");
                continue;
            }
        }
        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }
    fclose(info_fp);
}
int print_department(FILE *info_fp, char department)
{
    info_fp = fopen("second.txt", "r");
    int current_id;
    char chtr;
    char initial_letter;
    int flag = 0;
    int midterm1 = 0;
    int midterm2 = 0;
    int final = 0;
    int counter = 0;
    int course_id = 0;
    while (fscanf(info_fp, "%d", &current_id))
    {
        counter = 0;
        if (flag == 1)
        {
            break;
        }
        while (fscanf(info_fp, "%c", &chtr))
        {
            if (chtr == ';')
            {
                counter++;
            }
            if (counter == 3)
            {
                fscanf(info_fp, "%c", &initial_letter);
                break;
            }
        }
        if (initial_letter == 's' && initial_letter == department)
        {
            printf("%d: student\n", current_id);
        }
        else if (initial_letter == 'i' && initial_letter == department)
        {
            printf("%d: instructor\n", current_id);
        }
        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }
    fclose(info_fp);
    return 0;
}
int find_courses(FILE *info_fp, int course)
{
    info_fp = fopen("first.txt", "r");
    int current_id;
    int midterm1 = 0;
    int midterm2 = 0;
    int final = 0;
    int course_id = 0;

    int flag = 0;

    while (fscanf(info_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }
        int check = fscanf(info_fp, ";%d;%d;%d;%d", &midterm1, &midterm2, &final, &course_id);
        if (check == 2)
        {
            continue;
        }
        else if (check == 3 || check == 4)
        {
            if (check == 3)
            {
                course_id = final;
            }
            if (course_id == course)
            {
                double GPA = average_grade(info_fp, current_id);
                GPA = GPA / 10;
                printf("%d:", current_id);
                if (GPA <= 1)
                {
                    printf("FF :FAIL\n");
                }
                else if (GPA > 1 && GPA <= 2.5)
                {
                    printf("DD :PASS\n");
                }
                else if (GPA > 2.5 && GPA <= 3)
                {
                    printf("CC:PASS\n");
                }
                else if (GPA > 3 && GPA <= 3.5)
                {
                    printf("BB:PASS\n");
                }
                else if (GPA > 3.5)
                {
                    printf("AA:PASS\n");
                }
            }
            else
            {
                continue;
            }
        }
        else
        {
            printf("There is a problem.");
        }
        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }

    fclose(info_fp);
    return 0;
}
int print_same_name(FILE *info_fp, int id)
{
    info_fp = fopen("first.txt", "r");
    int current_id;
    int midterm1 = 0;
    int midterm2 = 0;
    int final = 0;
    int course_id = 0;

    int flag = 0;

    while (fscanf(info_fp, "%d", &current_id) != EOF)
    {
        if (flag == 1)
        {
            break;
        }
        if (current_id == id)
        {
            int check = fscanf(info_fp, ";%d;%d;%d;%d", &midterm1, &midterm2, &final, &course_id);
            if (check == 2)
            {
                continue;
            }
            else if (check == 3 || check == 4)
            {
                double GPA = average_grade(info_fp, current_id);
                GPA = GPA / 10;
                printf("%d:", current_id);
                if (GPA <= 1)
                {
                    printf("FF :FAIL\n");
                }
                else if (GPA > 1 && GPA <= 2.5)
                {
                    printf("DD :PASS\n");
                }
                else if (GPA > 2.5 && GPA <= 3)
                {
                    printf("CC:PASS\n");
                }
                else if (GPA > 3 && GPA <= 3.5)
                {
                    printf("BB:PASS\n");
                }
                else if (GPA > 3.5)
                {
                    printf("AA:PASS\n");
                }
            }
            else
            {
                printf("There is a problem.");
            }
        }

        while (1)
        {
            char current_letter;
            if (fscanf(info_fp, "%c", &current_letter) == EOF)
            {
                flag = 1;
                break;
            }
            if (current_letter == '\n')
            {
                break;
            }
        }
    }

    fclose(info_fp);
    return 0;
}

int main()
{
    FILE *id_fp;
    FILE *info_fp;
    char choice;
    int id, course_id;
    char initial;
    int ids;

    do
    {
        printf("\nMenu:\n");
        printf("p: Print all the users pass or fail\n");
        printf("n: Print only the user with a specific first initial\n");
        printf("g: Calculate the GPA of a given student\n");
        printf("c: Print whether each user passed or failed the same class\n");
        printf("t: Print the number of classes for the instructor\n");
        printf("d: Print the department of all persons according to the role\n");
        printf("l: Print the course_id of a given student\n");
        printf("e: Quit the program\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'p':
            pass_fail(info_fp);
            break;
        case 'n':
            printf("Enter a letter to print id: ");
            scanf(" %c", &initial);
            get_id_fi(id_fp, initial);
            FILE *file = fopen("idOfNames.txt", "r");
            while (fscanf(file, "%d\n", &ids) == 1)
            {
                print_same_name(info_fp, ids);
            }
            break;
        case 'g':
            printf("Enter a id to calculate the GPA: ");
            scanf("%d", &id);
            double GPA = average_grade(id_fp, id);
            GPA = GPA / 10;
            printf("%d:", id);
            if (GPA <= 1)
            {
                printf("FF :FAIL\n");
            }
            else if (GPA > 1 && GPA <= 2.5)
            {
                printf("DD :PASS\n");
            }
            else if (GPA > 2.5 && GPA <= 3)
            {
                printf("CC:PASS\n");
            }
            else if (GPA > 3 && GPA <= 3.5)
            {
                printf("BB:PASS\n");
            }
            else if (GPA > 3.5)
            {
                printf("AA:PASS\n");
            }
            break;
        case 'c':
            printf("Enter a class('102' or '108'): ");
            scanf("%d", &course_id);
            find_courses(info_fp, course_id);
            if (course_id == 102)
            {
                float avg_Mgrade = midterm_avg(info_fp, 102);
                float avg_Fgrade = final_avg(info_fp, 102);
                printf("Average of Class: %.2f", (avg_Mgrade + avg_Fgrade) / 2);
            }
            else if (course_id == 108)
            {
                float avg_Mgrade = midterm_avg(info_fp, 108);
                float avg_Fgrade = final_avg(info_fp, 108);
                printf("Average of Class: %.2f", (avg_Mgrade + avg_Fgrade) / 2);
            }
            else
            {
                printf("There is not this class.");
            }
            break;
        case 't':
            printf("Enter an instructor id: ");
            scanf("%d", &course_id);
            find_classes(info_fp, course_id);
            break;
        case 'd':
            printf("Enter a letter to print id('s' or 'i'): ");
            scanf(" %c", &initial);
            print_department(info_fp, initial);
            break;
        case 'l':
            printf("Enter an id: ");
            scanf("%d", &id);
            find_courseid(info_fp, id);
            break;
        case 'e':
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'e');
    return 0;
}
