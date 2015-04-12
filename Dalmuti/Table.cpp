#include "Table.h"


Table::Table()
{
	lastCardValue = NOCARD;
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
	CheckIfAllPassed();

	PrintCurrentTable();

	Card* playedCards = CallCurrentPlayerAI();
	bool legitPlay = CheckPlay(playedCards);
	if (legitPlay == false)
		std::cout << "Player made illegal play, PASS" << std::endl;
	if (playedCards->GetCardValue() != NOCARD && legitPlay)
	{
		DiscardCards(playedCards);
		passes = 0;
	}
	else
		passes++;
	SetNextPlayer();
}
// Tarkastetaan saako seuraava pelaaja pelata mitä vain
void Table::CheckIfAllPassed()
{
	if (passes == players.size() - 1)
	{
		lastCardValue = NOCARD;
		lastCardAmount = 1;
		std::cout << "All other players passed!" << std::endl;
		passes = 0;
	}
}

// Ai palauttaa pelatut koritt
Card* Table::CallCurrentPlayerAI()
{
	return (*playerIterator)->AI(&discard, lastCardValue, lastCardAmount);
}

// Tarkastetaan voiko kortteja pelata
bool Table::CheckPlay(Card* playedCards)
{
	// pelaajan PASS hyväksytään aina.
	if (playedCards->GetCardValue() == NOCARD)
		return true;

	if (CheckTable(playedCards))
	{
		if (CheckHand(playedCards))
			return true;
		return false;
	}
	return false;
}

// Tarkastetaan, onko pelaajan pelaamia kortteja tarpeeksi, ja ovatko ne tarpeeksi pieniä.
bool Table::CheckTable(Card* playedCards)
{
	// Mitä tahansa joka laitetaan PASS:n päälle hyväksytään
	if (lastCardValue == NOCARD)
		return true; 

	if (lastCardValue > playedCards->GetCardValue())
	{
		if (lastCardAmount <= playedCards->GetCardAmount())
			return true;
		return false;
	}
	return false;
}

// Tarkastetaan, onko pelaajalla näitä kortteja.
bool Table::CheckHand(Card* playedCards)
{
	std::vector<Card*> playerHand = (*playerIterator)->GetHand();

	int cardAmount = 0;

	// Tarkastetaan onko pelaajalla yhtään näitä kortteja.
	for (unsigned i = 0; i < playerHand.size(); i++)
	{
		if (playerHand[i]->GetCardValue() == playedCards->GetCardValue())
		{
			cardAmount = playerHand[i]->GetCardAmount();
			break;
		}
	}
	if (cardAmount == 0)
		return false;
	// Etsitään, onko pelaajalla jokereitaa korvaamaan pelattuja kortteja.

	else if (cardAmount < playedCards->GetCardAmount())
	{
    	int jokerAmount = 0;
		for (unsigned i = 0; i < playerHand.size(); i++)
		{
			if (playerHand[i]->GetCardValue() == JOKER)
			{
				jokerAmount = playerHand[i]->GetCardAmount();
				break;
			}
		}
		if (cardAmount + jokerAmount < playedCards->GetCardAmount())
		{
			std::cout << (*playerIterator)->GetName() << " tried to play " << playedCards->GetCardAmount() << "x" << playedCards->GetCardValue()
				<< ", but has not enought jokers. Jokeramount: " << jokerAmount << std::endl;
			return false;
		}
	}

	return true;
}

void Table::SetNextPlayer()
{
	playerIterator++;
	if (playerIterator == players.end())
		playerIterator = players.begin();
}

// Asetetaan pelattujen korttien arvot discardipinon arvoihin, ja poistetaan kortit pelaajan kädestä.
void Table::DiscardCards(Card* playedCards)
{
	discard.push_back(playedCards);

	lastCardValue = playedCards->GetCardValue();
	lastCardAmount = playedCards->GetCardAmount();

	(*playerIterator)->RemoveCards(playedCards->GetCardValue(), playedCards->GetCardAmount());
	//delete playedCards;
}

// Tulostaa tietoja näytölle, ei muuta toiminnallisuutta.
void Table::PrintCurrentTable()
{
	PrintPlayerHands();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << (*playerIterator)->GetName() << "'s turn" << std::endl;
 	discardIterator = discard.end();
	if (discardIterator == discard.begin())
	{
		std::cout << "Table holds nothing" << std::endl;
		std::cout << "What do you play?" << std::endl;
	}
	else if (lastCardValue == NOCARD)
	{
		std::cout << "Table holds nothing" << std::endl;
		std::cout << "What do you play?" << std::endl;
	}
	else
	{
		std::cout << "Table holds " << lastCardAmount << "x(" << lastCardValue << ") ";
		switch (lastCardValue)
		{
			default:
				std::cout << "nothing";
				break;
			case 0:
				std::cout << "JOKER";
				break;
			case 1:
				std::cout << "DALMUTI";
				break;
			case 2:
				std::cout << "BISHOP";
				break;
			case 3:
				std::cout << "EARL";
				break;
			case 4:
				std::cout << "DUCHESS";
				break;
			case 5:
				std::cout << "ABEDISSA";
				break;
			case 6:
				std::cout << "KNIGHT";
				break;
			case 7:
				std::cout << "SEAMSTRESS";
				break;
			case 8:
				std::cout << "MASON";
				break;
			case 9:
				std::cout << "COOK";
				break;
			case 10:
				std::cout << "SHEPHERDESS";
				break;
			case 11:
				std::cout << "STONECUTTER";
				break;
			case 12:
				std::cout << "PEASANT";
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

void Table::PrintPlayerHands()
{
	std::vector<std::string> playerNames;
	std::vector <std::vector<Card*>> playerHands;
	for (unsigned i = 0; i < players.size(); i++)
	{
		playerNames.push_back(players[i]->GetName());
		playerHands.push_back(players[i]->GetHand());
	}

	for (int i = 0; i < 15; i++)
	std::cout << std::endl;


	for (unsigned i = 0; i < playerHands.size(); i++)
	{		
		std::cout << playerNames[i] << "Hand:  ";
	}
	std::cout << std::endl;
	unsigned largestHand = 0;
	for (unsigned i = 0; i < playerHands.size(); i++)
	{
		if (largestHand < playerHands[i].size())
			largestHand = playerHands[i].size();
	}

	for (unsigned j = 0; j < largestHand; j++)
	{
		for (unsigned i = 0; i < playerHands.size(); i++)
		{
			if (playerHands[i].size() > j)
			{
				std::cout << playerHands[i].at(j)->GetCardAmount() << "x" << playerHands[i].at(j)->GetCardValue();
				if (playerHands[i].at(j)->GetCardAmount() < 10)
					std::cout << " ";
				if (playerHands[i].at(j)->GetCardValue() < 10)
					std::cout << " ";
				std::cout << "        ";
			}
			else
			{
				std::cout << "             ";
			}
		}
		std::cout << std::endl;
	}

}

