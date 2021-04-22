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
	int weight;//Ȩֵ 
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

typedef struct sqStack//���Ϊ0��ջ 
{
	Elemtype* top;
	int container;
	Elemtype* base;
}sqStack;

int *etv,*ltv;
int *TopoStack;
int top2;

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
	s.base = (Elemtype*)malloc(G->numVertexes*sizeof(Elemtype));
	s.container = G->numVertexes;
	for(i = 0;i<G->numVertexes;i++)//���������Ϊ0�Ľ����ջ //O(n)
	{
		if(!G->adjlist[i].in)
		{
			Push(&s,i);
		}
	}
	
	//initial TopoNode
	TopoStack = (int*)malloc(G->numVertexes*sizeof(int));
	etv = (int*)malloc(G->numVertexes*sizeof(int));
	memset(etv,0,sizeof(etv));
	
	while(s.top != s.base)//�ϱ� O(e) 
	{
		gettop = Pop(&s);
		TopoStack[top2++] = gettop;
		count++;
		
		for(e = G->adjlist[gettop].firstEdge ; e ; e=e->next)
		{
			k = e->adjvex;
			if(!(--G->adjlist[k].in))//�ж���ȼ�һ���Ƿ�Ϊ0,��Ϊ0����ջ 
			{
				Push(&s,k);
			}
			
			if(etv[gettop]+e->weight > etv[k])
			{
				etv[k] = e->weight+etv[gettop];
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

int Critical_Path(MGraph *G)
{
	EdgeNode* e;
	int i,gettop,k,j;
	int ete,lte;
	
	//����Topological_Sort,���etv��TopoStack��ֵ;
	Topological_Sort(G);
	
	//��ʼ�����е��ltv��Ϊ���ʱ��
	ltv=(int*)malloc(G->numVertexes*sizeof(int));
	for(i = 0;i<G->numVertexes;i++)
	{
		ltv[i] = etv[G->numVertexes-1];	
	}
	
	//�ӻ�㵹��������ltv
	while(top2)
	{
		gettop = TopoStack[--top2];//��һ�����ǻ��
		for(e = G->adjlist[gettop].firstEdge;e;e=e->next)
		{
			k = e->adjvex;
			if(ltv[k] - e->weight < ltv[gettop])//ȷ��ltv[gettop]�㹻С,��֤������Ŀ������� 
			{
				ltv[gettop] = ltv[k] - e->weight;	
			}	
		}	
	} 
	
	//ͨ��ltv��etv��ete��lte
	for(j = 0;j<G->numVertexes;j++)
	{
		for(e = G->adjlist[j].firstEdge; e ; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k]-e->weight;
			
			if(ete == lte)
			{
				printf("<v%d,v%d> length: %d ," G->adjlist[j].data , G->adjlist[k].data , e->weight);	
			}	
		}	
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
