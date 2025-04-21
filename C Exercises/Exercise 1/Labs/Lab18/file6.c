#include <stdio.h>


void printsdas(const int a[]) {
    // Base case: if the current element is negative, return
    if (*a < 0) {
        return;
    }

    // Recursive call to move to the next element in the array
    printsdas(a + 1);

    // Print the current element after the recursive call to ensure reverse order
    printf("%d ", *a);
}
int main(){
int a[]={1,2,3,4,5,6,-1};
int b[]={1,2,3,4,5,6,7,-1};

printsdas(a);

    return 0;
}