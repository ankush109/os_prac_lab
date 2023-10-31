// AIM: Using 10 threads to divide tasks and find out primes in the range of 1-N (where N is user-input)
// Developed By Anuvab Chakravarty
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdbool.h>
typedef struct {
    int ll,ul;
} range; // end of structure definition
void* findPrimesInRange(void*);
bool isPrime(int);
void main() {
    int n,i;
    printf("Please enter the value of N: ");
    scanf("%d",&n);
    range* Range=(range*)malloc(sizeof(range));
    Range->ll=1;
    int step=n/10,rem=n%10;
    pthread_t thread;
    for(i=1;i<=10;i++) {
        if(i==10) Range->ul=Range->ll+step-1+rem;
        else Range->ul=Range->ll+step-1;
        printf("Creating Thread %d...\n",i);
        pthread_create(&thread,NULL,findPrimesInRange,(void*)Range);
        pthread_join(thread,NULL);
        printf("Thread %d has now joined the Main Thread.\n",i);
        Range->ll+=step;
    } // end of for loop
    printf("All 10 Threads have successfully done their tasks and then joined the Main Thread in Sequence.\n");
} // end of main
void* findPrimesInRange(void* args) {
    range* Range=(range*)args;
    int upper_lim=Range->ul,lower_lim=Range->ll;
    int i;
    printf("The primes in the Range %d - %d are as follows: ",lower_lim,upper_lim);
    for(i=lower_lim;i<=upper_lim;i++) if(isPrime(i)) printf("%d ",i);
    printf("\n");
} // end of fn.
bool isPrime(int num) {
    if(num==1) return false;
    int factors=0;
    for(int i=1;i<=num;i++) if(num%i==0) factors++; 
    return factors==2;
} // end of fn.