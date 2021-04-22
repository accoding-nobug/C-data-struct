#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_STACK 10
typedef char Elemtype; /*数据类型转换,利于维护*/
//119
typedef struct sqStack
{
	Elemtype *top;
	int container;
	Elemtype *base;
}sqStack;
void initStack(sqStack* s);
void Push(sqStack* s , Elemtype e);
void Pop(sqStack*s , Elemtype*e );
int StackLen(sqStack *s);
int judge(char c);

int main()
{
//	freopen("中缀改逆波兰.txt","r",stdin);
	printf("输入中缀算式,数字与运算符空格分开,#结尾");
	sqStack s;
	initStack(&s);
	char c ;
	scanf("%c",&c);
	while(c != '#')
	{
		while(isdigit(c))
		{
			printf("%c ",c);
			scanf("%c",&c);
		}
		if( c != ' ' && c != '#')
		{
			if(StackLen(&s) == 0 || c == '(')
			{
				Push(&s,c);
			}
			else if (c == ')')
			{
				Elemtype t;
				Pop(&s,&t);
				printf("%c ",t);
				Pop(&s,&t);
			}else
			{
				Elemtype t;
				if(StackLen(&s)) Pop(&s,&t);
				while(1)
				{
					if(judge(t) >= judge(c))
					{
						printf("%c ",t);
						if(StackLen(&s)) Pop(&s,&t);
						else break;
					}else
					{
						Push(&s,t);
						break;
					}
				}
				Push(&s,c);	
			}
		}
		scanf("%c",&c);
	}
	while( StackLen(&s) != 0 )
	{
		Pop(&s,&c);
		printf("%c ",c);
	}
	return 0;
}


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

int judge(char c)
{
	switch(c)
	{
		case '+': return 1;
			break;
		case '-': return 1;
		    break;
		case '*': return 2;
		    break;
		case '/': return 2;
		    break;	
		case '(': return -1;
		    break;						
	}
}
