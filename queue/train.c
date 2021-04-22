#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Destination
{
	char name[55];
	int dis;
}Destination;

typedef struct trunk
{
	char number[5];
	int dis;
	struct trunk *next,*prior;
}trunk;

int main()
{
	int len = 0,n,num_push = 0;
	scanf("%d",&len);
	Destination dest[55] = {0};
	for(int i = 0;i<len;i++)
	{
		scanf("%s %d",dest[i].name,&dest[i].dis);
	}
	scanf("%d",&n);
	trunk ans[55],*rail = 0,*rear;
	
	for(int i = 0;i<n;i++)
	{
		char tempname[55];
		scanf("%s %s",ans[i].number,tempname);
		
		for(int j = 0;j<len;j++)
		{
			if(strcmp(tempname,dest[j].name) == 0)
			{
				ans[i].dis = dest[j].dis;
				break;
			}
		}
		
		if(rail == NULL)
		{
			rail = (trunk*)malloc(sizeof(trunk));
			rail->next = rail->prior = 0;
			rail->dis = ans[i].dis;
			strcpy(rail->number,ans[i].number);
			rear = rail;
		}else
		{
			trunk* node = (trunk*)malloc(sizeof(trunk));
			node->next = NULL;
			node->prior = rear;
			node->dis = ans[i].dis;
			strcpy(node->number,ans[i].number) ;
			rear->next = node;
			rear = node;
		}
	}
	
	int flag = 1;
	while(flag)
	{
		flag = 0;
		for(int i = 0;i<n-1;i++)
		{
			if(ans[i].dis<ans[i+1].dis)
			{
				trunk temp = ans[i];
				ans[i]=ans[i+1];
				ans[i+1] = temp;
				flag = 1;
			}
		}
	}
	
	for(int i = 0;i<n;i++)
	{
		trunk *head = rail;
		int cout = 1;
		while(strcmp(head->number,ans[i].number) != 0)
		{
			head = head->next;
			cout++;
		}
		
		if(cout == 1)
		{
			num_push++;
			rail = head->next;
			free(head);	
		}else
		{
			num_push+=cout+1;
			head->prior->next = head->next;
			if(head->next)
			{
				head->next->prior = head->prior;
			}
			free(head);
		}
	}
	for(int i = 0;i<n;i++)
	{
		printf("%s ",ans[i].number);
	}
	printf("\n");
	printf("%d",num_push);
}
