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
	Card card = ChooseCardToPlay(playableCards);
	// voi miksi
	Card* returnCard = new Card(card.GetCardValue(), card.GetCardAmount());
	
	return returnCard;
}

std::vector<Card> VesaAly::FindPlayableCards(int cardValue, int cardAmount)
{
	int jokerAmount = FindCard(JOKER).GetCardAmount();
	std::vector<Card> playableCards;
	// Ei etsit� jokereita, aloitetaan 1.
 	for (int i = 1; i < cardValue; i++)
	{
 		Card card = FindCard(i);
		// Tarkastetaan, ettei palautett kortti ole tyhj� 
		// ja ett� kortteja on tarpeeksi jokerit mukaan lukien,
		// sek� ett� kortteja on edes yksi.
		if (card.GetCardValue() != NOCARD && card.GetCardAmount() + jokerAmount >= cardAmount
			&& card.GetCardAmount() > 0)
		{
			// Lasketaan montako jokeria tarvitaan, vain jos jokereita tarvitaan.
			if (card.GetCardAmount() < cardAmount)
			{
				int neededJokerAmount = cardAmount - card.GetCardAmount();
				card.SetCardAmount(card.GetCardAmount() + neededJokerAmount);
			}
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
			Card card(cardValue, amount);	// Kortin voi kopioida jotenkin suoraan it:lt�
			return card;
		}
	}
	return Card(NOCARD);
}


Card VesaAly::ChooseCardToPlay(std::vector<Card> PlayableCards)
{
	Card card = FindBiggestValue(PlayableCards);
	if (card.GetCardValue() == NOCARD)
	{
		std::cout <<"PASS || NOCARD" << std::endl;
	}
	else
	{
		std::cout << playerName << " plays card " << card.GetCardAmount() << "x" << card.GetCardValue() << std::endl;
	}
	return card;
		
}

Card VesaAly::FindBiggestValue(std::vector<Card> possibleCards)
{
	if (possibleCards.size() == 0)
		return Card(NOCARD);
	int cardAmount = 0;
	int biggestValue = 0;
	for (unsigned i = 0; i < possibleCards.size(); i++)
	{
		if (biggestValue < possibleCards[i].GetCardValue())
		{
			biggestValue = possibleCards[i].GetCardValue();
			cardAmount = possibleCards[i].GetCardAmount();
		}
	}

	Card card(biggestValue, cardAmount);
	return card;
}
Card VesaAly::FindMostCards(std::vector<Card> possibleCards)
{
	int largestAmount = 0;
	int cardValue = -1;

	for (unsigned i = 0; i < possibleCards.size(); i++)
	{
		if (largestAmount < possibleCards[i].GetCardAmount())
		{
			cardValue = possibleCards[i].GetCardValue();
			largestAmount = possibleCards[i].GetCardAmount();
		}
	}
	if (cardValue == -1)
		cardValue = NOCARD;

	Card card(cardValue);
	card.SetCardAmount(largestAmount);
	return card;
}



