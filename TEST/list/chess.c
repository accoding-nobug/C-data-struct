#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX_SIZE 19


int main(void)
{
	int chess[MAX_SIZE][MAX_SIZE];
	int i,j;
	for(i = 0;i<MAX_SIZE;i++)
	{
		for(j = 0;j<MAX_SIZE;j++)
		{
			scanf("%d",&chess[i][j]);
		}
	}
//shu
	for(j = 0;j<MAX_SIZE;j++)
	{
		int flag = 1,judge = 0;
		for(i = 0;i<MAX_SIZE;i++)
		{		
			if(chess[i][j] != judge)
			{
				if(flag == 4)
				{
					printf("%d:%d,%d\n",judge,i+1-4,j+1);
					return 0;
				}
				judge = chess[i][j];
				flag = 1;	
			}else if(chess[i][j] != 0)
			{
				flag++;	
			}	
		}	
	}		
//heng
	for(i = 0;i<MAX_SIZE;i++)
	{
		int flag = 1,judge = 0;
		for(j = 0;j<MAX_SIZE;j++)
		{		
			if(chess[i][j] != judge)
			{
				if(flag == 4)
				{
					printf("%d:%d,%d\n",judge,i+1,j+1-4);
					return 0;
				}
				judge = chess[i][j];
				flag = 1;	
			}else if(chess[i][j] != 0)
			{
				flag++;	
			}	
		}	
	}		
//zuo xie 1-16 1-16
	for(i = 15,j=0;i>=0&&j<16;i--)
	{
		int mark_i = i,mark_j = j;
		int flag = 1,judge = 0;
		for(;mark_i<MAX_SIZE && mark_j<MAX_SIZE;mark_i++,mark_j++)
		{
			if(chess[mark_i][mark_j] != judge)
			{
				if(flag == 4)
				{
					printf("%d:%d,%d\n",judge,mark_i+1-4,mark_j+1-4);
					return 0;
				}
				judge = chess[mark_i][mark_j];
				flag = 1;	
			}else if(chess[mark_i][mark_j] != 0)
			{
				flag++;	
			}			
		}
		if(i == 0 && j <16)
		{
			i++;
			j++;
		}
	}
//you xie
	for(j = 15,i=18;j>=0&&i>4;j--)
	{
		int mark_i = i,mark_j = j;
		int flag = 1,judge = 0;
		for(;mark_i>=0 && mark_j<MAX_SIZE;mark_i--,mark_j++)
		{
			if(chess[mark_i][mark_j] != judge)
			{
				if(flag == 4)
				{
					printf("%d:%d,%d\n",judge,mark_i+1+1,mark_j+1-1);
					return 0;
				}
				judge = chess[mark_i][mark_j];
				flag = 1;	
			}else if(chess[mark_i][mark_j] != 0)
			{
				flag++;	
			}			
		}
		if(j == 0 && i >4)
		{
			i--;
			j++;
		}
	}
	printf("No\n");
	return 0;		
}
/*
0 2 2 2 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/

