#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct BTNode
{
	struct BTNode* left;//smaller
	int data;
	struct BTNode* right;//bigger
}BTNode;
int SearchBST(BTNode* T,int key,BTNode* f,BTNode**p);
void Insert_Tree(BTNode** root,int data);
BTNode* DeleteBST(BTNode* T,int key);
void Traverse_Tree(BTNode *root);

//递归查找是否存在key
//指针r指向t的双亲,初始化为 0
//若查找成功,则指针p指向该结点,否则指向最后一个结点. 

int main(void)
{
	int data;
	BTNode *root = 0;
	BTNode *p = 0;
	while(scanf("%d",&data) != EOF)
	{
		if(!root)
		{
			BTNode * temp=(BTNode*)malloc(sizeof(BTNode));
			temp->data = data;
			temp->left = temp->right = 0;	
			root = temp;		
		}
		else
		{
			if(!SearchBST(root,data,root,&p))
			{
				Insert_Tree(&p,data);
			}			
		} 
	}
	Traverse_Tree(root);
	return 0;
}


BTNode* DeleteBST(BTNode* T,int key)
{
	if(!T)
	{
		return 0;
	}else
	{
		if(T->data == key)
		{
			if(!T->left && !T->right)
			{
				free(T);
				return NULL;
			}
			if(!T->left || !T->right)
			{
				BTNode* temp = (T->left)?T->left:T->right;
				free(T);
				return temp;
			}else
			{
				BTNode* q=T->left;
				BTNode* s = T;
				while(q->right)
				{
					s = q;
					q = q->right;
				}
				T->data = q->data;
				return DeleteBST(T->left,T->data);
			}
		}else if(key< T->data)
		{
			T->left = DeleteBST(T->left,key);
		}else
		{
			T->right = DeleteBST(T->right,key);
		}
		return T;
	}
}

int SearchBST(BTNode* T,int key,BTNode* f,BTNode**p)
{
	if(!T)
	{
		*p = f;
		return 0;
	}else
	{
		if(key == T->data)
		{
			return 1;
		}
		else if(key > T->data)
		{
			return SearchBST(T->right,key,T,p);
		}else
		{
			return SearchBST(T->left,key,T,p);
		}
	}
 } 


void Insert_Tree(BTNode** root,int data)
{
	BTNode * temp=(BTNode*)malloc(sizeof(BTNode));
	temp->data = data;
	temp->left = temp->right = 0;
	if(*root)
	{
		
		if(data > (*root)->data)
		{
			(*root)->right = temp;
		}else if(data < (*root)->data)
		{
			(*root)->left = temp;		
		}
			
	}else
	{
		(*root) = temp;
	}
	return;
}

void Traverse_Tree(BTNode *root)
{
	if(root->left)
	{
		Traverse_Tree(root->left);
	}
	printf("%d\n",root->data);
	if(root->right)
	{
		Traverse_Tree(root->right);
	}
}


