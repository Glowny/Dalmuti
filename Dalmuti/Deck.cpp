#include "Deck.h"
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>

Deck::Deck(std::vector<Card*> tempCards)
{
	cards = tempCards;
	numberOfCards = cards.size();
}


Deck::~Deck()
{
	
}

Deck* Deck::MakeADeck()
{
	std::srand(unsigned(std::time(0)));

	std::vector<Card*> tempCards;
	for (int i = 0; i < 12; i++)
	{
		Card* asd = new Card(12);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 11; i++)
	{
		Card* asd = new Card(11);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 10; i++)
	{
		Card* asd = new Card(10);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 9; i++)
	{
		Card* asd = new Card(9);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 8; i++)
	{
		Card* asd = new Card(8);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 7; i++)
	{
		Card* asd = new Card(7);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 6; i++)
	{
		Card* asd = new Card(6);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 5; i++)
	{
		Card* asd = new Card(5);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 4; i++)
	{
		Card* asd = new Card(4);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 3; i++)
	{
		Card* asd = new Card(3);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 2; i++)
	{
		Card* asd = new Card(2);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 1; i++)
	{
		Card* asd = new Card(1);
		tempCards.push_back(asd);
	}
	for (int i = 0; i < 2; i++)
	{
		Card* asd = new Card(0);
		tempCards.push_back(asd);
	}
	std::random_shuffle(tempCards.begin(), tempCards.end());

	Deck* tempDeck = new Deck(tempCards);
	return tempDeck;
}

Card* Deck::DealCard()
{
	Card* tempCard = cards.at(0);
	cards.erase(cards.begin());
	if (cards.begin() == cards.end())
		return nullptr;
	return tempCard;
}
