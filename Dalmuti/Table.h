#pragma once
#include "Player.h"
class Table
{
public:

	Table();
	~Table();

	void AddPlayer(Player*);

	void Update();

private:

	std::vector<Player*> players;
	std::vector<Player*>::iterator plit;

	std::vector<Card*> discard;
	std::vector<Card*>::iterator diit;

	int lastCard;
	int lastCardAmount;

	void AskPlayerToPlay();
	void checkWinner();

	int passes;

};

