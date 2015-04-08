#pragma once
#include "Card.h"
#include <vector>
class Deck
{
public:

	
	~Deck();

	static Deck* MakeADeck();
	Card* DealCard();

private:

	unsigned int numberOfCards;

	std::vector<Card*> cards;

	Deck(std::vector<Card*> cards);
};

