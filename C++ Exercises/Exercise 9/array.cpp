#include <iostream>
#include <vector>
using namespace std;

// Selection sort fonksiyonu
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i; // En küçük elemanın indeksi
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {                 // Yeni en küçük elemanı bul
                minIndex = j; // En küçük elemanın indeksini güncelle
            }
        }
        // Bulunan en küçük eleman ile mevcut elemanı yer değiştir
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
void bubbleSort(int arr[], int size)
{
    int length = size; // Dizinin uzunluğunu tutar
    for (int i = length - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1])

            {
                // Swap the numbers
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
}

int findMax(int arr[], int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[maxIndex] < arr[i])
        {
            maxIndex = i; // Yeni en büyük elemanı bul
        }
    }
    return maxIndex;
}
void frequency(int arr[], int size)
{
    vector<int> arr2(size, 0); // Frekansları tutmak için bir vector oluştur

    // Frekansları say
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        { // j'yi i+1'den başlat
            if (arr[i] == arr[j])
            {
                arr2[i] += 1; // Aynı eleman bulunduğunda frekansı artır
                arr2[j] = -1; // İşlenmiş elemanı işaretle
            }
        }
    }

    // Frekansları yazdır
    cout << "Eleman frekansları:" << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr2[i] != -1)
        {                                                  // İşlenmiş elemanları atla
            cout << arr[i] << ": " << arr2[i] + 1 << endl; // Frekansı yazdır
        }
    }
}
// Ana fonksiyon
int main()
{
    int arr[] = {64, 25, 12, 22, 11};        // Sıralanacak dizi
    int size = sizeof(arr) / sizeof(arr[0]); // Dizinin boyutunu hesapla

    cout << "Sorted array in ascending order: ";
    bubbleSort(arr, size); // Sıralama fonksiyonunu çağır

    // Sıralanmış diziyi yazdır
    for (int x : arr)
    {
        cout << x << " ";
    }
    frequency(arr, size); // Sıralan
    cout << endl;         // Yeni satır ekle
    cout << arr[findMax(arr, size)];

    return 0; // Programdan çık
}
