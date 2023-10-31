#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
void *fun1();
void *fun2();
int shared=1;
sem_t s; //semaphore variable
int main(){
sem_init(&s,0,1); // initialise semaphore variable
pthread_t t1,t2;
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("final value of shared variable is %d\n",shared);
}
void *fun1()

{
int x;
sem_wait(&s);
x=shared;
printf("t1 reads the value as %d\n",x);
x++;
printf("local updatation by t1 %d\n",x);
sleep(1);
shared=x;
printf("value of shared updated by t1 %d\n",shared);
sem_post(&s);
}
void *fun2()

{
int x;
sem_wait(&s);
x=shared;
printf("t2 reads the value as %d\n",x);
x--;
printf("local updatation by t2 %d\n",x);
sleep(1);
shared=x;
printf("value of shared updated by t2 %d\n",shared);
sem_post(&s);
}

