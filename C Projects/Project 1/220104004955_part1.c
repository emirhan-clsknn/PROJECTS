#include <stdio.h>

int find_key(long long int studentid) /*This function gives the key we use during student number encryption.*/ 
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

    int inComment = 0;
    int commentCount = 0;

    while (scanf("%c", &ch) != EOF) /*It pulls data one by one in the input file*/
    {
        if (ch == '/') /*When it comes across a comment line, it encrypts it differently.*/
        {
            scanf("%c", &ch);
            if (ch == '*')
            {
                printf("@ ");
                inComment = 1;
            }
        }
        if (ch == '*') /*comment line ending.*/
        {
            scanf("%c", &ch);
            if (ch == '/')
            {
                int digit2 = commentCount % 10;  /*Encrypting the number of characters in a comment line*/
                int digit1 = commentCount / 10;
                int index = 0;
                while (alphabet[index] != (digit1 + 48))
                {
                    index++;
                }
                printf("%c", alphabet[(index + key) % 61]);

                int index1 = 0;
                while (alphabet[index1] != (digit2 + 48))
                {
                    index1++;
                }
                printf("%c", alphabet[(index1 + key) % 61]);

                inComment = 0;
                commentCount = 0;
                scanf("%c", &ch);
            }
        }

        if (inComment == 0) /*the part where the code is encrypted*/
        {
            if (ch == ' ')
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
                printf("%c", alphabet[(index + key) % 61]);
            }
        }
        if (inComment == 1) /*where the characters inside the comment line are counted*/
        {
            if (ch == ' ')
            {
                commentCount = commentCount;
            }
            else
            {
                commentCount++;
            }
        }
    }
    return 0;
}
