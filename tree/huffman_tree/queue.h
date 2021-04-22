#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include"huffman.h"


#define TYPE htNode*
#define MAX_SZ 256

typedef struct pQueueNode
{
	TYPE val;
	unsigned int priority;
	struct pQueueNode *next;
}pQueueNode;

typedef struct pQueue/*统计出现次数的链表指针*/
{
	unsigned int size;
	pQueueNode *first;
}pQueue;


void initPQueue(pQueue** queue);
void addPQueue(pQueue ** queue, TYPE val , unsigned int priority);
TYPE getPQueue(pQueue**queue);


#endif
