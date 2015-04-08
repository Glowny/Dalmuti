#pragma once
#include "Player.h"
class VesaAly :public Player
{
public:
	VesaAly(std::vector<Card*> hand, std::string playerName);
	Card* AI(std::vector<Card*>* poytakortit, int ylinkortti, int ylimmankortinmaara);
	Card ChooseCardToPlay(std::vector<Card> PlayableCards);
	std::vector<Card> FindPlayableCards(int cardValue, int cardAmount);
	Card FindBiggestValue(std::vector<Card> possibleCards);
	Card FindLargestAmountOfCards(std::vector<Card> possibleCards);
	Card FindCard(int cardValue);
	~VesaAly();
};

