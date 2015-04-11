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

	bool CheckPlay(Card* playedCards);
		// alifunktioita CheckPlay():lle
	bool CheckTable(Card* playedCards);
	bool CheckHand(Card* playedCards);
	

	void DiscardCards(Card* playedCards);
	int passes;

};

