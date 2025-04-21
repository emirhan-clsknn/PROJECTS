#include <stdio.h>

void drawStickman(int position, char armStatus) {
	
    switch(position) {
        case 0:
            if (armStatus == 'u') {
                printf(" o\n");
                printf("/|\\ \n");
                printf(" | \n");
                printf("/ \\ \n");
            } else {
                printf(" o\n");
                printf(" |\n");
                printf(" |\n");
                printf("/ \\ \n");
            }
            break;
        case 1:
            if (armStatus == 'u') {
                printf("  o\n");
                printf(" /|\\ \n");
                printf("  |\n");
                printf(" / \\ \n");
            } else {
                printf("  o\n");
                printf("  |\n");
                printf("  |\n");
                printf(" / \\ \n");
            }
            break;
        case 2:
            if (armStatus == 'u') {
                printf("   o\n");
                printf("  /|\\ \n");
                printf("   |\n");
                printf("  / \\ \n");
            } else {
                printf("   o\n");
                printf("   |\n");
                printf("   |\n");
                printf("  / \\ \n");
            }
            break;
        case 3:
            if (armStatus == 'u') {
                printf("    o\n");
                printf("   /|\\ \n");
                printf("    |\n");
                printf("   / \\ \n");
            } else {
                printf("    o\n");
                printf("    |\n");
                printf("    |\n");
                printf("   / \\ \n");
            }
            break;
        case 4:
            if (armStatus == 'u') {
                printf("     o\n");
                printf("    /|\\ \n");
                printf("     |\n");
                printf("    / \\ \n");
            } else {
                printf("     o\n");
                printf("     |\n");
                printf("     |\n");
                printf("    / \\ \n");
            }
            break;
        case 5:
            if (armStatus == 'u') {
                printf("      o\n");
                printf("     /|\\ \n");
                printf("      |\n");
                printf("     / \\ \n");
            } else {
                printf("      o\n");
                printf("      |\n");
                printf("      |\n");
                printf("     / \\ \n");
            }
            break;
        case 6:
            if (armStatus == 'u') {
                printf("       o\n");
                printf("      /|\\ \n");
                printf("       |\n");
                printf("      / \\ \n");
            } else {
                printf("       o\n");
                printf("       |\n");
                printf("       |\n");
                printf("      / \\ \n");
            }
            break;
         case 7:
            if (armStatus == 'u') {
                printf("        o\n");
                printf("       /|\\ \n");
                printf("        |\n");
                printf("       / \\ \n");
            } else {
                printf("        o\n");
                printf("        |\n");
                printf("        |\n");
                printf("       / \\ \n");
            }
            break;   
                    
        default:
            if (armStatus == 'u') {
                printf(" o\n");
                printf("/|\\ \n");
                printf(" |\n");
                printf("/ \\ \n");
            } else {
                printf(" o\n");
                printf("/|\\ \n");
                printf(" |\n");
                printf("/ \\ \n");
            }
            break;
    }
}

int moveStickman(int position, char move) {

    switch (move) {
        case 'a':
            if(position <=0){
            return position=0;
            }else{
            return position - 1;
            }
            
        case 'd':
            if(position >=7){
            return position=7;
            }else{
            return position + 1;
            }
        case 's':
            return -1;
        default:
            return position;
    }
    
}

int main() {
    int position = 0, newPosition = 0;
    char userData = 'b';
    char armStatus = 'd';
    char move = 'n';

    printf("Welcome to Stickman Animation!\nUse 'a' to move left, 'd' to move right, 's' to switch arms, and 'e' to exit.\n");

    while (1) {
        printf("Enter your move:");
        scanf(" %c", &userData); 

        if (userData == 'd' || userData == 'a' || userData == 's' || userData == 'e') {
            if (userData == 'e') {
                printf("Exiting...\n");
                break; 
            }
            move = userData;
        } else {
            printf("\nPlease Enter right characters.\n");
            continue; 
        }
        newPosition = moveStickman(position, move);

        if (newPosition != -1) {
            position = newPosition; 
        } else {
            armStatus = (armStatus == 'd') ? 'u' : 'd'; 
        }

        drawStickman(position, armStatus); 
    }

    return 0;
}

