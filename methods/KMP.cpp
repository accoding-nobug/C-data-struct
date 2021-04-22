#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Array_Size 100
int next[Array_Size];

void ini_next(char target[]/*��next������г�ʼ��*/)
{
	int i = 0,j=-1;
	next[0] = -1;
	while(i <strlen(target))
	{
		if(-1 == j || target[j] == target[i])
		{
			i++;
			j++;
			if(target[j] != target[i])	next[i] = j;
			if(target[j] == target[i])	next[i] = next[j];
		}else j = next[j];/* �����ڵݹ�˼�� , �Ӵ�target��Ŀ�괮letter�Ƚ�,�� i����ƥ��,����ݵ�next[j]�����Ƚ�
						  ,ͬ��,���Ӵ�target,ǰj���target[i]��ƥ��,��targetΪletter��,��ǰk��Ϊ�µ�target��,�ⲽ,����֮��*/
	}
}

int KMP(char target[], char letter[] )
{
	int j = 0,cnt = 0;
	for(int i = 0;i<strlen(letter);i++)
	{
		if(letter[i] == target[j])
		{
			j++; 
		}else
		{
			j =next[j];
			if(j != -1)	i--;
			if(-1 == j)
			{
				j = 0;
			}
		}
		if(strlen(target)-1 == j)
		return i;
	}
	return 0;
}

int main()
{
	
}
