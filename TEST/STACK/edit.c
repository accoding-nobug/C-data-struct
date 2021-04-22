#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_Stack 200
#define Max_len 600
char liter[Max_len];
//119
//正向 1为插入,2为删除; 
typedef struct Memory_Node
{
	int operation;
	int pos;
	char str[Max_len];
}Memory_Node;

typedef struct Memory
{
	Memory_Node *top,*base;
	int container;
}Memory;

void Operation(Memory_Node compound);
void Insert(int ops,char str[]);
void Delete(int ops,char str[]);
void Push(Memory *memory,Memory_Node node);
Memory_Node Pop(Memory *memory);
void Reserve(Memory_Node compound);

int main(void)
{
	gets(liter);
	
	int pos = 0,len = 0;
	char temp[520];
	int op = 0;
	Memory_Node input;
	Memory* memory = (Memory*)malloc(sizeof(Memory));
	memory->base = (Memory_Node*)malloc(MAX_Stack*sizeof(Memory_Node));
	memory->top = memory->base;
	memory->container = MAX_Stack;
	
	int n;
	scanf("%d",&n);
	while(n--)
	{		
		scanf("%d %d %s",&input.operation,&input.pos,input.str);
		Push(memory,input);	
	}
	getchar();
	while(1)
	{
		scanf("%d",&op);
		if(op == -1)
		{
			break;
		}else if(op == 3)
		{
			if(memory->top > memory->base) Reserve(Pop(memory));
		}else
		{
			switch(op)
			{
				case 1:
					scanf("%d %s",&pos,temp);
					input.operation = op;
					input.pos = pos;
					strcpy(input.str,temp);
					Push(memory,input);
					Operation(input);
					break;
				case 2:
					scanf("%d %d",&pos,&len);
					input.operation = op;
					input.pos = pos;						
					if(pos+len>=strlen(liter))//太长了,就把后面的全部字符删掉并保存下来 
					{
						char*q = liter+pos;
						strcpy(input.str,q);					
					}else
					{
						char q[520];
						strcpy(q,liter+pos);
						q[len] = 0;
						strcpy(input.str,q);
					}
					Push(memory,input);
					Operation(input);
					break;	
			}
		}
	}
	printf("%s",liter);
}



Memory_Node Pop(Memory *memory)
{
	--memory->top;
	Memory_Node ret = *(memory->top);
	return ret;
}

void Push(Memory *memory,Memory_Node node)
{
	if(memory->top - memory->base >= memory->container)
	{
		memory->base = (Memory_Node*)realloc(memory->base,(memory->container+10)*sizeof(Memory_Node));
		memory->top = memory->base+memory->container;
		memory->container+=10;
	}
	*(memory->top++) = node;
	return;
}

void Operation(Memory_Node compound)
{
	switch(compound.operation)
	{
		case 1:
			Insert(compound.pos,compound.str);
			break;
		case 2:
			Delete(compound.pos,compound.str);
			break;	
	}
}

void Insert(int pos,char str[])
{
	if(pos<strlen(liter))
	{
		char *latter = liter+pos;
		char temp[Max_len];
		strcpy(temp,latter);
		*latter = 0;
		strcat(liter,str);
		strcat(liter,temp);		
	}else
	{
		strcat(liter,str);
	}

	return;
}
void Delete(int pos,char str[])
{
	int len = strlen(str);
	char *former = liter+pos; //第一个间断点,前面的保留 
	char *latter = former+len;//第二个间断点,后面的保留 
//	char temp[520];
//	strcpy(temp,latter);
	*former = 0;
	strcat(liter,latter);
//	strcat(liter,temp);
	return;
}
void Reserve(Memory_Node compound)
{
	switch(compound.operation)
	{
		case 2:
			Insert(compound.pos,compound.str);
			break;
		case 1:
			Delete(compound.pos,compound.str);
			break;			
	}
}
