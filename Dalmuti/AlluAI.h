#pragma once
#include "Player.h"
class AlluAI :
	public Player
{
public:
	AlluAI(std::vector<Card*> hand, std::string playerName);
	~AlluAI();

	Card* AI(std::vector<Card*>* poytakortit, int ylinkortti, int ylimmankortinmaara);
};