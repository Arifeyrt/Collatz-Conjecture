#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main(){

int xs;
int seqlen;
int *seq;
int a=8;
printf("Please enter the sequance length: ");
scanf("%d",&seqlen);
printf("please enter the first element: ");
scanf("%d",&xs);


int loop[20],looplen;
check_loop_iterative(&generate_sequence,xs,seqlen,loop,&looplen);
if(looplen != -2){
printf("\nLoop:{");
for(int j = 0;j < looplen;j++) {//numbers in the loop
printf("%d ",loop[j]);
	if(j+1!=looplen)
	{printf(",");
	}}
printf("}\n");
}

int *h = (int*)malloc(sizeof(int) * 9);
for(int i = 1;i < 10;i++)
	hist_of_firstdigits(&generate_sequence, xs, seqlen, h, i);
	
printf("\nHistogram of the sequence: ");
printf("{");
for(int i = 0;i < 9;i++){
	printf("%d",h[i]);
	if( a<9 && a!=0)
	{
	printf(",");
	a--;
	}
	
	}
	printf("}");
	free(h);
















  return 0;
}















