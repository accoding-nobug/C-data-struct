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
	int weight;//权值 
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

typedef struct sqStack//入度为0的栈 
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

//拓扑排序算法
//若graph无回路,则输出拓扑排序序列并返回1,否则返回0;
int Topological_Sort(MGraph *G); 
int Topological_Sort(MGraph *G)
{
	EdgeNode *e;
	int i,k,gettop;
	int count = 0;//统计输出顶点个数 
	
	sqStack s;
	s.base = (Elemtype*)malloc(G->numVertexes*sizeof(Elemtype));
	s.container = G->numVertexes;
	for(i = 0;i<G->numVertexes;i++)//将所有入度为0的结点入栈 //O(n)
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
	
	while(s.top != s.base)//断边 O(e) 
	{
		gettop = Pop(&s);
		TopoStack[top2++] = gettop;
		count++;
		
		for(e = G->adjlist[gettop].firstEdge ; e ; e=e->next)
		{
			k = e->adjvex;
			if(!(--G->adjlist[k].in))//判断入度减一后是否为0,若为0则入栈 
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
	
	//调用Topological_Sort,求出etv和TopoStack的值;
	Topological_Sort(G);
	
	//初始化所有点的ltv都为汇点时间
	ltv=(int*)malloc(G->numVertexes*sizeof(int));
	for(i = 0;i<G->numVertexes;i++)
	{
		ltv[i] = etv[G->numVertexes-1];	
	}
	
	//从汇点倒过来计算ltv
	while(top2)
	{
		gettop = TopoStack[--top2];//第一个点是汇点
		for(e = G->adjlist[gettop].firstEdge;e;e=e->next)
		{
			k = e->adjvex;
			if(ltv[k] - e->weight < ltv[gettop])//确保ltv[gettop]足够小,保证所有项目都能完成 
			{
				ltv[gettop] = ltv[k] - e->weight;	
			}	
		}	
	} 
	
	//通过ltv和etv求ete和lte
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
