#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CountMax 13
typedef struct Node
{
	int data;
	struct Node* next;
} Node;

Node* Creat_list();
void Magician(Node*);
void Myfree(Node*);

int main(void)
{
	Node* head = Creat_list();
	Magician(head);
	
	/*Êä³ö*/
	Node *p = head;
	do
	{
		printf("ºÚÌÒ%d",p->data);
		p = p->next;
	}while(p != head);
	Myfree(head);
	return 0;
}

Node* Creat_list()
{
	Node* rear = (Node*)malloc(sizeof(Node));
	rear->next = rear;
	for(int i = 1;i<CountMax;i++)
	{
		Node* temp= (Node*)malloc(sizeof(Node));
		temp->next = rear->next;
		rear->next = temp;
		rear = temp;
	}
	return rear->next;
}

void Magician(Node* head)
{
	Node* p = head;
	p->data = 1;
	for(int Count = 2 ; Count <= CountMax;Count++)
	{
		for(int step = 1;step<=Count;step++)
		{
			p = p->next;
		}
		p->data = Count;
	}
}
void Myfree(Node*)
{
	Node* p = head->next;
	while(p != p->next)
	{
		Node* temp = p->next;
		free(p);
		p = temp;
	}
}
