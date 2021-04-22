#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXVEX 10
typedef int Elemtype;

//边表声明 
typedef struct EdgeNode
{
	int adjvex;//下标 
	struct EdgeNode* next;
}EdgeNode;

//顶点表结点声明
typedef struct VertexNode
{
	int in;//入度
	int data;
	EdgeNode *firstEdge; 
}VertexNode;

typedef struct MGraph
{
	VertexNode adjlist[MAXVEX];
	int numVertexes;	
}MGraph;

typedef struct sqStack
{
	Elemtype* top;
	int container;
	Elemtype* base;
}sqStack;

void Push(sqStack* s , Elemtype e);
Elemtype Pop(sqStack*s);

//拓扑排序算法
//若graph无回路,则输出拓扑排序序列并返回1,否则返回0;
int Topological_Sort(MGraph *G); 
int Topological_Sort(MGraph *G)
{
	EdgeNode *e;
	int i,k,gettop;
	int count = 0;//统计输出顶点个数 
	sqStack s;
	s.base = (Elemtype*)malloc(MAXVEX*sizeof(Elemtype));
	s->container = MAXVEX;
	for(i = 0;i<G->numVertexes;i++)//将所有入度为0的结点入栈 //O(n)
	{
		if(!G->adjlist[i].in)
		{
			Push(&s,i);
		}
	}
	
	while(s.top != s.base)//断边 O(e) 
	{
		gettop = Pop(&s);
		printf("%d -> ",G->adjlist[gettop].data);
		count++;
		
		for(e = G->adjlist[gettop].firstEdge;e;e=e->next)
		{
			k = e->adjvex;
			if(!(--G->adjlist[k].in))//判断入度减一后是否为0,若为0则入栈 
			{
				Push(&s,k);
			}
		}
	}
	
	if(count<G->numVertexes)
	{
		return 0;
	}else
	{
		return 1; 
	}
}

void Push(sqStack* s , Elemtype e)
{
	if(s->top - s->base >= s->container)
	{
		s->base = (Elemtype*)realloc(s->base,(MAXVEX+s->container)*sizeof(Elemtype*));
		s->top=s->base+s->container;
		s->container+=MAX_STACK; 
	}
	*(s->top) = e;
	s->top++;
}

Elemtype Pop(sqStack*s)
{
	if(s->top == s->base)
	{
		printf("ERROR");
		return;
	}
	return *(--(s->top));
	
}


