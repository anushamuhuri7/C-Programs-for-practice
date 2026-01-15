#include<stdio.h>
#include<stdlib.h>
#define MAX_NO 7
void push(int peg[], int *top, int disk){
peg[++(*top)]=disk;
}
int pop(int peg[], int *top){
return peg[(*top)--];
}
void printpeg(int peg[],int top, char name){
printf("Peg %c: ",name);
for(int i=0;i<=top;i++){
printf("%d", peg[i]);
}
printf("\n");
}
void printall(int a[], int ta, int b[], int tb, int c[], int tc){
printpeg(a,ta,'A');
printpeg(b,tb,'B');
printpeg(c,tc,'C');
printf("-----------------\n");
}
void move(int n,int src[], int *src_t,int dest[],int *dest_t,int aux[], int *aux_t, char s_n, char d_n, char a_n, int pA[], int *tA, int pB[], int *tB, int pC[], int *tC){
if(n==0) return;
move(n-1,src, src_t,aux,aux_t,dest,dest_t,s_n,a_n,d_n, pA, tA, pB, tB, pC, tC);
int disk=pop(src,src_t);
push(dest,dest_t,disk);
printf("Move disk %d from %c to %c\n", disk, s_n,d_n);
printall(pA,*tA, pB, *tB, pC, *tC);
move(n-1,aux,aux_t,dest,dest_t,src,src_t,a_n,d_n,s_n, pA,tA,pB,tB,pC,tC);
} 
int main(){
int pegA[7],pegB[7],pegC[7];
int topA=-1, topB=-1, topC=-1;
int n=7;
for(int i=n;i>=1;i--){
push(pegA,&topA,i);
}
printf("Initial State/; \n");
printall(pegA,topA,pegB,topB,pegC,topC);
move(n, pegA,&topA,pegC, &topC, pegB,&topB,'A','C','B',pegA,&topA,pegB,&topB,pegC, &topC);
return 0;
}


