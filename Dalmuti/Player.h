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
	virtual Card* AI(std::vector<Card*>* poytakortit, int ylinkortti, int ylimmankortinmaara)
	{
		std::cout << playerName << " plays " << "1 Earl!" <<std::endl;
		return new Card(3);
	};
	void DeleteCards(int card, int amount);
	
	std::string GetName(){ return playerName; };
	
protected:

	std::vector<Card*> hand;

	int handSize;
	std::string playerName;
};

