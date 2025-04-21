#include <stdio.h>

#define MAXIT 100

void hs(int nums[], int *cn, int maxit) {
    ;	
    if (nums[*cn-1] == 1 || *cn >= maxit) {
        return;
    }
    
    if (nums[*cn-1] % 2 == 0)
        nums[*cn-1] = nums[*cn-1] / 2;
    else if(*cn==1){	
    nums[0]=nums[0];	
    }
    else
        nums[*cn-1] = 3 * nums[*cn-1] + 1;
    
    
    nums[*cn] = nums[*cn-1];
    *cn += 1; 
    
    hs(nums, cn, maxit);
}

int main() {
    int a[MAXIT] = {5};
    int n = 1;


    hs(a, &n, MAXIT);


    printf("Hailstone Sequence:\n");
    int i;
    for (i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

