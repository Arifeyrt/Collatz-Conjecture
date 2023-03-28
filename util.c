#include <stdio.h>
#include <stdlib.h>

void generate_sequence (int xs, int currentlen, int seqlen, int *seq){
if(currentlen<seqlen)
{
seq[currentlen]=xs;
if(xs%2==0){ //the first count is even is dividing by two
xs=xs/2;
}
else{  // the first count is odd , multiply by 3 and add 1
xs=3*xs+1;
}
generate_sequence(xs,currentlen+1,seqlen,seq);}}
int has_loop(int *arr, int n, int looplen, int *ls, int *le);
void check_loop_iterative(void (*f)(int,int,int,int*), int xs, int seqlen, int *loop,int *looplen){
int last;
int first;
int currentlen=0;
int *seq;
seq=(int*)calloc(seqlen,sizeof(int));
f(xs,currentlen,seqlen,seq);
int currentLen = seqlen / 2;
printf("\nSequence:{");
int y=seqlen -1;
for(int m = 0;m < seqlen;m++){  //numbers resulting from the operation
    printf("%d ",seq[m]);
    if(y<seqlen && y!=0){// for ,
    printf(",");
    y--;}}
printf("}\n\n"); 

while(currentLen > 1)
{
   printf("Checking if there is a loop of length %d...\n",currentLen);
   int res = has_loop(seq,seqlen,currentLen,&first,&last);
   if(res == 1)
	{        
	        printf("\nloop detected with a length of %d.\n",currentLen);
		printf("The indexes of the loop's first occurance:%d(first digit), %d(last digit)",first,last);
		
		for(int k = 0;k < currentLen;k++)
			loop[k] = seq[first + k];
		*looplen = currentLen;
		return;
	}
   --currentLen;
}

printf("No loop found\n");
*looplen = -2;

}

int check_equal_loop(int* arr0, int* arr1, int looplen){

    for(int i=0;i<looplen;i++)
        if(arr0[i] != arr1[i])
	    return 0;
    return 1;
}
int has_loop(int *arr, int n, int looplen, int *ls, int *le){

    int loop[looplen];
    
    if(looplen <= 1) //no loop
    	return 0;
    
    if(n < looplen*2)//no loop
    	return 0;
    
   for(int i = 0;i < looplen;i++) //to check as many elements of the array as the last number of loops
   {
   	loop[i] = arr[n - looplen + i];
   }
   
   int currentIndex = n;
   int loopCount = 0;
   int control = 1;
   while(currentIndex - looplen >= 0)  //there is loop
   {
   	currentIndex -= looplen;
	control = 1;
   	for(int i = 0;i < looplen;i++)
   	{
		if(arr[currentIndex + i] != loop[i]) //checking to see if the inside of the loops are the same
   	   {
		control = 0;
   	   	if(loopCount < 2)
   	   		return 0;
   	   	else
   	   	{
   	   	   *ls = n - (loopCount)*looplen; //I look back as many times as the number inside the loop to find the first number of the loop
   	   	   *le = *ls + looplen-1;
   	   	   return 1;
   	   	}
   	   }
   	}
   	
   	++loopCount;//we find out how many loops it is
   }
   if(control == 1){
	   *ls = n - (loopCount)*looplen; //I look back as many times as the number inside the loop to find the first number of the loop
   	   	*le = *ls + looplen;
   	   	return 1;
   }
    


}


void hist_of_firstdigits(void (*f)(int,int,int,int*), int xs, int seqlen, int *h, int digit)
{
	int currentlen=0;
	int *seq;
	seq=(int*)calloc(seqlen,sizeof(int));
	f(xs,currentlen,seqlen,seq);
	for(int i = 0;i < seqlen;i++)
	{
	   int current = seq[i];
	   while(current / 10) //find the number in the first digit
	   	current /= 10;
	   if(digit == (current % 10))
	   	++h[digit - 1];
	}
}










