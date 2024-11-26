#include<stdio.h>
#include"blackjack.h"
#define NUM_DECKS 2


struct test {
	struct cards hand;
	struct cards deck;
};


char suit_to_char(enum suit s);
void print_cards(struct cards c, int items_in_line);


int main() {
	srand(time(NULL));
	int i, sum;

	//TEST GEN
	printf("\nTEST GEN\n");
	struct cards deck = deck_gen(NUM_DECKS);
	puts("Mazzo generato:");
	print_cards(deck, 13);
	puts("\n");

	//TEST SHUFFLE
	printf("\nTEST SHUFFLE\n");
	deck_shuffle(&deck);
	puts("Mazzo mischiato:");
	print_cards(deck, 13);
	puts("\n");
	
	//TEST SUM
	printf("\nTEST SUM\n");
	struct cards hand;
	struct single_card h1[10] = { {1, SPADES},{12, HEARTS} };
	struct single_card h2[10] = { {5, DIAMONDS},{13, SPADES}, {1, CLUBS} };

	hand.cards = h1;
	hand.size = 2;
	sum = sum_points(hand);
	printf("carte: ");
	print_cards(hand, -1);
	printf("\t\tsum: %d\n", sum);
	puts("");

	hand.cards = h2;
	hand.size = 3;
	sum = sum_points(hand);
	printf("carte: ");
	print_cards(hand, -1);
	printf("\tsum: %d\n", sum);
	
	//TEST DEAL
	deck.size = 5;
	printf("\nTEST DEAL\n");
	printf("Prima - DECK:  ");
	print_cards(deck, -1);
	puts("");

	printf("Prima - HAND: ");
	print_cards(hand, -1);
	puts("");

	deal_card(&deck, &hand);

	printf("Dopo - DECK: ");
	print_cards(deck, -1);
	puts("");
	deck.size = 5;

	printf("Dopo - HAND: ");
	print_cards(hand, -1);
	puts("");
	return 0;
}



void print_cards(struct cards c, int items_in_line) {
	int i;
	for (i = 0; i < c.size; i++) {
		if (items_in_line!= -1 && i % items_in_line == 0) puts("");
		switch (c.cards[i].ranking)
		{
		case 1: printf(" A%c ", suit_to_char(c.cards[i].suit)); break;
		case 11: printf(" J%c ", suit_to_char(c.cards[i].suit)); break;
		case 12: printf(" Q%c ", suit_to_char(c.cards[i].suit)); break;
		case 13: printf(" K%c ", suit_to_char(c.cards[i].suit)); break;
		default:
			printf("%2d%c ", c.cards[i].ranking, suit_to_char(c.cards[i].suit));
			break;
		}

	}
}


char suit_to_char(enum suit s) {
	return s + 3;
}