#pragma once
#include <iostream>
#include <string>
enum CARD
	{
		JOKER,
		DALMUTI,
		BISHOP,
		EARL,
		DUCHESS,
		ABEDISSA,
		KNIGHT,
		SEAMSTRESS,
		MASON,
		COOK,
		SHEPHERDESS,
		STONECUTTER,
		PEASANT,
		NOCARD
	};

class Card
{
public:

	Card(int cardValue);
	~Card();

	int GetCardValue();

	int GetCardAmount();
	int SetCardAmount();

private:

	int cardValue;
	int cardAmount;
	int passes;
};

