#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *prime(void *input){
int *a=input;
int count=a[0];
int start=a[1];
int end=a[2];
int i,j,c;
printf("Inside thread %d : prime numbers in range %d -> %d \n",count,start,end);
for(i=start;i<=end;i++){
if(i==1) continue;
c=0;
for(int j=1;j<=i;j++){
if(i%j==0) {
c+=1;
}

}
if(c==2) printf("%d",i);

}
printf("\n");
pthread_exit(NULL);
}

void main(){
int n,step,rem,start,end;
int input[3];
pthread_t t;
printf("enter a number");
scanf("%d",&n);
step=n/10;
rem=n%10;
start=1;
for(int i=0;i<10;i++){
input[0]=i+1;
end=start+step-1;
input[1]=start;
input[2]=end;
if(i==9) input[2]+=rem;
pthread_create(&t,NULL,prime,(void*)input);
pthread_join(t,NULL);
sleep(1);
start+=step;

}



}
