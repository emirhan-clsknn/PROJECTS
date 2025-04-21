#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card
{
    const char *face;
    const char *suit;
}card;

void initializeDeck(card deck[])
{
    const char *faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    int index = 0;
    int suit, face;
    for (suit = 0; suit < 4; suit++)
    {
        for (face = 0; face < 13; face++)
        {
            deck[index].face = faces[face];
            deck[index].suit = suits[suit];
            index++;
        }
    }
}

void shuffleDeck(card deck[])
{
    srand(time(0));
    int i;
    for (i = 0; i < 52; i++)
    {
        int j = rand() % 52;

        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(card deck[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        printf("%5s of %-8s\n", deck[i].face, deck[i].suit);
    }
}

int main()
{
    card deck[52];

    initializeDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);

    return 0;
}
