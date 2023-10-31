#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *args);
int i,n,j;
int main(){
pthread_t th; // thread declaration
pthread_create(&th,NULL,thread_function,NULL); // thread is created
pthread_join(th,NULL); // waiting for thread to finish 
printf("inside the program");
for(j=20;j<25;j++)
{
printf("%d\n",j);
sleep(1);
}
}

void *thread_function(void *args){
printf("inside thread");
for(int i=0;i<5;i++){
printf("%d\n",i);
sleep(1);

}
}
