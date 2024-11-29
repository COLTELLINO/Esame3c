

#include "blackjack.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

static void init_part(struct cards* c, int starting_index, enum suit s) {
	int i;
	int rank;
	for (rank = 1, i = starting_index; i < starting_index + 13; i++, rank++) {
		c->cards[i].ranking = rank;
		c->cards[i].suit = s;
	}
}

static void init_standard_deck(struct cards* deck, int deck_index) {
	int i;
	for (i = 0; i < 4; i++) {
		init_part(deck, (CARDSxDECK * deck_index) + i * 13, HEARTS + i);
	}
}

/*inizializza le strutture dati e crea un mazzo*/


void deal_card_sol(struct cards* deck, struct cards* hand) {
	hand->cards[hand->size].ranking = deck->cards[deck->size - 1].ranking;
	hand->cards[hand->size].suit = deck->cards[deck->size - 1].suit;
	hand->size++;
	deck->size--;
}

/*Prende in input il puntatore a un mazzo e lo mischia*/
void deck_shuffle_sol(struct cards* deck) {
	int idx1, idx2, i, iterations = rand() % 150 + 200;
	struct single_card tmp;
	for (i = 0; i < iterations; i++) {
		idx1 = rand() % deck->size;
		idx2 = rand() % deck->size;
		tmp.ranking = deck->cards[idx1].ranking;
		tmp.suit = deck->cards[idx1].suit;
		deck->cards[idx1].ranking = deck->cards[idx2].ranking;
		deck->cards[idx1].suit = deck->cards[idx2].suit;
		deck->cards[idx2].ranking = tmp.ranking;
		deck->cards[idx2].suit = tmp.suit;
	}
}

struct cards deck_gen_sol(int num_decks) {
	struct cards deck;
	int i, d, s;
	deck.size = num_decks * CARDSxDECK;
	deck.cards = (struct single_card*)calloc(deck.size, sizeof(struct single_card));

	for (d = 0; d < num_decks; d++)
		init_standard_deck(&deck, d);

	return deck;
}


int sum_points_sol(struct cards hand) {
	int i, sum = 0, val = 0, rank;
	for (i = 0; i < hand.size; i++) {
		rank = hand.cards[i].ranking;
		if (rank != 1) sum += rank > 9 ? 10 : rank;
	}

	for (i = 0; i < hand.size; i++) {
		rank = hand.cards[i].ranking;
		if (rank == 1)
			sum += (sum + 11 > 21 ? 1 : 11);
	}

	return sum;
}
