#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NumberofVertix 10

int TraceDfs[NumberofVertix];

void Dfs(int map[NumberofVertix][NumberofVertix],int begin/*����*/)
{
	for(int j = 0;j<NumberofVertix;j++)//�ƶ��� 
	{
		if(map[begin][j] && !TraceDfs[j]/*begin �� j ��edge ����jû�о���*/)
		{
			printf("%d",map[begin][j]);
			TraceDfs[j] = 1;
			Dfs(map[NumberofVertix][NumberofVertix],j);
		}
		 
	}
}
