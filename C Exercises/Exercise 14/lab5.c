#include <stdio.h>
#include <time.h>
typedef struct block{
char type;
int cost;

}block;
int initBoard(struct block board[10][10]){
int i,j;
for(i=0;i<10;i++){
   for(j=0;j<10;j++){
   	board[i][j].type='.';
   	board[i][j].cost=rand()%(10+1);
   }	
}
int cx=rand()%(10);
int cy=rand()%(10);
board[rand()%(10)][rand()%(10)].type='F';
board[cx][cy].type='C';
}

void printBoard(struct block board[10][10]){
int i,j;
for(i=0;i<10;i++){
   for(j=0;j<10;j++){
   	printf("%c ",board[i][j].type);
   }	
   printf("\n");
}
}

void printMoves(char printMoves[]){
int i=0;
while(1){
if(printMoves[i]=='\0'){
break;
}
printf("%c ",printMoves[i]);
i++;
}
printf("\n");
}

void gameplay(struct block board[10][10]){
char moves[50]={'\0'};
char chtr;
char chtr2;
initBoard(board);
int cx;
int cy;
int fx;
int fy;
int i ,j;
for(i=0;i<10;i++){
   for(j=0;j<10;j++){
   	if(board[i][j].type=='C'){
   	cx=i;
   	cy=j;
   	}
   	if(board[i][j].type=='F'){
   	fx=i;
   	fy=j;
   	}
   }	
}
char arrr[10][10];
for(i=0;i<10;i++){
   for(j=0;j<10;j++){
   	arrr[i][j]=board[i][j].type;
   }	
}

i=0;
j=0;
int a=0;
while(1){
printBoard(board);
printMoves(moves);
printf("Enter your moves(When you ready enter 'r'):");
scanf("%c",&chtr);
scanf("%c",&chtr2);
int flag=0;
switch(chtr){
case 'w':
moves[i]='^';
j--;
arrr[cx+j][cy+a]='-';
break;
case 'a':
moves[i]='<';
a--;
arrr[cx+j][cy+a]='-';
break;
case'd':
moves[i]='>';
a++;
arrr[cx+j][cy+a]='-';
break;
case's':
moves[i]='v';
j++;
arrr[cx+j][cy+a]='-';
break;
case 'r':
break;
default:
printf("Invalid choice.");
break;
}
if(chtr=='r'){
if(fx==cx+j){
if(fy==cy+a){
printf("\nYou have done\n");
}
}
break;
}
moves[i+1]='\0';
i++;
}
for(i=0;i<10;i++){
   for(j=0;j<10;j++){
   	printf("%c ",arrr[i][j]);
   }	
   printf("\n");
}
}



int main() {
srand(time(NULL));
block board[10][10];
gameplay(board);
return 0;
}
