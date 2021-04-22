#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

char model[26]="zyxwvutsrqponmlkjihgfedcba";

void search(char in[])
{
	int i = 0,j=0;
	for(;i<strlen(in);i++)
	{
		for(j = i+1;j<strlen(in);j++)
		{
			if(in[i]==in[j])
			{
				char*p = in+j;
				char temp[55];
				strcpy(temp,p+1);
				*p=0;
				strcat(in,temp);
			}
		}
	}
}

int main(void)
{
	char in[55];
	scanf("%s",in);
	freopen("encrypt.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char secret[55]={0};
	search(in);
	int len = strlen(in);
	int i = 0;
	for(;i<len;i++)
	{
		secret[i] = in[i];	
	}
		
	strcat(secret,model);
	search(secret);

	
	char input[55];
//	getchar();
//	getchar();
	gets(input);
	for(i = 0;i<strlen(input);i++)
	{
		if(isalpha(input[i]))
		{
			printf("%c",secret[input[i]-'a']);
		}else
		{
			printf("%c",input[i]);
		}
	}
	return 0;
}

