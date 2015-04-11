#pragma once
#include "Player.h"
class Table
{
public:

	Table();
	~Table();

	void InitTable(){ playerIterator = players.begin(); };

	void AddPlayer(Player*);

	void Update();

private:

	std::vector<Player*> players;
	std::vector<Player*>::iterator playerIterator;

	std::vector<Card*> discard;
	std::vector<Card*>::iterator discardIterator;

	int lastCardValue;
	int lastCardAmount;

	void AskPlayerToPlay();
	void CheckWinner();

	int passes;

};

