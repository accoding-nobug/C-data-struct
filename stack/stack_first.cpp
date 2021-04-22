#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK 10
typedef int Elemtype; /*数据类型转换,利于维护*/

typedef struct sqStack
{
	Elemtype *top;
	int container;
	Elemtype *base;
}sqStack;

void initStack(sqStack* s)
{
	s->base = (Elemtype*)malloc(MAX_STACK*sizeof(Elemtype));
	s->top = s->base;
	s->container = MAX_STACK;
}

void Push(sqStack* s , Elemtype e)
{
	if(s->top - s->base >= s->container)
	{
		s->base = (Elemtype*)realloc(s->base,(MAX_STACK+s->container)*sizeof(Elemtype*));
		s->top=s->base+s->container;
		s->container+=MAX_STACK; 
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack*s , Elemtype*e )
{
	if(s->top == s->base)
	{
		printf("ERROR");
		return;
	}
	*e = *(--(s->top));
	return;
}

int StackLen(sqStack *s)
{
	return(s->top - s->base);
}
