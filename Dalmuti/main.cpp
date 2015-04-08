#include "GameGenerator.h"


int main()
{
	Table* asd = GameGenerator::GenerateGameTable(4);
	asd->initTable();
	while (true)
	{
 	 	asd->Update();
  		system("PAUSE");
  	}
	return 0;
}