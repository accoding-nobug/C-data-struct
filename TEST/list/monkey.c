#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int data;
	struct Node* prior;
	struct Node* next;
}Node;

typedef struct Link
{
	Node* head;
	Node* tail;
}Link;

int main(void)
{
	int n,q,m;
	scanf("%d%d%d",&n,&m,&q);
	Link* Pointer = NULL;
	for(int i = 0;i<n;i++)
	{
		if(Pointer == NULL)
		{
			Pointer = (Link*)malloc(sizeof(Link));
			Pointer->head = (Node*)malloc(sizeof(Node));
			Pointer->head->data = i+1;
			Pointer->tail = Pointer->head;
			Pointer->tail->next = Pointer->head;
			Pointer->tail->prior = Pointer->head;
			Pointer->head->next=Pointer->head->prior = Pointer->tail; 
		}else
		{
			Node* temp = (Node*)malloc(sizeof(Node));
			temp->data = i+1;
			temp->next = Pointer->head;
			temp->prior = Pointer->tail;
			Pointer->tail->next = temp;
			Pointer->tail = temp;
			Pointer->head->prior = Pointer->tail;
		}
	}
	Node* begin = Pointer->head;
	for(int i = 1;i<q;i++)
	{
		begin = begin->next;
	}
	int flag = 1;
	while(begin->next != begin)
	{
		if(flag == m)
		{
			Node* temp = begin->next;
			begin->prior->next = begin->next;
			begin->next->prior = begin->prior;
			free(begin);
			begin = temp;
			flag = 1;
			continue;
		}
		begin = begin->next;
		flag++;
	}
	printf("%d",begin->data);
}

