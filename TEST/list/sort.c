#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

char addition[10][4] = {{"_1"},{"_2"},{"_3"},{"_4"},{"_5"},{"_6"},{"_7"},{"_8"},{"_9"},{"_10"}};

typedef struct person
{
	char name[30];
	char tel[25];
	struct person *next;
}person;

typedef struct Headp
{
	person* head;
	person* tail;
}Hpointer;

void Delete(person *latter)
{
	person* temp = latter->next;
	latter->next=latter->next->next;
	free(temp);
}

void fun( Hpointer*Pointer )
{
	person* former = Pointer->head;
	person* latter,*temp;
	while(former)
	{
		if(!isdigit(former->name[strlen(former->name)-1]))
		{
		//traverse
			latter = former->next;
			temp = former;
			int flag = 0;
			while(latter)
			{
				if(!strcmp(former->name,latter->name))
				{
					if(!strcmp(former->tel,latter->tel))
					{
						Delete(temp);
						latter = temp->next;
						continue;
					}else
					{
						strcat(latter->name,addition[flag]);
						flag++;
						latter=latter->next;
						temp = temp->next;
						continue;
					}
				}
				latter = latter->next;
				temp = temp->next;
				
			}			
		}		
		former = former->next;
	}
}

void sort(Hpointer* Pointer)
{
	person*former = Pointer->head;
	int flag = 1;
	while(flag)
	{
		former = Pointer->head;
		flag = 0;
		while(former->next)
		{
			if(strcmp(former->name,former->next->name) > 0)
			{
				flag = 1;
				char name[30],tel[25];
				strcpy(name,former->name);
				strcpy(former->name,former->next->name);
				strcpy(former->next->name,name);
				
				strcpy(tel,former->tel);
				strcpy(former->tel,former->next->tel);
				strcpy(former->next->tel,tel);
			}
			former = former->next;
		}
	}
}

void Traverse(Hpointer* Pointer)
{
	person*temp = Pointer->head;
	while(temp)
	{
		printf("%s %s\n",temp->name,temp->tel);
		temp = temp->next;
	}
}

int main(void)
{
	Hpointer* Pointer = (Hpointer*)malloc(sizeof(Hpointer));
	Pointer->head = NULL;
	Pointer->tail = Pointer->head;
	char name[30],tel[25];
	int n ;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",name);
		scanf("%s",tel);
		if(Pointer->head)
		{
			Pointer->tail->next = (person*)malloc(sizeof(person));
			strcpy(Pointer->tail->next->name,name);
			strcpy(Pointer->tail->next->tel,tel);	
			Pointer->tail = Pointer->tail->next;		
		}
		else
		{
			Pointer->head = (person*)malloc(sizeof(person));
			strcpy(Pointer->head->name,name);
			strcpy(Pointer->head->tel,tel);
			Pointer->tail = Pointer->head;
		}
		Pointer->tail->next = NULL;
	}
	
	fun(Pointer);
	sort(Pointer);
	Traverse(Pointer);
	
	return 0;
}
