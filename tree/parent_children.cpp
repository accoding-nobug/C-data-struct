#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TREE_SIZE 100
typedef int Elemtype; 
typedef struct CTNode
{
	int child;/*孩子结点的下标*/
	struct CTNode* next;/*指向下一个孩子结点的指针*/
}ChildPtr;

//表头结构
typedef struct CTBox
{
	Elemtype data;/*数据*/
	int parent;/*双亲的下标*/ 
	ChildPtr firstchild;/*第一个孩子的指针*/ 
}CTBox;

//树结构
typedef struct PTree/*树的结构*/
{
	CTBox nodes[MAX_TREE_SIZE];
	int r;/*root's location*/
	int n;/*the number of nodes*/
}PTree; 
