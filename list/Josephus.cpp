#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;
int len ;
Node* def_List(int len);
void Josephus_kill(Node* head);
 

int main(void)
{
	freopen("Josephus.txt","r",stdin);
	printf("输入所需循环链表长度: ");
	scanf("%d",&len);
	Node* head = def_List(len);
	Josephus_kill(head);
	return 0;
}

Node* def_List(int len)
{
	Node *ret = (Node*)malloc(sizeof(Node*));
	ret->data = 1;
	ret->next =ret;
	for(int j = 2;j<=len;j++)
	{
		Node *temp = (Node*)malloc(sizeof(Node*));
		temp->data = j;
		temp->next = ret->next;
		ret->next = temp;
		ret = temp;
	}
	return ret->next;
}

void Josephus_kill(Node* head)
{
	Node*p = head;
	while( p->next != p)
	{
		for(int i = 1;i<2;i++)
		{
			p = p->next;
		}
		Node*temp = p->next->next;
		printf("%d->",p->next->data);
		free(p->next);
		p->next = temp;
		p = temp;
	}
	printf("%d",p->data);
}

