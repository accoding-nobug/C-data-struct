#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListLink
{
	int data;
	struct ListLink* next;
} Listlink;

void CreatlistHead(Listlink*,int);/*头插法*/
void CreatlistTail(Listlink*,int); /*尾接法*/
void Myfree(Listlink*);/*free链表*/
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
	Listlink* head = (Listlink*)malloc(sizeof(Listlink*));/*头指针,不放数据*/
	head->next = NULL;
	Listlink* p;
	printf("%p",head);
	int len = 0;
	printf("输入链表长度: ");
	scanf("%d",&len);
	printf("输入数据: ");
	CreatlistTail(head,len);	
	Myprint(head);
	
	int i = 0,loc = 0;
	printf("输入插入数据: ");
	scanf("%d",&i);
	printf("输入插入位置前一个位置"); 
	scanf("%d",&loc);
	insert_list(i,loc,head);
	Myprint(head);
	
	int del_seq = 0;
	printf("输入删除的序号");
	scanf("%d",&del_seq);
	del_list(del_seq,head);
	Myprint(head);
	
	Myfree(head);
	return 0;
}

void CreatlistHead(Listlink*const head, int len)/*头插法*/
{
	/*
		头插法,新结点在head之后,head永远指向第一个结点,不需要辅助指针 
	*/
	for(int j = 0;j<len;j++)
	{
		Listlink* kint = (Listlink*)malloc(sizeof(Listlink));
		scanf("%d",&kint->data);
		kint->next = head->next;
		head->next = kint;				 
	}	
}
	
void CreatlistTail(Listlink* head , int len) /*尾接法*/
{
	/*
		尾接法,以此向后,需要辅助指针指向最后一个结点 
	*/
	
	Listlink* p = head;/* 变动的结点,用于指向最后一个结点*/ 	
	for(int j = 0;j<len;j++)
	{
		Listlink* kint = (Listlink*)malloc(sizeof(Listlink*));
		scanf("%d",&kint->data);
		p->next = kint;/* 头结点指向第一个结点*/
		p = kint ; /*指针p移动一位*/
		p->next = NULL;/*指针初始化*/
	}	
}



void Myfree(Listlink* head)/*循环最后free*/ 
{
	Listlink *p;
	Listlink *q;	
	p = head;
	q = head->next;
	
//	while(p)
//	{
//		free(p);
//		p = q;
//		if(q) q = q->next;/*q可能为NULL,没有next*/
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
		p = q;/*p指向第j个结点*/
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
	for(j = 1;j<del_seq/*这样p指向目标结点前一个结点,q指向目标结点*/&&p;j++)
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




