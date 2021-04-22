#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_STACK 201
typedef char Elemtype;

typedef struct Node
{
	Elemtype data;
	int line;
}Node;

typedef struct Stack
{
	Node *base;
	Node *top;
	int container;
}Stack;

void Push(Elemtype data,Stack* SNode,int line);
Elemtype Pop(Stack* SNode);
int Judge(Elemtype data);
char Match(Elemtype data);

int main(void)
{
	freopen("example.c","r",stdin);
	int line = 1;
	char temp= 0;
	int Get1 = 1,Get2 = 1,Get3 = 1;
	int IfPrint = 1;
	
	Stack *SHead = (Stack*)malloc(sizeof(Stack));
	SHead->base = (Node*)malloc(MAX_STACK*sizeof(Node));
	SHead->top = SHead->base;
	SHead->container = MAX_STACK;
	
	char ans[205];
	int len = 0;		
	while(scanf("%c",&temp)!= EOF&&IfPrint)
	{
		if(temp == '\n')
		{
			line++;
			Get2 = 1;
			continue;
		}
		if(temp == '"')
		{
			Get1 = Get1^1;
			continue;
		}
		else if(temp == '/')
		{
			scanf("%c",&temp);
			if(temp == '/')
			{
				Get2 = 0;
			}else if(temp == '*')
			{
				Get3 = 0;
			}
		}else if(temp == '*')
		{
			scanf("%c",&temp);
			if(temp == '/')
			{
				Get3 = 1;
			}
		}
		if(Get1 && Get2 && Get3&&Judge(temp))
		{
			char gettop,getline; 
			switch(Judge(temp))
			{
				case 1 ://×óÀ¨ºÅ
				gettop = Pop(SHead);
				getline = SHead->top->line;
				if(temp == '{' && gettop == '(')
				{
					printf("without maching '%c' at line %d",gettop,getline);
					IfPrint = 0;
				}				
				else
				{
					if(gettop != 0) Push(gettop,SHead,getline);
					Push(temp,SHead,line);
					ans[len++] = temp;					
				}
				break;
				case 2 ://ÓÒÀ¨ºÅ
				gettop = Pop(SHead);
				getline = SHead->top->line;				
				if(gettop != Match(temp))
				{
					printf("without maching '%c' at line %d",temp,line);
					IfPrint = 0;
				}else
				{
					ans[len++] = temp;
				}
				break;	
			}
		}
	}
	ans[len] = 0;
	if(SHead->base != SHead->top&&IfPrint == 1)
	{
		IfPrint = 0;
		char ans_get = Pop(SHead);
		int ans_line = SHead->top->line;
		if(Judge(ans_get) == 1)
		printf("without maching '%c' at line %d",ans_get,ans_line);
	}//without maching '{' at line 2
	if(IfPrint)
	{
		printf("%s",ans);
	}
	return 0;
}

void Push(Elemtype data,Stack* SNode,int line)
{
	if((SNode->top) - (SNode->base) == SNode->container)
	{
		return;
	}

	SNode->top->data = data;
	SNode->top->line = line;
	SNode->top++;
	return;
} 

Elemtype Pop(Stack* SNode)
{
	Elemtype e;
	if(SNode->top == SNode->base)
	{
		return 0;
	}
	--SNode->top;
	e = SNode->top->data;
	return e;
}

int Judge(Elemtype data)
{
	if(data == '('||data == '{'||data=='[')
	{
		return 1;
	}
	else if(data== ')'|| data == '}'||data==']')
	{
		return 2;
	}
	return 0;
}
char Match(Elemtype data)//data== '' || data == '' || data == ''
{
	if(data == ')')
	{
		return '(';
	}
	if(data == '}')
	{
		return '{';
	}
	if(data == ']')
	{
		return '[';
	}
}

