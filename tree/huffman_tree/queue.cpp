#include"queue.h" 
#include"huffman.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void initPQueue(pQueue **queue)
{
	(*queue) = (pQueue*)malloc(sizeof(pQueue));
	(*queue)->first = NULL;
	(*queue)->size = 0;
	return;
}

void addPQueue(pQueue ** queue, TYPE val , unsigned int priority)
{	
	pQueueNode *aux=(pQueueNode*)malloc(sizeof(pQueueNode));
	aux->priority = priority;
	aux->val = val;
	
	if(0 == (*queue)->size || (*queue)->first == NULL)
	{
		(*queue)->first = aux;
		(*queue)->first->next = NULL;
		(*queue)->size++;
		return;
	}else
	{
		if(aux->priority <= (*queue)->first->priority)
		{
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			(*queue)->size++;
			return;
		}else
		{
			pQueueNode * iterator = (*queue)->first;
			while(iterator->next != NULL)
			{
				if(iterator->next->priority >= aux->priority)
				{
					aux->next = iterator->next;
					iterator->next = aux;
					(*queue)->size++;
					return;
				}
				iterator = iterator->next;
			}
			if(iterator->next == NULL)
			{
				iterator->next = aux;
				aux->next = NULL;
				(*queue)->size++;
				return;
			}
		}
		
	}
}

TYPE getPQueue(pQueue**queue)
{
	if((*queue)->size)
	{
		pQueueNode* newNode = (*queue)->first;
		TYPE ret = (*queue)->first->val;
		(*queue)->first = (*queue)->first->next;
		(*queue)->size--;
		return ret;
	}
	printf("\nEmpty\n");
	return NULL;
}
