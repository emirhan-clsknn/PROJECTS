#include <stdio.h>

int find_key(long long int studentid)
{
    while (studentid > 9)
    {
        int sum = 0;
        while (studentid != 0)
        {
            sum += studentid % 10;
            studentid = studentid / 10;
        }
        studentid = sum;
    }
    return studentid;
}

int main()
{
    long long int studentid = 225004001180;
    int key = find_key(studentid);
    char ch;
    char alphabet[61] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                         'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                         '(', '<', '=', '+', ')', '[', '*', '/', ']', '{', '>', '!', '-', '}', '?',
                         '\\', '&', '|', '%', '_', ';', '"', '#', '.', '\'', '0', '1', '2', '3', '4',
                         '5', '6', '7', '8', '9'};
    printf("Decrypted C code: \n");
    while (scanf("%c", &ch) != EOF)
    {
        if (ch == '@')
        {
            scanf("%c", &ch);
            scanf("%c", &ch);
            int index = 0;
            while (alphabet[index] != ch)
            {
                index++;
            }
            printf("/* There is %c", alphabet[(index - key +61 ) % 61]);
            scanf("%c",&ch);
            int index1 = 0;
            while (alphabet[index1] != ch)
            {
                index1++;
            }
            printf("%c characters as comment.*/", alphabet[(index1 - key +61 ) % 61]); 

        }
        else if (ch == ' ')
        {
            printf("%c", ch);
        }
        else if (ch == '\t')
        {
            printf("%c", ch);
        }
        else if (ch == '\n')
        {
            printf("%c", ch);
        }
        else
        {
            int index = 0;
            while (alphabet[index] != ch)
            {
                index++;
            }
            printf("%c", alphabet[(index - key +61 ) % 61]);
        }
    }
    return 0;
}
