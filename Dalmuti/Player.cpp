#include "Player.h"


Player::Player(std::vector<Card*> tempHand, std::string tempName)
{
	playerName = tempName;
	hand = tempHand;
	handSize = 0;
	for (int i = 0; i < hand.size(); i++)
	{
		handSize += hand.at(i)->GetCardAmount();
	}
}

Player::~Player()
{

}

void Player::DeleteCards(int tempCARD, int tempAmount)
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
	if (hand.size() == 0)
		std::cout << "Player " << playerName << " wins!" << std::endl;
}