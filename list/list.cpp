#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListLink
{
	int data;
	struct ListLink* next;
} Listlink;

void CreatlistHead(Listlink*,int);/*ͷ�巨*/
void CreatlistTail(Listlink*,int); /*β�ӷ�*/
void Myfree(Listlink*);/*free����*/
int insert_list(int , int , Listlink* );
int del_list(int,Listlink*);
int loc_list(Listlink* ,int); 



void Myprint( Listlink*const head)
{
	Listlink* p = head;
	p = head->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;	
	} 
}

int main()
{
	freopen("list.txt","r",stdin);
	Listlink* head = (Listlink*)malloc(sizeof(Listlink*));/*ͷָ��,��������*/
	head->next = NULL;
	Listlink* p;
	printf("%p",head);
	int len = 0;
	printf("����������: ");
	scanf("%d",&len);
	printf("��������: ");
	CreatlistTail(head,len);	
	Myprint(head);
	
	int i = 0,loc = 0;
	printf("�����������: ");
	scanf("%d",&i);
	printf("�������λ��ǰһ��λ��"); 
	scanf("%d",&loc);
	insert_list(i,loc,head);
	Myprint(head);
	
	int del_seq = 0;
	printf("����ɾ�������");
	scanf("%d",&del_seq);
	del_list(del_seq,head);
	Myprint(head);
	
	Myfree(head);
	return 0;
}

void CreatlistHead(Listlink*const head, int len)/*ͷ�巨*/
{
	/*
		ͷ�巨,�½����head֮��,head��Զָ���һ�����,����Ҫ����ָ�� 
	*/
	for(int j = 0;j<len;j++)
	{
		Listlink* kint = (Listlink*)malloc(sizeof(Listlink));
		scanf("%d",&kint->data);
		kint->next = head->next;
		head->next = kint;				 
	}	
}
	
void CreatlistTail(Listlink* head , int len) /*β�ӷ�*/
{
	/*
		β�ӷ�,�Դ����,��Ҫ����ָ��ָ�����һ����� 
	*/
	
	Listlink* p = head;/* �䶯�Ľ��,����ָ�����һ�����*/ 	
	for(int j = 0;j<len;j++)
	{
		Listlink* kint = (Listlink*)malloc(sizeof(Listlink*));
		scanf("%d",&kint->data);
		p->next = kint;/* ͷ���ָ���һ�����*/
		p = kint ; /*ָ��p�ƶ�һλ*/
		p->next = NULL;/*ָ���ʼ��*/
	}	
}



void Myfree(Listlink* head)/*ѭ�����free*/ 
{
	Listlink *p;
	Listlink *q;	
	p = head;
	q = head->next;
	
//	while(p)
//	{
//		free(p);
//		p = q;
//		if(q) q = q->next;/*q����ΪNULL,û��next*/
//	}
	 
//	while(head)
//	{
//		Listlink *p = head;
//		head = head->next;
//		free(p);
//	}	
	while(q)
	{
		p = q;
		q = q->next;
		free(p);
	}
	printf("\nFREE OVER!");
	head = NULL;/**/
	return;
}

int insert_list(int i, int loc, Listlink *head )
{
	Listlink *p = head;
	Listlink *q = head->next;
	int j ;
	for(j = 1;j<=loc&&p;j++)
	{
		p = q;/*pָ���j�����*/
		if(q != NULL) q = q->next;
	} 
	if(j > loc+1|| !p)
	{
		printf("INSERT ERROR!\n");
		return 0;	
	}else
	{
		Listlink *temp = (Listlink*)malloc(sizeof(Listlink));
		temp->data = i;
		temp->next = q;
		p->next = temp;	
		return 1;
	}	
}

int del_list(int del_seq,Listlink* head)
{
	int j = 0;
	Listlink *p = head;
	Listlink *q = head->next;	
	for(j = 1;j<del_seq/*����pָ��Ŀ����ǰһ�����,qָ��Ŀ����*/&&p;j++)
	{
		p = q ;
		if(q) q = q->next;
	}
	if(!p || j>del_seq)
	{
		printf("DELELT ERROR\n");
		return 0;
	}
	p->next = q->next;
	free(q);	
}




