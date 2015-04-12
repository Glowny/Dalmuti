#include "GameGenerator.h"


int main()
{
	Table* table = GameGenerator::GenerateGameTable(5);
	table->InitTable();
	while (true)
	{
 	 	table->Update();
  		system("PAUSE");
  	}
	return 0;
}