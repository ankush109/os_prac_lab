#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<fcntl.h>

int rec=0;

void leap(int n){
if(n%400==0) printf("leap year\n");
else if(n%100!=0 && n%4==0) printf("leap year\n");
else printf("not a leap year\n");
}

void custom_handler(int signum){
rec=1;
}

void main(){
int pid,n,i=1;
signal(SIGCHLD,custom_handler);
pid=fork();
if(pid==0){
	printf("child process with pid %d and ppid %d \n",getpid(),getppid());
	while(1){
	pause();
	if(rec==1){
	printf("Child Process %d : Enter year to check leap year or not : ",getpid());
	scanf("%d",&n);
	leap(n);
	rec=0;
}
	}
}

else{
	printf("parent process with pid %d  started \n",getpid());
	while(i==1){
	 sleep(5);
	 printf("enter 1 to continuee\n");
	scanf("%d",&i);
	if(i==0) continue;
	printf("parent signal to child process \n");
	kill(pid,SIGCHLD);
	}
}

}
