#include "Player.h"


Player::Player(std::vector<Card*> tempHand, std::string tempName)
{
	playerName = tempName;
	hand = tempHand;
	handSize = 0;
	for (unsigned i = 0; i < hand.size(); i++)
	{
		handSize += hand.at(i)->GetCardAmount();
	}
}

Player::~Player()
{

}

void Player::RemoveCards(int cardValue, int cardAmount)
{
	int extraCardAmount = 0;

	for (std::vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
	{
		if ((*it)->GetCardValue() == cardValue)
		{
			extraCardAmount = cardAmount - ((*it)->GetCardAmount() );
			if (extraCardAmount < 0)
				(*it)->SetCardAmount((*it)->GetCardAmount() - cardAmount);
			else
				hand.erase(it);
			break;
		}
	}
	
	if (extraCardAmount > 0)
	{
 		for (std::vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
		{
			if ((*it)->GetCardValue() == JOKER)
			{
				if ((*it)->GetCardAmount() > extraCardAmount)
					(*it)->SetCardAmount((*it)->GetCardAmount() - extraCardAmount);
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