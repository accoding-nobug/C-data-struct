#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"huffman.h"

int main(void)
{
	htTree *codeTree = buildTree("I love youWASD FDSFF SDF fasdf  SDf  assdf ADFDSADsefa ds afwe");/*����huffman tree*/
	
	hlTable*codeTable = buildTable(codeTree);/*����huffman tree���������ɱ��,��0��1*/ 
	
	encode(codeTable,"I love you");
	
	decode(codeTree,"10111000101111010110011100111100001111010110011101");
	
	return 0;
}
