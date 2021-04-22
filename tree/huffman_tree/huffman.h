#pragma once
#ifndef _HUFF_H
#define _HUFF_H

typedef struct htNode
{
	char symbol;
	struct htNode *left;
	struct htNode *right;
}htNode;

typedef struct htTree
{
	htNode *root;
}htTree;

typedef struct hlNode
{
	char symbol;
	char *code;/*symnolµÄhuffman±àÂë*/
	struct hlNode* next;
}hlNode;

typedef struct hlTable/*·½±ãË÷Òý*/ 
{
	hlNode *first;
	hlNode *last;
}hlTable;




htTree* buildTree(char* );
hlTable *buildTable(htTree *huffmanTree);
void encode(hlTable *table,char* const string_To_Encode);
void decode(htTree *tree , char * const string_To_Decode);
void traverseTree(htNode* root,hlTable**,int k,char code[]);

#endif










