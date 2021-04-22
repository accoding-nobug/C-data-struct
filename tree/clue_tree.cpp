#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Elemtype;

typedef struct BiTNode
{
	struct BiTNode* lchild;
	int ltag;/*1��ʾ���Ӵ���,0��ʾҶ�ӽ��,ָ��ǰ��Ԫ��*/
	Elemtype data;
	int rtag;/*1��ʾ�Һ��Ӵ���,0��ʾҶ�ӽ��,ָ����Ԫ��*/ 
	struct BiTNode* rchild;
}BiTNode;

//����ȫ�ֱ�����������������㼣
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
		(*root)->ltag = 1;/*��װ����*/
		(*root)->rtag = 1;
		Creat_Tree(&(*root)->lchild);
		Creat_Tree(&(*root)->rchild);
	}
}

void InThreading(BiTNode* root)
{
	if(root)
	{
		InThreading(root->lchild);//�ݹ�����������
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
		InThreading(root->rchild);//�ݹ��Һ��������� 

	}
}

void InOrderThreading(BiTNode**p,BiTNode* root)/*����ǰ���˳��*/ 
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

void InOrderTraverse(BiTNode* head)/*����ͷ���*/
{
	BiTNode* p;
	p = head->lchild;
	
	while(p != head)
	{
		while(p->ltag == 1)/*ǰ������������к���,��һ���Ѹ��ڵ����������*/
		{
			p=p->lchild;
		}
		visit(p->data);
		
		while(p->rtag == 0 && p->rchild != head)/*��Ҷ�ڵ㷵�ص���һ��˫��*/
		{
			p=p->rchild;
			visit(p->data);
		}
		
		p = p->rchild;/*�Ѹ��������Ҷ�ڵ���*/
	}
}

int main(void)
{
	BiTNode* root = NULL;
	BiTNode* p = NULL;/*ͷ���*/ 
	Creat_Tree(&root);
	InOrderThreading(&p,root);
	InOrderTraverse(p);
	return 0;
} 
