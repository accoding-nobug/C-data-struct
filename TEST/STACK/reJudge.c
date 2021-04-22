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
typedef struct qStack
{
	Node *top;
	Node *base;
	int container;
}qStack;

void Push(Elemtype data,int line,qStack* Shead);
Elemtype Pop(qStack* Shead);
int Judge(Elemtype data);//ÅĞ¶Ï×óÓÒÀ¨ºÅ
Elemtype Match(Elemtype data);//Ñ°ÕÒÅäÌ×µÄÀ¨ºÅ

int main(void)
{
	freopen("example.c","r",stdin);
	char input;
	char ans[MAX_STACK];
	int len = 0;
	qStack *Shead = (qStack*)malloc(sizeof(qStack));
	Shead->base = (Node*)malloc(MAX_STACK*sizeof(Node));
	Shead->top = Shead->base;
	Shead->container = MAX_STACK;
	memset(Shead->base,0,sizeof(Shead->base));
	
	int flag = 1,line = 1;
	Elemtype getdata;
	int getline;	
	while(scanf("%c",&input)!= EOF && flag)
	{
		if(input == '\n')
		{
			line++;
			continue;
		}
		if(input == '/')
		{
			scanf("%c",&input);
			if(input == '/')
			{
				while(scanf("%c",&input) != EOF)
				{
					if(input == '\n')
					{
						line++;
						break;
					}
				}
				continue;	
			}else if(input == '*')
			{
				int symbol = 0;
				while(scanf("%c",&input) != EOF)
				{
					if(input == '\n') line++;
					while(input == '*')
					{
						scanf("%c",&input);
						if(input == '\n') line++;
						if(input == '/')
						{
							symbol = 1;
							break;
						}
						
					}
					if(symbol) break;
				}
				continue;				
			}
		}
		if(input == '\"')
		{
			while(scanf("%c",&input)!= EOF)
			{
				if(input == '\"')
				break;
			}
			continue;
		}
		if(input == '\'')
		{
			while(scanf("%c",&input)!= EOF)
			{
				if(input == '\'')
				break;
			}
			continue;
		}
		switch(Judge(input))
		{
			case 1://×óÀ¨ºÅ 
				getdata = Pop(Shead);
				getline = Shead->top->line;
				if(input == '{' && getdata == '(')
				{
					printf("without maching '%c' at line %d",getdata,getline);
					flag = 0;
				}else
				{
					if(getdata) Push(getdata,getline,Shead);
					Push(input,line,Shead);
					ans[len++] = input;
				}
				break;
			case 2://ÓÒÀ¨ºÅ 
				getdata = Pop(Shead);
				if(getdata != Match(input))
				{
					printf("without maching '%c' at line %d",input,line);
					flag = 0;
				}else
				{
					ans[len++] = input;
				}
				break;
			case 0:
				break;	
		}
	}
	ans[len] = 0;
	if(Shead->top != Shead->base && flag)
	{	
		getdata = Pop(Shead);
		getline = Shead->top->line;		
		printf("without maching '%c' at line %d",getdata,getline);
		return 0;
	}	
	if(flag)printf("%s",ans);
	return 0;
} 

void Push(Elemtype data,int line,qStack* Shead)
{
	if((Shead->top) - (Shead->base) >= Shead->container)
	{
		return;
	}
	Shead->top->data = data;
	Shead->top->line = line;
	Shead->top++;
	return;
}
Elemtype Pop(qStack* Shead)
{
	if(Shead->base == Shead->top)
	{
		return 0;
	}
	Elemtype ret;
	Shead->top--;
	ret = Shead->top->data;
	return ret;
}
int Judge(Elemtype data)//ÅĞ¶Ï×óÓÒÀ¨ºÅ
{	
	if(data == '(' || data == '{'  /*data == '['*/)
	{
		return 1;
	}
	if(data == ')' || data == '}' /*data == ']'*/)
	{
		return 2;
	}
	return 0;
} 
Elemtype Match(Elemtype data)//Ñ°ÕÒÅäÌ×µÄÀ¨ºÅ
{
/*	if(data == ']')
	{
		return '[';
	}*/
	if(data == ')')
	{
		return '(';
	}
	if(data == '}')
	{
		return '{';
	}
	return 0;
}














