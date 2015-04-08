#include "Table.h"


Table::Table()
{
	lastCard = 13;
	lastCardAmount = 1;
	passes = 0;
	plit = players.begin();
}
void Table::AddPlayer(Player* newPlayer)
{
	players.push_back(newPlayer);
}

void Table::Update()
{
	AskPlayerToPlay();
	Card* cardsToPlay = (*plit)->AI(&discard, lastCard, lastCardAmount);
	if (cardsToPlay->GetCardValue() != 13)
	{
		discard.push_back(cardsToPlay);

		lastCard = cardsToPlay->GetCardValue();
		lastCardAmount = cardsToPlay->GetCardAmount();

		players.at(0)->DealCards(cardsToPlay->GetCardValue(), cardsToPlay->GetCardAmount());
		delete cardsToPlay;
		passes = 0;
		plit++;
		if (plit == players.end())
			plit = players.begin();
	}
	else
		passes++;
}

void Table::AskPlayerToPlay()
{
	std::cout << (*plit)->GetName() << "'s turn" << std::endl;
	diit = discard.end();
	if (diit == discard.begin())
	{
		std::cout << "Table holds nothing" << std::endl;
		std::cout << "What do you play?" << std::endl;
	}
	else
	{
		std::cout << "Table holds " << lastCardAmount;
		switch (lastCard)
		{
			default:
				std::cout << " nothing";
				break;
			case 0:
				std::cout << " JOKER";
				break;
			case 1:
				std::cout << " DALMUTI";
				break;
			case 2:
				std::cout << " BISHOP";
				break;
			case 3:
				std::cout << " EARL";
				break;
			case 4:
				std::cout << " DUCHESS";
				break;
			case 5:
				std::cout << " ABEDISSA";
				break;
			case 6:
				std::cout << " KNIGHT";
				break;
			case 7:
				std::cout << " SEAMSTRESS";
				break;
			case 8:
				std::cout << " MASON";
				break;
			case 9:
				std::cout << " COOK";
				break;
			case 10:
				std::cout << " SHEPHERDESS";
				break;
			case 11:
				std::cout << " STONECUTTER";
				break;
			case 12:
				std::cout << " PEASANT";
				break;
		}
		if (lastCardAmount >= 2)
		{
			if (lastCard == SEAMSTRESS || lastCard == DUCHESS)
				std::cout << "ES";
			else
				std::cout << "S";
		}
		std::cout << std::endl;
		std::cout << "What do you play?" << std::endl;
	}
}



