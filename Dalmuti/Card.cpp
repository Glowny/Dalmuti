#include "Card.h"


Card::Card(int tempCardValue)
{
	cardValue = tempCardValue;
	cardAmount = 1;
}


Card::Card(int tempCardValue, int amount)
{
	cardValue = tempCardValue;
	cardAmount = amount;
}



Card::~Card()
{
}

int Card::GetCardValue()
{
	return cardValue;
}

int Card::GetCardAmount()
{
	return cardAmount;
}

void Card::SetCardAmount(int amount)
{
	cardAmount = amount;
}