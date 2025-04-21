#include <stdio.h>

int isPrime(int number){
    if(number <= 1) 
        return 0;
    
    int i;
    for(i = 2; i*i <= number; i++) {
        if(number % i == 0)
            return 0; 
    }
    return 1; 
}

int countPrimes(int arr[], int sizeOfArray){
    int numberOfPrimes = 0;
    int i;
    for( i = 0; i < sizeOfArray; i++) {
        if(isPrime(arr[i]))
            numberOfPrimes++;
    }
    return numberOfPrimes;
}

int main() {
    int arr[5] = {1, 2, 1, 2, 5};
    int count = countPrimes(arr, 5);
    
    printf("%d", count);
    
    return 0;
}

