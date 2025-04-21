#include <stdio.h>
int number_array[] = { 
         45,  46,  47,  48,  49,  50,  133,  52,  53,  54,  55,  111,  57,  58,  59,  60, 
         61,  62,  63,  64,  65,  66,  55,  55,  69,  70,  55,  45,  73,  55,  75,  76,
         77,  78,  79,  80,  81,  82,  55,  55,  85,  86,  87,  88,  89,  90,  91,  92,
         93,  193, 95,   133,  76,  191,  55, 100, 101, 102, 76, 104, 105, 106, 107, 108,
        120, 110, 111, 112, 113, 114, 115, 116, 117, 118, 163, 120, 121, 122, 193, 124,
        125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
        141, 193, 133, 144, 145, 146, 147, 148, 149, 150, 151, 193, 153, 154, 155, 156,
        157, 158, 111, 160, 120, 162, 163, 128, 165, 166, 167, 168, 169, 170, 171, 172,
        173, 174, 175, 176, 177, 111, 179, 180, 181, 111, 120, 184, 133, 186, 187, 188,
        125, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 125, 201, 202, 203, 173,
        205,  61, 128, 173,  76, 111,133,45,-1};

int find_size_of_array(int A[])
{
    int i = 0;
    while (A[i] != -1)
    {
        i++;
    }
    return i + 1;
}
void find_avg(int num1, int num2)
{
    int i = 0;
    int j = 0;
    float total = 0;
    int count = 0;
    while (num2 != num1 + i - 1) // num2 ye kadar ulaşması için -1 
    {
        j = 0;
        while (number_array[j] != -1) // her sayı için kaç tane olduğunu buluyor toplama ekliyor bulduğu sayıları
        {
            if (number_array[j] == num1 + i)
            {
                total += num1 + i;
                count++;
            }
            j++;
        }
        i++;
    }
    printf("Average: %.2f", total / count);
}
void find_mod(int num1, int num2)
{
    int size_array = find_size_of_array(number_array);
    int y_values[num2 - num1 + 1]; // histogramda kaç tane değer varsa okadarlık bir array
    int a = 0;
    for (a = 0; a < num2 - num1 + 1; a++) // array içini sıfıra çekiyoruz
    {
        y_values[a] = 0;
    }
    int i = 0;
    int j = 0;
    int max_y = 0;
    int count = 0;
    while (num2 != num1 + i - 1)
    {
        j = 0;
        while (number_array[j] != -1)
        {
            if (number_array[j] == num1 + i) // arraydeki elemanları kaçartane olduğunu bulan while
            {
                y_values[i] += 1;
            }
            j++;
        }
        i++;
    }

    int max_deger = y_values[0];
    for (i= 1; i < num2 - num1 + 1; i++) // en çok kaç defa tekrar etmiş onu buluyoruz
    {
        if (y_values[i] > max_deger)
        {
            max_deger = y_values[i];
        }
    }
    printf("\nMode: ");
    for (i = 0; i < num2 - num1 + 1; i++) // en çok tekrar edenleri bastırıyoruz
    {
        if (y_values[i] == max_deger)
        {
            printf("%d ", i + num1);
        }
    }
}
int find_median(int num1, int num2) 
{
    int y_values[num2 - num1 + 1];
    int i = 0;
    int j = 0;
    float total = 0;
    int count = 0;
    while (num2 != num1 + i - 1)
    {
        j = 0;
        while (number_array[j] != -1)
        {
            if (number_array[j] == num1 + i) // y_values arrayini sayı aralığıyla dolduruyoruz
            {
                y_values[count] = num1 + i;
                count++;
            }
            j++;
        }
        i++;
    }

    float num = 0.0;
    for (i = 0; i < count; i++)
    {
        if (count % 2 == 0) 
        {
            if (i == count / 2)
            {

                num = (float)(y_values[i - 1] + y_values[i]) / 2;// ortadaki iki sayının ortalaması alınır
            }
        }
        else
        {
            if (i == count / 2)
            {
                num = (float)y_values[i]; // ortadaki sayı alınır
            }
        }
    }
    printf("\nMedian: %.2f", num);
}
int draw_histogram(int num1, int num2)
{
    int size_array = find_size_of_array(number_array);
    int y_values[num2 - num1 + 1];
    int a = 0;
    for (a = 0; a < num2 - num1 + 1; a++)
    {
        y_values[a] = 0;
    }
    int i = 0;
    int j = 0;
    int max_y = 0;
    int count = 0;
    while (num2 != num1 + i - 1)
    {
        count = 0;
        j = 0;
        while (number_array[j] != -1)
        {

            if (number_array[j] == num1 + i) // hangi sayıdan kaç tane var onu y_values arrayine bastıran kod
            {
                y_values[i] += 1;
                count++;
            }
            j++;
        }
        if (count > max_y) // maxy yi bulur
        {
            max_y = count;
        }
        i++;
    }
    int x, y;

    for (y = max_y; y >= 1; y--) // max y den başlatarak *ları bastıran kod
    {

        for (x = 1; x <= num2 - num1 + 1; x++)
        {
            if (y <= y_values[x - 1]) // y sürekli 1 azaldığı için eğer o indexteki sayı y sayısından büyük veya eşitse * bastır
            {
                printf("*");
            }

            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
int main()
{

    int num1, num2;
    int decide;
    while (1)
    {
        printf("\nEnter A and B values: ");
        scanf("%d %d", &num1, &num2);
        if (num1 >= 50 && num2 <= 200)
        {
            draw_histogram(num1, num2);
            printf("Would you like to add new numbers? (Press 1 for yes ,Press 0 for no): ");
            scanf("%d", &decide);
            if (decide == 0)
            {
                find_avg(num1, num2);
                find_median(num1, num2);
                find_mod(num1, num2);
                break;
            }
            else if (decide == 1)
            {
                int count = 0, input;
                printf("Enter numbers (up to 5), enter 0 to proceed to Part 3, or -1 to finish input:\n");
                while (1)
                {
                    if (count == 5)
                    {
                        draw_histogram(num1, num2);
                        find_avg(num1, num2);
                        find_median(num1, num2);
                        find_mod(num1, num2);
                        break;
                    }
                    scanf("%d", &input);
                    if (input == -1)
                    {
                        draw_histogram(num1, num2);
                        find_avg(num1, num2);
                        find_median(num1, num2);
                        find_mod(num1, num2);
                        break;
                    }
                    else if (input == 0)
                    {
                        find_avg(num1, num2);
                        find_median(num1, num2);
                        find_mod(num1, num2);
                        break;
                    }
                    else
                    {
                        int size_array = find_size_of_array(number_array);
                        number_array[size_array - 1] = input;
                        number_array[size_array] = -1;
                        count++;
                    }
                }
            }
            else
            {
                printf("\nInvalid Input\n");
            }
            break;
        }
        else
        {
            printf("50 and 200 arası numbers!\n");
        }
    }
}