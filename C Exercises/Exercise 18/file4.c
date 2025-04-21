#include <stdio.h>
#include <string.h>

// Yardımcı bir fonksiyon: Verilen stringdeki sayıların frekansını sayar.
void count_digits(const char *str, int *digit_count) {
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            digit_count[*str - '0']++;
        }
        str++;
    }
}

// İki array girişindeki sayısal karakterlerin toplam sayısını karşılaştıran fonksiyon.
int compare_digit_counts(const int *a, const int *b) {
    for (int i = 0; i < 10; i++) {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
    }
    return 0;
}

void common(char *arr[], int size, int *idx1, int *idx2) {
    int max1 = -1, max2 = -1;
    int count1[10] = {0}, count2[10] = {0};

    // Tüm stringler için tekrar eden sayı karakterlerini sayar ve karşılaştırır.
    for (int i = 0; i < size; i++) {
        int temp_count[10] = {0};
        count_digits(arr[i], temp_count);

        // Mevcut stringi karşılaştır
        if (compare_digit_counts(temp_count, count1) > 0) {
            // max2'yi max1'e, count2'yi count1'e kopyala
            max2 = max1;
            memcpy(count2, count1, sizeof(count1));

            // max1'i güncelle, count1'i temp_count'a kopyala
            max1 = i;
            memcpy(count1, temp_count, sizeof(count1));
        } else if (compare_digit_counts(temp_count, count2) > 0) {
            // max2'yi ve count2'yi güncelle
            max2 = i;
            memcpy(count2, temp_count, sizeof(count2));
        }
    }

    *idx1 = max1;
    *idx2 = max2;
}

void test() {
    char s1[] = "125";
    char s2[] = "0011";
    char s3[] = "9821";
    char s4[] = "512";
    char *pts[5] = {s1, s2, s3, s4};
    int i1, i2;
    common(pts, 4, &i1, &i2);
    /* should print --> i1: 0, i2: 3 */
    printf("i1: %d, i2: %d\n", i1, i2);
}

int main() {
    test();
    return 0;
}
