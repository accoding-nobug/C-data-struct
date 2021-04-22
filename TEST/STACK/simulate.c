#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_QUEUE 100
typedef struct Node
{
	int data;
	int circle;
	struct Node* next;
}Node;

typedef struct queue
{
	Node *head,*rear;
	int all;
}queue;

void Push(queue* line,int data)
{
	if(line->head == NULL)
	{
		line->head = (Node*)malloc(sizeof(Node));
		line->rear = line->head;
		line->head->data = data;
		line->head->circle = 0;
		line->head->next = 0;
	}else
	{
		Node *temp=(Node*)malloc(sizeof(Node));
		temp->circle = 0;
		temp->data = data;
		temp->next = 0;
		line->rear->next = temp;
		line->rear = temp;
	}
}

void Pop(queue*line,int *data,int *circle)
{
	*data = line->head->data;
	*circle = line->head->circle;
	Node*temp = line->head;
	line->head = line->head->next;
	line->all--;
	free(temp);
}

void end(queue*line)
{
	Node *temp = line->head;
	if(temp)
	do
	{
		temp->circle++;
		temp = temp->next;
	}while(temp);
	return;
}

int main()
{
	int n = 0;
	int people = 1;
	int wait[500]={0};
	
	queue* line =(queue*)malloc(sizeof(queue));
	line->all = 0;
	line->head = line->rear = 0;
	
	scanf("%d",&n);
	int court = 3;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&wait[i]);
	}
	for(int i = 0;i<n||line->all;i++)
	{
		if(i<n)
		{
			int j = 1;
			while(j<=wait[i])
			{
				Push(line,people);
				people++;
				j++;
			}
			line->all+=wait[i];
		}
		
		while(line->all > 7*court&&court+1<=5&&i<n)
		{
			court++;
		}
		
		if(i>=n && 7*court > line->all&&court>3)
		{
			court--;
		}
		for(int k=0;k<court&&line->all;k++)
		{
			int getdata,getcircle;
			Pop(line,&getdata,&getcircle);
			printf("%d : %d\n",getdata,getcircle);		
		}
	
		end(line);		
	}
	return 0;
}
