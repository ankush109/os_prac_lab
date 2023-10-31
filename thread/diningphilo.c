#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t chopstick[5];

void eat (int n){
	printf("philosopher %d is eating ",n);

}
void *philoeats(void *input){
int n=*(int*) input;
printf("philosopher %d wants to eat\n",n);
sem_wait(&chopstick[n]);
printf(" philosopher %d  picks left stick\n",n);
sem_wait(&chopstick[(n+1)%5]);
printf("philosopher %d  picks right stick\n",n);
eat(n);
sleep(2);
printf("philosopher %d has finished eating \n",n);
sem_post(&chopstick[(n+1)%5]);
printf("philosopher %d has put left chopstick down \n",n);
sem_post(&chopstick[n]);
printf("philosopher %d has put right chopstick down \n",n);
}
int main(){
int i,n[5];
pthread_t t[5];
for(i=0;i<5;i++){
sem_init(&chopstick[i],0,1);
}
for(i=0;i<5;i++){
	n[i]=i;
pthread_create(&t[i],NULL,philoeats,&n[i]);
}
for(i=0;i<5;i++)
{
pthread_join(t[i],NULL);
}


}




