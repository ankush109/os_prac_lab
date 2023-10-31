#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
void *thread_function(void *args);

int num[2] = {2, 3};

int main() {
    pthread_t th; // thread declaration
    void *result;
    pthread_create(&th, NULL, thread_function, (void*)num); // thread is created
    pthread_join(th, &result); // waiting for thread to finish

    int *sum = (int*)result; // Cast the result back to int pointer
    printf("inside the program\n");
    printf("Thread returned %d\n", *sum);
}

void *thread_function(void *args) {
    printf("Inside thread\n");
    int *x = (int*)args;
    int s = x[0] + x[1];

  //  int *result = malloc(sizeof(int)); // Allocate memory for the result
    //*result = s;

    pthread_exit(*s);
}

