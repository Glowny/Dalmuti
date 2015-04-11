#include "Table.h"


Table::Table()
{
	lastCardValue = 13;
	lastCardAmount = 1;
	passes = 0;
	playerIterator = players.begin();
}
void Table::AddPlayer(Player* newPlayer)
{
	players.push_back(newPlayer);
}

void Table::Update()
{
	if (passes == players.size() - 1)
	{
		lastCardValue = 13;
		lastCardAmount = 1;
		std::cout << "pass succesfull!" << std::endl;
		passes = 0;
	}

	AskPlayerToPlay();

	Card* cardsToPlay = (*playerIterator)->AI(&discard, lastCardValue, lastCardAmount);
	if (cardsToPlay->GetCardValue() != 13)
	{
		discard.push_back(cardsToPlay);

		lastCardValue = cardsToPlay->GetCardValue();
		lastCardAmount = cardsToPlay->GetCardAmount();

		(*playerIterator)->DeleteCards(cardsToPlay->GetCardValue(), cardsToPlay->GetCardAmount());
		delete cardsToPlay;
		passes = 0;
	}
	else
		passes++;

	playerIterator++;
	if (playerIterator == players.end())
		playerIterator = players.begin();
}

// Tässä tietojen tulostus näytölle, ei muuta toiminnallisuutta.
void Table::AskPlayerToPlay()
{
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << (*playerIterator)->GetName() << "'s turn" << std::endl;
	discardIterator = discard.end();
	if (discardIterator == discard.begin())
	{
		std::cout << "Table holds nothing" << std::endl;
		std::cout << "What do you play?" << std::endl;
	}
	else if (lastCardValue == 13)
	{
		std::cout << "Table holds nothing" << std::endl;
		std::cout << "What do you play?" << std::endl;
	}
	else
	{
		std::cout << "Table holds " << lastCardAmount;
		switch (lastCardValue)
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
			if (lastCardValue == SEAMSTRESS || lastCardValue == DUCHESS || lastCardValue == SHEPHERDESS)
				std::cout << "ES";
			else
				std::cout << "S";
		}
		std::cout << std::endl;
		std::cout << "What do you play?" << std::endl;
	}
}


