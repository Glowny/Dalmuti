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

	void PrintPlayerHands();
	void PrintCurrentTable();
	void CheckWinner();

	void CheckIfAllPassed();
	void SetNextPlayer();
	Card* CallCurrentPlayerAI();

	bool CheckPlay(Card* cards);
		// alifunktioita CheckPlay():lle
	bool CheckTable(Card* cards);
	bool CheckHand(Card* cards);
	

	void DiscardCards(Card* playedCards);
	int passes;

};

