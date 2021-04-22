//邻接矩阵的广度遍历算法 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Elemtype;
#define numVertexse 10
int visited[numVertexes];
typedef struct MGraph
{
	Elemtype vex[numVertexes];
	int art[numVertexes][numVertexes]; 
}MGraph;

typedef struct Queue
{
	int data;
	struct Queue *next;
}

void BFSTraverse ( 	MGraph G )
{
	int i , j;
	Queue Q;
	
	for(i = 0;i<numVertexes;i++)
	{
		if( !visited[i] )
		{
			printf("%c",G.vex[i]);
			visited[i] = true;
			EnQueue(&Q,i);
			
			while( !QueueEmpty(Q) )
			{
				Dequeue(&Q,&i);/*回溯*/
				for(j = 0;j<numVertexes;j++)
				{
					if(G.art[i][j] && !visited[j] )
					{
						printf("%c",G.vex[j]);
						visited[j] = true;
						EnQueue(&Q,j);
					}
				}
			}
		}
	}
}
int main(void)
{
	MGraph G;
	
}
