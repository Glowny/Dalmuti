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

void Player::RemoveCards(int tempCARD, int tempAmount)
{
	int requestedJokerAmount = tempAmount;

	for (std::vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
	{
		if ((*it)->GetCardValue() == tempCARD)
		{
			requestedJokerAmount  = tempAmount - (*it)->GetCardAmount();
			hand.erase(it);
			break;
		}
	}
	
	if (requestedJokerAmount > 0)
	{
		for (std::vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
		{
			if ((*it)->GetCardValue() == JOKER)
			{
				if ((*it)->GetCardAmount() > requestedJokerAmount)
					hand.erase(it);
				else
					(*it)->SetCardAmount((*it)->GetCardAmount() - requestedJokerAmount);
				break;
			}
		}
	}

	if (hand.size() == 0)
		std::cout << "Player " << playerName << " wins!" << std::endl;
}

std::vector<Card*> Player::GetHand()
{
	return hand;
}