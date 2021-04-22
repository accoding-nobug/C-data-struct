#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int posx1;
	int posy1;
	int posx2;
	int posy2;	
	struct Node* next;
}Node;

typedef struct line
{
	Node* head;
	Node* tail;
	int len;
}line;
line start[100];

int judge(line p,Node q)
{
	if(p.head->posx1 == q.posx2&&p.head->posy1 == q.posy2)
	{
		return 12;
	}
	if(p.tail->posx2 == q.posx1&&p.tail->posy2 == q.posy1)
	{
		return 21;
	}		
	return 0;	
}

int main(void)
{
	Node rec;
	rec.next = NULL;
	int n = 0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&rec.posx1,&rec.posy1,&rec.posx2,&rec.posy2);
		int flag = 1;
		int i = 0;
		Node* newbuild = (Node*)malloc(sizeof(Node));
		*newbuild = rec;
		newbuild->next = NULL;		
		for(;start[i].len;i++)
		{
			switch(judge(start[i],rec))
			{
				case 0:
					break;
				case 12:
					newbuild->next = start[i].head;
					start[i].head = newbuild;
					start[i].len++;
					flag = 0;
					break;						
				case 21:
					(start[i].tail)->next = newbuild;
					start[i].tail = newbuild;
					start[i].len++;
					flag = 0;
					break;															
			}
		}
		if(flag)//没有连接的点
		{
			start[i].head = newbuild;
			start[i].tail = start[i].head;
			start[i].len++;		
		} 
	}
	int ans_len,ans_pos;
	for(int j = 0;start[j].len;j++)
	{
		int tmp_len = start[j].len;
		Node* p = start[j].tail->next;
		while(p)
		{
			tmp_len++;
			p = p->next;
		}
		if(tmp_len>ans_len)
		{
			ans_len = tmp_len;
			ans_pos = j;
		}
	}
	printf("%d %d %d",ans_len,start[ans_pos].head->posx1,start[ans_pos].head->posy1);
	return 0;
}
