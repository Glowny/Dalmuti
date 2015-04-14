#include "AlluAI.h"


AlluAI::AlluAI(std::vector<Card*> hand, std::string playerName) : Player(hand, playerName)
{
}


AlluAI::~AlluAI()
{
}


Card* AlluAI::AI(std::vector<Card*>* poytakortit, int ylinkortti, int ylimmankortinmaara)
{
	std::vector<Card*> playbleCards;
	Card toPlay = Card(NOCARD);
	
	if (ylinkortti == NOCARD)
	{
		for (unsigned i = 0; i < hand.size(); i++)
		{
			if (hand.at(i)->GetCardValue() != 0)
				playbleCards.push_back(hand.at(i));
		}
	}
	else
	{
		for (unsigned i = 0; i < hand.size(); i++)
		{
			if (hand.at(i)->GetCardValue() < ylinkortti)
			{
				if (hand.at(i)->GetCardValue() != 0)
				{
					if (hand.at(i)->GetCardAmount() >= ylimmankortinmaara)
					{
						playbleCards.push_back(hand.at(i));
					}
				}
			}
		}
	}

	if (playbleCards.size() > 0)
	{
		toPlay = *playbleCards.at(0);
		for (unsigned i = 1; i < playbleCards.size(); i++)
		{
			if (playbleCards.at(i)->GetCardValue() > toPlay.GetCardValue())
			{
				toPlay = *playbleCards.at(i);
			}
		}
	}

	if (toPlay.GetCardValue() != NOCARD)
	{
		for (unsigned i = 0; i < hand.size(); i++)
		{
			if (hand.at(i)->GetCardValue() == JOKER)
			{
				toPlay.SetCardAmount(toPlay.GetCardAmount() + hand.at(i)->GetCardAmount());
				break;
			}
		}

		//std::cout << playerName << " plays: " << toPlay.GetCardAmount() << "x" << toPlay.GetCardValue() << std::endl;
	}

	return new Card(toPlay.GetCardValue(), toPlay.GetCardAmount());
}