#include "Player.h"


Player::Player(std::vector<Card*> tempHand, std::string tempName)
{
	playerName = tempName;
	hand = tempHand;
	handSize = hand.size();
}

Player::~Player()
{

}

void Player::DealCards(int tempCARD, int tempAmount)
{
	for (int i = 0; i < tempAmount; i++)
	{
		for (std::vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
		{
			if ((*it)->GetCardValue() == tempCARD)
			{
				hand.erase(it);
				break;
			}
		}
	}
	handSize = handSize - tempAmount;

	if (handSize == 0)
		std::cout << "Player " << playerName << " wins!" << std::endl;
}