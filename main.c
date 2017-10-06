#include "TopologicalSort.h"

main(void)
{
	GraphAdjList G;
	CreateGraphAdjList(&G);
	TopologicalSort(&G);
	system("pause");
	return 0;
}