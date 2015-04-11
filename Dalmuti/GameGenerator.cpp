#include "GameGenerator.h"

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

	for (int i = 0; i < playerAmount; i++)
	{
		Player* newPlayer2 = new VesaAly(playerHands[i], nameList[i * 2 + 1]);
		tempTable->AddPlayer(newPlayer2);
		Player* newPlayer = new AlluAI(playerHands[i], nameList[i*2]);
		tempTable->AddPlayer(newPlayer);

	}
	return tempTable;
}

