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

	if (playedCards->GetCardValue() != NOCARD && CheckPlay(playedCards))
	{
		DiscardCards(playedCards);
		passes = 0;
	}
	else
		passes++;
	SetNextPlayer();
}
// Tarkastetaan saako seuraava pelaaja pelata mit� vain
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
bool Table::CheckPlay(Card* cards)
{
	// pelaajan PASS hyv�ksyt��n aina.
	if (cards->GetCardValue() == NOCARD);
		return true;

	if (CheckTable(cards))
	{
		if (CheckHand(cards))
			return true;
		return false;
	}
	return false;
}

// Tarkastetaan, onko pelaajan pelaamia kortteja tarpeeksi, ja ovatko ne tarpeeksi pieni�.
bool Table::CheckTable(Card* cards)
{
	// Mit� tahansa joka laitetaan PASS:n p��lle hyv�ksyt��n
	if (lastCardValue == NOCARD)
		return true; 

	if (lastCardValue > cards->GetCardValue())
	{
		if (lastCardAmount < cards->GetCardAmount())
			return true;
		return false;
	}
	return false;
}

// Tarkastetaan, onko pelaajalla n�it� kortteja.
bool Table::CheckHand(Card* cards)
{
	std::vector<Card*> playerHand = (*playerIterator)->GetHand();

	int cardAmount = 0;

	// Tarkastetaan onko pelaajalla yht��n n�it� kortteja.
	for (int i = 0; i < playerHand.size(); i++)
	{
		if (playerHand[i]->GetCardValue() == cards->GetCardValue())
		{
			cardAmount++;
		}
	}
	if (cardAmount == 0)
		return false;
	// Etsit��n, onko pelaajalla jokereitaa korvaamaan pelattuja kortteja.

	else if (cardAmount < cards->GetCardAmount())
	{
		int jokerAmount = 0;
		for (int i = 0; i < playerHand.size(); i++)
		{
			if (playerHand[i]->GetCardValue() == JOKER)
			{
				jokerAmount++;
			}
		}
		if (cardAmount + jokerAmount < cards->GetCardAmount())
			return false;
	}
	else
	return true;
}

void Table::SetNextPlayer()
{
	playerIterator++;
	if (playerIterator == players.end())
		playerIterator = players.begin();
}

// Asetetaan pelattujen korttien arvot discardipinon arvoihin, ja poistetaan kortit pelaajan k�dest�.
void Table::DiscardCards(Card* playedCards)
{
	discard.push_back(playedCards);

	lastCardValue = playedCards->GetCardValue();
	lastCardAmount = playedCards->GetCardAmount();

	(*playerIterator)->RemoveCards(playedCards->GetCardValue(), playedCards->GetCardAmount());
	//delete playedCards;
}

// Tulostaa tietoja n�yt�lle, ei muuta toiminnallisuutta.
void Table::PrintCurrentTable()
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


