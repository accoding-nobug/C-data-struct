#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Node
{
	char word[100];
	long long times;
	struct Node* next;
	struct Node* prior;
}Node;

void Mylower(char*p)
{
	int j = 0;
	for(int i = 0;p[i];i++)
	{
		if(isalpha(p[i]))
		p[j++] = tolower(p[i]);
	}
	p[j] = 0;
	return;
}

int main()
{
	freopen("article.txt","r",stdin);
	Node* head = NULL ,*tail = NULL;
	char input[100];
	char tempc;
	while(scanf("%c",&tempc) != EOF)
	{
		int flag = 0;
		if(!isalpha(tempc)) 
		{
			continue;
		}else
		{
			while(isalpha(tempc))
			{
				input[flag++] = tempc;
				tempc = getchar();
			}	
		}
	
		input[flag] = 0;
		Mylower(input);
		Node* temp = head;
		if(!temp)
		{
			head = (Node*)malloc(sizeof(Node));
			strcpy(head->word,input);
			head->next = head->prior = NULL;
			head->times = 1;
			tail = head;
			continue;
		}
		for(;temp&&strcmp(temp->word,input)<0;temp=temp->next);
		if(!temp)
		{
			Node* newbuild = (Node*)malloc(sizeof(Node));
			strcpy(newbuild->word,input);
			newbuild->times = 1;
			newbuild->next = NULL;
			newbuild->prior = tail;
			tail->next = newbuild;
			tail = newbuild;
			continue;
		}
		else if(strcmp(temp->word,input) == 0)
		{
			temp->times++;
			continue;
		}else
		{
			if(temp == head)
			{
				Node* newbuild = (Node*)malloc(sizeof(Node));
				strcpy(newbuild->word,input);
				newbuild->times = 1;
				newbuild->prior = NULL;				
				head->prior = newbuild;
				newbuild->next = head;
				head = newbuild;
			}else
			{
				Node* newbuild = (Node*)malloc(sizeof(Node));
				strcpy(newbuild->word,input);
				newbuild->times = 1;				
				temp->prior->next = newbuild;
				newbuild->prior = temp->prior;
				temp->prior = newbuild;
				newbuild->next = temp;
			}
		}
		memset(input,0,sizeof(input));
	}
	Node* temp = head;
	while(temp)
	{
		printf("%s %lld\n",temp->word,temp->times);
		temp = temp->next;
	}
	return 0;
}
