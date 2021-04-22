#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Elemtype;

typedef struct BiTNode
{
	struct BiTNode* leftchild;
	Elemtype data;
	struct BiTNode* rightchild;
}BiTNode;

void Traverse_Left(BiTNode** root,int level)/*�Ӹ���ʼ,�ٱ�����ڵ�,Ȼ������ҽڵ�,�ݹ�*/
{
	if(*root == NULL) return; 
	printf("%c�ڵ�%d��\n",(*root)->data,level);
	if((*root)->leftchild) Traverse_Left(&(*root)->leftchild,level+1);
	if((*root)->rightchild) Traverse_Left(&(*root)->rightchild,level+1);
	return;
}

// ����һ����ȫ������

void Creat_Tree(BiTNode** root)
{
	Elemtype temp;
	scanf("%c",&temp);
	if(temp != '#') 
	{
		*root = (BiTNode*)malloc(sizeof(BiTNode*));
		(*root)->data = temp;
		(*root)->leftchild = NULL;
		(*root)->rightchild = NULL;
		Creat_Tree(&(*root)->leftchild);
		Creat_Tree(&(*root)->rightchild);	
	}	
} 

void Myfree(BiTNode** root)
{
	if((*root)->leftchild) Myfree(&(*root)->leftchild);
	if((*root)->rightchild) Myfree(&(*root)->rightchild);
	free(*root);
}

int main(void)
{
	int level = 1;
	BiTNode*root;
	Creat_Tree(&root);
	Traverse_Left(&root,level);
	Myfree(&root);
	return 0;
}
