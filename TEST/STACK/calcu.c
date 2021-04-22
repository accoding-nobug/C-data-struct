#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_Stack 100
typedef long long LL;
//1+0*5+5+5=
typedef struct Stack_Method
{
	char *top,*base;
	int container;
}Stack_Method;
typedef struct Stack_Data
{
	LL *top,*base;
	int container;
}Stack_Data;

void Push_data(Stack_Data *Sdata,LL data)
{
	if(Sdata->top - Sdata->base == Sdata->container)
	{
		Sdata->base = (LL*)realloc(Sdata->base,(10+Sdata->container)*sizeof(LL));
		Sdata->top = Sdata->base+Sdata->container;
		Sdata->container+=10;
	}
	*(Sdata->top) = data;
	Sdata->top++;
	return;
}
void Push_method(Stack_Method *Smethod,char method)
{
	if(Smethod->top - Smethod->base == Smethod->container)
	{
		Smethod->base = (char*)realloc(Smethod->base,(10+Smethod->container)*sizeof(char));
		Smethod->top = Smethod->base+Smethod->container;
		Smethod->container+=10;
	}
	*(Smethod->top) = method;
	Smethod->top++;
	return;
}

LL Pop_data(Stack_Data *Sdata)
{
	LL ret = *(--Sdata->top);
	return ret;
}

char Pop_method(Stack_Method *Smethod)
{
	--Smethod->top;
	char type = *(Smethod->top);
	return type;
}

int judge(char c)
{
	switch(c)
	{
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '/':
			return 2;
			break;
		case '*':
			return 2;
			break;
		case '%':
			return 2;
			break;
		default :
			return 0;
			break;			
	}
}

LL Calcu(char type,Stack_Data *Sdata)
{
	LL num1,num2;
	num1 = Pop_data(Sdata);
	num2 = Pop_data(Sdata);
	switch(type)
	{
		case '+':
//			printf("%lld\n",num1+num2);
			return num1+num2;
			break;
		case '-':
//			printf("%lld\n",-num1+num2);
			return -num1+num2;
			break;
		case '/':
//			printf("%lld\n",num2/num1);
			return num2/num1;
			break;
		case '*':
//			printf("%lld\n",num1*num2);
			return num1*num2;
			break;
		case '%':
//			printf("%lld\n",num2%num1);
			return num2%num1;
			break;				
	}		
}

int main(void)
{
	char input;
	int num = 0;
	int flag = 0;
	
	Stack_Data *Sdata = (Stack_Data*)malloc(sizeof(Stack_Data));
	Sdata->base = (LL*)malloc(MAX_Stack*sizeof(LL));
	Sdata->top = Sdata->base;
	Sdata->container = MAX_Stack;
	
	Stack_Method* Smethod= (Stack_Method*)malloc(sizeof(Stack_Method));
	Smethod->base = (char*)malloc(MAX_Stack*sizeof(char));
	Smethod->top = Smethod->base;
	Smethod->container = MAX_Stack;
	
	while(scanf("%c",&input) != EOF)
	{
		if(input == '=')
		{
			if(flag)
			{
				Push_data(Sdata,num);
				num = 0;
				flag = 0;
			}			
			break;
		}
		if(isdigit(input))
		{
			num=num*10+(input-'0');
			flag = 1;
		}else
		{
			if(flag)
			{
				Push_data(Sdata,num);
				num = 0;
				flag = 0;
			}
			if((Smethod->base == Smethod->top && judge(input))|| input == '(')
			{
				Push_method(Smethod,input);
			}else if(input ==')')
			{
				char gettop = Pop_method(Smethod);
				while(gettop != '(')
				{
					Push_data(Sdata,Calcu(gettop,Sdata));				
					gettop = Pop_method(Smethod);
				}
			}else if(judge(input))
			{
				char gettop =Pop_method(Smethod);
				if(judge(gettop) >= judge(input))
				{
					Push_method(Smethod,input);
					Push_data(Sdata,Calcu(gettop,Sdata));
				}else
				{
					Push_method(Smethod,gettop);
					Push_method(Smethod,input);
				}
			}
		}
	}
	while(Smethod->base < Smethod->top)
	{
		Push_data(Sdata,Calcu(Pop_method(Smethod),Sdata));
	}
	if(Sdata->base+1 == Sdata->top)
	{
		printf("%lld",Pop_data(Sdata));
	}
	return 0;
}
