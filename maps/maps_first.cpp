#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NumberofVertix 10

int TraceDfs[NumberofVertix];

void Dfs(int map[NumberofVertix][NumberofVertix],int begin/*行数*/)
{
	for(int j = 0;j<NumberofVertix;j++)//移动列 
	{
		if(map[begin][j] && !TraceDfs[j]/*begin 到 j 有edge 而且j没有经过*/)
		{
			printf("%d",map[begin][j]);
			TraceDfs[j] = 1;
			Dfs(map[NumberofVertix][NumberofVertix],j);
		}
		 
	}
}
