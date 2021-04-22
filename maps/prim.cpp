#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxVertexse 10
typedef struct MGraph
{
	Elemtype vex[numVertexes];
	int arc[numVertexes][numVertexes]; 
	int numVertexse;
}MGraph;

void MiniSpanTree_Prim(MGraph G)
{
	int min , i , j ,k;
	int adjvex[MaxVertexse]; //保存相关顶点下标 
	int lowcost[MaxVertexse]; //保存相关顶点间边的权值
	
	lowcost[0] = 0;
	adjvex[0] = 0;  
	
	for(i = 1;i<G.numVertexse;i++)
	{
		lowcost[i] = G.arc[0][i];
	}
}
