#include "GameGenerator.h"

void addToCards(std::vector<Card*> &cards, Card* card)
{
	bool found = false;
	for (int i = 0; i < cards.size(); i++)
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

Table* GameGenerator::GenerateGameTable(int players)
{
	Table* tempTable = new  Table();
	

	Deck* tempDeck = Deck::MakeADeck();
	std::vector<std::vector<Card*>> playerHands;
	for (int i = 0; i < players; i++)
	{
		std::vector<Card*> cards;
		for (int j = 0; j < 80 / players; j++)
		{
			Card* card = tempDeck->DealCard();
			if (card != nullptr)
				addToCards(cards, card);
		}
		playerHands.push_back(cards);
	}

	for (int i = 0; i < players; i++)
	{
		Player* newPlayer = new AlluAI(playerHands[i], "Kokeilu");
		tempTable->AddPlayer(newPlayer);
	}
	return tempTable;
}