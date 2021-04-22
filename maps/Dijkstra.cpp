#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXVES 9
#define INFINITY 65535

int Patharc[MAXVEX]; //���ڴ������·���±������ 
int ShortPathTable[MAXVEX]; //���ڴ��浽�������·����Ȩֵ��

void ShortestPath_Dijkstra(MGraph G, int V0,Patharc *P,ShortPathTable *D)
{
	int v,w,k,min;
	int final[MAXVEX];//�ж��Ƿ��ҵ����·��
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
				D[v] = G.arc[k][w];//�������� 
				P[w] = k;//���ǰ����� 
			}
		}
		
		
	}
		
} 
