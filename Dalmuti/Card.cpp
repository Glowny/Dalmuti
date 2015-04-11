#include "Card.h"


Card::Card(int tempCardValue)
{
	this->cardValue = tempCardValue;
	this->cardAmount = 1;
}


Card::Card(int cardValue, int amount)
{
	this->cardValue = cardValue;
	this->cardAmount = amount;
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