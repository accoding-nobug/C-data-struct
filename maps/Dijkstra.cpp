#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXVES 9
#define INFINITY 65535

int Patharc[MAXVEX]; //用于储存最短路径下标的数组 
int ShortPathTable[MAXVEX]; //用于储存到各点最短路径的权值合

void ShortestPath_Dijkstra(MGraph G, int V0,Patharc *P,ShortPathTable *D)
{
	int v,w,k,min;
	int final[MAXVEX];//判断是否找到最短路径
	for(v = 0;v<G.numVextexes;v++)
	{
		final[v] = 0;
		D[v] = G.arc[V0][v];
		P[v] = 0; 
	}
	final[V0] = 1; 
	for(v = 1;v<G.numVextexes;v++)
	{
		min = INFINITY;
		for(w = 0;w<G.numVextexe;w++)
		{
			if(!final[w] && D[w]<min)
			{
				min = D[w];
				k = w;
			}
		}
		final[k] = 1;
		
		for(w = 0;w<numVextexes;w++)
		{
			if(D[v] > G.arc[k][w]+D[k] && !final[w])
			{
				D[v] = G.arc[k][w];//更新数据 
				P[w] = k;//存放前驱结点 
			}
		}
		
		
	}
		
} 
