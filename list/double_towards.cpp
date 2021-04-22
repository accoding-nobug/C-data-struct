#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	struct Node* prior;
	int data;
	struct Node* next;
} Node;
int len;

Node* Creat_list();
void Myfree(Node* head);
void Myprint(Node* head);
Node* insert_list(Node* head,int element,int target);
Node* delete_list(Node* head,int target);

void PrintConsole()
{
	printf("ѭ��˫������:\n\
	���� 1 :�����б�\n\
	���� 2 :����б�\n\
	���� 3 :ɾ���б����ض�λ�õ�ֵ\n\
	���� 4 :���ض�λ�ò���һ��ֵ\n\
	����-1 :����");
}


int main(void)
{
//	freopen("double_list.txt","r",stdin);
	Node* head = Creat_list();
	int input = 0;
	PrintConsole();
	while(input != -1)
	{	
		printf("\n�������: ");
		scanf("%d",&input);
		int element,target;
		switch(input)
		{
			case 1:/*creat*/
				printf("���볤��: ");
				scanf("%d",&len);
				head = Creat_list();
				Myprint(head);
				break;
			case 2:/*print*/
				Myprint(head);
				break;
			case 3:/*insert*/
				printf("����ֵ��λ��: ");				
				scanf("%d%d",&element,&target);
				head = insert_list(head,element,target);
				Myprint(head);
				break;
			case 4:/*delete*/
				printf("����λ��: ");
				scanf("%d",&target);
				head = delete_list(head,target);
				Myprint(head); 
				break;
		}
	}
	return 0;
}

Node* Creat_list()
{
	Node* rear = (Node*)malloc(sizeof(Node*));
	Node* head = rear;
	head->data = 1;
	head->prior = rear;
	rear->next = head;
	for(int i = 2;i<=len;i++)
	{
		Node*temp = (Node*)malloc(sizeof(Node*));
		temp->data = i;
	    temp->next = rear->next;
	    temp->prior = rear;
	    head->prior = temp;
	    rear->next = temp;
	    rear = temp;
	}
	return head;
}
void Myfree(Node* head)
{
	Node*p=head->next;
	while(p!= head)
	{
		p->next->prior=p->prior;
		p->prior->next=p->next;
		Node* temp = p->next;
		free(p);
		p = temp;
	}
}
void Myprint(Node* head)
{
	Node*p = head;
	while(p->next != head)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d ",p->data);
}
Node* insert_list(Node* head,int element,int target)
{
	Node *p = head;
	Node* temp = (Node*)malloc(sizeof(Node*));
	if(0 == target)
	{
		printf("ERROR\n");
		return head;
	}	
	if(target == 1)
	{
		temp->data = element;
		temp->next = head;
		temp->prior = head->prior;
		head->prior->next = temp;
		head->prior = temp;
		len++;
		return p->prior;
	}
	for(int i = 1;i<target;i++)
	{
		p = p->next;
	}
	temp->data = element;
	temp->prior = p->prior;
	temp->next = p;
	p->prior->next = temp;
	p->prior = temp;
	len++;
	return head;
}
Node* delete_list(Node* head,int target)
{
	Node*p = head;
	if(0 == target)
	{
		printf("ERROR\n");
		return head;
	}
	if(1 == target)
	{
		p->next->prior = p->prior;
		p->prior->next = p->next;
		Node* temp = p->next;
		free(p);
		p = temp;
		len--;
		return p;		
	}
	for(int i = 1;i<target;i++) p = p->next;
	p->next->prior = p->prior;
	p->prior->next = p->next;
	Node* temp = p->next;
	free(p);
	len--;
	return head;	
}
