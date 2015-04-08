#include "GameGenerator.h"


int main()
{
	Table* asd = GameGenerator::GenerateGameTable(4);

	for (int i = 0; i < 3; i++)
	{
		asd->Update();
	}
	return 0;
}