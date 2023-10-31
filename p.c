#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


void *prime(void *input){
int *a =input;
int count=a[0];
int i=a[1];
int j=a[2];
int c=0;
printf("running thread %d from %d - > %d\n ",count,i,j);
for(int k=i;k<j;k++){
c=0;
if(k==1) continue;
for(int l=1;l<=k;l++){
if(k%l==0) c+=1;

}
if(c==2) printf("%d ",k);

}
printf("\n");

}
void main(){
int n;
printf("enter a number");
scanf("%d",&n);
int input[3];
int start,end,step,rem;
rem=n%10;
step=n/10;
pthread_t th;
start=1;
for(int i=0;i<10;i++){
input[0]=i+1;
input[1]=start;
input[2]=start+step-1;
if(i==9) input[2]+=rem;
pthread_create(&th,NULL,prime,(void *)input);
pthread_join(th,NULL);
sleep(1);
start+=step;

}



}
