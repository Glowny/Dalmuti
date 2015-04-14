#include "GameGenerator.h"
#include <algorithm>



std::string nameList[]
{
		"Pentti",
		"Marko",
		"Juhani",
		"Tapani",
		"Iiro",
		"Simo"
};

void AddToCards(std::vector<Card*> &cards, Card* card)
{
	bool found = false;
	for (unsigned i = 0; i < cards.size(); i++)
	{
		if (card->GetCardValue() == cards.at(i)->GetCardValue())
		{
			cards.at(i)->SetCardAmount(cards.at(i)->GetCardAmount() + 1);
			found = true;
			break;
		}
	}

	if (!found)
	{
		cards.push_back(card);
	}

}

Table* GameGenerator::GenerateGameTable(int playerAmount)
{
	Table* tempTable = new Table();
	
	Deck* tempDeck = Deck::MakeADeck();
	std::vector<std::vector<Card*>> playerHands;


	for (int i = 0; i < playerAmount; i++)
	{
		std::vector<Card*> cards;
		for (int j = 0; j < 80 / playerAmount; j++)
		{
			Card* card = tempDeck->DealCard();
			if (card != nullptr)
				AddToCards(cards, card);
		}
		playerHands.push_back(cards);
	}


	for (int i = 0; i < playerAmount/2; i++)
	{
		Player* newPlayer2 = new VesaAly(SortCards(playerHands[i]), nameList[i]);
		tempTable->AddPlayer(newPlayer2);
		Player* newPlayer = new AlluAI(SortCards(playerHands[i+2]), nameList[i+2]);
		tempTable->AddPlayer(newPlayer);

	}


	return tempTable;
}
bool sortFunction(Card* a, Card* b)
{
	return (a->GetCardValue() < b->GetCardValue());
}

std::vector<Card*> GameGenerator::SortCards(std::vector<Card*> cardsToBeSorted)
{
	std::sort(cardsToBeSorted.begin(), cardsToBeSorted.end(), sortFunction);
	return cardsToBeSorted;
}