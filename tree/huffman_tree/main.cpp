#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"huffman.h"

int main(void)
{
	htTree *codeTree = buildTree("I love youWASD FDSFF SDF fasdf  SDf  assdf ADFDSADsefa ds afwe");/*生成huffman tree*/
	
	hlTable*codeTable = buildTable(codeTree);/*根据huffman tree的索引生成表格,左0右1*/ 
	
	encode(codeTable,"I love you");
	
	decode(codeTree,"10111000101111010110011100111100001111010110011101");
	
	return 0;
}
