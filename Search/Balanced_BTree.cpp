#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define LH 1
#define RH -1
#define EH 0


typedef struct BiTNode
{
	int data;
	int bf;//Æ½ºâÒò×Ó
	struct BiTNode *left,*right; 
}BiTNode,*BiTree;

int InsertAVL(BiTree *T,int e,int *taller);
void LeftBalance(BiTree* T);
void RightBalance(BiTree* T);
void R_Rotate(BiTree *T);
void L_Rotate(BiTree *T);


int InsertAVL(BiTree *T,int e,int *taller)
{
	if(!T)
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->left = (*T)->right = NULL;
		(*T)->bf = EH;
		*taller = true;
	}else
	{
		if(e == (*T)->data)
		{
			*taller = false;
			return 0;
		}
		if(e < (*T)->data)
		{
			if(!InsertAVL(&(*T)->left,e,taller))
			{
				return 0;
			}
			if(*taller)
			{
				
				switch((*T)->bf)
				{
					case LH:
						LeftBalance(T);
						break;
					case RH:
						(*T)->bf = EH;
						break;
					case EH:
						(*T)->bf = LH;
						*taller = true;
						break;		
				}
			}
		}else
		{
			if(!InsertAVL(&(*T)->right,e,taller))
			{
				return 0;
			}
			if(*taller)
			{
				
				switch((*T)->bf)
				{
					case LH:
						(*T)->bf = EH;
						break;
					case RH:
						RightBalance(T);
						break;
					case EH:
						(*T)->bf = RH;
						*taller = true;
						break;		
				}
			}
		}
	}
}
void LeftBalance(BiTree* T)
{
	BiTree L,Lr;
	L = (*T)->left;
	switch(L->bf)
	{
		case LH:
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH:
			Lr = L->right;
			switch(Lr->bf)
			{
				case LH:
					(*T)->bf = RH;
					L->bf = EH;
					break;
				case EH:
					(*T)->bf = L->bf = EH;
					break;
				case RH:
					(*T)->bf = EH;
					L->bf = LH;
					break;		
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->left);
			R_Rotate(T);
			break;		
	}
}
void RightBalance(BiTree* T)
{
	BiTree L,Lr;
	L = (*T)->right;
	switch(L->bf)
	{
		case RH:
			(*T)->bf = L->bf = EH;
			L_Rotate(T);
			break;
		case LH:
			Lr = L->left;
			switch(Lr->bf)
			{
				case LH:
					(*T)->bf = EH;
					L->bf = RH;
					break;
				case EH:
					(*T)->bf = L->bf = EH;
					break;
				case RH:
					(*T)->bf = LH;
					L->bf = EH;
					break;		
			}
			Lr->bf = EH;
			R_Rotate(&(*T)->right);
			L_Rotate(T);
			break;		
	}	
}
void R_Rotate(BiTree *T)
{
	BiTree L = (*T)->left;
	(*T)->left = L->right;
	L->right = (*T);
	*T = L ;
}

void L_Rotate(BiTree *T)
{
	BiTree L = (*T)->right;
	(*T)->right = L->left;
	L->left = (*T);
	*T = l ;	
}

