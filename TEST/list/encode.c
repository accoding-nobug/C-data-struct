#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Node
{
	char data;
	struct Node* next;
	struct Node* prior;
}Node;

Node* init_liter();
Node* Link_list(Node*p,Node*q);
void Del_Rep(Node*p);
int Del_Elem(Node*p);


Node* init_liter()
{
	Node*head = (Node*)malloc(sizeof(Node));
	head->data = 32;
	head->prior = head->next = head;
	Node *p = head;
	for(int i = 33;i<=126;i++)
	{
		Node*temp = (Node*)malloc(sizeof(Node));
		temp->data = i;	
		temp->next = head;
		temp->prior = p;
		p->next = temp;
		head->prior = temp;
		p = temp;
	}
	return head;
}

Node* Link_list(Node*p,Node*q)
{
	Node* headp = p,*tailp = p->prior;
	Node* headq = q,*tailq = q->prior;
	tailp->next = headq;
	headq->prior = tailp;
	tailq->next = headp;
	headp->prior = tailq; 
	return p;
}

void Del_Rep(Node*p)
{
	Node*former,*latter;
	former = p;
	latter = p->next;
	while(former->next != p)
	{
		latter = former->next;
		while(latter->next != p)
		{
			if(former->data == latter->data)
			{
				Node*temp = latter->prior;
				Del_Elem(latter);
				latter = temp;
			}
			latter = latter->next;
		}
		former = former->next;
	}
}

int Del_Elem(Node*p)
{
	int ret = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return ret;
}

int main(void)
{
	Node* liter = init_liter();
	int code[130] = {0};
	Node* input = NULL;
	Node* pointer;
	char tempc[40];
	gets(tempc);
	for(int i = 0;tempc[i];i++)
	{
		if(!input)
		{
			input = (Node*)malloc(sizeof(Node));
			input->next = input->prior = input;
			input->data = tempc[i];
			pointer = input;
		}else
		{
			Node *newbuild =(Node*)malloc(sizeof(Node));
			newbuild->data = tempc[i];
			pointer->next = newbuild;
			newbuild->prior = pointer;
			newbuild->next = input;
			input->prior = newbuild;
			pointer = newbuild;
		}
	}
	Link_list(input,liter);
	Del_Rep(input);
	
	Node* target = input;
	int step = 0,num = 126-32+1,encode,mem,flag = 1;
	while(target->next != target)
	{
		Node* temp = target->next;
		encode = Del_Elem(target);
		if(flag)	
		{
			mem = encode;
			flag = 0;
		}
		num--;
		target = temp;
		step = encode%num;
		if(step == 0)
		{
			code[encode] = target->prior->data;
			target=target->prior;
		}else
		{
			step--;
			while(step--)
			{
				target = target->next;
			}
			code[encode] = target->data;
		}
	}
	code[target->data] = mem;

	FILE* in = fopen("in.txt","r");
	FILE* out = fopen("in_crpyt.txt","w");
	
	char character;
	while(fscanf(in,"%c",&character) != EOF)
	{
		if(character<32||character>126)
		{
			fprintf(out,"%c",character);
		}
		else if(code[character])
		{
			fprintf(out,"%c",code[character]);
		}
	}
}
