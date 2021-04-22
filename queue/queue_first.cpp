// 队列(queue)先入先出,尾入头出 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int Elemtype
typedef struct QNode
{
	Elemtype data;
	struct QNode* next;
}QNode;
typedef struct QueuePtr
{
	QNode* head;/*pop 的指针*/
	QNode* rear;/*push 的指针*/
}LinkQueue;

void initQue(LinkQueue *q)
{
	q->head = (QNode*)malloc(sizeof(QNode));
	q->rear = q->head;
	q->head->next = NULL;
}

void InsertQueue(LinkQueue *q, Elemtype e)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

void PopQueue(LinkQueue *q , Elementype *e)
{
	if(q->head == q->rear)
	return;
	QNode* p = q->head->next;
	*e = p->data;
	q->head->next = p->next;
	if(p == q->rear)
	q->rear = q->head ;
	free(p);
}

void DestoryQueue(LinkQueue *q)
{
	while(q->head)
	{
		q->rear = q->head->next;
		free(q->head);
		q->head = q->rear;
	}
}
