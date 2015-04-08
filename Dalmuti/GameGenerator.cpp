#include "GameGenerator.h"

Table* GameGenerator::GenerateGameTable(int players)
{
	Table* tempTable = new  Table();
	

	Deck* tempDeck = Deck::MakeADeck();
	for (int i = 0; i < players; i++)
	{
		std::vector<Card*> cards;
		for (int j = 0; j < 93/players; j++)
			cards.push_back(tempDeck->DealCard());
		Player* newPlayer = new Player(cards, "Kokeilu");
		tempTable->AddPlayer(newPlayer);
	}
	return tempTable;
}