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

	Card(){};
	Card(int cardValue);
	Card(int cardValue, int amount);
	~Card();

	int GetCardValue();
	void SetCardValue(int value);

	int GetCardAmount();
	void SetCardAmount(int amount);

private:

	int cardValue;
	int cardAmount;
};

