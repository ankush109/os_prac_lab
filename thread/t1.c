#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sum;
void *thread_fun(void *input){
int n=*((int*)input);
sum=(n*(n+1)/2);
printf("hello from custom thread %ld\n",pthread_self());
pthread_exit(&sum);
}



void main(){
pthread_t t;
void  *res;
int n;
printf("enter a number");
scanf("%d",&n);
//getchar();
printf("sending value to n the custom thread \n");

pthread_create(&t,NULL,thread_fun,&n);
pthread_join(t,&res); // waits for t thread to finish then return to main thread

printf("the sum of %d natural numbers is %d ",n,*((int*)res));

}
