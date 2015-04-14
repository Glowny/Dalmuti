#pragma once
#include "Player.h"
class VesaAly :public Player
{
public:
	VesaAly(std::vector<Card*> hand, std::string playerName);
	~VesaAly();
	Card* AI(std::vector<Card*>* poytakortit, int ylinkortti, int ylimmankortinmaara);

private:

	std::vector<Card> FindPlayableCards(int cardValue, int cardAmount);
	Card FindCard(int cardValue);

	Card ChooseCardToPlay(std::vector<Card> PlayableCards);
	Card FindBiggestValue(std::vector<Card> possibleCards);
	Card FindMostCards(std::vector<Card> possibleCards);




};

