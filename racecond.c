#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared=1;
int main(){
pthread_t t1,t2;
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("final value of shared is %d\n",shared);

}
void *fun1(){
int x;
x=shared;
printf("thread reads %d\n",x);
x++;
printf("local up %d",x);
sleep(1);
shared=x;
printf("updated by t1 is %d\n",shared);
}
void *fun2(){
int y;
y=shared;
printf("thread2 reads shared val %d ",y);
y--;
printf("local updation by t1 is %d",y);
sleep(1);
shared=y;
printf("value updated by t2 is %d\n",shared);
}
