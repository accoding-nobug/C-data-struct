#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TREE_SIZE 100
typedef int Elemtype; 
typedef struct CTNode
{
	int child;/*���ӽ����±�*/
	struct CTNode* next;/*ָ����һ�����ӽ���ָ��*/
}ChildPtr;

//��ͷ�ṹ
typedef struct CTBox
{
	Elemtype data;/*����*/
	int parent;/*˫�׵��±�*/ 
	ChildPtr firstchild;/*��һ�����ӵ�ָ��*/ 
}CTBox;

//���ṹ
typedef struct PTree/*���Ľṹ*/
{
	CTBox nodes[MAX_TREE_SIZE];
	int r;/*root's location*/
	int n;/*the number of nodes*/
}PTree; 
