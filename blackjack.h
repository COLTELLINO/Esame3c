#define CARDSxDECK 52
enum suits { HEARTS,DIAMONDS, CLUBS, SPADES}; //Nell'ordine: cuori, quadri, fiori, picche

/*Modella una carta*/
struct single_card {
	int ranking; // 1,2,3...10,11,12,13  che corrispondono a: A, 2, 3 ... 10, J, Q, K
	enum suits suit; // seme (cuori, quadri, fiori, picche)
};

/*Modella un insieme di carte*/
struct cards {
	struct single_card* cards; //array di carte
	int size; //numero di carte nell'array
};

struct cards deck_gen(int num_decks);
void deck_shuffle(struct cards* deck);
void deal_card(struct cards* deck, struct cards* hand);
int sum_points(struct cards hand);


