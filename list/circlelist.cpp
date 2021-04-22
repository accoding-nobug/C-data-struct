#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

void def_List(Node* head,int len);
void Myprint(Node* head);
void Myfree(Node*);/*free链表*/

int main(void)
{
	freopen("circle_list.txt","r",stdin);
	Node* head = (Node*)malloc(sizeof(Node*));
	head->next = head;
	head->data = 5;
	printf("输入所需循环链表长度: ");
	int len = 0;
	scanf("%d",&len);
	printf("输入数据: ");
	def_List(head,len);
	Myprint(head);	
	Myfree(head);
}

void def_List(Node* head,int len)
{
	Node *former,*last;
	former = head;
	for(int j = 1;j<=len;j++)
	{
		last = (Node*)malloc(sizeof(Node*));
		scanf("%d",&last->data);
		last->next = former->next;
		former->next = last;
		former = last;
	}
}

void Myprint(Node* head)
{
	Node*p = head;
	while(p->next != head)
	{
		printf("%d ",p->next->data);
		p = p->next;
	}
}

void Myfree(Node* head)/*循环最后free*/ 
{
	Node *p;
	Node *q;	
	p = head;
	q = head->next;	
	while(q != head)
	{
		p = q;
		q = q->next;
		free(p);
	}
	printf("\nFREE OVER!");
	head->next = head ;/**/
	return;
}
