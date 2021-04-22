#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_STACK 100

//1 push 0 pop -1 end

typedef struct Stack
{
	int *base;
	int *top;
	int container;
}Stack;

void Push(int data,Stack* SNode)
{
	if((SNode->top) - (SNode->base) == SNode->container)
	{
		printf("error ");
		return;
	}
	*(SNode->top++) = data;
	return;
} 

void Pop(Stack* SNode)
{
	int e;
	if(SNode->top == SNode->base)
	{
		printf("error ");
		return;
	}
	e = *(--SNode->top);
	printf("%d ",e);
}

int main(void)
{
	int type = 0;
	Stack *SNode = (Stack*)malloc(sizeof(Stack));
	SNode->base = (int*)malloc(MAX_STACK*sizeof(int));
	SNode->top = SNode->base;
	SNode->container = MAX_STACK;
	while(1)
	{
		int flag = 0;
		scanf("%d",&type);
		int data = 0;
		switch(type)
		{
			case 1 :
				scanf("%d",&data);
				Push(data,SNode);
				break;
			case 0 :
			    Pop(SNode);
			    break;
			case -1:
				flag = 1;
				break;		
		}
		if(flag)
		break;
	}
	return 0;
}
