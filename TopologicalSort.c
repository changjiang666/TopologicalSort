#include "TopologicalSort.h"
#include <stdlib.h>
#include <stdio.h>

Status TopologicalSort(GraphAdjList *G)
{
	//定义变量
	int i, gettop;
	int count = 0;
	EageNode *e;

	int top = 0;
	int *stack;
	stack = (int *)malloc(MAXVEXS * sizeof(int));
	
	for (i = 0; i < G->vexNum; ++i)
	{
		if (0 == G->adjList[i].in)
			stack[++top] = i;
	}

	while (top != 0)
	{
		gettop = stack[top--];
		printf("%c", G->adjList[gettop].data);
		++count;
		for (e = G->adjList[gettop].firsteage; e; e = e->next)
		{
			if (!(--G->adjList[e->adjvex].in))
				stack[++top] = e->adjvex;
		}
	}

	if (G->vexNum == count)
		return OK;
	else
		return ERROR;

}