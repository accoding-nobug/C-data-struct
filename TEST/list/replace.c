#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

void Build_KMP(char target[],int next[])
{
	int i=0,j=-1;
	int len = strlen(target);
	while(i<len)
	{
		if(-1 == j || target[j] == target[i])
		{
			i++;
			j++;
			if(target[i] != target[j])	next[i] = j;
			if(target[i] == target[j])	next[i] = next[j];//ABCDABCe -1 -1 -1 -1 -1 -1 -1 3
		}else
		{
			j = next[j];
		}
	}
}

int Judge(char c,char target[],int next[])
{
	int i = 0,len = strlen(target),flag;
	char temp[15]={0};
	do
	{
		temp[i] = c;
		temp[i+1] = 0;
		if(c == tolower(target[i]) || c==toupper(target[i]))
		{
			if(i != len-1)
			{
				i++;	
			}else
			{
				return 1;
			}	
		}else
		{
			flag = i;
			i = next[i];
			if(-1 == i)
			{
				printf("%s",temp);
				return 0;				
			}else// ACACA ACACB -1 -1 -1 -1 2
			{
				while(temp[flag] != target[i])//寻找完全契合的片段 
				{
					i = next[i];
					if(i == -1)
					{
						printf("%s",temp);
						return 0;						
					}
				}
				int len_temp = strlen(temp)/*len = 5,i = 2,flag = 4 printf 0 1*/;
				int j = 0;
				for(;j<flag-i;j++)
				{
					printf("%c",temp[j]);
				}
				char*q=temp+j+1;
				temp[j] = 0;
				strcat(temp,q);
				i++;
			}
		}
	}while(scanf("%c",&c) != EOF);
}

int main(void)
{
	char target[10];
	int next[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	scanf("%s",target);
	Build_KMP(target,next);
	char replace[50];
	scanf("%s",replace);
	getchar();
	
	freopen("filein.txt","r",stdin);
	freopen("fileout.txt","w",stdout);
	char c;
	while(scanf("%c",&c) != EOF)
	{
		if(Judge(c,target,next))
		{
			printf("%s",replace);
		}
	}
}
