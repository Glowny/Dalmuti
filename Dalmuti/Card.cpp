#include "Card.h"


Card::Card(int tempCardValue)
{
	cardValue = tempCardValue;
	cardAmount = 1;
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

int Card::SetCardAmount()
{
	return cardAmount;
}