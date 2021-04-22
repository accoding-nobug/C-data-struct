#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Array_Size 100
int next[Array_Size];

void ini_next(char target[]/*对next数组进行初始化*/)
{
	int i = 0,j=-1;
	next[0] = -1;
	while(i <strlen(target))
	{
		if(-1 == j || target[j] == target[i])
		{
			i++;
			j++;
			if(target[j] != target[i])	next[i] = j;
			if(target[j] == target[i])	next[i] = next[j];
		}else j = next[j];/* 类似于递归思想 , 子串target和目标串letter比较,在 i处不匹配,则回溯到next[j]继续比较
						  ,同理,对子串target,前j项和target[i]不匹配,令target为letter串,则前k项为新的target串,这步,神来之笔*/
	}
}

int KMP(char target[], char letter[] )
{
	int j = 0,cnt = 0;
	for(int i = 0;i<strlen(letter);i++)
	{
		if(letter[i] == target[j])
		{
			j++; 
		}else
		{
			j =next[j];
			if(j != -1)	i--;
			if(-1 == j)
			{
				j = 0;
			}
		}
		if(strlen(target)-1 == j)
		return i;
	}
	return 0;
}

int main()
{
	
}
