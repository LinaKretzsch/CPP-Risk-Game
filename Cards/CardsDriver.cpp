#include "Cards.h"
#include <time.h>



int main1() {

	srand(time(0));
	//Fill deck with cards example
	Deck Deck1;
	Deck1.initializeDeck(4);
	cout << Deck1;

	//draw() method example
	Hand aHandCard;
	Hand bHandCard;
	Hand cHandCard;
	Hand dHandCard;
	Deck1.printDeckSize();
	cout << " test to assign 5 random cards into hand \n" << endl;
	for (int i = 0; i < 5; i++) {
		aHandCard.addCard(Deck1.draw());
		bHandCard.addCard(Deck1.draw());
		cHandCard.addCard(Deck1.draw());
		dHandCard.addCard(Deck1.draw());
	}
	
	cout << aHandCard;
	cout << bHandCard;
	cout << cHandCard;
	cout << dHandCard;
	Deck1.printDeckSize();


	//test the play cards order of HandCard
	//traverse to set all HandCards will play
	cout << " test to play all Cards of this hand..put the cards into playCards vector \n" << endl;
	
	int handSize = aHandCard.getHand()->size();
	for (int k = 0; k < handSize ; k++) {
		aHandCard.play(aHandCard.getHand()->front(), &Deck1);
	}

	//print the vec_play_cards
	//aHandCard.printVecPlayCards();

	cout << aHandCard;
	//test return played cards to deck
	//aHandCard.returnPlayedCardToDeck(&Deck1);

	//test remove all played cards of hand cards
	//aHandCard.removeAllPlayedCardsOfHand();

	//then clear the play cards of vec_play_cards. Notice: clean play_cards at end.
	//aHandCard.clearPlayCards();

	//print the vec_play_cards
	//aHandCard.printVecPlayCards();

	//print the current hand cards
	//aHandCard.printVecHand();

	//test the size of current deck
	Deck1.printDeckSize();

	return 0;
}