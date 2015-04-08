#pragma once
#include "Deck.h"

enum PLAYERS
{
	VESA,
	ALEKSI,
	JP,
	RANDOM
};

class Player
{
public:

	Player(std::vector<Card*> hand, std::string playerName);
	~Player();
	Card* AI(std::vector<Card*>* poytakortit, int ylinkortti, int ylimmankortinmaara)
	{
		return new Card(3);
	};
	void DealCards(int card, int amount);

private:

	std::vector<Card*> hand;

	int handSize;
	std::string playerName;
};

