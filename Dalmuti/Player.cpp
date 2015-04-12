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

void Player::RemoveCards(int cardValue, int cardAmount)
{
	int requestedJokerAmount = 0;

	for (std::vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
	{
		if ((*it)->GetCardValue() == cardValue)
		{
			requestedJokerAmount = cardAmount - (*it)->GetCardAmount();
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
					(*it)->SetCardAmount((*it)->GetCardAmount() - requestedJokerAmount);
				else
					hand.erase(it);
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