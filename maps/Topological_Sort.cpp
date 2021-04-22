#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXVEX 10
typedef int Elemtype;

//�߱����� 
typedef struct EdgeNode
{
	int adjvex;//�±� 
	struct EdgeNode* next;
}EdgeNode;

//�����������
typedef struct VertexNode
{
	int in;//���
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

//���������㷨
//��graph�޻�·,����������������в�����1,���򷵻�0;
int Topological_Sort(MGraph *G); 
int Topological_Sort(MGraph *G)
{
	EdgeNode *e;
	int i,k,gettop;
	int count = 0;//ͳ������������ 
	sqStack s;
	s.base = (Elemtype*)malloc(MAXVEX*sizeof(Elemtype));
	s->container = MAXVEX;
	for(i = 0;i<G->numVertexes;i++)//���������Ϊ0�Ľ����ջ //O(n)
	{
		if(!G->adjlist[i].in)
		{
			Push(&s,i);
		}
	}
	
	while(s.top != s.base)//�ϱ� O(e) 
	{
		gettop = Pop(&s);
		printf("%d -> ",G->adjlist[gettop].data);
		count++;
		
		for(e = G->adjlist[gettop].firstEdge;e;e=e->next)
		{
			k = e->adjvex;
			if(!(--G->adjlist[k].in))//�ж���ȼ�һ���Ƿ�Ϊ0,��Ϊ0����ջ 
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


