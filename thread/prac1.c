#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *prime(void *input)
{
int *a=input;
int count =a[0];
int start=a[1];
int end =a[2];
int i,j,c;
printf("inside thread %d running from %d -> %d\n ",count,start,end);
for(int i=start;i<=end;i++){
c=0;
if(i==1) continue;
for(int j=1;j<=i;j++){
if(i%j==0) c+=1;
}
if(c==2) printf("%d ",i);
}
printf("\n");

}
void main(){
int n,start,end,rem;
pthread_t t;
printf("enter a number ");
scanf("%d",&n);
int input[3];
start=1;
int steps;
steps=n/10;
rem=n%10;
for(int i=0;i<10;i++){
input[0]=i+1;
input[1]=start;
input[2]=start+steps-1;
if(i==9) input[2]+=rem;
pthread_create(&t,NULL,prime,(void*)input);
pthread_join(t,NULL);
sleep(1);
start+=steps;
}



}

