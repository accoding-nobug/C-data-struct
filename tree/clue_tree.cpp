#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Elemtype;

typedef struct BiTNode
{
	struct BiTNode* lchild;
	int ltag;/*1表示左孩子存在,0表示叶子结点,指向前驱元素*/
	Elemtype data;
	int rtag;/*1表示右孩子存在,0表示叶子结点,指向后继元素*/ 
	struct BiTNode* rchild;
}BiTNode;

//定义全局变量保存中序遍历的足迹
BiTNode* pre; 

void visit (Elemtype c)
{
	printf("%c",c);
}

void Creat_Tree(BiTNode** root)
{
	Elemtype c;
	scanf("%c",&c);
	if(c == '#')
	{
		*root=NULL;
	}else
	{
		*root = (BiTNode*)malloc(sizeof(BiTNode));
		(*root)->data = c;
		(*root)->ltag = 1;/*假装存在*/
		(*root)->rtag = 1;
		Creat_Tree(&(*root)->lchild);
		Creat_Tree(&(*root)->rchild);
	}
}

void InThreading(BiTNode* root)
{
	if(root)
	{
		InThreading(root->lchild);//递归左孩子线索化
		if(! root->lchild)
		{
			root->ltag = 0;
			root->lchild = pre;	
		}		
		if(! pre->rchild)
		{
			pre->rtag = 0;
			pre->rchild = root;				
		} 
		pre = root;
		InThreading(root->rchild);//递归右孩子线索化 

	}
}

void InOrderThreading(BiTNode**p,BiTNode* root)/*建立前序的顺序*/ 
{
	*p = (BiTNode*)malloc(sizeof(BiTNode));
	(*p)->ltag = 1;
	(*p)->rtag = 0;
	(*p)->rchild = *p;
	if(!root)
	{
		(*p)->lchild = *p;
	}else
	{
		(*p)->lchild = root;
		pre = *p;
		InThreading(root);
		pre->rchild = *p;
		pre->rtag = 0;
		(*p)->rchild = pre;
	}
}

void InOrderTraverse(BiTNode* head)/*建立头结点*/
{
	BiTNode* p;
	p = head->lchild;
	
	while(p != head)
	{
		while(p->ltag == 1)/*前序遍历先左再中后右,这一步把根节点推向最左边*/
		{
			p=p->lchild;
		}
		visit(p->data);
		
		while(p->rtag == 0 && p->rchild != head)/*把叶节点返回到上一个双亲*/
		{
			p=p->rchild;
			visit(p->data);
		}
		
		p = p->rchild;/*把跟结点往右叶节点推*/
	}
}

int main(void)
{
	BiTNode* root = NULL;
	BiTNode* p = NULL;/*头结点*/ 
	Creat_Tree(&root);
	InOrderThreading(&p,root);
	InOrderTraverse(p);
	return 0;
} 
