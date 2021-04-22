#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define X 2
#define Y 2

int chess[X][Y];

int nextstep(int *x,int *y,int count)/*判断能否行走*/
{
	switch(count)
	{
		case 1:
			if(*x+2<X &&*y+1<Y &&!chess[*x+2][*y+1])
			{
				*x+=2;
				*y+=1;
				return 1;
			}
			
			break;
		case 2:
			if(*x+2<X &&*y-1<Y && *y-1>=0 && !chess[*x+2][*y-1])
			{
				*x+=2;
				*y-=1;
				return 1;
			}			
			
			break;	
		case 3:
			if(*x-2<X &&*y+1<Y && *x-2>=0 && !chess[*x-2][*y+1])
			{
				*x-=2;
				*y+=1;
				return 1;
			}			
			
			break;
		case 4:
			if(*x-2<X &&*y-1<Y && *x-2>=0 && *y-1>=0 && !chess[*x-2][*y-1])
			{
				*x-=2;
				*y-=1;
				return 1;
			}			
			
			break;
		case 5:
			if(*x+1<X &&*y+2<Y && !chess[*x+1][*y+2])
			{
				*x+=1;
				*y+=2;
				return 1;
			}			
			
			break;
		case 6:
			if(*x+1<X &&*y-2<Y && *y-2>=0 && !chess[*x+1][*y-2])
			{
				*x+=1;
				*y-=2;
				return 1;
			}
			
			break;
		case 7:
			if(*x-1<X &&*y+2<Y && *x-1>=0 && !chess[*x-1][*y+2])
			{
				*x-=1;
				*y+=2;
				return 1;
			}			
			
			break;	
		case 8:
			if(*x-1<X &&*y-2<Y && *x-1>=0 && *y-2>=0 && !chess[*x-1][*y-2])
			{
				*x-=1;
				*y-=2;
				return 1;
			}				
			break;	
		default:
			break;			
	}
	return 0;					
}

/*深度搜索遍历棋盘*/ 
int DfsChess(int x ,int y,int tag/*标记变量*/)
{
	chess[x][y] = tag;
	int flag = 0,count = 1;
	
	if(X*Y == tag)
	{
		return 1;
	}
	
//寻找第一个能走的点
	while(!flag&& count<=X )
	{
		flag = nextstep(&x,&y,count);
		count++;
	}

//尝试走这条路,成功返回1,失败换一条,一直到所有的路都试完了	

	while(flag)
	{
		if(DfsChess(x,y,tag+1))
		{
			return 1;
		}else
		{
			while(!flag && count<=X )
			{
				flag = nextstep(&x,&y,count);
				count++;
			}
		}
	}

	if(0 == flag&& X == count)
	{
		chess[x][y] = 0;
	}
	return 0;
}

int main(void)
{
	clock_t start,finish;
	start = clock();
	int x , y;
	scanf("%d%d",&x,&y);
	if(DfsChess(x,y,1))
	{
		for(int i = 0;i < X;i++)
		{
			for(int j = 0;j<Y;j++)
			{
				printf("%02d ",chess[i][j]);
			}
			printf("\n");
		}
		finish = clock();
		printf("花费%f s",(double)finish-start/CLOCKS_PER_SEC);
	}
	else
	{
		printf("WASTED");
	}
	return 0;
}
