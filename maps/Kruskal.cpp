#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct edge
{
	int begin;
	int end;
	int weight;
}edge;

int find(int *parent int f)
{
	while(parent[f])
	{
		f = parent[f];
	}
	return f;
}

void MiniSpanTree_Kruskal(MGraph G)
{
	int i,n,m;
	Edge edges[MAGEDGE];/*ÉıĞò*/
	int parent[MAXVES];
	
	memset(parent,0,sizeof(parent));
	
	for(i = 0;i<G.numEdges;i++)
	{
		n = Find(parent,edges[i].begin);
		m = Find(parent,edges[i].end);
		
		if(n != m)
		{
			parent[n] = m;
			printf("%d %d %d",edges[i].begin,edges[i].end,edges[i].weight);
			
		}
		
		
	}
}



int main()
{
	
}
