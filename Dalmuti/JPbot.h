#pragma once
#include "Player.h"
class JPbot : Player
{
public:

	JPbot(std::vector<Card*> hand, std::string playerName);
	~JPbot();
	Card* AI(std::vector<Card*>* poytakortit, int ylinkortti, int ylimmankortinmaara);

};

