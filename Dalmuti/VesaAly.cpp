#include "VesaAly.h"


VesaAly::VesaAly(std::vector<Card*> hand, std::string playerName) : Player(hand, playerName)
{
	
}


VesaAly::~VesaAly()
{
}

Card* VesaAly::AI(std::vector<Card*>* poytakortit, int ylinkortti, int ylimmankortinmaara)
{
	std::vector<Card> playableCards = FindPlayableCards(ylinkortti, ylimmankortinmaara);
	Card cardToPlay = ChooseCardToPlay(playableCards);
	return &cardToPlay;
}

Card VesaAly::ChooseCardToPlay(std::vector<Card> PlayableCards)
{
	Card card = FindBiggestValue(PlayableCards);
	if (card.GetCardValue() == -1)
	{
		std::cout <<"VesaAly: En kehtaa pelata tuohon nyt mittaa. PASS || (cardValue -1)" << std::endl;
	}
	else
	{
		std::cout << "Koska tykkään puhella, niin pelaanpa tästä tälläisen" << card.GetCardValue() << " ja niitä on tässä juuurikin nyt" << card.GetCardAmount() << ". :)" << std::endl;
	}
	return card;
		
}

Card VesaAly::FindBiggestValue(std::vector<Card> possibleCards)
{
	int cardAmount = 0;
	int biggestValue = -1;
	for (int i = 0; i < possibleCards.size(); i++)
	{
		if (biggestValue < possibleCards[i].GetCardValue())
		{
			biggestValue = possibleCards[i].GetCardValue();
			cardAmount = possibleCards[i].GetCardAmount();
		}
	}
	Card card(biggestValue);
	card.SetCardAmount(cardAmount);
	return card;
}
Card VesaAly::FindLargestAmountOfCards(std::vector<Card> possibleCards)
{
	int largestAmount = 0;
	int cardValue = -1;

	for (int i = 0; i < possibleCards.size(); i++)
	{
		if (largestAmount < possibleCards[i].GetCardAmount())
		{
			cardValue = possibleCards[i].GetCardValue();
			largestAmount = possibleCards[i].GetCardAmount();
		}
	}
	Card card(cardValue);
	card.SetCardAmount(largestAmount);
	return card;
}


std::vector<Card> VesaAly::FindPlayableCards(int cardValue, int cardAmount)
{
	std::vector<Card> playableCards;
	for (int i = cardValue; i > 0; i--);
	{
		Card card = FindCard(cardValue);
		if (card.GetCardValue() != -1 && card.GetCardAmount() > cardAmount)
		{
			playableCards.push_back(card);
		}
	}
	return playableCards;
}

Card VesaAly::FindCard(int cardValue)
{
	for (std::vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
	{
		if ((*it)->GetCardValue() == cardValue)
		{
			int amount = (*it)->GetCardAmount();	
			Card card(cardValue);	// Kortin voi kopioida jotenkin suoraan it:ltä
			card.SetCardAmount(amount);
			return card;
		}
	}
	return Card(-1);
}
