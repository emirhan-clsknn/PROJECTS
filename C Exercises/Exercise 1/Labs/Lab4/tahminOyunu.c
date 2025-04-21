#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
int target,guess,guessCount=0;
srand(time(0));
target=rand() %1000 +1;
printf("Welcome to the Guessing Game!\n");
while(1){
printf("Enter your guess(between 1 and 1000):");
scanf("%d",&guess);
if(guess<1000 && guess>1){
if(guess<target){
printf("Your guess is less than the target.\n");
guessCount++;
}else if(guess>target){
printf("Your guess is greater than the target.\n");
guessCount++;
}else if(guess==target){
printf("Congratulations! You guessed the target number!\n");
printf("Total guesses made:%d \n",guessCount);
break;
}
}else{
printf("\nPlease Enter a number between 1 and 1000");
}
}

return 0;
}
