#pragma once
#include "Table.h"
#include "Deck.h"
#include "AlluAI.h"
#include "VesaAly.h"
class GameGenerator
{
public:

	static Table* GenerateGameTable(int playerAmount);

private:
	static std::vector<Card*> SortCards(std::vector<Card*> cardsToBeSorted);
};

