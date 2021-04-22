#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Node
{
	long long radio/* xishu */;
	long long power/* mi */ ;
	struct Node* next;
	struct Node* prior;
}Node;

typedef struct Link
{
	Node* head;
	Node* tail;
}Link;

int main()
{
	Link* head1 =(Link*)malloc(sizeof(Link));
	head1->head = head1->tail = NULL;
	Link* head2 =(Link*)malloc(sizeof(Link));
	head2->head = head2->tail = NULL;
	Link* ans = (Link*)malloc(sizeof(Link));
	ans->head = ans->tail = NULL;
	Link* p = head1;
	int n = 2;
	while(n--)
	{
		char tempc;
		tempc = getchar();
		int judge = 1;
		long long num = 0;
		while(tempc!='\n')
		{
			if(isdigit(tempc))
			{
				num=num*10+tempc-'0';
			}
			else if(tempc ==' ')
			{
				if(judge == 1)
				{
					if(p->head == NULL)
					{
						p->head = (Node*)malloc(sizeof(Node));
						p->head->radio = num;
						p->tail = p->head;
						p->tail->next = p->head->prior = NULL;
						num=0;
					}
					else
					{
						Node* temp = (Node*)malloc(sizeof(Node));
						temp->radio = num;
						temp->next = NULL;
						temp->prior = p->tail;
						p->tail->next = temp;
						p->tail = temp;
						num = 0;
					}	
					judge = 2;				
				}else
				{
					p->tail->power = num;
					num = 0;
					judge = 1;					
				}
	
			}
			tempc = getchar();
			if (tempc=='\n')
			{
				p->tail->power = num;
				num = 0;
				judge = 1;
			}			
		}
		p = head2;
	}
	

	Node* p1 = head1->head;
	Node* q1 = head2->head;
	
	while(p1)
	{
		q1 = head2->head;
		while(q1)
		{
			Node*temp=(Node*)malloc(sizeof(Node));
			temp->power = (p1->power)+(q1->power);
			temp->radio = (p1->radio) * (q1->radio);
			if(ans->head == NULL)
			{
				ans->tail = ans->head =temp ;
				temp->prior = ans->tail;
				temp->next = ans->head;	
				ans->head->prior = NULL;
				ans->tail->next = NULL;
				q1=q1->next;	
				continue;		
			}			
			Node* traver = ans->head;
			for(;traver && temp->power < traver->power;)
			{
				traver = traver->next;
			}
			if(traver != NULL)
			{
				if(temp->power == traver->power)
				{
					traver->radio +=temp->radio;
					free(temp); 
				}else
				{
					if(traver == ans->head)
					{
						ans->head = temp;
						ans->head->prior = NULL;
					}else
					{
						traver->prior->next = temp;
						temp->prior = traver->prior;
					}
					temp->next = traver;
					traver->prior = temp;
				}
			}else if(traver == NULL)
			{
				ans->tail->next = temp;
				temp->prior = ans->tail;
				temp->next = NULL;
				ans->tail = temp;
			}
			q1=q1->next;
		}
		p1=p1->next;
	}
	
	Node* traver = ans->head;
	while(traver)
	{
		printf("%lld %lld ",traver->radio,traver->power);
		traver = traver->next;
	}
	return 0;
}
