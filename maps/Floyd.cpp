#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXVEX 5
typedef int Elemtype;
typedef int Pathmatrix[MAXVEX][MAXVEX];//记录中间节点 

typedef struct sqStack
{
	Elemtype* top;
	int container;
	Elemtype* base;
}sqStack;
typedef struct MGraph
{
	int numVextexes;
	int matrix[MAXVEX][MAXVEX];
}MGraph;

void Path_Traverse(sqStack* s,int begin,int end,Pathmatrix *P);
void initStack(sqStack* s);
void Push(sqStack* s , Elemtype e);
Elemtype Pop(sqStack*s);
void ShortextPath_Floyd(MGraph *G, Pathmatrix *P);

int main(void)
{
	int n = 0;
	scanf("%d",&n);
	MGraph G;
	G.numVextexes = n;
	sqStack s;
	initStack(&s);
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			scanf("%d",&G.matrix[i][j]);
		}
	}
	int P[MAXVEX][MAXVEX];
	ShortextPath_Floyd(&G,&P);
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			printf("%d -> %d: weight:%d ",i+1,j+1,G.matrix[i][j]);
			Path_Traverse(&s,i,j,&P);
			printf("%d",i+1);
			while(s.top != s.base)
			{
				printf("->%d",Pop(&s)+1);
			}
			if(i != j)
			{
				printf("->%d",j+1);
			}
			printf("\n");
		}
	}
	return 0;
}
/*
	4
	0   1   3   100
	1   0   1   100 
	3   1   0   1 
	100 100 1   0    


*/
void Path_Traverse(sqStack* s,int begin,int end,Pathmatrix *P)
{
	if((*P)[begin][end] != end)
	{
		Push(s,(*P)[begin][end]);
		Path_Traverse(s,begin,(*P)[begin][end],P);
	}else
	{
		return;
	}
}
void initStack(sqStack* s)
{
	s->base = (Elemtype*)malloc(MAXVEX*sizeof(Elemtype));
	s->top = s->base;
	s->container = MAXVEX;
}

void Push(sqStack* s ,Elemtype e)
{
	*((s->top)++)=e;
}

Elemtype Pop(sqStack*s )
{
	Elemtype e = *(--(s->top));
	return e;
}

 
void ShortextPath_Floyd(MGraph *G, Pathmatrix *P) 
{
	int v,w,k;
	
	//initial
	for(v = 0;v < G->numVextexes;v++)
	{
		for(w = 0;w<G->numVextexes;w++)
		{
			(*P)[v][w] = w;
		}
	}
	
	for(k = 0;k<G->numVextexes;k++)
	{
		for(v = 0;v<G->numVextexes;v++)
		{
			for(w = 0;w<G->numVextexes;w++)
			{
				if(G->matrix[v][w] > G->matrix[v][k]+G->matrix[k][w])
				{
					G->matrix[v][w] = G->matrix[v][k]+G->matrix[k][w];					
					(*P)[v][w] = k;						
				}	
			}
		}
	}	
}
