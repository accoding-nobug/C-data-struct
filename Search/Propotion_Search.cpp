#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int Propotion_Search(int* array,int begin,int end,int key)
{
	if(begin > end) return -1;
	int mid = begin+(key-a[begin])/(a[end]-a[begin])*(end-begin);
	if(array[mid] == key)
	{
		return mid;
	}else if(array[mid] > key)
	{
		return Propotion_Search(array,begin,mid-1,key) ;
	}else
	{
		return Propotion_Search(array,mid+1,end,key) ;
	}
}
