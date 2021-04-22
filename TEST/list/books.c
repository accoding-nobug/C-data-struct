#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
/*�û������ӿ���̨���룬�����������������ţ�1����¼�������2������Ҳ�����3����ɾ��������0�����Ѹ��µ�ͼ����Ϣ���浽����в��˳����򣩣�
Ȼ������һ��������Ӧ�Ĳ�����Ϣ��¼�������Ҫ����һ��ͼ����Ϣ�����Һ�ɾ��������ֻҪ���������������в�����Ϣ��������֧�й����п��Խ��ж�β�����
ֱ���˳����������0������
����ռ50���ַ���ȣ�����ռ20���ַ���ȣ�������ռ30���ַ���ȣ���������ռ10���ַ���ȣ�������������*/
typedef struct books
{
	struct books *prior;
	char name[55];
	char author[25];
	char industry[35];
	char date[15];
	struct books *next;
}books;

typedef struct Pointer
{
	books* head;
	books* tail;
}Bookp;

void Add_list(Bookp *Headbp,char name[55],char author[25],char industry[35],char date[15]);
void Delete(Bookp *Headbp);
void Search(Bookp *Headbp);
void Traverse(Bookp *Headbp,FILE* out);

int main(void)
{
	FILE *in,*out;
	in = fopen("books.txt","r");
	Bookp* Headbp=(Bookp*)malloc(sizeof(Bookp));
	Headbp->head = NULL;
	Headbp->tail = Headbp->head;
	
	char name[55];
	char author[25];
	char industry[35];
	char date[15];	
	
	while(fscanf(in,"%s",name) != EOF  &&fscanf(in,"%s",author) != EOF &&fscanf(in,"%s",industry) != EOF &&fscanf(in,"%s",date) != EOF )
	{
		Add_list(Headbp,name,author,industry,date);
	}

	int type ;
	while(1)
	{
		scanf("%d",&type);
		if(0 == type) break;
		switch(type)
		{
			case 1 : 
			scanf("%s",name);
			scanf("%s",author);
			scanf("%s",industry);
			scanf("%s",date);	
			Add_list(Headbp,name,author,industry,date);
				break;
			case 2 : Search(Headbp);
				break;
			case 3 : Delete(Headbp);
				break;		
		}
	}
	out = fopen("ordered.txt","w");
	Traverse(Headbp,out);
	return 0;		
} 

void Add_list(Bookp *Headbp,char name[55],char author[25],char industry[35],char date[15])
{
	if(Headbp->head)
	{
		
		books *temp = (books*)malloc(sizeof(books));
		strcpy(temp->author,author);
		strcpy(temp->name,name);
		strcpy(temp->date,date);
		strcpy(temp->industry,industry);
		temp->next = NULL;
		temp->prior = NULL;
		books *p = Headbp->head;
		while(p && strcmp(temp->name,p->name) >=0 )
		{
			p = p->next;
			if(!p) break;
		}			
		if(p)
		{
			if(p->prior)
			{
				p->prior->next = temp;
				temp->prior = p->prior;
			}else
			{
				Headbp->head = temp;
				temp->prior = NULL;
			}
			temp->next = p;
			p->prior = temp;				
		}else//temp jie zai wei bu
		{
			Headbp->tail->next = temp;
			temp->prior = Headbp->tail;
			Headbp->tail = temp;
			Headbp->tail->next = NULL;
		}
					
	}else
	{
		Headbp->head = (books*)malloc(sizeof(books));
		Headbp->tail = Headbp->head;
		
		strcpy(Headbp->tail->author,author);
		strcpy(Headbp->tail->name,name);
		strcpy(Headbp->tail->date,date);
		strcpy(Headbp->tail->industry,industry);
		
		Headbp->head->prior = NULL;	
		Headbp->tail->next = NULL;	
	}
	
}

void Delete(Bookp *Headbp)
{
	char name[55];
	scanf("%s",name);
	books *p = Headbp->head;
	while(p)
	{
		if(strstr(p->name,name))
		{
			books*temp;
			if(p->prior)
			{
				temp = p->prior;
				p->prior->next = p->next;
				if(p->next)
				{
					p->next->prior = p->prior;
					
				}else
				{
					Headbp->tail = p->prior;
				}
				free(p);
				p = temp->next;
			}else
			{
				Headbp->head = p->next;
				temp = Headbp->head;
				if(p->next)	p->next->prior = p->prior;
				free(p);
				p = temp;				
			}	
		}
		else p = p->next;
	}
}
void Search(Bookp *Headbp)/*50 20 30 10*/
{
	char name[55];
	scanf("%s",name);
	books *p = Headbp->head;	
	while(p)
	{
		if(strstr(p->name,name))
		{
			printf("%-50s%-20s%-30s%-10s\n",p->name,p->author,p->industry,p->date);	
		}	
		p = p->next;
	}	
}
void Traverse(Bookp *Headbp,FILE* out)
{
	books *p = Headbp->head;	
	while(p)
	{
		fprintf(out,"%-50s%-20s%-30s%-10s\n",p->name,p->author,p->industry,p->date);	
		p = p->next;				
	}	
}
