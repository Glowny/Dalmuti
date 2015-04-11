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
		std::cout << playerName << " has no AI function"  <<std::endl;
		std::cout << playerName << " returning pass (NOCARD)" << std::endl;
		return new Card(NOCARD);
	};
	void RemoveCards(int card, int amount);
	
	std::string GetName(){ return playerName; };
	
	std::vector<Card*> GetHand();
protected:

	std::vector<Card*> hand;

	int handSize;
	std::string playerName;
};

