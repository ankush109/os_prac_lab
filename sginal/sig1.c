#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<signal.h>
#include<fcntl.h>
int alarm_raised=0;
int sig=0;
void raised_alarm(int signum){
	alarm_raised=1;
	sig=signum;
}
void  main(){
	signal(SIGALRM,raised_alarm);
	int pid =fork();
	if(pid==-1){
	    perror("fork");
	    exit(1);

	}
	if(pid==0){
	 printf("child process with pid %d and ppid %d is running .. \n",getpid(),getppid());
	 sleep(5);
	 kill(getppid(),SIGALRM);
	 printf("child process send alarm to the parent\n");
	}
	else{
	 printf("parent process with pid %d is waiting \n",getpid());
	 while(alarm_raised==0){
	 printf("hello I am Ankush from parent process...\n");
	 sleep(1);
	}
	printf("parent received alarm from child with pid %d ",pid);
	printf("the signal number is %d\n",sig);

	}
}
