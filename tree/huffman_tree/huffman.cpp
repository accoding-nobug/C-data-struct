#include"huffman.h"
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
htTree* buildTree(char* literature)
{
	int* probability = (int*)malloc(sizeof(int)*MAX_SZ);
	//初始化 
	for(int i = 0;i<MAX_SZ;i++)
	{
		probability[i] = 0;
	}
	//统计各个字符出现次数 
	for(int j = 0;literature[j];j++)
	{
		probability[ (unsigned char)literature[j] ]++;
	}
	
	pQueue *huffmanQueue;
	initPQueue(&huffmanQueue);
	
	for(int k = 0;k<MAX_SZ;k++)
	{
		if(probability[k])
		{
			TYPE aux = (TYPE)malloc(sizeof(htNode));
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k;
			addPQueue(&huffmanQueue,aux,probability[k]);
		}
	}
	
	free(probability);
	
	while(huffmanQueue->size!=1)/*当为一的时候就是huffman tree了*/
	{
		unsigned int priority = huffmanQueue->first->priority 
		+ huffmanQueue->first->next->priority;
		TYPE left = NULL;
		TYPE right = NULL;
		left = getPQueue(&huffmanQueue);
		right = getPQueue(&huffmanQueue);
		TYPE newNode = (TYPE)malloc(sizeof(htNode));
		newNode->left = left;
		newNode->right = right;
		addPQueue(&huffmanQueue,newNode,priority);
	}
	htTree* ret = (htTree*)malloc(sizeof(htTree));
	ret->root = getPQueue(&huffmanQueue);
	return ret;
}

hlTable *buildTable(htTree *huffmanTree)
{
	hlTable *table = (hlTable*)malloc(sizeof(hlTable));
	table->first = NULL;
	table->last = NULL;
	//初始化
	
	char code[MAX_SZ];
	int k = 0;
	
	traverseTree(huffmanTree->root,&table,k,code);
	return table; 
}

void traverseTree(htNode* root,hlTable** table,int k,char code[])
{
	if(root->left != NULL)
	{
		code[k] = '0';
		traverseTree(root->left,table,k+1,code);
	}
	if(root->right)
	{
		code[k] = '1';
		traverseTree(root->right,table,k+1,code);
	}	
	if(!root->right&&!root->left)/*叶节点操作*/
	{
		code[k] = '\0';
		hlNode* aux = (hlNode*)malloc(sizeof(hlNode));
		aux->symbol = root->symbol;
		aux->code = (char*)malloc(sizeof(char)*(strlen(code)+1));
		strcpy(aux->code,code);
		aux->next = NULL;
		
		
		if((*table)->first == NULL)
		{
			(*table)->first = aux;
			(*table)->last = aux;
		}else
		{
			(*table)->last->next = aux;
			(*table)->last = aux; 
		}
	}
}

void encode(hlTable *table,char* const string_To_Encode)
{
	int len = strlen(string_To_Encode);
	for(int i = 0;i < len;i++)
	{
		hlNode*iterate = table->first;
		while(iterate)
		{
			if(iterate->symbol == string_To_Encode[i])
			{
				printf("%s",iterate->code);
				break;
			}
			iterate = iterate->next;
		}
		if(!iterate)
		{
			printf("No such a character");
		}
	}
	printf("\n");
}

void decode(htTree *tree , char * const string_To_Decode)
{
	int len = strlen(string_To_Decode);
	htNode *iterate = tree->root;
	for(int i = 0;i < len;i++)
	{

		if(string_To_Decode[i] == '0')
		{
			iterate = iterate->left;
		}
		if(string_To_Decode[i] == '1')
		{
			iterate = iterate->right;
		}
		if(!iterate->left && !iterate->right)
		{
			printf("%c",iterate->symbol);
			iterate = tree->root;
			continue;
		}		
	}
}










